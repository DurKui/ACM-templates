#include <bits/stdc++.h>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAXSIZE 10000
#define MaxInt 32767
#define MVNum 100
typedef int Status;
using namespace std;
typedef int ArcType;
typedef char VerTexType;
//最短路径主要涉及两个算法//
//dijsktra与floyd算法//
//dijsktra算法又称迪结斯科拉//
//最短路径与最小生成树之间的区别是最短路径不用包含所有顶点
//主要有如下几个步骤
//先找到能直达的顶点//再从这些路径中找出权值最小的那一条//更新能到达的顶点的最短路径//再从能到达的顶点的路径中找出最小的重复上述操作||重复n-1次
//引出三个数组 S[]：相应顶点是否已被确立为最短路径，D[]原点到相应顶点路径长度，Path[]相应顶点前驱
//邻接矩阵存储
typedef struct
{
  VerTexType vexs[MVNum];
  ArcType arcs[MVNum][MVNum];
  int vexnum, arcnum;
} AMGraph;
int LocateVex(AMGraph g, VerTexType s) //确定顶点在图中的位置
{
  for (int i = 0; i < g.vexnum; i++)
  {
    if (g.vexs[i] == s)
      return i;
  }
  return -1;
}
//构建有向图邻接矩阵
Status CreateUDN(AMGraph &G)
{
  cin >> G.vexnum >> G.arcnum;
  for (int i = 0; i < G.vexnum; i++) //输入顶点信息
    cin >> G.vexs[i];
  for (int i = 0; i < G.vexnum; i++)
  {
    for (int j = 0; j < G.vexnum; j++) //邻接矩阵初始化
    {
      G.arcs[i][j] = MaxInt;
    }
  }
  for (int i = 0; i < G.arcnum; i++) //输入一条边依附的两个顶点
  {
    char v1, v2;
    int w;
    cin >> v1 >> v2 >> w;
    int j, k;
    j = LocateVex(G, v1);
    k = LocateVex(G, v2);
    G.arcs[j][k] = w;
    G.arcs[k][j] = G.arcs[j][k];
  }
  return OK;
}
bool S[MVNum];
int D[MVNum],Path[MVNum];
void dij(AMGraph G,int v0){
int n=G.vexnum;
for(int i=0;i<n;i++) //初始化
{
    S[i]=false;         
    D[i]=G.arcs[v0][i]; 
    if(D[i]<MaxInt)
    Path[i]=v0;     //前一个顶点为v0
    else Path[i]=-1; 
}
S[v0]=true;   //标记找到最短路
D[v0]=0;
for(int i=1;i<n;i++)    //执行n-1次，因为没执行一次找到一个最短路，一共有n-1个顶点需要找最短路
{
    int minn=MaxInt,v;
    for(int w=0;w<n;w++)
    {
        if(!S[w]&&D[w]<minn)//最小值就是最短路
        {
             v=w;minn=D[w];
        }
        S[v]=true;
    }
    for(int w=0;w<n;w++)
    {
        if(!S[w]&&(D[v]+G.arcs[v][w])<D[w])//根据找到的一条最短路更新D[]数组
        {
            D[w]=D[w]+G.arcs[v][w];
            Path[w]=v;
        }
    }
}
}
//Floyd算法
//初始化，一开始不允许有中间节点，则任意两点的最短路径为它们之间直达的点的最短边
//逐步加入中间结点，更新任意两点间的最短路径
int DD[MVNum][MVNum];
void floyd(AMGraph T){
for(int i=0;i<T.vexnum;i++)
{
  for(int j=0;j<T.vexnum;j++)
  {
    DD[i][j]=T.arcs[i][j];
  }
  for(int k=0;k<T.vexnum;k++)
  for(int i=0;i<T.vexnum;i++)
  for(int j=0;j<T.vexnum;j++)
  {
    if(DD[i][k]+DD[k][j]<DD[i][j])
    DD[i][j]=DD[i][k]+DD[k][j];
  }
}
}
int main(){
  return 0;
}
