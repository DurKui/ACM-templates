#include <bits/stdc++.h>
#include <cstring>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAXSIZE 10000
typedef int Status;
using namespace std;
//*****遍历二叉树*****//
//二叉链表
typedef struct BiTNode
{
    char data;
    BiTNode *lchild, *rchild;
} BiTNode, *BiTree;
//链栈
typedef struct StackNode
{
    StackNode *top;
    BiTree data;
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
    Status Push(BiTree e) //入栈
    {
        StackNode *p;
        p = new StackNode;
        p->data = e;
        p->next = top;
        top = p;
        return OK;
    }
    Status Pop(BiTree &ch) //出栈
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
} StackNode;//栈
char pre[MAXSIZE], In[MAXSIZE], post[MAXSIZE];
//根据先序与中序建树
void buildBiTree(BiTree &p, int l, int r, int &t)
{
    int k = -1;
    for (int i = l; i <= r; i++)//在中序序列中找到pre[t],如果找到则k的左边为k的左子树，右边为右子树
    {
        if (In[i] == pre[t])
        {
            k = i;
            break;
        }
    }
    if (k == -1)    //找不到pre[t]结点
        return;
    p = new BiTNode;
    p->lchild = NULL;
    p->rchild = NULL;
    p->data = In[k];
    ++t;
    if (k > l)  //如果左子树不为空
        buildBiTree(p->lchild, l, k - 1, t);
    if (k < r)  //如果右子树不为空
        buildBiTree(p->rchild, k + 1, r, t);
}
//递归实现中序遍历
void InOrderTaverse(BiTree T){
    if(T)
    {
    InOrderTaverse(T->lchild);
    cout<<T->data<<" ";
    InOrderTaverse(T->rchild);
    }
}
//非递归实现中序遍历
void  InOrderTaverse_non(BiTree T){
    StackNode s;
    s.InitStack();
    BiTree p=T;
    BiTree q=new BiTNode;
    while(p||!s.StackEmpty())
    {
        if(p) //如果p存在，则入栈，进入左子树
        {
            s.Push(p);
            p=p->lchild;
        }
        else   //p不存在，则弹出最近一次入栈的结点，输出它，并遍历其右子树
        {
            s.Pop(q);
            cout<<q->data<<" ";
            p=q->rchild;
        }
    }
}
//递归实现后序遍历
void PostOrderTraverse(BiTree T)
{
    if (T)
    {
        PostOrderTraverse(T->lchild);
        PostOrderTraverse(T->rchild);
        cout << T->data << " ";
    }
}
//递归实现先序遍历
void PreOrderTraverse(BiTree T){
    if(T){
        cout<<T->data<<" ";
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
    }
}

//*****二叉树遍历算法的应用*****//
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
//复制二叉树
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
//二叉树深度
int Depth(BiTree T){
    int l,r;
    if(T==NULL) return 0;
    else{
        l=Depth(T->lchild);
        r=Depth(T->rchild);
        return max(l,r)+1;
    }
}
//二叉树节点数
int Nodecount(BiTree T)
{
    if(T==NULL) return 0;
    else{
        return Nodecount(T->lchild)+Nodecount(T->rchild)+1;
    }
}
/*
//*****线索化二叉树*****
typedef struct BiThrNode{
    char data;
    BiThrNode *lchild,*rchild;
    int Ltag=0,Rtag=0;
}BiThrNode,*BiThrTree;
void CreateBiTree(BiThrTree &T)//利用先序序列建立二叉树
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
//以p为根节点的子树中序线索化
BiThrTree pre=NULL;
void Inthreading(BiThrTree p){
if(p)
{
    Inthreading(p->lchild); 
    if(!p->lchild){         
        p->Ltag=1;
        p->lchild=pre;      //p的左线索为pre
    }
    else p->Ltag=0;
    if(!pre->rchild){
        pre->Rtag=1;
        pre->rchild=p;  //pre的右线索为p
    }
    else pre->Rtag=0;
    pre=p;//更新pre
    Inthreading(p->rchild);
}
}
//带头结点的二叉树中序线索化
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
        Inthreading(T); //T中序线索化
        pre->rchild=Thrt;//pre为T中的最右结点，其后继为头结点
        pre->Rtag=1;
       Thrt->rchild=pre;//头结点的右线索为pre
    }
}
void InOrderTraverse_Thr(BiThrTree T)
{
    BiThrTree p=T->lchild;
    while(p!=T)
    {
        while(p->Ltag==0) p=p->lchild;//p转移到最左端
        cout<<p->data<<" ";
        while(p->Rtag==1&&p->rchild!=T)//右子树为空，则前往当前结点后继，相当于回溯
        {
            p=p->rchild;
            cout<<p->data<<" ";
        }
        p=p->rchild;//右子树不为空，往右子树走
    }
}
*/
//HuffmanCode
typedef char ** HuffmanCode;
typedef struct{
int weight ;
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
//表达式求值
//二叉树的二叉链表
typedef struct BiTNode
{
    BiTNode *lchild, *rchild;
    char data;
} BiTNode, *BiTree;
//运算符栈
typedef struct stackNode
{
    stackNode *top;
    char data;
    stackNode *next;
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
    Status Push(char e) //入栈
    {
        stackNode *p;
        p = new stackNode;
        p->data = e;
        p->next = top;
        top = p;
        return OK;
    }
    Status Pop(char &ch) //出栈
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
    char GetTop() //获取栈顶元素
    {
        if (!StackEmpty())
        {
            return top->data;
        }
    }
} stackNode;
//表达式树的栈
typedef struct SstackNode
{
    SstackNode *top;
    BiTree data;
    SstackNode *next;
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
    Status Push(BiTree e) //入栈
    {
        SstackNode *p;
        p = new SstackNode;
        p->data = e;
        p->next = top;
        top = p;
        return OK;
    }
    Status Pop(BiTree &ch) //出栈
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
    BiTree GetTop() //获取栈顶元素
    {
        if (!StackEmpty())
        {
            return top->data;
        }
    }
} SstackNode;
//判断ch是否为运算符i
bool in(char ch)
{ 
    if (!(ch >= '0' && ch <= '9'))
    {
        return true;
    }
    return false;
}
//判断运算符优先级
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
//计算两数运算结果
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
//构建表达式树
void CreateExpTree(BiTree &T, BiTree a, BiTree b, char x)
{
    T->lchild = a;
    T->rchild = b;
    T->data = x;
}
//后序遍历表达式求值
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
//表达式树的建立算法
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
  cout<<"请输入建立二叉树所需的先序序列与中序序列"<<endl;
  cin>>pre;
  cin>>In;
  int a=0;
    buildBiTree(T,0,strlen(pre)-1,a);
    cout<<"调用递归的中序遍历"<<endl;
    InOrderTaverse(T);
    cout<<endl;
    cout<<"调用非递归的中序遍历"<<endl;
    InOrderTaverse_non(T);
    cout<<endl;
    cout<<"该二叉树的先序序列为"<<endl;
    PreOrderTraverse(T);
    cout<<endl;
    cout<<"该二叉树的后序序列为"<<endl;
    PostOrderTraverse(T);
    cout<<endl;
//二叉树遍历算法的应用
//线索化二叉树
 /* BiThrTree T,Thrt;
    cout<<"请输入建树所需的先序序列"<<endl;
    CreateBiTree(T);
    InOrderInthreading(Thrt,T);
    cout<<"带头结点线索树中序遍历序列为："<<endl;
    InOrderTraverse_Thr(Thrt);
    */
//
//huffmancode
 string s;
   int v[27],vv[27];
   HuffumanTree HT;
   HuffmanCode HC;
    cin>>s;
    memset(v,0,sizeof(v));//数组初始化为0
    for(int i=0;i<s.length();i++)
    {
        v[s[i]-'a']++;      //统计频次
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
            cout<<(char)(i+'a')<<":"<<HC[k++]<<" ";//输出每个字母的huffman编码
        }
    }
    cout<<endl;
    for(int i=1;i<=kk;i++)
    {
        for(int j=0;j<HT[i].weight;j++) //输出解码后的字符串
        cout<<HC[i];
    }
    cout<<endl;
//表达式求值
    InitExpTree();
    return 0;
}
/*
① 遍历二叉树
1. 算法5.1 中序遍历的递归算法
2. 算法5.2 中序遍历的非递归算法
3. 先序遍历的递归算法
4. 后序遍历的递归算法
② 二叉树遍历算法的应用
1. 算法5.3 先序遍历的顺序建立二叉链表
2. 算法5.4 复制二叉树
3. 算法5.5 计算二叉树的深度
4. 算法5.6 统计二叉树中结点的个数
③ 线索二叉树
1. 算法5.7 以结点p为根的子树中序线索化
2. 算法5.8 带头结点的二叉树中序线索化
3. 算法5.9 遍历中序线索二叉树
④ 哈夫曼树
1. 算法5.10 构造哈夫曼树
2. 算法5.11 根据哈夫曼树求哈夫曼编码
⑤ 相关案例
1. 算法5.12 表达式树的创建
2. 算法5.13 表达式树的求值


*/