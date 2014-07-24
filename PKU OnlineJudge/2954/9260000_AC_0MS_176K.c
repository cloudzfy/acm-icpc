/* POJ 2954
 * 计算几何：Pick定理
 * 1.以格子点为顶点的线段，覆盖的点的个数为GCD(dx,dy)，
 *   其中，dxdy分别为线段横向占的点数和纵向占的点数。
 *   如果dx或dy为0，则覆盖的点数为dy或dx。
 * 2.Pick公式：平面上以格子点为顶点的简单多边形，如果
 *   边上的点数为on，内部的点数为in，则它的面积为A=on/2+in-1。
 *   http://episte.math.ntu.edu.tw/articles/sm/sm_25_10_1/index.html
 * 3.任意一个多边形的面积等于按顺序求相邻两个点与原点组成的向量的叉积之和
 * Memory:176K Time:0MS
 */
#include <stdio.h>
#include <math.h>
int gcd(int a,int b)
{
	int tmp;
	while(b)
	{
		tmp=b;
		b=a%b;
		a=tmp;
	}
	return a;
}
int main()
{
	int x1,y1,x2,y2,x3,y3,area,result;
	while(scanf("%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3)!=EOF)
	{
		if(x1==0&&y1==0&&x2==0&&y2==0&&x3==0&&y3==0)break;
		area=abs((x2-x1)*(y3-y1)-(x3-x1)*(y2-y1));
		result=area+2-gcd(abs(x2-x1),abs(y2-y1))-gcd(abs(x3-x1),abs(y3-y1))-gcd(abs(x3-x2),abs(y3-y2));
		printf("%d\n",result/2);
	}
	return 0;
}