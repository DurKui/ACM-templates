#include<stdio.h>
#include<stack>
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	getchar();
	stack<char>s;
	while(n--){
		while(1){
			char ch=getchar();
			if(ch==' '||ch==EOF||ch=='\n') {
			while(!s.empty()){
				printf("%c",s.top());
				s.pop();
			}
			if(ch==EOF||ch=='\n') break;
			printf(" ");
		}
			else s.push(ch);
			
		}
		printf("\n");
	}
	return 0;
}
