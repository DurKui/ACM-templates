#include <bits/stdc++.h>
#include <cstring>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAXSIZE 10000
typedef int Status;
using namespace std;
//*****����������*****//
//��������
typedef struct BiTNode
{
    char data;
    BiTNode *lchild, *rchild;
} BiTNode, *BiTree;
//��ջ
typedef struct StackNode
{
    StackNode *top;
    BiTree data;
    StackNode *next;
    Status InitStack() //��ʼ��
    {
        top = NULL;
        return OK;
    }
    int StackEmpty() //�ж�ջ�Ƿ�Ϊ��
    {
        if (top == NULL)
            return 1;
        else
            return 0;
    }
    Status Push(BiTree e) //��ջ
    {
        StackNode *p;
        p = new StackNode;
        p->data = e;
        p->next = top;
        top = p;
        return OK;
    }
    Status Pop(BiTree &ch) //��ջ
    {
        if (StackEmpty())
        {
            return ERROR;
        }
        StackNode *p = top->next;
        ch=top->data;
        delete top;
        top = p;
        return OK;
    }
} StackNode;//ջ
char pre[MAXSIZE], In[MAXSIZE], post[MAXSIZE];
//����������������
void buildBiTree(BiTree &p, int l, int r, int &t)
{
    int k = -1;
    for (int i = l; i <= r; i++)//�������������ҵ�pre[t],����ҵ���k�����Ϊk�����������ұ�Ϊ������
    {
        if (In[i] == pre[t])
        {
            k = i;
            break;
        }
    }
    if (k == -1)    //�Ҳ���pre[t]���
        return;
    p = new BiTNode;
    p->lchild = NULL;
    p->rchild = NULL;
    p->data = In[k];
    ++t;
    if (k > l)  //�����������Ϊ��
        buildBiTree(p->lchild, l, k - 1, t);
    if (k < r)  //�����������Ϊ��
        buildBiTree(p->rchild, k + 1, r, t);
}
//�ݹ�ʵ���������
void InOrderTaverse(BiTree T){
    if(T)
    {
    InOrderTaverse(T->lchild);
    cout<<T->data<<" ";
    InOrderTaverse(T->rchild);
    }
}
//�ǵݹ�ʵ���������
void  InOrderTaverse_non(BiTree T){
    StackNode s;
    s.InitStack();
    BiTree p=T;
    BiTree q=new BiTNode;
    while(p||!s.StackEmpty())
    {
        if(p) //���p���ڣ�����ջ������������
        {
            s.Push(p);
            p=p->lchild;
        }
        else   //p�����ڣ��򵯳����һ����ջ�Ľ�㣬���������������������
        {
            s.Pop(q);
            cout<<q->data<<" ";
            p=q->rchild;
        }
    }
}
//�ݹ�ʵ�ֺ������
void PostOrderTraverse(BiTree T)
{
    if (T)
    {
        PostOrderTraverse(T->lchild);
        PostOrderTraverse(T->rchild);
        cout << T->data << " ";
    }
}
//�ݹ�ʵ���������
void PreOrderTraverse(BiTree T){
    if(T){
        cout<<T->data<<" ";
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
    }
}

//*****�����������㷨��Ӧ��*****//
void CreateBiTree(BiTree &T)
{   char ch;
    cin>>ch;
    if(ch=='#') T=NULL;
    else
    {
        T=new BiTNode;
        T->data=ch;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
}
//���ƶ�����
void Copy(BiTree T,BiTree &NewT)
{   if(T==NULL){
    NewT=NULL;
    return ;
}
    else{
        NewT=new BiTNode;
        NewT->data=T->data;
        Copy(T->lchild,NewT->lchild);
        Copy(T->rchild,NewT->rchild);
    }
}
//���������
int Depth(BiTree T){
    int l,r;
    if(T==NULL) return 0;
    else{
        l=Depth(T->lchild);
        r=Depth(T->rchild);
        return max(l,r)+1;
    }
}
//�������ڵ���
int Nodecount(BiTree T)
{
    if(T==NULL) return 0;
    else{
        return Nodecount(T->lchild)+Nodecount(T->rchild)+1;
    }
}
/*
//*****������������*****
typedef struct BiThrNode{
    char data;
    BiThrNode *lchild,*rchild;
    int Ltag=0,Rtag=0;
}BiThrNode,*BiThrTree;
void CreateBiTree(BiThrTree &T)//�����������н���������
{   char ch;
    cin>>ch;
    if(ch=='#') T=NULL;
    else
    {
        T=new BiThrNode;
        T->data=ch;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
}
//��pΪ���ڵ����������������
BiThrTree pre=NULL;
void Inthreading(BiThrTree p){
if(p)
{
    Inthreading(p->lchild); 
    if(!p->lchild){         
        p->Ltag=1;
        p->lchild=pre;      //p��������Ϊpre
    }
    else p->Ltag=0;
    if(!pre->rchild){
        pre->Rtag=1;
        pre->rchild=p;  //pre��������Ϊp
    }
    else pre->Rtag=0;
    pre=p;//����pre
    Inthreading(p->rchild);
}
}
//��ͷ���Ķ���������������
void InOrderInthreading(BiThrTree &Thrt,BiThrTree T){
    Thrt=new BiThrNode;
    Thrt->Ltag=0;
    Thrt->Rtag=1;
    Thrt->rchild=Thrt;
    if(!T){
        Thrt->lchild=Thrt;
    }
    else 
    {       
        Thrt->lchild=T;
        pre=Thrt;
        Inthreading(T); //T����������
        pre->rchild=Thrt;//preΪT�е����ҽ�㣬����Ϊͷ���
        pre->Rtag=1;
       Thrt->rchild=pre;//ͷ����������Ϊpre
    }
}
void InOrderTraverse_Thr(BiThrTree T)
{
    BiThrTree p=T->lchild;
    while(p!=T)
    {
        while(p->Ltag==0) p=p->lchild;//pת�Ƶ������
        cout<<p->data<<" ";
        while(p->Rtag==1&&p->rchild!=T)//������Ϊ�գ���ǰ����ǰ����̣��൱�ڻ���
        {
            p=p->rchild;
            cout<<p->data<<" ";
        }
        p=p->rchild;//��������Ϊ�գ�����������
    }
}
*/
//HuffmanCode
typedef char ** HuffmanCode;
typedef struct{
int weight ;
int lchild,rchild,parent;
}HTNode,*HuffumanTree;
//�ҳ�ǰn����Ȩֵ��С������
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
    if(HT[s1].weight>HT[s2].weight){//��С�ķ�������
        int t=s1;
        s1=s2;
        s2=t;
    }
}
//������������
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
//������ÿ���ַ��Ĺ���������
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
//���ʽ��ֵ
//�������Ķ�������
typedef struct BiTNode
{
    BiTNode *lchild, *rchild;
    char data;
} BiTNode, *BiTree;
//�����ջ
typedef struct stackNode
{
    stackNode *top;
    char data;
    stackNode *next;
    Status InitStack() //��ʼ��
    {
        top = NULL;
        return OK;
    }
    int StackEmpty() //�ж�ջ�Ƿ�Ϊ��
    {
        if (top == NULL)
            return 1;
        else
            return 0;
    }
    Status Push(char e) //��ջ
    {
        stackNode *p;
        p = new stackNode;
        p->data = e;
        p->next = top;
        top = p;
        return OK;
    }
    Status Pop(char &ch) //��ջ
    {
        if (StackEmpty())
        {
            return ERROR;
        }
        stackNode *p = top->next;
        ch = top->data;
        delete top;
        top = p;
        return OK;
    }
    char GetTop() //��ȡջ��Ԫ��
    {
        if (!StackEmpty())
        {
            return top->data;
        }
    }
} stackNode;
//���ʽ����ջ
typedef struct SstackNode
{
    SstackNode *top;
    BiTree data;
    SstackNode *next;
    Status InitStack() //��ʼ��
    {
        top = NULL;
        return OK;
    }
    int StackEmpty() //�ж�ջ�Ƿ�Ϊ��
    {
        if (top == NULL)
            return 1;
        else
            return 0;
    }
    Status Push(BiTree e) //��ջ
    {
        SstackNode *p;
        p = new SstackNode;
        p->data = e;
        p->next = top;
        top = p;
        return OK;
    }
    Status Pop(BiTree &ch) //��ջ
    {
        if (StackEmpty())
        {
            return ERROR;
        }
        SstackNode *p = top->next;
        ch = top->data;
        delete top;
        top = p;
        return OK;
    }
    BiTree GetTop() //��ȡջ��Ԫ��
    {
        if (!StackEmpty())
        {
            return top->data;
        }
    }
} SstackNode;
//�ж�ch�Ƿ�Ϊ�����i
bool in(char ch)
{ 
    if (!(ch >= '0' && ch <= '9'))
    {
        return true;
    }
    return false;
}
//�ж���������ȼ�
char Precede(char theta1, char theta2)
{ 
    if ((theta1 == '(' && theta2 == ')') || (theta1 == '=' && theta2 == '='))
    {
        return '=';
    }
    else if (theta1 == '(' || theta1 == '=' || theta2 == '(' || (theta1 == '+' || theta1 == '-') && (theta2 == '*' || theta2 == '/'))
    {
        return '<';
    }
    else
        return '>';
}
//��������������
double Getvalue(int first, char theta, int second)
{ 
    switch (theta)
    {
    case '+':
        return first+ second;
    case '-':
        return first-second;
    case '*':
        return first * second ;
    case '/':
        return first*1.0 / second ;
    }
    return 0;
}
//�������ʽ��
void CreateExpTree(BiTree &T, BiTree a, BiTree b, char x)
{
    T->lchild = a;
    T->rchild = b;
    T->data = x;
}
//����������ʽ��ֵ
int EvaluateExpTree(BiTree T){
int lvalue=0,rvalue=0;
if(T->lchild==NULL&&T->rchild==NULL)
    return T->data-'0';
else
    {
     lvalue=EvaluateExpTree(T->lchild);
     rvalue=EvaluateExpTree(T->rchild);
     return Getvalue(lvalue,T->data,rvalue);   
    }
}
//���ʽ���Ľ����㷨
void InitExpTree()
{ int c=1;
    while(c){
    SstackNode EXPT;
    stackNode OPTR;
    BiTree T, a, b;
    char theta, x;
    OPTR.InitStack();
    EXPT.InitStack();
    OPTR.Push('=');
    char ch;
    cin >> ch;
    if(ch=='=') break;
    while (ch != '=' || OPTR.GetTop() != '=')
    {   
        if (!in(ch))
        {   T=new BiTNode;
            CreateExpTree(T, NULL, NULL, ch);
            EXPT.Push(T);
            cin >> ch;
        }
        else
        {
            switch (Precede(OPTR.GetTop(), ch))
            {
            case '<':
                OPTR.Push(ch);
                cin >> ch;
                break;
            case '>':
                OPTR.Pop(theta);
                EXPT.Pop(a);EXPT.Pop(b);
                T=new BiTNode;
                CreateExpTree(T, b, a, theta);
                EXPT.Push(T);
                break;
            case '=':
                OPTR.Pop(x);
                cin >> ch;
                break;
            }
        }
    }
    cout<<EvaluateExpTree(EXPT.GetTop())<<endl;
}
}
int main()
{    BiTree T;
  cout<<"�����뽨�������������������������������"<<endl;
  cin>>pre;
  cin>>In;
  int a=0;
    buildBiTree(T,0,strlen(pre)-1,a);
    cout<<"���õݹ���������"<<endl;
    InOrderTaverse(T);
    cout<<endl;
    cout<<"���÷ǵݹ���������"<<endl;
    InOrderTaverse_non(T);
    cout<<endl;
    cout<<"�ö���������������Ϊ"<<endl;
    PreOrderTraverse(T);
    cout<<endl;
    cout<<"�ö������ĺ�������Ϊ"<<endl;
    PostOrderTraverse(T);
    cout<<endl;
//�����������㷨��Ӧ��
//������������
 /* BiThrTree T,Thrt;
    cout<<"�����뽨���������������"<<endl;
    CreateBiTree(T);
    InOrderInthreading(Thrt,T);
    cout<<"��ͷ��������������������Ϊ��"<<endl;
    InOrderTraverse_Thr(Thrt);
    */
//
//huffmancode
 string s;
   int v[27],vv[27];
   HuffumanTree HT;
   HuffmanCode HC;
    cin>>s;
    memset(v,0,sizeof(v));//�����ʼ��Ϊ0
    for(int i=0;i<s.length();i++)
    {
        v[s[i]-'a']++;      //ͳ��Ƶ��
    }
     int kk=0,t=1;
    for(int i=0;i<26;i++)
    {
        if(v[i]>0){
            kk++;
            vv[t++]=v[i];   
        }
    }
    HT=new HTNode[2*kk];
    for(int i=1;i<t;i++)
    HT[i].weight=vv[i];
    CreateHuffmanTree(HT,kk);
    CreateHuffmanCode(HT,HC,kk);
    int k=1;
    for(int i=0;i<26;i++)
    {
        if(v[i]>0){
            cout<<(char)(i+'a')<<":"<<HC[k++]<<" ";//���ÿ����ĸ��huffman����
        }
    }
    cout<<endl;
    for(int i=1;i<=kk;i++)
    {
        for(int j=0;j<HT[i].weight;j++) //����������ַ���
        cout<<HC[i];
    }
    cout<<endl;
//���ʽ��ֵ
    InitExpTree();
    return 0;
}
/*
�� ����������
1. �㷨5.1 ��������ĵݹ��㷨
2. �㷨5.2 ��������ķǵݹ��㷨
3. ��������ĵݹ��㷨
4. ��������ĵݹ��㷨
�� �����������㷨��Ӧ��
1. �㷨5.3 ���������˳������������
2. �㷨5.4 ���ƶ�����
3. �㷨5.5 ��������������
4. �㷨5.6 ͳ�ƶ������н��ĸ���
�� ����������
1. �㷨5.7 �Խ��pΪ������������������
2. �㷨5.8 ��ͷ���Ķ���������������
3. �㷨5.9 ������������������
�� ��������
1. �㷨5.10 �����������
2. �㷨5.11 ���ݹ������������������
�� ��ذ���
1. �㷨5.12 ���ʽ���Ĵ���
2. �㷨5.13 ���ʽ������ֵ


*/