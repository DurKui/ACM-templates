#include<stdio.h>
#include<math.h>
#include<string.h>
int col[12]={0};
int n,t;
bool check(int r,int c){
	for(int i=0;i<r;i++){
		if(c==col[i]||r-i==abs(col[i]-c))
		return false;
}
	return true;
}
void dfs(int r){
	int i;
	if(r==n){
		t++;
		return ;
}
	for(int c=0;c<n;c++){
		if(check(r,c)){
			col[r]=c;
			dfs(r+1);
		}
	}
}
int main(){
	int i;
	int ans[12]={0};
	for(n=0;n<=10;n++){
		memset(col,0,sizeof(col));
		t=0;
		dfs(0);
		ans[n]=t;
	}
	while(~scanf("%d",&n)){
	if(n==0) return 0;	
	printf("%d\n",ans[n]);
}
	return 0;
} 
