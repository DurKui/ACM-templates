#include<stdio.h>
#include<string.h>
int value[5]={1,5,10,25,50};
int dp[251][101];
int main(){
	int n;
	dp[0][0]=1;
	for(int i=0;i<5;i++)
	for(int k=1;k<=100;k++)
	for(int j=value[i];j<251;j++){
		dp[j][k]+=dp[j-value[i]][k-1];
	}
	int ans[251]={0};
	for(int i=0;i<251;i++)
	for(int j=0;j<=100;j++)
	ans[i]+=dp[i][j];
	while(~scanf("%d",&n)){
	printf("%d\n",ans[n]);
}
	return 0;
} 
