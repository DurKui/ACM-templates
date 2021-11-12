#include <stdio.h>
#include <algorithm>
#include <string.h>
int s[50005], enemy[50005];
int n, m;
void initialset()
{
    for (int i = 1; i <= n; i++)
    {
        s[i] = i;
    }
}
int find(int x)
{
    if (s[x] != x)
        s[x] = find(s[x]);
    return s[x];
}
void uniontree(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x != y)
        s[x] = y;
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        memset(enemy, 0, sizeof(enemy));
        scanf("%d%d", &n, &m);
        initialset();
        while (m--)
        {
            char a;
            int i, j;
            getchar();
            scanf("%c%d%d", &a, &i, &j);
            if (a == 'D')
            {
                if (enemy[i])
                    uniontree(enemy[i], j);
                if (enemy[j])
                    uniontree(enemy[j], i);
                enemy[i] = j;
                enemy[j] = i;
            }
            else
            {
                if (s[i] == s[enemy[j]])
                    printf("In different gangs\n");
                else if (s[i] == s[j])
                    printf("In the same gang\n");
                else
                    printf("Not sure yet\n");
            }
        }
    }

    return 0;
}