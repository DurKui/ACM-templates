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
//����ͼ�ڽӾ���洢
typedef struct
{
    VerTexType vexs[MVNum];
    ArcType arcs[MVNum][MVNum];
    int vexnum, arcnum;
} AMGraph;
int LocateVex(AMGraph g, VerTexType s)//ȷ��������ͼ�е�λ��
{
    for (int i = 0; i < g.vexnum; i++)
    {
        if (g.vexs[i] == s)
            return i;
    }
    return -1;
}
//��������ͼ�ڽӾ���
Status CreateUDN(AMGraph &G)
{    cout<<"�����붥���������"<<endl;
    cin >> G.vexnum >> G.arcnum;
    getchar();
    cout<<"���������Ķ�������"<<endl;
    for (int i = 0; i < G.vexnum; i++)//���붥����Ϣ
        cin >> G.vexs[i];
    for (int i = 0; i < G.vexnum; i++)
    {
        for (int j = 0; j < G.vexnum; j++)//�ڽӾ����ʼ��
        {
            G.arcs[i][j] = MaxInt;
        }
    }
    if(G.arcnum!=0) cout<<"�����������������������"<<endl;
    for (int i = 0; i < G.arcnum; i++)//����һ������������������
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

//�ڽӱ�洢����ͼ
typedef struct ArcNode      //�߽��
{
    int adjvex;             //�ñ���ָ��Ķ����λ��
    struct ArcNode *nextarc;
    //int w;                    //������Ϣ
} ArcNode;
typedef struct VNode    //����ڵ�
{
    VerTexType data;
    ArcNode *fistarc;
} VNode, AdjList[MVNum];
typedef struct  //�ڽӱ�
{
    AdjList vertices;
    int vexnum, arcnum;
} AlGraph;
int LocateVex(AlGraph G, char x)    //ȷ��������ͼ�е�λ��
{
    for (int i = 0; i < G.vexnum; i++)
        if (x == G.vertices[i].data)
            return i;
    return -1;
}
//��������ͼ�ڽӱ�
Status CreateUDG(AlGraph &G)
{   cout<<"�����붥���������"<<endl;
    cin >> G.vexnum >> G.arcnum;
    cout<<"���������Ķ�������"<<endl;
    for (int i = 0; i < G.vexnum; i++) //������㣬�����ͷ����
    {
        cin >> G.vertices[i].data;
        G.vertices[i].fistarc = NULL;
    }
    if(G.arcnum!=0) cout<<"�����������������������"<<endl;
    for (int i = 0; i < G.arcnum; i++)
    {
        char v1, v2;
        int w, j, k;
        cin >> v1 >> v2;        //����һ������������������
        j = LocateVex(G, v1);
        k = LocateVex(G, v2);
        ArcNode *p1, *p2;       //ǰ�巨�����ڶ�����뵽��Ӧͷ�ڵ�
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
//�����ڽӾ����һϵ�в���
Status InsertVex(AMGraph &G,VerTexType v)
{
    if(G.vexnum+1>MVNum) {cout<<"��������ʧ�ܣ��������ѵ�����"<<endl;return ERROR;}
    for(int i=0;i<G.vexnum;i++)
    if(G.vexs[i]==v) {cout<<"�����Ѵ���"<<endl;return ERROR;}
    G.vexs[G.vexnum++]=v;
    cout<<"�������ӳɹ�"<<endl;
    return OK;
}
Status DeleteVex(AMGraph &G,VerTexType v)
{
    int w=LocateVex(G,v);
    if(w<0) {cout<<"û��Ҫɾ���Ķ���"<<endl;return ERROR;}
    char t;
        t=G.vexs[w];
        G.vexs[w]=G.vexs[G.vexnum-1];//����ɾ�����㽻�������һ�������λ�ã�Ȼ��ֱ��ɾ��
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
        cout<<"��ɾ������"<<v<<"������صı�"<<endl;
        return OK;
}
Status InsertArc(AMGraph &G,VerTexType v1,VerTexType v2)
{
    int v=LocateVex(G,v1);
    int w=LocateVex(G,v2);
    if(v==w||v<0||w<0) {cout<<"������󣬱����ʧ��"<<endl;return ERROR;}
    if(G.arcs[v][w]==MaxInt){
    G.arcs[v][w]=1;
    G.arcnum++;
}
cout<<v1<<"-"<<v2<<"����ӳɹ�"<<endl;
return OK;
}
Status DeleteArc(AMGraph &G,VerTexType v1, VerTexType v2)
{
     int v=LocateVex(G,v1);
    int w=LocateVex(G,v2);
    if(v<0||w<0) {cout<<"��ɾ��ʧ��,û��������"<<endl;;return ERROR;}
    G.arcs[v][w]=MaxInt;
    G.arcs[w][v]=MaxInt;
    cout<<"��ɾ���ɹ�"<<endl;
    return OK;
}


//�����ڽӱ��һϵ�в���
Status InsertVex(AlGraph &G,VerTexType v)
{
    int w=LocateVex(G,v);
    if(G.vexnum+1>MVNum)  {cout<<"��������ʧ�ܣ��������ѵ�����"<<endl;return ERROR;}
    for(int i=0;i<G.vexnum;i++)
    {
        if(G.vertices[i].data==v) {cout<<"�����Ѵ���"<<endl;break;return ERROR;}
    }
    G.vexnum++;
    G.vertices[G.vexnum-1].data=v;
    G.vertices[G.vexnum-1].fistarc=NULL;
     cout<<"�������ӳɹ�"<<endl;
    return OK;
}
Status DeleteVex(AlGraph &G,VerTexType v)
{   int w=LocateVex(G,v);
    if(w<0) {cout<<"û��Ҫɾ���Ķ���"<<endl;return ERROR;}
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
    cout<<"��ɾ������"<<v<<"������صı�"<<endl;
    return OK;
}
Status InsertArc(AlGraph &G,VerTexType v1, VerTexType v2)
{
    int v=LocateVex(G,v1);
    int w=LocateVex(G,v2);
     if(v<0||w<0||v==w) {cout<<"������󣬱����ʧ��"<<endl;return ERROR;}
    ArcNode *n=new ArcNode;
    n->adjvex=v;
    n->nextarc=G.vertices[w].fistarc;
    G.vertices[w].fistarc=n;
    ArcNode *t=new ArcNode;
    t->adjvex=w;
    t->nextarc=G.vertices[v].fistarc;
    G.vertices[v].fistarc=t;
    cout<<v1<<"-"<<v2<<"����ӳɹ�"<<endl;
    return OK;
}
Status DeleteArc(AlGraph &G,VerTexType v1,VerTexType v2)
{
   int v=LocateVex(G,v1);
   int w=LocateVex(G,v2);
   if(v<0||w<0||v==w) {cout<<"��ɾ��ʧ�ܣ�û��������"<<endl;return ERROR;}
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
    cout<<"��ɾ���ɹ�"<<endl;
    return OK;
}
int main()
{
AMGraph G;
CreateUDN(G);
cout<<"�����ڽӾ����һϵ�в���"<<endl;
cout<<"������Ҫ����Ķ�������"<<endl;
char s;
cin>>s;InsertVex(G,s);
cout<<"������Ҫ����ı�"<<endl;
char v1,v2;
cin>>v1>>v2;
InsertArc(G,v1,v2);
cout<<"������Ҫɾ���Ķ���"<<endl;
cin>>s;
DeleteVex(G,s);
cout<<"������Ҫɾ���ı�"<<endl;
cin>>v1>>v2;DeleteArc(G,v1,v2);
cout<<"�����ڽӱ��һϵ�в���"<<endl;
AlGraph T;
CreateUDG(T);
cout<<"������Ҫ����Ķ�������"<<endl;
cin>>s;InsertVex(T,s);
cout<<"������Ҫ����ı�"<<endl;
cin>>v1>>v2;
InsertArc(T,v1,v2);
cout<<"������Ҫɾ���Ķ���"<<endl;
cin>>s;
DeleteVex(T,s);
cout<<"������Ҫɾ���ı�"<<endl;
cin>>v1>>v2;DeleteArc(T,v1,v2);
    return 0;
}