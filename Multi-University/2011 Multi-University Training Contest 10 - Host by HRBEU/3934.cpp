#include <iostream>  
#include <algorithm>  
#include <cmath>  
#define MAX_N 1150005  
#define EPS 1e-8  
using namespace std;  
//存储凸包点在nodes里的下标  
struct p  
{  
    int index;  
}pol[MAX_N];  
int polnum;  
//存储输入点  
struct node  
{  
    double x, y;  
}nodes[MAX_N];  
int noden, sindex;  
double sx, sy;  
//向量(n1, n3) 与向量 (n2, n3)的差积  
double crossMult(const node &n1, const node &n2, const node &n3)  
{  
    return (n1.x - n3.x) * (n2.y - n3.y) - (n2.x - n3.x) * (n1.y - n3.y);  
}  
//点n1与nodes[0]的距离的平方  
double dist(const node &n1)  
{  
    return (n1.x - nodes[0].x) * (n1.x - nodes[0].x) + (n1.y - nodes[0].y) * (n1.y - nodes[0].y);  
}  
//计算凸包之前的排序比较函数  
bool compare(const node &n1, const node &n2)  
{  
    double type = crossMult(n1, n2, nodes[0]);  
    if(type < -EPS) return false;  
    else if(type > EPS) return true;  
    else return dist(n1) <= dist(n2);  
}  
//计算凸包, 逆时针排序, 共线点需要加上  
void getPoly()  
{  
    polnum = 0;  
    pol[polnum++].index = 0;  
    pol[polnum++].index = 1;  
    for(int i = 2; i < noden; i++)  
    {  
        while(true) //唉,这次又把这儿给漏了  
        {  
            int index1 = pol[--polnum].index;  
            int index0 = pol[--polnum].index;  
            double type = crossMult(nodes[i], nodes[index1], nodes[index0]);  
            pol[polnum++].index = index0;  
            if(type <= -EPS)  
            {  
                pol[polnum++].index = index1;  
                break;  
            }  
            if(polnum == 1) break;  
        }  
        pol[polnum++].index = i;  
    }  
}  
//旋转卡壳  
double getMaxSize()  
{  
    int i, j, k;  
    double maxSize = 0;  
    //遍历i  
    for(i = 0; i < polnum; i++)  
    {  
        //初始化j, k分别为下一个和下下个凸包上的点  
        j = (i + 1) % polnum;  
        k = (j + 1) % polnum;  
        double c1, c2;  
        //旋转k直到k == i或者三角形(i, j, k+1)的面积不再增加  
        while(k != i)  
        {  
             double c1 = crossMult(nodes[pol[j].index], nodes[pol[k].index], nodes[pol[i].index]);  
             double c2 = crossMult(nodes[pol[j].index], nodes[pol[(k + 1) % polnum].index], nodes[pol[i].index]);  
             if(c1 + EPS < c2) k = (k + 1) % polnum;  
             else break;  
        }  
        if(k == i) continue;  
        int kk = (k + 1) % polnum;  
          
        //旋转j, k直到j == kk 或者k == i  
        while(j != kk && k != i)  
        {  
            //更新最大面积  
            c1 = crossMult(nodes[pol[j].index], nodes[pol[k].index], nodes[pol[i].index]);  
            if(c1 > maxSize + EPS) maxSize = c1;  
            //旋转k直到 k == i 或者三角形(i, j, k+1)的面积不再增加   
            while(k != i)  
            {  
                c1 = crossMult(nodes[pol[j].index], nodes[pol[k].index], nodes[pol[i].index]);  
                c2 = crossMult(nodes[pol[j].index], nodes[pol[(k + 1) % polnum].index], nodes[pol[i].index]);  
                if(c1 + EPS < c2) k = (k + 1) % polnum;  
                else break;  
            }  
            j = (j + 1) % polnum;  
        }  
    }  
    return maxSize / 2.0;  
}  
int main()  
{  
    int i;  
    while(scanf("%d", &noden)!=EOF)  
    {  
        sx = sy = INT_MAX;   
        for(i = 0; i < noden; i++)  
        {  
            scanf("%lf%lf", &nodes[i].x, &nodes[i].y);  
            if(nodes[i].y + EPS < sy || (fabs(nodes[i].y - sy) < EPS && nodes[i].x + EPS < sx))  
            {  
                sx = nodes[i].x;  
                sy = nodes[i].y;  
                sindex = i;  
            }  
        }  
        if(noden <= 2) printf("0.00/n");  
        else  
        {  
            if(sindex != 0)  
            {  
                int tempx = nodes[0].x, tempy = nodes[0].y;  
                nodes[0].x = nodes[sindex].x; nodes[0].y = nodes[sindex].y;  
                nodes[sindex].x = tempx; nodes[sindex].y = tempy;  
            }  
            sort(&nodes[1], &nodes[1] + noden - 1, compare);  
            getPoly();  
            printf("%.2lf\n", getMaxSize());  
        }          
    }  
    return 0;  
}  