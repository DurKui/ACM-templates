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
//树状数组，是一种利用二进制来实现的一种奇妙的数据结构，效率与线段树一样高，代码却简洁的可怕，复杂度只有O(log2^n)
//其核心思想便是引进一个操作lowbit 即x&-x，其原理是利用负数的补码表示，补码是原码取反加一，功能是找到二进制数的最后一个一
//从lowbit(x)引出一个tree[]数组，所有的计算都围绕这tree数组展开//
//令m=lowbit(x)，tree[x]的值就是ax与它前面公m个数相加的结果
//核心为下列两个函数
int n,tree[10005];
#define lowbit(x) ((x)&-(x))
void add(int x, int d){        //修改元素值
    while(x<=n){
        tree[x]+=n;
        x+=lowbit(x);
    }
}
int sum(int x){         //求和sum(x)那么求i到j区间的和则为sum(j)-sum(i-1)
    int sum=0;
    while(x>0){
        sum+=tree[x];
        x-=lowbit(x);
    }
    return sum;
}