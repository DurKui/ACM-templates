#include<stdio.h>
#include<string.h>
#include<math.h>
int flag[110][110];
char s[110][110];
int m,n;
int dir[8][2]{{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
void dfs(int x,int y){
	if(x<0||y<0||x>=m||y>=n)
	return ;
	if(flag[x][y]==1||s[x][y]!='@')
	return ;
	flag[x][y]=1;
	/*for(int i=-1;i<2;i++)
	for(int j=-1;j<2;j++)*/
	for(int i=0;i<8;i++)
		dfs(x+dir[i][0],y+dir[i][1]);
}
int main(){
	while(scanf("%d%d",&m,&n)!=EOF){
		if(m==0) return 0;
		getchar();
		int i,j;
		for(i=0;i<m;i++)
		scanf("%s",s[i]);
		memset(flag,0,sizeof(flag));
		int t=0;
		for(i=0;i<m;i++){
			for(j=0;j<n;j++){
				if(flag[i][j]==0&&s[i][j]=='@'){
					t++;
					dfs(i,j);
}
} 
}
	printf("%d\n",t);
}
	return 0;
}
