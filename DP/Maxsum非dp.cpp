#include<stdio.h>
int main()

{   int t,i,max=-1001,start=0,end=0,temp=0,sum=0;
    int a;
    long n;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {   if(i!=1)
        printf("\n");
        scanf("%d",&n);
        max=-1001,start=0,end=0,temp=1,sum=0;
        for(int j=1;j<=n;j++)
        {   scanf("%d",&a);
            sum+=a;
            if(sum>max)
            {   max=sum;
                end=j;
                start=temp;

            }

            if(sum<0)
            {  sum=0;
               temp=j+1;
            }
        }

        printf("Case %d:\n",i);

        printf("%d %d %d\n",max,start,end);

    }

    return 0;

}
