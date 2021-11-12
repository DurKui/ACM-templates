#include <bits/stdc++.h>
#include <cstring>
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
//BF �����㷨
int Index_BF(Sstring S, Sstring T, int pos)
{
  int i = pos, j = 1;
  while (i <= S.length && j <= T.length)
  {
    if (S.ch[i] == T.ch[j])
    {
      i++;
      j++;
    }
    else
    {
      i = i - j + 2; //i����
      j = 1;          //j���1
    }
  }
  if (j > T.length)
    return i - T.length; //����ģʽ����һ���ַ���������λ��
  else
    return 0;   //�����ƥ�䷵��0
}

//KMP
int Index_KMP(Sstring S, Sstring T, int pos)
{
  int i = pos;
  int j = 1;
  while (i <= S.length && j <= T.length)
  {
  if (j == 0 || S.ch[i] == T.ch[j])//���j==0����S.ch[i] == T.ch[j]��i��j������                         
  {                                  //j==0������ǵ�һ���Ͳ�ƥ�����������Ҳ�����ȵ�һֱִ�� j = nextvalue[j]��ֱ������0��ֱ������
      i++;
      j++;
    }
    else
      j = nextvalue[j]; //�ƶ�j������i������
  }
  if (j > T.length)
    return i - T.length;  //����ģʽ����һ���ַ���������λ��
  else
    return 0;   //��ƥ�䷵��0
}
void get_nextvalue(Sstring T, int nextvalue[])//��ȡnext��������ֵ
{
  nextvalue[1] = 0;           //����һ���Ͳ�ͬ��ֱ�Ӹ�����һ����nextֵ
  int k = 0;
  int j = 1;  //�ڶ�����ͬ��Ҳû��ǰ׺��next[2]=k++=1;ʹk=1,j=2,�Ӷ����ж�3
  while (j <= T.length)
  {
    if (k == 0 || T.ch[k] == T.ch[j])//k=0�������û��ǰ׺����ͷ��ʼ
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
//�������
int main()
{  
while(1){
Sstring S;
Sstring T;
char tt[2 * MAXSIZE + 1];
  int ff, pos = 1,f,i,j;
  int flag=0;      //��ʶ�Ƿ�ƥ��
  cin >> S.ch + 1;
  cin >> tt + 1;
  if(strcmp(S.ch + 1,"0")==0&&strcmp(tt + 1,"0")==0) break;
  S.length = strlen(S.ch + 1);
  int len = strlen(tt + 1);
  T.length = len;
  cout << "ѡ��Ҫʹ�õļ���ֶ�:" << endl;
  cout << "1 BF" << endl
       << "2 KMP" << endl;
  cin >> ff;
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
    if (ff)                       //ѡ��ļ���ֶ�
    {
      f = Index_BF(S, T, pos);
      if (f != 0)           //f��Ϊ0���ڻ������ҵ��˲���
      {
        flag = 1;
        break;
      }
    }
    else
    {
      f = Index_KMP(S, T, pos);
      if (f != 0)         ////f��Ϊ0���ڻ������ҵ��˲���
      {
        flag = 1;
        break;
      }
    }
  }
  if (flag)                   //�������Ⱦ���YES����֮���NO
    cout << "YES" << endl<<endl;
  else
    cout << "NO" << endl<<endl;;
}
return 0;
}
