#include<stdio.h>
#include<algorithm>
#include<queue>
#include<string.h>
using namespace std;
char s[25][25];
int m,n,dx,dy,t;
int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int flag[25][25];
struct node{
	int x,y;
};
bool check(int x,int y){
	if(x<0||y<0||x>=m||y>=n)
	return false;
	return true;
}
void bfs(){
struct node start,next;
queue<node> q;
t=1; 
start.x=dx;
start.y=dy;
q.push(start);
while(!q.empty()){
	start=q.front();
	q.pop();
	for(int i=0;i<4;i++){
		next.x=start.x+dir[i][0];
		next.y=start.y+dir[i][1];
		if(check(next.x,next.y)==true&&s[next.x][next.y]=='.'&&flag[next.x][next.y]==0) {
		flag[next.x][next.y]=1;
		t++;
		q.push(next);
	}
}
}
}

int main(){
	while(~scanf("%d%d",&n,&m)){
		getchar();
		if(m==0&&n==0)
		return 0;
		int i,j;
		for(i=0;i<m;i++)
		scanf("%s",s[i]);
		memset(flag,0,sizeof(flag));
		for(i=0;i<m;i++)
		for(j=0;j<n;j++)
		if(s[i][j]=='@'){
			dx=i;
			dy=j;
		}
		t=0;
		bfs();
		printf("%d\n",t);
	}
	return 0;
}
