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
    if (j == 0 || S.ch[i] == T.ch[j])//如果j==0或者S.ch[i] == T.ch[j]则i与j往后移
    {
      i++;
      j++;
    }
    else
      j = nextvalue[j]; //移动j，保持i不回溯
  }
  if (j > T.length)
    return i - T.length;  ////返回模式串第一个字符在主串的位置
  else
    return 0;   //不匹配返回0
}
void get_nextvalue(Sstring T, int nextvalue[])//获取next数组修正值
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
        nextvalue[j] = nextvalue[k];//如果移动后的字符与原来一样，直接跳过
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
  int flag=0;             //标识是否匹配
  scanf("%s",tt + 1);     //输入病毒DNA
  scanf("%s",S.ch + 1);   //输入患者DNA
  if(strcmp(S.ch + 1,"0")==0&&strcmp(tt + 1,"0")==0) break;
  S.length = strlen(S.ch + 1);
  int len = strlen(tt + 1);
  T.length = len;
  for ( i = len + 1, j = 1; j <= len; j++)
  {
    tt[i++] = tt[j];                      //病毒DNA扩大两倍
  }
  tt[i]='\0';//添加结束字符
  for (i = 1; i <= len; i++)          //依次取得长度为len的环状病毒DNA
  {
    int k = 1;
    for (j = i; j < i + len; j++)
    {
      T.ch[k++] = tt[j];
    }
      f = Index_KMP(S, T,1);
      if (f != 0)         //f不为0则在患者中找到了病毒
      {
        flag = 1;
        break;
      }
  }
  if (flag)                   //如果被感染输出YES，反之输出NO
    printf("YES\n");
  else
    printf("NO\n");
}
return 0;
}
