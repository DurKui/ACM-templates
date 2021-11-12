#include <bits/stdc++.h>
#include <cstring>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAXSIZE 10000
#define ll long long
using namespace std;
//SplayҲ��һ�ֽ�Ϊ�򵥵Ķ���ƽ��������
//��ά��������̬��Ҫ����ת�����ң�����Ԫ�أ�ɾ��Ԫ�ض�Ҫ������ת����Ҫ���ҡ������Ԫ����ת�����ڵ�
//��������Ҫ�ص��ǿ��Խ�����ƽ������ͬʱ���κ�һ���ڵ���ת�����ڵ�
//������ת��Ҫϸ�ֳ����֣�1.x�ĸ��ڵ��Ǹ��ڵ㣺ֱ����תxһ�� 2.x�ĸ��ڵ���x�ĸ��ڵ�ĸ��ڵ���ͬһ��ֱ���ϣ�����תһ
//��x�ĸ��ڵ㣬����תһ��x 3.x�ĸ��ڵ���x�ĸ��ڵ�ĸ��ڵ㲻��ͬһ��ֱ���ϣ���ת����x
typedef struct node
{
    int key;
    node *ch[2];
    node *ff = NULL;
    int cnt;
    int size;
} node;
node *root = NULL;
void update(node *p)
{
    p->size = p->ch[0]->size + p->ch[1]->size + p->cnt;
}
void rorate(node *&x)
{
    node *y = x->ff;
    node *z = y->ff;
    int k = y->ch[1] == x;
    z->ch[z->ch[1] == y] = x;
    x->ff = z;
    y->ch[k] = x->ch[k ^ 1];
    x->ch[k ^ 1]->ff = y;
    x->ch[k ^ 1] = y;
    y->ff = x;
    update(x);
    update(y);
}
void Splay(node *x, node *o)
{
    while (x->ff != o)
    {
        node *y = x->ff;
        node *z = y->ff;
        if (z != o)
        {
            (z->ch[0] == y) ^ (y->ch[0] == x) ? rorate(x) : rorate(y);
        }
        rorate(x);
    }
    if (o == NULL)
        root = x;
}
void find(int x)
{
    node *p = root;
    if (p == NULL)
        return;
    while (p->ch[p->key < x] != NULL && p->key != x)
        p = p->ch[p->key < x];
    Splay(p, NULL);
}
void Insert(int x)
{
    node *fa = NULL;
    node *u = root;
    node *o = NULL;
    while (u != NULL && x != u->key)
    {
        fa = u;
        u = u->ch[u->key < x];
    }
    if (u != NULL)
    {
        u->cnt++;
    }
    else
    {
        o = new node;
        if (fa = NULL)
            root = o;
        else
            fa->ch[x > fa->key] = o;
        o->ff = fa;
        o->cnt = 1;
        o->key = x;
        o->size = 1;
        u = o;
    }
    Splay(u, NULL);
}
node *pre(int x)
{
    find(x);
    node *u = root->ch[0];
    if (u == NULL)
        return 0;
    else
        while (u->ch[1] != NULL)
            u = u->ch[1];
    return u;
}
node *post(int x)
{
    find(x);
    node *u = root->ch[1];
    if (u == NULL)
        return 0;
    else
        while (u->ch[0] != NULL)
            u = u->ch[0];
    return u;
}
void delet(int x)
{
    node *y = pre(x);
    node *z = post(x);
    Splay(y, NULL);
    Splay(z, root);
    node *u = root->ch[1]->ch[0];
    if (u->cnt > 1)
    {
        u->cnt--;
        Splay(u, NULL);
    }
    else
    {
        delete u;
        root->ch[1]->ch[0] = NULL;
    }
}

node *findk(int x)
{
    node *u = root;
    if (u->size < x)
        return NULL;
    while (1)
    {
        if (x <= u->ch[0]->size)
            u = u->ch[0];
        else if (x > u->ch[0]->size&& x <= u->ch[0]->size + u->cnt)
            return u;
        else
            u = u->ch[1], x -= u->ch[0]->size + u->cnt;
    }
}