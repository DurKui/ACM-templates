#include<stdio.h>
#define MOD 1000000009
long long powerpow(long long a,long long b){
	long long ans=1;
	long long base=a;
	while(b){
		if(b&1)
		ans=(ans*base)%MOD;
		base=(base*base)%MOD;
		b/=2;
	}
	return ans;
}
int main(){
	long long n,m,k,t;
	scanf("%lld %lld %lld",&n,&m,&k);
	t=n/k;
	if(n-t>=m)
	printf("%lld",m);
	else {
		long long time=t-n+m;
		long long ans=k*(powerpow(2,time+1)-2)%MOD;
		ans+=m-time*k;
		printf("%lld",(ans+MOD)%MOD);
		} 
return 0;	
}
