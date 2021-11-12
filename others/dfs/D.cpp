#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
const int N=10; 
char s[N][N];
int n,m,t,dx,dy;
int f[N][N];
bool flag;
int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};

void dfs(int x,int y,int time){
	if(flag) return ;
	if(x<0||y<0||x>=n||y>=m||time>t)
	return ;
	if(x==dx&&y==dy&&time==t)
	{
		flag=true;
		return ;
	}
	int temp=t-time-abs(dx-x)-abs(dy-y);
    if(temp&1) return ;

	for(int i=0;i<4;i++)
	{	int tx=x+dir[i][0];
		int ty=y+dir[i][1];
		if(!f[tx][ty]&&s[tx][ty]!='X'){
		f[tx][ty]=1;
		dfs(tx,ty,time+1);
		f[tx][ty]=0;
	}
	}
}
int main(){
	while(~scanf("%d%d%d",&n,&m,&t)){
		int sx,sy;
		if(m==0&&n==0&&t==0) return 0;
		getchar();
		flag=false;		
		int i,j; 
		memset(f,0,sizeof(f));
		for(i=0;i<n;i++){
		scanf("%s",s[i]);
		for(int j=0;j<m;j++){
			if(s[i][j]=='S'){
				sx=i;
				sy=j;
				f[sx][sy]=1;
			}
		    if(s[i][j]=='D'){
		    	dx=i;
		    	dy=j;
			}
		}
	}
	/*if(n*m-k-1>=t)*/ dfs(sx,sy,0);
	if(flag) printf("YES\n");
	else printf("NO\n");
}
return 0;
}
