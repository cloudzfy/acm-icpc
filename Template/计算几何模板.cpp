/* 计算几何模板
 * By Cloudzfy
 * 2011/8/31
 */

#define INF 100000
#define eps 1e-10

/*结构体*/
struct Point
{
	double x,y;
	Point(){}
	Point(double _x,double _y):x(_x),y(_y){}
	bool operator<(const Point q)const
	{
		if(fabs(y-q.y)<eps)return x<q.x;
		return y<q.y;
	}
	bool operator>(const Point q)const
	{
		if(fabs(y-q.y)<eps)return x>q.x;
		return y>q.y;
	}
	struct Point operator-(const Point q)const
	{
		return Point(x-q.x,y-q.y);
	}
};
struct Segment
{
	struct Point start,end;
};
struct Circle
{
	struct Point origin;
	double r;
};

/*判断大小*/
int sig(double k)
{
	return (k<-eps)?-1:(k>eps);
}

/*点积*/
double dotmultiply(struct Point start,struct Point end,struct Point origin)
{
	return (start.x-origin.x)*(end.x-origin.x)+(start.y-origin.y)*(end.y-origin.y);
}

/*叉积*/
double multiply(struct Point start,struct Point end,struct Point origin)
{
	return (start.x-origin.x)*(end.y-origin.y)-(end.x-origin.x)*(start.y-origin.y);
}

/*两点间的距离*/
double dist(struct Point a,struct Point b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

/*点到直线的垂足*/
double relation(struct Point p,struct Segment l)
{
	return dotmultiply(p,l.end,l.start)/(dist(l.start,l.end)*dist(l.start,l.end));
}
struct Point perpendicular(struct Point p,struct Segment l)
{
	struct Point ans;
	double r=relation(p,l);
	ans.x=l.start.x+r*(l.end.x-l.start.x);
	ans.y=l.start.y+r*(l.end.y-l.start.y);
	return ans;
}

/*两条直线交点*/
struct Point intersect_P(struct Segment a,struct Segment b)
{
	double dot1,dot2;
	struct Point q;
	dot1=multiply(a.end,a.start,b.start);
	dot2=multiply(b.end,a.start,a.end);
	q.x=(b.start.x*dot2+b.end.x*dot1)/(dot2+dot1);
	q.y=(b.start.y*dot2+b.end.y*dot1)/(dot2+dot1);
	return q;
}

/*三角形垂足*/
struct Point OrthoCenter(struct Point a,struct Point b,struct Point c)
{
	struct Point p;
	struct Segment l1,l2,l;
	l1.start=a;
	l.start=b;
	l.end=c;
	l1.end=perpendicular(a,l);
	l2.start=b;
	l.start=a;
	l.end=c;
	l2.end=perpendicular(b,l);
	p=intersect_P(l1,l2);
	return p;
}

/*求三角形外接圆圆心*/
struct Point cocircle(struct Point a,struct Point b,struct Point c)
{
	struct Point q;
	double u1,u2;
	u1=(b.x*b.x-a.x*a.x+b.y*b.y-a.y*a.y)/2;
	u2=(c.x*c.x-a.x*a.x+c.y*c.y-a.y*a.y)/2;
	q.x=(u1*(c.y-a.y)-u2*(b.y-a.y))/((b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y));
	q.y=(u2*(b.x-a.x)-u1*(c.x-a.x))/((b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y));
	return q;
}

/*半平面交*/
int judgein(int x,int y,int z)
{
	struct Point q=intersect_P(line[x],line[y]);
	return sig(multiply(line[z].end,q,line[z].start))>0;
}
int HalfPlaneIntersection(struct Point polygon[],int n)
{
	int i,tmpn;
	for(i=0;i<n;i++)
	{
		at2[i]=atan2(line[i].end.y-line[i].start.y,line[i].end.x-line[i].start.x);
		order[i]=i;
	}
	qsort(order,n,sizeof(order[0]),cmp);
	for(i=1,tmpn=1;i<n;i++)
	{
		if(sig(at2[order[i]]-at2[order[i-1]]))order[tmpn++]=order[i];
	}
	n=tmpn;
	deque<int> dq;
	dq.push_front(order[0]);
	dq.push_back(order[1]);
	for(i=2;i<n;i++)
	{
		while(dq.size()>=2&&judgein(dq[dq.size()-2],dq[dq.size()-1],order[i]))dq.pop_back();
		while(dq.size()>=2&&judgein(dq[1],dq[0],order[i]))dq.pop_front();
		dq.push_back(order[i]);
	}
	while(dq.size()>=2&&judgein(dq[dq.size()-2],dq[dq.size()-1],dq[0]))dq.pop_back();
	while(dq.size()>=2&&judgein(dq[1],dq[0],dq[dq.size()-1]))dq.pop_front();
	dq.push_front(dq.back());
	n=0;
	for(i=1;i<(int)dq.size();i++)
	{
		polygon[n++]=intersect_P(line[dq[i-1]],line[dq[i]]);
	}
	return n;
}

/*旋转卡壳求最远点对*/
int rotating_calipers(int n)
{
	int ans=0,q=1,i;
	for(i=0;i<n;i++)
	{
		while(abs(multiply(res[(q+1)%n],res[(i+1)%n],res[i]))>abs(multiply(res[q],res[(i+1)%n],res[i])))
			q=(q+1)%n;
		if(ans<dist(res[i],res[q]))ans=dist(res[i],res[q]);
	}
	return ans;
}

/*凸包*/
int Graham_Scan()
{
	int top=1,len,i;
	qsort(point,N,sizeof(point[0]),cmp);
	if(N==0) return 0;
	res[0]=point[0];
	if(N==1) return 1;
	res[1]=point[1];
	if(N==2) return 2;
	res[2]=point[2];
	for(i=2;i<n;i++)
	{
		while(top&&!(multiply(point[i],res[top],res[top-1])<0)) top--;
		res[++top]=point[i];
	}
	len=top;
	res[++top]=point[n-2];
	for(i=n-3;i>=0;i--)
	{
		while(len<top&&!(multiply(point[i],res[top],res[top-1])<0)) top--;
		res[++top]=point[i];
	}
	return top;
}

/*点与多边形关系（简单多边形）*/
int online(struct Segment l,struct Point p)//点在线段上
{
	return (multiply(l.end,p,l.start)==0&&
		(l.start.x-p.x)*(l.end.x-p.x)<=0&&
		(l.start.y-p.y)*(l.end.y-p.y)<=0);
}
int intersect(struct Segment a,struct Segment b)//判断两线段是否相交（包括端点）
{
	return (max(a.start.x,a.end.x)>=min(b.start.x,b.end.x)&&
		max(b.start.x,b.end.x)>=min(a.start.x,a.end.x)&&
		max(a.start.y,a.end.y)>=min(b.start.y,b.end.y)&&
		max(b.start.y,b.end.y)>=min(a.start.y,a.end.y)&&
		multiply(b.start,a.end,a.start)*multiply(b.end,a.end,a.start)<=0&&
		multiply(a.start,b.end,b.start)*multiply(a.end,b.end,b.start)<=0);
}
int intersect_A(struct Segment a,struct Segment b)//判断两线段是否相交（不包括端点）
{
	return (intersect(a,b)&&
		(!online(a,b.start))&&(!online(a,b.end))&&
		(!online(b,a.start))&&(!online(b,a.end)));
}
int InsidePolygon(struct Point polygon[],int num,struct Point q)
{
	int i,c=0;
	struct Segment l1,l2;
	l1.start=q;
	l1.end.y=INF;
	l1.end.x=INF;
	for(i=0;i<num;i++)
	{
		l2.start=polygon[i];
		l2.end=polygon[(i+1)%num];
		if(online(l2,q)) return 1;//点在多边形上
		if(intersect_A(l1,l2)||//相交且不在端点
			(online(l1,polygon[(i+1)%num])&&//第二个端点在射线上
			((!online(l1,polygon[(i+2)%num]))&&
			multiply(polygon[i],polygon[(i+1)%num],l1.start)*multiply(polygon[(i+1)%num],polygon[(i+2)%num],l1.start)>0||//前一个端点和后一个端点在射线两侧
			online(l1,polygon[(i+2)%num])&&
			multiply(polygon[i],polygon[(i+2)%num],l1.start)*multiply(polygon[(i+2)%num],polygon[(i+3)%num],l1.start)>0)))//下一条边是水平线，前一个端点和后一个端点在射线两侧
			c++;
	}
	if(c%2==1) return 0;//点在多边形内
	return 2;//点在多边形外
}

/*点与凸包的关系*/
int insidePoint()
{
	int i;
	double now ,pre=multiply(point[0],point[1],peg);
	for(i=1;i<N;i++)
	{
		now=multiply(point[i],point[(i+1)%N],peg);
		if(pre*now<eps) return 0;
		pre=now;
	}
	return 1;
}

/*最小包围圆*/
struct Circle cocircle(struct Point a,struct Point b,struct Point c)
{
	struct Circle d;
	double u1,u2;
	u1=(b.x*b.x-a.x*a.x+b.y*b.y-a.y*a.y)/2;
	u2=(c.x*c.x-a.x*a.x+c.y*c.y-a.y*a.y)/2;
	d.origin.x=(u1*(c.y-a.y)-u2*(b.y-a.y))/((b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y));
	d.origin.y=(u2*(b.x-a.x)-u1*(c.x-a.x))/((b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y));
	d.r=sqrt((a.x-d.origin.x)*(a.x-d.origin.x)+(a.y-d.origin.y)*(a.y-d.origin.y));
	return d;
}
struct Circle MiniDisc(struct Point p[],int n)
{
	int i,j,k;
	struct Circle d;
	d.origin.x=(p[0].x+p[1].x)/2;
	d.origin.y=(p[0].y+p[1].y)/2;
	d.r=dist(d.origin,p[0]);
	for(i=2;i<n;i++)
	{
		if(sig(dist(p[i],d.origin)-d.r)>0)
		{
			d.origin.x=(p[0].x+p[i].x)/2;
			d.origin.y=(p[0].y+p[i].y)/2;
			d.r=dist(d.origin,p[0]);
			for(j=1;j<i;j++)
			{
				if(sig(dist(p[j],d.origin)-d.r)>0)
				{
					d.origin.x=(p[i].x+p[j].x)/2;
					d.origin.y=(p[i].y+p[j].y)/2;
					d.r=dist(d.origin,p[i]);
					for(k=0;k<j;k++)
					{
						if(sig(dist(p[k],d.origin)-d.r)>0)
						{
							d=cocircle(p[i],p[j],p[k]);
						}
					}
				}
			}
		}
	}
	return d;
}

/*求简单多边形重心*/
struct Point gravitycenter(struct Point polygon[],int n)
{
	int i;
	double area=0,mu;
	struct Point p,origin;
	origin.x=origin.y=0;
	p.x=p.y=0;
	for(i=0;i<n;i++)
	{
		mu=multiply(polygon[i],polygon[(i+1)%n],origin);
		area+=mu;
		p.x+=(polygon[i].x+polygon[(i+1)%n].x)*mu;
		p.y+=(polygon[i].y+polygon[(i+1)%n].y)*mu;
	}
	p.x/=(3*area);
	p.y/=(3*area);
	return p;
}
