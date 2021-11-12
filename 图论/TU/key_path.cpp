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
typedef struct StackNode
{
    StackNode *top;
    int data;
    StackNode *next;
    Status InitStack() //初始化
    {
        top = NULL;
        return OK;
    }
    int StackEmpty() //判断栈是否为空
    {
        if (top == NULL)
            return 1;
        else
            return 0;
    }
    Status Push(int e) //入栈
    {
        StackNode *p;
        p = new StackNode;
        p->data = e;
        p->next = top;
        top = p;
        return OK;
    }
    Status Pop(int &ch) //出栈
    {
        if (StackEmpty())
        {
            return ERROR;
        }
        StackNode *p = top->next;
        ch = top->data;
        delete top;
        top = p;
        return OK;
    }
    char GetTop() //获取栈顶元素
    {
        if (!StackEmpty())
        {
            return top->data;
        }
    }
} StackNode;

typedef struct ArcNode{
    int weight;
        int adjvex;
        struct ArcNode * nextarc;
}ArcNode;
typedef struct VNode{
VerTexType data;
ArcNode * firstarc;
}VNode;
typedef struct {
    VNode vertices[MVNum];
    int arcnum,vexnum;
}AlGraph;
int Locate(AlGraph T,char x){
    for(int i=0;i<T.vexnum;i++)
    {
        if(T.vertices[i].data==x)
        return i;
    }
}
Status CreateUDG(AlGraph &G){
  cout<<"请输入顶点数与边数"<<endl;
    cin>>G.vexnum>>G.arcnum;
    cout<<"请输入顶点名称"<<endl;
    for(int i=0;i<G.vexnum;i++)
    {
        cin>>G.vertices[i].data;
        G.vertices[i].firstarc=NULL;
    }
    cout<<"请输入有向边的起点与终点以及所带的权值"<<endl;
    for(int i=0;i<G.arcnum;i++)
    {
        char v1,v2;
        int ww;
        cin>>v1>>v2>>ww;
        int w,k;
        w=Locate(G,v1);
        k=Locate(G,v2);
        ArcNode *vv;
        vv=new ArcNode;
        vv->adjvex=k;
        vv->weight=ww;
        vv->nextarc=G.vertices[w].firstarc;
        G.vertices[w].firstarc=vv;
    }
    return OK;
}
void FindDegree(AlGraph G,int In[])
{
  for(int i=0;i<G.vexnum;i++)
  {
    int t=0;
    for(int j=0;j<G.vexnum;j++){
      if(j!=i){
      ArcNode* p=G.vertices[j].firstarc;
      while(p!=NULL)
      {
        if(p->adjvex==i) t++;
        p=p->nextarc;
      }
      }
    }
    In[i]=t;
  }
}
Status topologicalSort(AlGraph G,int topo[])
{   int Indegree[MVNum];
    FindDegree(G,Indegree);
    StackNode S;
    S.InitStack();
    for(int i=0;i<G.vexnum;i++)
    if(!Indegree[i]) S.Push(i);
    int m=0;
    while(!S.StackEmpty())
    {   int n;
        S.Pop(n);
        topo[m++]=n;
        ArcNode* p=G.vertices[n].firstarc;
        while(p)
        {
            int kk;
            kk=p->adjvex;
            Indegree[kk]--;
            if(Indegree[kk]==0) S.Push(kk);
            p=p->nextarc;
        }
    }
    if(m<G.vexnum) return ERROR;
    else return OK;
}
void key_path(AlGraph G)
{
    int topo[MVNum];
    topologicalSort(G,topo);
    int n=G.vexnum;
    int ve[n],vl[n];
    for(int i=0;i<n;i++)
    ve[i]=0;
    for(int i=0;i<n;i++)
    {
        int k=topo[i];
        ArcNode *p=G.vertices[k].firstarc;
        while(p)
        {
            int j=p->adjvex;
            if(ve[j]<ve[k]+p->weight)
            ve[j]=ve[k]+p->weight;
            p=p->nextarc;
        }
    }
    for(int i=0;i<n;i++)
    vl[i]=ve[topo[n-1]];
    for(int i=n-1;i>=0;i--)
    {
        int kk=topo[i];
        ArcNode *q=G.vertices[kk].firstarc;
        while(q)
        {   int j=q->adjvex;
            if(vl[kk]>vl[j]-q->weight)
            vl[kk]=vl[j]-q->weight;
            q=q->nextarc;
        }
    }
    //查找关键路径
    for(int i=0;i<n;i++)
    {
        ArcNode * p=G.vertices[i].firstarc;
        while(p)
        {
            int j=p->adjvex;
            int e=ve[i];    //活动的最早开始时间
            int l=vl[j]-p->weight;//活动的最迟开始时间
        if(e==l) 
        cout<<G.vertices[i].data<<" "<<G.vertices[j].data<<endl;
        p=p->nextarc;
        }//while
    }//for
}
int main(){
  AlGraph G;
  CreateUDG(G);
  cout<<"关键活动有："<<endl;
  key_path(G);
    return 0;
}
