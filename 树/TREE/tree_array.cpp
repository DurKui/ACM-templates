#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <stack>
#include <queue>
#include <list>
#include <map>
using namespace std;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const double Pi = acos(-1.0);
const long double eps = 1e-6;
#define mem(a, x) memset(a, x, sizeof a)
#define ll long long
//��״���飬��һ�����ö�������ʵ�ֵ�һ����������ݽṹ��Ч�����߶���һ���ߣ�����ȴ���Ŀ��£����Ӷ�ֻ��O(log2^n)
//�����˼���������һ������lowbit ��x&-x����ԭ�������ø����Ĳ����ʾ��������ԭ��ȡ����һ���������ҵ��������������һ��һ
//��lowbit(x)����һ��tree[]���飬���еļ��㶼Χ����tree����չ��//
//��m=lowbit(x)��tree[x]��ֵ����ax����ǰ�湫m������ӵĽ��
//����Ϊ������������
int n,tree[10005];
#define lowbit(x) ((x)&-(x))
void add(int x, int d){        //�޸�Ԫ��ֵ
    while(x<=n){
        tree[x]+=n;
        x+=lowbit(x);
    }
}
int sum(int x){         //���sum(x)��ô��i��j����ĺ���Ϊsum(j)-sum(i-1)
    int sum=0;
    while(x>0){
        sum+=tree[x];
        x-=lowbit(x);
    }
    return sum;
}