#include<stdio.h>
#include<queue>
using namespace std;
struct node{
	int x,y;
	friend bool operator<(node a,node b){
	if(a.x==b.x&&a.y>b.y) return true;
	else if(a.x<b.x)return true;
	else return false;
}
}m,g;
priority_queue<node>a;
priority_queue<node>b;
priority_queue<node>c;
int main(){
	int n,s1,s2;
	while(~scanf("%d",&n)){
		while(!a.empty()){
			a.pop();
		}
		while(!b.empty()){
			b.pop();
		}
		while(!c.empty()){
			c.pop();
		}
		int k=1;
	while(n--){
		getchar();
		char ch[50];
		scanf("%s",ch);
		if(ch[0]=='I'){
		scanf("%d %d",&s1,&s2);
		if(s1==1){
		m.x=s2;
		m.y=k;
		a.push(m);	
		}	
		if(s1==2){
		m.x=s2;
		m.y=k;
		b.push(m);	
		}	
		if(s1==3){
		m.x=s2;
		m.y=k;
		c.push(m);	
		}
		k++;	
		}
		else{
			scanf("%d",&s1);
			if(s1==1){
				if(a.empty()) printf("EMPTY\n");
				else{
				g=a.top();
				a.pop();
				printf("%d\n",g.y);
			}
			}
			if(s1==2){
				if(b.empty()) printf("EMPTY\n");
				else{
				g=b.top();
				b.pop();
				printf("%d\n",g.y);
			}
			}
			if(s1==3){
				if(c.empty()) printf("EMPTY\n");
				else {
				g=c.top();
				c.pop();
				printf("%d\n",g.y);
}
}
}
}
printf("\n");		
}
	return 0;
}
