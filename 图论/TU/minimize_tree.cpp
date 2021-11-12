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
//�������㷨�����������Ȩͼ��//

//******prim�㷨*****//
//prim�㷨�ֳ�����ķ�㷨�����������С������������
//�����������ͼ�����߽϶��ͼ
//ԭ���ǹ鲢���㣬����޹�//
//����һ�����ϣ�ÿ���ҳ��ڼ����ڵĶ����벻�ڼ�������ɵ�Ȩֵ��С��һ���ߣ�����һͷ�Ķ�����뵽�ü���ֱ�����ж��㶼�ڼ�����//
struct closedge
{
  VerTexType adjvex; //��С����U�еĶ���
  ArcType lowcost;   //��С���ϵ�Ȩֵ
} closedge[MVNum];
//����ͼ�ڽӾ���洢
typedef struct
{
  VerTexType vexs[MVNum];
  ArcType arcs[MVNum][MVNum];
  int vexnum, arcnum;
} AMGraph;
int LocateVex(AMGraph g, VerTexType s) //ȷ��������ͼ�е�λ��
{
  for (int i = 0; i < g.vexnum; i++)
  {
    if (g.vexs[i] == s)
      return i;
  }
  return -1;
}
//��������ͼ�ڽӾ���
struct node //�߽�㣬���бߵ��ж�����β����
{
  VerTexType head;
  VerTexType tail;
  ArcType lowcost;
} Edge[MVNum];
Status CreateUDN(AMGraph &G)
{
  cout<<"�����붥���������"<<endl;
  cin >> G.vexnum >> G.arcnum;
  cout<<"���������������"<<endl;
  for (int i = 0; i < G.vexnum; i++) //���붥����Ϣ
    cin >> G.vexs[i];
  for (int i = 0; i < G.vexnum; i++)
  {
    for (int j = 0; j < G.vexnum; j++) //�ڽӾ����ʼ��
    {
      G.arcs[i][j] = MaxInt;
    }
  }
  cout<<"��������������������������Լ�Ȩֵ"<<endl;
  for (int i = 0; i < G.arcnum; i++) //����һ������������������
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
int Min(AMGraph G, struct closedge *x)//��closedge����Сֵ
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
  int k = LocateVex(G, u);          //�ҵ�u��G�е�λ��
  for (int i = 0; i < G.vexnum; i++)
    if (i != k)
      closedge[i] = {u, G.arcs[k][i]}; //��ʼ��
  closedge[k].lowcost = 0; //��u����U
  for (int i = 1; i < G.vexnum; i++)
  {
    int m = Min(G, closedge);       //����U�ж������ڵ�Ȩֵ��С�ı�
    char u0 = closedge[m].adjvex;  //��С��U�ж���
    char v0 = G.vexs[m];           //����U�е��Ǹ�����
    cout << u0 << " " << v0 << endl;    //�����С�ߵ�ͷβ����
    for (int j = 0; j < G.vexnum; j++) //������С��
    {
       closedge[m].lowcost = 0; //��m����U
      if (G.arcs[m][j] < closedge[j].lowcost)
      {
        closedge[j].lowcost = G.arcs[m][j];
        closedge[j].adjvex = v0;
      }
    }
  }
}


//*****Kruskal*****//
//�ֳƿ�³˹�����㷨//
//��prim�㷨�෴��Kruskal�㷨�鲢�ߣ��붥�����޹�,�ʺ�ϡ��ͼ//
//���Ȱ����бߺ��ԣ����ж��㵱����������ͨ����
//����һ���߼���T
//ÿ��ѡȡȨֵ��С���Ǹ��ߣ�����ߵ�������������ͬ��ͨ�����о���������ߣ���֮���뵽T��

//sort��������cmp
bool cmp(node a, node b)
{
  return a.lowcost < b.lowcost;
}
//�����ж��Ƿ���ͬ����ͨ������
int Vexset[MVNum];
//�㷨���庯��
void Min_kruskal(AMGraph G)
{
  sort(Edge, Edge + G.arcnum, cmp); //���ȸ���Ȩֵ�Ա߽�������
  for (int i = 0; i < G.arcnum; i++)//��ʼ��Vex���飬�������㵱����������ͨ����
    Vexset[i] = i;
  for (int i = 0; i < G.arcnum; i++)
  {
    int v1, v2;
    v1 = LocateVex(G, Edge[i].head);
    v2 = LocateVex(G, Edge[i].tail);
    int vs1 = Vexset[v1];   //�ҳ�v1���ڵ���ͨ����
    int vs2 = Vexset[v2]; //�ҳ�v2���ڵ���ͨ����
    if (vs1 != vs2)//�������ͬһ��ͨ����������뵽T��
    {
      cout << Edge[i].head << " " << Edge[i].tail << endl;//�����С��
      for (int j = 0; j < G.arcnum; j++)//ͳһ��ͨ����
        if (Vexset[j] == vs1)
          Vexset[j] = vs2;
    }
  }
}
int main()
{
AMGraph G;
CreateUDN(G);
cout<<"Prim�㷨���õ�����С�������ĸ�����"<<endl;
Min_Prim(G,'A');
cout<<"Kruskal�㷨���õ�����С�������ĸ�����"<<endl;
Min_kruskal(G);
    return 0;
}