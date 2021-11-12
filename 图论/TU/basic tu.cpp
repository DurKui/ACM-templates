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
//*****����******//
typedef struct QNode
{
    ELemtype data;
    QNode *next;
} QNode, *QueuePtr;
typedef struct
{
    QueuePtr rear;
    QueuePtr front;
    int IsEmpty(){//�ж϶����Ƿ�Ϊ��
        if(rear==front) return 1;
        else return 0;
    }
    Status InitQueue()//��ʼ��
    {
        front = rear = new QNode;//ͷ�ڵ�
        front->next = NULL;
        return OK;
    }
    Status EnQueue(ELemtype e)//���
    {
        QueuePtr p;
        p = new QNode;
        p->data = e;
        p->next = NULL;
        rear->next = p;
        rear = p;
        return OK;
    }
    Status DeQueue(ELemtype &e)//�ɹ�
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
}LinkQueue;//����

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

bool visit[MVNum];
void DFS_AM(AMGraph G, int v)//�ڽӾ�������ϵ�DFS
{
    cout <<G.vexs[v]<<" ";
    visit[v] = true;
    for (int w = 0; w < G.vexnum; w++)
    {
        if (G.arcs[v][w]!=MaxInt&&!visit[w])
            DFS_AM(G, w);
    }
}

void DFS_Al(AlGraph G, int v)//�ڽӱ�����ϵ�DFS
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

void DFS_UNC(AlGraph G)//DFS����ͨͼ
{
for(int i=0;i<G.vexnum;i++)
visit[i]=false;
for(int i=0;i<G.vexnum;i++)//�ҵ�û�����ʵĶ��㣬�Դ�Ϊ���DFS
if(!visit[i]) DFS_Al(G,i);
}
//�������������BFS��
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
    cout<<"//******�����ڽӾ�����ͨͼ*****//"<<endl;
    CreateUDN(G1);//�ڽӾ�����ͨͼ
    cout<<"//******�����ڽӱ���ͨͼ*****//"<<endl;
    CreateUDG(G2);//�ڽӱ���ͨͼ
    cout<<"//******�����ڽӱ����ͨͼ*****//"<<endl;
    CreateUDG(G3);//��������ͨͼ
    cout<<"��ͨͼ�ڽӾ����ϵ�DFS"<<endl;
    DFS_AM(G1,0);cout<<endl;
    cout<<"��ͨͼ�ڽӱ��ϵ�DFS"<<endl;
    memset(visit,0,sizeof(visit));
    DFS_Al(G2,0);cout<<endl;
    cout<<"��ͨͼ�ڽӱ�BFS��"<<endl;
    memset(visit,0,sizeof(visit));
    BFS(G2,0);cout<<endl;
    cout<<"����ͨͼ��DFS"<<endl;
    memset(visit,0,sizeof(visit));
    DFS_UNC(G3);cout<<endl;
    return 0;
}