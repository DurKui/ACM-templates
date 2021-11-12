#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
int num[110];
int f[110];
int n;
int judge(int p){
	int i;
	for(i=2;i<=sqrt(p);i++){
	if(p%i==0) break;
	 }
	 if(i<=sqrt(p)) return 0;
	 else return 1;
}
void dfs(int x){
 	int i;
 	if(x==n+1&&judge(num[x-1]+1)){
 		printf("1");
		 for(i=2;i<=n;i++)
		 printf(" %d",num[i]); 
		 printf("\n");
	 }
	 if(x==n+1) return ;
	 for(i=2;i<=n;i++){
	 	if(!f[i]&&judge(num[x-1]+i)){
	 		num[x]=i;
	 		f[i]=1;
	 		dfs(x+1);
	 		f[i]=0;
		 }
	 }
 }
int main(){
	int k=1;
	while(~scanf("%d",&n)){
		memset(f,0,sizeof(f));
		num[1]=1;
		f[1]=1;
		printf("Case %d:\n",k++);
		dfs(2);
		printf("\n");
	}
	
	
	return 0;
}
