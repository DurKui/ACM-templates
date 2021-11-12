#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
long long n,k;
const int N=1000000;
int flag[N+10];
struct node{
	long long x,time;
};
bool check(long long x){
	if(x<0||x>=N||flag[x])
	return false;
	return true; 
}
int bfs( ){
	struct node start,next;
	queue<node> q;
	start.x=n;
	start.time=0;
	flag[start.x]=1;
	q.push(start); 
	while(!q.empty()){
		start=q.front();
		q.pop();
		if(start.x==k) 
		return start.time;
		next=start;
		next.x=start.x+1;
		if(check(next.x)){
			next.time=start.time+1;
			flag[next.x]=1;
			q.push(next);
		}
		next.x=start.x-1;
		if(check(next.x)){
			next.time=start.time+1;
			flag[next.x]=1;
			q.push(next);
		}
		next.x=start.x*2;
		if(check(next.x)){
			next.time=start.time+1;
			flag[next.x]=1;
			q.push(next);
		}
	}
	return -1;
}
int main(){
	scanf("%lld %lld",&n,&k);
	memset(flag,0,sizeof(flag));
	long long t;
	t=bfs();
	printf("%lld\n",t);
	return 0;
} 
