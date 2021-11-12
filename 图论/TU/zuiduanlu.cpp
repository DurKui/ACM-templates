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
//���·����Ҫ�漰�����㷨//
//dijsktra��floyd�㷨//
//dijsktra�㷨�ֳƵϽ�˹����//
//���·������С������֮������������·�����ð������ж���
//��Ҫ�����¼�������
//���ҵ���ֱ��Ķ���//�ٴ���Щ·�����ҳ�Ȩֵ��С����һ��//�����ܵ���Ķ�������·��//�ٴ��ܵ���Ķ����·�����ҳ���С���ظ���������||�ظ�n-1��
//������������ S[]����Ӧ�����Ƿ��ѱ�ȷ��Ϊ���·����D[]ԭ�㵽��Ӧ����·�����ȣ�Path[]��Ӧ����ǰ��
//�ڽӾ���洢
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
Status CreateUDN(AMGraph &G)
{
  cin >> G.vexnum >> G.arcnum;
  for (int i = 0; i < G.vexnum; i++) //���붥����Ϣ
    cin >> G.vexs[i];
  for (int i = 0; i < G.vexnum; i++)
  {
    for (int j = 0; j < G.vexnum; j++) //�ڽӾ����ʼ��
    {
      G.arcs[i][j] = MaxInt;
    }
  }
  for (int i = 0; i < G.arcnum; i++) //����һ������������������
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
for(int i=0;i<n;i++) //��ʼ��
{
    S[i]=false;         
    D[i]=G.arcs[v0][i]; 
    if(D[i]<MaxInt)
    Path[i]=v0;     //ǰһ������Ϊv0
    else Path[i]=-1; 
}
S[v0]=true;   //����ҵ����·
D[v0]=0;
for(int i=1;i<n;i++)    //ִ��n-1�Σ���Ϊûִ��һ���ҵ�һ�����·��һ����n-1��������Ҫ�����·
{
    int minn=MaxInt,v;
    for(int w=0;w<n;w++)
    {
        if(!S[w]&&D[w]<minn)//��Сֵ�������·
        {
             v=w;minn=D[w];
        }
        S[v]=true;
    }
    for(int w=0;w<n;w++)
    {
        if(!S[w]&&(D[v]+G.arcs[v][w])<D[w])//�����ҵ���һ�����·����D[]����
        {
            D[w]=D[w]+G.arcs[v][w];
            Path[w]=v;
        }
    }
}
}
//Floyd�㷨
//��ʼ����һ��ʼ���������м�ڵ㣬��������������·��Ϊ����֮��ֱ��ĵ����̱�
//�𲽼����м��㣬�����������������·��
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
