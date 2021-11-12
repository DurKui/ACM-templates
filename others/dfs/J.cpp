#include<stdio.h>
#include<string.h>
int w,h,sx,sy;
char s[25][25];
int flag[25][25];
int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
void dfs(int x,int y){
	if(x<0||y<0||x>=h||y>=w)
	return ;
	if(s[x][y]=='#'||flag[x][y]==1)
	return ;
	flag[x][y]=1;
	for(int i=0;i<4;i++){
		dfs(x+dir[i][0],y+dir[i][1]);
	}
	
	
	
}
int main(){
	int i,j;
	while(~scanf("%d %d",&w,&h)){
		getchar();
		if(w==0&&h==0) return 0;
	for(i=0;i<h;i++)
	scanf("%s",s[i]);
	memset(flag,0,sizeof(flag));
	int t=0;
	for(i=0;i<h;i++)
	for(j=0;j<w;j++){
		if(s[i][j]=='@'&&flag[i][j]==0){
			sx=i;
			sy=j;
		}
	}
	dfs(sx,sy);
	for(i=0;i<h;i++)
	for(j=0;j<w;j++)
	if(flag[i][j]==1) t++;
	printf("%d\n",t);
}
	return 0;
}
