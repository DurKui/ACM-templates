#include<stdio.h>
#include<string.h>
#include<math.h>
char s[110][110];
int flag[110][110];
int n,m;
int dir[8][2]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
void dfs(int x,int y){
	if(x<0||y<0||x>=m||y>=n)
	return ;
	if(flag[x][y]==1||s[x][y]!='W')
	return ;
	flag[x][y]=1;
	for(int i=0;i<8;i++){
		x=x+dir[i][1];
		y=y+dir[i][0];
		dfs(x,y);
	}
}
int main(){
	scanf("%d %d",&m,&n);
	getchar();
	memset(flag,0,sizeof(flag));
	int i,j;
	for(i=0;i<m;i++)
	scanf("%s",s[i]);
	int t=0;
	for( i=0;i<m;i++){
		for(j=0;j<n;j++){
	 		if(s[i][j]=='W'&&flag[i][j]==0){
	 		t++;
	 		dfs(i,j);
	 	}
	 }
}
	printf("%d\n",t);
	
	return 0;
}
