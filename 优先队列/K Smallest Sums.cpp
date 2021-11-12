#include<bits/stdc++.h>
using namespace std;
//��·�鲢�����ȶ���ά��
//�����鲢��˼��������ȶ��е�˼��
//��k��k�еľ���ת��Ϊ2��k�У�������ǰkС��ֵ
//�������ȶ���ÿ�ν���С�Ķ���Ԫ�ص�������������һ�е�ֵ
//��sum���ڵ�һ�У���ʡ�ռ�
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
    for(int i=0;i<n;i++)q.push(Item(A[i]+B[0],0));//�ϲ���һ�ź͵ڶ��ŵ�һ��ֵ
        for(int i=0;i<n;i++){
            Item item = q.top();
            q.pop();
            C[i] = item.s;//��¼��ǰ��iС��ֵ
            int b = item.b;//��¼�±�
            if(b+1<n)q.push(Item(item.s-B[b]+B[b+1],b+1));//���£����ڶ����±����һ��
                                                            //��Ϊÿһ���ǰ��մ�С�������򣬸�����Ϊ��ȡ����һ��С��ֵ
        }                                                   //��ǰ��ֵ�϶�Ϊ��iС�����ƶ��õ���sumһ�����ڵ�ǰֵ
}
int main(){
    int n;
    while(scanf("%d",&n)==1){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)scanf("%d",&A[i][j]);
                sort(A[i],A[i]+n);
        }
        //��k��ѹ��������
        for(int i=1;i<n;i++)
            merge(A[0],A[i],A[0],n);//���Ը���A[0]����¼�������Լ�ռ䡣
        printf("%d",A[0][0]);
        for(int i=1;i<n;i++)//���ǰkС��sum
            printf(" %d",A[0][i]);
        printf("\n");
    }
return 0;
}