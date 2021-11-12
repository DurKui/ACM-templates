#include <bits/stdc++.h>
#include <cstring>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAXSIZE 10000
typedef int Status;
using namespace std;                                                                                                                                  
typedef char ** HuffmanCode;
typedef struct{
int weight;
int lchild,rchild,parent;
}HTNode,*HuffumanTree;
//找出前n项中权值最小的两项
void Select(HuffumanTree HT,int n,int &s1,int &s2){
    int minn=1000000000;
    for(int i=1;i<=n;i++)
    {
        if(HT[i].parent==0)
        {   
           if(minn>HT[i].weight)
           { minn=HT[i].weight;
            s1=i;
           }
        }
    }
    minn=1000000000;
     for(int i=1;i<=n;i++)
    {
        if(HT[i].parent==0&&i!=s1)
        {   
            if(minn>HT[i].weight)
            {minn=HT[i].weight;
            s2=i;
            }
        }
    }
    if(HT[s1].weight>HT[s2].weight){//把小的放在左树
        int t=s1;
        s1=s2;
        s2=t;
    }
}
//建立哈夫曼树
void CreateHuffmanTree(HuffumanTree &HT,int n){
    if(n<=1) return;
    int m=2*n-1;
    for(int i=1;i<=m;i++)
    {
        HT[i].parent=0;HT[i].lchild=0;HT[i].rchild=0;
    }
    for(int i=n+1;i<=m;i++)
    {   int s1,s2;
        Select(HT,i-1,s1,s2);
        HT[s1].parent=i;HT[s2].parent=i;
        HT[i].lchild=s1;HT[i].rchild=s2;
        HT[i].weight=HT[s1].weight+HT[s2].weight;
    }
}
//逆向求每个字符的哈夫曼编码
void CreateHuffmanCode(HuffumanTree HT,HuffmanCode &HC,int n){
HC=new char *[n+1];
char * cd=new char[n];
cd[n-1]='\0';
int start,c,f;
for(int i=1;i<=n;i++)
{ start=n-1;
c=i;f=HT[i].parent;
while(f!=0)
{
    --start;
    if(HT[f].lchild==c) cd[start]='0';
    else cd[start]='1';
    c=f;f=HT[f].parent;
}
HC[i]=new char[n-start];
strcpy(HC[i],&cd[start]);
}
}
int main(){
   string s;
   int v[27],k,vv[27];
   HuffumanTree HT;
   HuffmanCode HC;
    int t;
    while(1){//输入有多组
        cin>>s;
    if(s=="0") break;//如果输入只有‘0’，则输入结束
    memset(v,0,sizeof(v));//数组初始化为0
    memset(vv,0,sizeof(vv));
    for(int i=0;i<s.length();i++)
    {
        v[s[i]-'a']++;
    }
    k=1;t=0;
    for(int i=0;i<26;i++)
    {
        if(v[i]>0){
            t++;
            vv[k++]=v[i];
            cout<<(char)(i+'a')<<":"<<v[i]<<" ";//输出每个字母出现的频次
        }
    }
    cout<<endl;
    HT=new HTNode[2*t];
    for(int i=1;i<k;i++)
    HT[i].weight=vv[i];
    CreateHuffmanTree(HT,t);
    for(int i=1;i<=2*t-1;i++)
    cout<<i<<" "<<HT[i].weight<<" "<<HT[i].parent<<" "<<HT[i].lchild<<" "<<HT[i].rchild<<endl;
    CreateHuffmanCode(HT,HC,t);

    k=1;
    for(int i=0;i<26;i++)
    {
        if(v[i]>0){
            cout<<char(i+'a')<<":"<<HC[k++]<<" ";//输出每个字母的编码
        }
    }
    cout<<endl;
    for(int i=1;i<=t;i++)
    {
        for(int j=0;j<HT[i].weight;j++)//输出解码后的字符串
        cout<<HC[i];
    }
    cout<<endl;
    }
    return 0;
} 