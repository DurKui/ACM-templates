#include <iostream>
#include <stdio.h>
#include <queue>
#include <bits/stdc++.h>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAXSIZE 10000
#define MaxInt 32767
#define MVNum 100
typedef int Status;
typedef int ELemtype;
using namespace std;
typedef int ArcType;
typedef char VerTexType;
//无向图邻接矩阵存储
typedef struct
{
    VerTexType vexs[MVNum];
    ArcType arcs[MVNum][MVNum];
    int vexnum, arcnum;
} AMGraph;
int LocateVex(AMGraph g, VerTexType s)//确定顶点在图中的位置
{
    for (int i = 0; i < g.vexnum; i++)
    {
        if (g.vexs[i] == s)
            return i;
    }
    return -1;
}
//构建无向图邻接矩阵
Status CreateUDN(AMGraph &G)
{    cout<<"请输入顶点数与边数"<<endl;
    cin >> G.vexnum >> G.arcnum;
    getchar();
    cout<<"输入各个点的顶点名称"<<endl;
    for (int i = 0; i < G.vexnum; i++)//输入顶点信息
        cin >> G.vexs[i];
    for (int i = 0; i < G.vexnum; i++)
    {
        for (int j = 0; j < G.vexnum; j++)//邻接矩阵初始化
        {
            G.arcs[i][j] = MaxInt;
        }
    }
    if(G.arcnum!=0) cout<<"输入各条边依附的两个顶点"<<endl;
    for (int i = 0; i < G.arcnum; i++)//输入一条边依附的两个顶点
    {
        char v1, v2;
        //int w;
        cin >> v1 >> v2;
        int j, k;
        j = LocateVex(G, v1);
        k = LocateVex(G, v2);
        G.arcs[j][k] = 1;
        G.arcs[k][j] = G.arcs[j][k];
    }
    return OK;
}

//邻接表存储无向图
typedef struct ArcNode      //边结点
{
    int adjvex;             //该边所指向的顶点的位置
    struct ArcNode *nextarc;
    //int w;                    //其他信息
} ArcNode;
typedef struct VNode    //顶点节点
{
    VerTexType data;
    ArcNode *fistarc;
} VNode, AdjList[MVNum];
typedef struct  //邻接表
{
    AdjList vertices;
    int vexnum, arcnum;
} AlGraph;
int LocateVex(AlGraph G, char x)    //确定顶点在图中的位置
{
    for (int i = 0; i < G.vexnum; i++)
        if (x == G.vertices[i].data)
            return i;
    return -1;
}
//构建无向图邻接表
Status CreateUDG(AlGraph &G)
{   cout<<"请输入顶点数与边数"<<endl;
    cin >> G.vexnum >> G.arcnum;
    cout<<"输入各个点的顶点名称"<<endl;
    for (int i = 0; i < G.vexnum; i++) //输入各点，构造表头结点表
    {
        cin >> G.vertices[i].data;
        G.vertices[i].fistarc = NULL;
    }
    if(G.arcnum!=0) cout<<"输入各条边依附的两个顶点"<<endl;
    for (int i = 0; i < G.arcnum; i++)
    {
        char v1, v2;
        int w, j, k;
        cin >> v1 >> v2;        //输入一条边依附的两个顶点
        j = LocateVex(G, v1);
        k = LocateVex(G, v2);
        ArcNode *p1, *p2;       //前插法将相邻顶点加入到相应头节点
        p1 = new ArcNode;
        p1->adjvex = k;
        //  p1->w=w;
        p1->nextarc = G.vertices[j].fistarc;
        G.vertices[j].fistarc = p1;
        p2 = new ArcNode;
        p2->adjvex = j;
        // p2->w=w;
        p2->nextarc = G.vertices[k].fistarc;
        G.vertices[k].fistarc = p2;
    }
    return OK;
}
//基于邻接矩阵的一系列操作
Status InsertVex(AMGraph &G,VerTexType v)
{
    if(G.vexnum+1>MVNum) {cout<<"顶点增加失败，顶点数已到极限"<<endl;return ERROR;}
    for(int i=0;i<G.vexnum;i++)
    if(G.vexs[i]==v) {cout<<"顶点已存在"<<endl;return ERROR;}
    G.vexs[G.vexnum++]=v;
    cout<<"顶点增加成功"<<endl;
    return OK;
}
Status DeleteVex(AMGraph &G,VerTexType v)
{
    int w=LocateVex(G,v);
    if(w<0) {cout<<"没有要删除的顶点"<<endl;return ERROR;}
    char t;
        t=G.vexs[w];
        G.vexs[w]=G.vexs[G.vexnum-1];//将待删除顶点交换到最后一个顶点的位置，然后直接删除
        G.vexs[G.vexnum-1]=t;
        int s;
        for(int i=0;i<G.vexnum;i++){
        s=G.arcs[i][w];
        G.arcs[i][w]=G.arcs[i][G.vexnum-1];
        G.arcs[i][G.vexnum-1]=s;
        G.arcs[w][i]=G.arcs[i][w];
        }
        G.arcs[w][w]=MaxInt;
        G.vexnum--;
        cout<<"已删除顶点"<<v<<"及其相关的边"<<endl;
        return OK;
}
Status InsertArc(AMGraph &G,VerTexType v1,VerTexType v2)
{
    int v=LocateVex(G,v1);
    int w=LocateVex(G,v2);
    if(v==w||v<0||w<0) {cout<<"输入错误，边添加失败"<<endl;return ERROR;}
    if(G.arcs[v][w]==MaxInt){
    G.arcs[v][w]=1;
    G.arcnum++;
}
cout<<v1<<"-"<<v2<<"边添加成功"<<endl;
return OK;
}
Status DeleteArc(AMGraph &G,VerTexType v1, VerTexType v2)
{
     int v=LocateVex(G,v1);
    int w=LocateVex(G,v2);
    if(v<0||w<0) {cout<<"边删除失败,没有这条边"<<endl;;return ERROR;}
    G.arcs[v][w]=MaxInt;
    G.arcs[w][v]=MaxInt;
    cout<<"边删除成功"<<endl;
    return OK;
}


//基于邻接表的一系列操作
Status InsertVex(AlGraph &G,VerTexType v)
{
    int w=LocateVex(G,v);
    if(G.vexnum+1>MVNum)  {cout<<"顶点增加失败，顶点数已到极限"<<endl;return ERROR;}
    for(int i=0;i<G.vexnum;i++)
    {
        if(G.vertices[i].data==v) {cout<<"顶点已存在"<<endl;break;return ERROR;}
    }
    G.vexnum++;
    G.vertices[G.vexnum-1].data=v;
    G.vertices[G.vexnum-1].fistarc=NULL;
     cout<<"顶点增加成功"<<endl;
    return OK;
}
Status DeleteVex(AlGraph &G,VerTexType v)
{   int w=LocateVex(G,v);
    if(w<0) {cout<<"没有要删除的顶点"<<endl;return ERROR;}
    for(int i=0;i<G.vexnum;i++)
    {   ArcNode* vv;
        if(G.vertices[i].data==v)
        {ArcNode* vv=G.vertices[i].fistarc;
        while(vv)
        {   ArcNode*x=vv;
            vv=vv->nextarc;
            delete x;
        }   
        }
        else{ vv=G.vertices[i].fistarc;
        if(vv){
        if(vv->adjvex==w) {delete vv;G.vertices[i].fistarc=NULL;}
        else{
            ArcNode* pre=vv;
            vv=vv->nextarc;
        while(vv){
            if(vv->adjvex==w) 
            {pre->nextarc=vv->nextarc;
            delete vv;
            break;
            }
            pre=vv;vv=vv->nextarc;
        }
        }
        }
        }
    }
    G.vexnum--;
    cout<<"已删除顶点"<<v<<"及其相关的边"<<endl;
    return OK;
}
Status InsertArc(AlGraph &G,VerTexType v1, VerTexType v2)
{
    int v=LocateVex(G,v1);
    int w=LocateVex(G,v2);
     if(v<0||w<0||v==w) {cout<<"输入错误，边添加失败"<<endl;return ERROR;}
    ArcNode *n=new ArcNode;
    n->adjvex=v;
    n->nextarc=G.vertices[w].fistarc;
    G.vertices[w].fistarc=n;
    ArcNode *t=new ArcNode;
    t->adjvex=w;
    t->nextarc=G.vertices[v].fistarc;
    G.vertices[v].fistarc=t;
    cout<<v1<<"-"<<v2<<"边添加成功"<<endl;
    return OK;
}
Status DeleteArc(AlGraph &G,VerTexType v1,VerTexType v2)
{
   int v=LocateVex(G,v1);
   int w=LocateVex(G,v2);
   if(v<0||w<0||v==w) {cout<<"边删除失败，没有这条边"<<endl;return ERROR;}
   ArcNode *n=G.vertices[v].fistarc;
   if(n){
   if(n->adjvex==w)
   { delete n;
    G.vertices[v].fistarc=NULL;
   }
   else {
       ArcNode *p=n;
       n=n->nextarc;
    while(n)
   {
       if(n->adjvex==w){
           p->nextarc=n->nextarc;
           delete n;
           break;
       }
           p=n;
           n=n->nextarc;
   }
   }
   }
    n=G.vertices[w].fistarc;
if(n){
   if(n->adjvex==v)
   { delete n;
    G.vertices[w].fistarc=NULL;
   }
   else {
       ArcNode *p=n;
       n=n->nextarc;
    while(n)
   {
       if(n->adjvex==v){
           p->nextarc=n->nextarc;
           delete n;
           break;
       }
       else {
           p=n;
           n=n->nextarc;
       }
   }
   }
}
   G.arcnum--;
    cout<<"边删除成功"<<endl;
    return OK;
}
int main()
{
AMGraph G;
CreateUDN(G);
cout<<"基于邻接矩阵的一系列操作"<<endl;
cout<<"请输入要插入的顶点名称"<<endl;
char s;
cin>>s;InsertVex(G,s);
cout<<"请输入要插入的边"<<endl;
char v1,v2;
cin>>v1>>v2;
InsertArc(G,v1,v2);
cout<<"请输入要删除的顶点"<<endl;
cin>>s;
DeleteVex(G,s);
cout<<"请输入要删除的边"<<endl;
cin>>v1>>v2;DeleteArc(G,v1,v2);
cout<<"基于邻接表的一系列操作"<<endl;
AlGraph T;
CreateUDG(T);
cout<<"请输入要插入的顶点名称"<<endl;
cin>>s;InsertVex(T,s);
cout<<"请输入要插入的边"<<endl;
cin>>v1>>v2;
InsertArc(T,v1,v2);
cout<<"请输入要删除的顶点"<<endl;
cin>>s;
DeleteVex(T,s);
cout<<"请输入要删除的边"<<endl;
cin>>v1>>v2;DeleteArc(T,v1,v2);
    return 0;
}