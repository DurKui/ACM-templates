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
//*****队列******//
typedef struct QNode
{
    ELemtype data;
    QNode *next;
} QNode, *QueuePtr;
typedef struct
{
    QueuePtr rear;
    QueuePtr front;
    int IsEmpty(){//判断队列是否为空
        if(rear==front) return 1;
        else return 0;
    }
    Status InitQueue()//初始化
    {
        front = rear = new QNode;//头节点
        front->next = NULL;
        return OK;
    }
    Status EnQueue(ELemtype e)//入队
    {
        QueuePtr p;
        p = new QNode;
        p->data = e;
        p->next = NULL;
        rear->next = p;
        rear = p;
        return OK;
    }
    Status DeQueue(ELemtype &e)//成功
    {
        if (rear == front){
            return ERROR;
        }
        QueuePtr p = front->next;
        e = p->data;
        front->next = p->next;
        if (rear == p)
            rear = front;
        delete p;
        return OK;
    }
}LinkQueue;//链队

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

bool visit[MVNum];
void DFS_AM(AMGraph G, int v)//邻接矩阵基础上的DFS
{
    cout <<G.vexs[v]<<" ";
    visit[v] = true;
    for (int w = 0; w < G.vexnum; w++)
    {
        if (G.arcs[v][w]!=MaxInt&&!visit[w])
            DFS_AM(G, w);
    }
}

void DFS_Al(AlGraph G, int v)//邻接表基础上的DFS
{
    cout <<G.vertices[v].data<<" ";
    visit[v] = true;
    ArcNode *p;
    p = G.vertices[v].fistarc;
    while (p != NULL)
    {
        int w = p->adjvex;
        if (!visit[w])
            DFS_Al(G, w);
        p = p->nextarc;
    }
}

void DFS_UNC(AlGraph G)//DFS非连通图
{
for(int i=0;i<G.vexnum;i++)
visit[i]=false;
for(int i=0;i<G.vexnum;i++)//找到没被访问的顶点，以此为起点DFS
if(!visit[i]) DFS_Al(G,i);
}
//广度优先搜索（BFS）
void BFS(AlGraph G,int v){
cout<<G.vertices[v].data<<" ";visit[v]=true;
LinkQueue Q;
Q.InitQueue();
Q.EnQueue(v);
while(!Q.IsEmpty()){
    int u;
    Q.DeQueue(u);
    for(ArcNode* w=G.vertices[u].fistarc;w!=NULL;w=w->nextarc)
    if(!visit[w->adjvex]) 
    {   
        cout<<G.vertices[w->adjvex].data<<" ";
        visit[w->adjvex]=true;
        Q.EnQueue(w->adjvex);
    }
}
}
int main(){
    AMGraph G1;
    AlGraph G2,G3;
    cout<<"//******构建邻接矩阵连通图*****//"<<endl;
    CreateUDN(G1);//邻接矩阵连通图
    cout<<"//******构建邻接表连通图*****//"<<endl;
    CreateUDG(G2);//邻接表连通图
    cout<<"//******构建邻接表非连通图*****//"<<endl;
    CreateUDG(G3);//构建非连通图
    cout<<"连通图邻接矩阵上的DFS"<<endl;
    DFS_AM(G1,0);cout<<endl;
    cout<<"连通图邻接表上的DFS"<<endl;
    memset(visit,0,sizeof(visit));
    DFS_Al(G2,0);cout<<endl;
    cout<<"连通图邻接表BFS："<<endl;
    memset(visit,0,sizeof(visit));
    BFS(G2,0);cout<<endl;
    cout<<"非连通图的DFS"<<endl;
    memset(visit,0,sizeof(visit));
    DFS_UNC(G3);cout<<endl;
    return 0;
}