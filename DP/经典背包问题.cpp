#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;
struct bone{
	int val;
	int vol;
}s[1100];
int dp[1001][1001];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
	int n,v;
	dp[0][0]=0;
	scanf("%d%d",&n,&v);
	for(int i=1;i<=n;i++)
	scanf("%d",&s[i].val);
	for(int i=1;i<=n;i++)
	scanf("%d",&s[i].vol);	
	for(int i=1;i<=n;i++)
	for(int j=0;j<=v;j++){
		if(s[i].vol>j)
		dp[i][j]=dp[i-1][j];
		else{
			dp[i][j]=max(dp[i-1][j],dp[i-1][j-s[i].vol]+s[i].val);
		}	
	}	
	printf("%d\n",dp[n][v]);
		
		
	}
	return 0;
}
