 j#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <stack>
#include <queue>
#include <list>
using namespace std;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const double Pi = acos(-1.0);
const long double eps = 1e-6;
#define mem(a,x) memset(a,x,sizeof a)
#define ll long long
#define lowbit(x) ((x) & - (x)) 
//#define For(i,a,b) for (int i = a; i <= b; ++i)
//#define rush() int T;scanf("%d", &T);for(int Ti=1;Ti<=T;Ti++)
//#define scd(x) scanf("%d", &x)
//#define scl(x) scanf("%lld", &x)
//#define scdd(x,y) scanf("%d %d", &x, &y)
/*char pre[1005];
char in[1005];
int maxx=-1;
//char post[1005];*/
typedef struct node{
	char value;
	node* l=NULL;
	node* r=NULL;
}node;

int post[1005];
int in[1005];
node* build(int n1,int n2,int m1,int m2){
	//if(t<=0) return NULL;
	node* head;
	head=new node;
	head->value=post[n2];
	int k=-1;
	for(int i=m1;i<=m2;i++)
	{
		if(in[i]==post[n2])
	{
		k=i;
		break;
	}
}
if(k!=m1)	head->l=build(n1,n2-m2+k-1,m1,k-1);
if(k!=m2)	head->r=build(n1-m1+k,n2-1,k+1,m2);
	return head;
}
void preto(node* head){
	if(head!=NULL){
		printf("%d ",head->value);
		preto(head->l);
		preto(head->r);
	}
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	scanf("%d",&post[i]);
	for(int i=1;i<=n;i++)
	scanf("%d",&in[i]);
	node* head;
	head=build(1,n,1,n);
//	printf("Preorder: ");
	preto(head);
	return 0;
}
