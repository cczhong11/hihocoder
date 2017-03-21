#include<cstdio>
#define MAX 10020
int a[MAX],s,b,e;
int find_min(int b, int e)
{
    int min = a[b-1];
    for(int i = b-1; i < e; i++ )
    {
        if(a[i]<min) min = a[i];
    }
    return min;
}
int main()
{
    freopen("in18.txt", "r", stdin);
    int N, M;
    scanf("%d",&N);
    for(int i = 0; i< N; i++)
    {
        scanf("%d", &a[i]);
    }
    scanf("%d",&M);
    for(int i = 0; i<M; i++)
    {
        scanf("%d %d %d", &s, &b, &e);
        if(s==0) printf("%d\n", find_min(b,e));
        else{
            a[b-1] = e;
        }
    }

}