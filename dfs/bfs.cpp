#include<stdio.h>
#include<algorithm>
#include<queue>
#include<string.h>
using namespace std;
char s[30][30][30];
int l,m,n,dx,dy,dz,ans;
int flag[30][30][30];
int dir[6][3]={{0,0,1},{0,0,-1},{0,1,0},{0,-1,0},{1,0,0},{-1,0,0}};
struct node{
	int x,y,z,step;
};
bool check(int x,int y,int z){
	if(x<0||y<0||z<0||x>=l||y>=m||z>=n||s[x][y][z]=='#'||flag[x][y][z]==1)
	return  true;
	return false;
}
int bfs(){
struct node start,next;
queue<node>q;
start.x=dx;
start.y=dy;
start.z=dz;
start.step=0;
flag[start.x][start.y][start.z]=1;
q.push(start);
while(!q.empty()){
	start=q.front();
	q.pop();
	if(s[start.x][start.y][start.z]=='E')
	return start.step;
	for(int i=0;i<6;i++){
		next=start;
		next.x=start.x+dir[i][0];
		next.y=start.y+dir[i][1];
		next.z=start.z+dir[i][2];
		if(check(next.x,next.y,next.z))
		continue;
	flag[next.x][next.y][next.z]=1;
		next.step=start.step+1;
		q.push(next);
}	
}
return 0;
}
int main(){
	while(~scanf("%d%d%d",&l,&m,&n)){
		if(l==0&&m==0&&n==0)
		return 0;
		int i,j,k;
		getchar();
		ans=0;
		memset(flag,0,sizeof(flag));
		for(i=0;i<l;i++){
			for(j=0;j<m;j++){
				for(k=0;k<n;k++){
					s[i][j][k]=getchar();
					if(s[i][j][k]=='S'){
						dx=i;
						dy=j;
						dz=k;
			}
		}
		getchar();
	}
	getchar();
}		ans=bfs();
		if(ans)
		printf("Escaped in %d minute(s).\n",ans);
		else printf("Trapped!\n");
	}

	return 0;
} 
