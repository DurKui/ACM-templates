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
//“以下算法适用于无向带权图”//

//******prim算法*****//
//prim算法又称普莱姆算法，用于求解最小生成树的问题
//适用于像稠密图这样边较多的图
//原理是归并顶点，与边无关//
//设立一个集合，每次找出在集合内的顶点与不在集合内组成的权值最小的一条边，将另一头的顶点加入到该集合直到所有顶点都在集合里//
struct closedge
{
  VerTexType adjvex; //最小边在U中的顶点
  ArcType lowcost;   //最小边上的权值
} closedge[MVNum];
//无向图邻接矩阵存储
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
//构建无向图邻接矩阵
struct node //边结点，含有边的有顶点与尾顶点
{
  VerTexType head;
  VerTexType tail;
  ArcType lowcost;
} Edge[MVNum];
Status CreateUDN(AMGraph &G)
{
  cout<<"请输入顶点数与边数"<<endl;
  cin >> G.vexnum >> G.arcnum;
  cout<<"请输入各顶点名称"<<endl;
  for (int i = 0; i < G.vexnum; i++) //输入顶点信息
    cin >> G.vexs[i];
  for (int i = 0; i < G.vexnum; i++)
  {
    for (int j = 0; j < G.vexnum; j++) //邻接矩阵初始化
    {
      G.arcs[i][j] = MaxInt;
    }
  }
  cout<<"请输入各边所依附的两个顶点以及权值"<<endl;
  for (int i = 0; i < G.arcnum; i++) //输入一条边依附的两个顶点
  {
    char v1, v2;
    int w;
    cin >> v1 >> v2 >> w;
    int j, k;
    Edge[i].head=v1;
    Edge[i].tail=v2;
    Edge[i].lowcost=w;
    j = LocateVex(G, v1);
    k = LocateVex(G, v2);
    G.arcs[j][k] = w;
    G.arcs[k][j] = G.arcs[j][k];
  }
  return OK;
}
int Min(AMGraph G, struct closedge *x)//找closedge中最小值
{ 
  int minn, minx, i;
  for (i = 0; i < G.vexnum; i++)
    if (x[i].lowcost != 0&&x[i].lowcost!=MaxInt)
    {
      minn = x[i].lowcost;
      minx = i;
      break;
    }
  for (int j = i + 1; j < G.vexnum; j++)
  {
    if (x[j].lowcost > 0 && minn > x[j].lowcost)
    {
      minn = x[j].lowcost;
      minx = j;
    }
  }
  return minx;
}
void Min_Prim(AMGraph G, VerTexType u)
{
  int k = LocateVex(G, u);          //找到u在G中的位置
  for (int i = 0; i < G.vexnum; i++)
    if (i != k)
      closedge[i] = {u, G.arcs[k][i]}; //初始化
  closedge[k].lowcost = 0; //将u并入U
  for (int i = 1; i < G.vexnum; i++)
  {
    int m = Min(G, closedge);       //找与U中顶点相邻的权值最小的边
    char u0 = closedge[m].adjvex;  //最小边U中顶点
    char v0 = G.vexs[m];           //不在U中的那个顶点
    cout << u0 << " " << v0 << endl;    //输出最小边的头尾顶点
    for (int j = 0; j < G.vexnum; j++) //更新最小边
    {
       closedge[m].lowcost = 0; //将m并入U
      if (G.arcs[m][j] < closedge[j].lowcost)
      {
        closedge[j].lowcost = G.arcs[m][j];
        closedge[j].adjvex = v0;
      }
    }
  }
}


//*****Kruskal*****//
//又称克鲁斯卡尔算法//
//与prim算法相反，Kruskal算法归并边，与顶点数无关,适合稀疏图//
//首先把所有边忽略，所有顶点当作单独的连通分量
//设立一个边集合T
//每次选取权值最小的那个边，如果边的两个顶点在相同连通分量中就抛弃这个边，反之加入到T中

//sort函数重载cmp
bool cmp(node a, node b)
{
  return a.lowcost < b.lowcost;
}
//用来判断是否在同意连通分量中
int Vexset[MVNum];
//算法主体函数
void Min_kruskal(AMGraph G)
{
  sort(Edge, Edge + G.arcnum, cmp); //首先根据权值对边进行排序
  for (int i = 0; i < G.arcnum; i++)//初始化Vex数组，各个顶点当作单独的连通分量
    Vexset[i] = i;
  for (int i = 0; i < G.arcnum; i++)
  {
    int v1, v2;
    v1 = LocateVex(G, Edge[i].head);
    v2 = LocateVex(G, Edge[i].tail);
    int vs1 = Vexset[v1];   //找出v1所在的连通分量
    int vs2 = Vexset[v2]; //找出v2所在的连通分量
    if (vs1 != vs2)//如果不在同一连通分量，则加入到T中
    {
      cout << Edge[i].head << " " << Edge[i].tail << endl;//输出最小边
      for (int j = 0; j < G.arcnum; j++)//统一连通分量
        if (Vexset[j] == vs1)
          Vexset[j] = vs2;
    }
  }
}
int main()
{
AMGraph G;
CreateUDN(G);
cout<<"Prim算法所得到的最小生成树的各个边"<<endl;
Min_Prim(G,'A');
cout<<"Kruskal算法所得到的最小生成树的各个边"<<endl;
Min_kruskal(G);
    return 0;
}