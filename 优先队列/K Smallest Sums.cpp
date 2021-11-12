#include<bits/stdc++.h>
using namespace std;
//多路归并，优先队列维护
//这道题归并的思想大于优先队列的思想
//将k行k列的矩阵转换为2行k列，分行求前k小的值
//利用优先队列每次将最小的队首元素弹出，并更新下一列的值
//将sum存在第一行，节省空间
const int maxn = 768;
int A[maxn][maxn];
struct Item{
    int s,b;
    Item(){}
    Item(int ss,int bb):s(ss),b(bb){}
    bool operator<(const Item & r)const{
        return s>r.s;
    }
};
void merge(int* A,int *B,int* C,int n){
    priority_queue<Item> q;
    for(int i=0;i<n;i++)q.push(Item(A[i]+B[0],0));//合并第一排和第二排第一个值
        for(int i=0;i<n;i++){
            Item item = q.top();
            q.pop();
            C[i] = item.s;//记录当前第i小的值
            int b = item.b;//记录下标
            if(b+1<n)q.push(Item(item.s-B[b]+B[b+1],b+1));//更新，将第二排下标后移一个
                                                            //因为每一行是按照从小到大排序，更新是为了取得下一个小的值
        }                                                   //当前的值肯定为第i小，后移而得到的sum一定大于当前值
}
int main(){
    int n;
    while(scanf("%d",&n)==1){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)scanf("%d",&A[i][j]);
                sort(A[i],A[i]+n);
        }
        //将k行压缩成两行
        for(int i=1;i<n;i++)
            merge(A[0],A[i],A[0],n);//可以覆盖A[0]来记录结果，节约空间。
        printf("%d",A[0][0]);
        for(int i=1;i<n;i++)//输出前k小的sum
            printf(" %d",A[0][i]);
        printf("\n");
    }
return 0;
}