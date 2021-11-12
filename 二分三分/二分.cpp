#include<stdio.h>
long long s,n;
bool judge(long long num){
	long long  b=0,x=num;
	while(x>0){
	b+=x%10;
	x/=10;
	}
	if(num-b>=s) return true;
	return false;
}
int main(){
	long long mid,l,r;
	scanf("%lld %lld",&n,&s);
	l=s;r=n;
	while(l<=r){
		mid=l+(r-l)/2;
		if(judge(mid))
		r=mid-1;
	   else l=mid+1; 
	}
	long long ans=n-l+1;
	if(ans<0) ans=0;
	printf("%lld\n",ans);
	return 0;
} 
