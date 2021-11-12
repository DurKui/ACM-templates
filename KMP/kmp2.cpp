#include <bits/stdc++.h>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAXSIZE 10000
typedef int Status;
using namespace std;
typedef struct
{
  char ch[2 * MAXSIZE + 1];
  int length;
} Sstring;
int nextvalue[1005];
//KMP
int Index_KMP(Sstring S, Sstring T, int pos)
{
  int i = pos;
  int j = 1;
  while (i <= S.length && j <= T.length)
  {
    if (j == 0 || S.ch[i] == T.ch[j])//���j==0����S.ch[i] == T.ch[j]��i��j������
    {
      i++;
      j++;
    }
    else
      j = nextvalue[j]; //�ƶ�j������i������
  }
  if (j > T.length)
    return i - T.length;  ////����ģʽ����һ���ַ���������λ��
  else
    return 0;   //��ƥ�䷵��0
}
void get_nextvalue(Sstring T, int nextvalue[])//��ȡnext��������ֵ
{
  nextvalue[1] = 0;
  int k = 0;
  int j = 1;
  while (j <= T.length)
  {
    if (k == 0 || T.ch[k] == T.ch[j])
    {
      k++;
      j++;
      if (T.ch[k] != T.ch[j])     
        nextvalue[j] = k;
      else
      {
        nextvalue[j] = nextvalue[k];//����ƶ�����ַ���ԭ��һ����ֱ������
      }
    }
    else
      k = nextvalue[k];
  }
}
int main()
{  int a=1;
while(a){
Sstring S;
Sstring T;
char tt[2 * MAXSIZE + 1];
  int f,i,j;
  int flag=0;             //��ʶ�Ƿ�ƥ��
  scanf("%s",tt + 1);     //���벡��DNA
  scanf("%s",S.ch + 1);   //���뻼��DNA
  if(strcmp(S.ch + 1,"0")==0&&strcmp(tt + 1,"0")==0) break;
  S.length = strlen(S.ch + 1);
  int len = strlen(tt + 1);
  T.length = len;
  for ( i = len + 1, j = 1; j <= len; j++)
  {
    tt[i++] = tt[j];                      //����DNA��������
  }
  tt[i]='\0';//��ӽ����ַ�
  for (i = 1; i <= len; i++)          //����ȡ�ó���Ϊlen�Ļ�״����DNA
  {
    int k = 1;
    for (j = i; j < i + len; j++)
    {
      T.ch[k++] = tt[j];
    }
      f = Index_KMP(S, T,1);
      if (f != 0)         //f��Ϊ0���ڻ������ҵ��˲���
      {
        flag = 1;
        break;
      }
  }
  if (flag)                   //�������Ⱦ���YES����֮���NO
    printf("YES\n");
  else
    printf("NO\n");
}
return 0;
}
