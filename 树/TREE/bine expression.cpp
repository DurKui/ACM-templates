#include <bits/stdc++.h>
#include <cstring>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAXSIZE 10000
typedef int Status;
using namespace std;
//二叉树的二叉链表
typedef struct BiTNode
{
    BiTNode *lchild, *rchild;
    char data;
} BiTNode, *BiTree;
//运算符栈
typedef struct StackNode
{
    StackNode *top;
    char data;
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
    Status Push(char e) //入栈
    {
        StackNode *p;
        p = new StackNode;
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
        StackNode *p = top->next;
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
} StackNode;
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
//判断ch是否为运算符
bool In(char ch)
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
double Getvalue(double first, char theta, double second)
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
double lvalue=0,rvalue=0;
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
    StackNode OPTR;
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
        if (!In(ch))
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
    double ans=EvaluateExpTree(EXPT.GetTop());
    cout<<ans<<endl;
}
}
int main()
{
    InitExpTree();
    return 0;
}