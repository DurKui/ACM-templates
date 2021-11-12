#include<stdio.h>
#include<vector>
using namespace std; 
int main(){
vector<int>table;
int n,m;
while(~scanf("%d%d",&n,&m)){
	table.clear();
	for(int i=0;i<2*n;i++) table.push_back(i);
	int pos=0;
	for(int i=0;i<n;i++){
		pos=(pos+m-1)%table.size();
		table.erase(table.begin()+pos);
	} 
	int k=0;
	for(int i=0;i<2*n;i++){
		if(!(i-1)%50&&i!=1) printf("\n");
		if(k<n&&i==table[k]){
			k++;
			printf("G");
		}
		else printf("B");
	}
	printf("\n\n");
}
return 0;
} 
