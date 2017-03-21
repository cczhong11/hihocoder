#include<cstdio>
#define MAX 100220
int a[MAX],s,b,e;
int find_sum(int b, int e)
{
    int sum = a[b-1];
    for(int i = b; i < e; i++ )
    {
        sum += a[i];
    }
    return sum;
}
int main()
{
    freopen("in20.txt", "r", stdin);
    int N, M;
    scanf("%d",&N);
    for(int i = 0; i< N; i++)
    {
        scanf("%d", &a[i]);
    }
    scanf("%d",&M);
    for(int i = 0; i<M; i++)
    {
       
        scanf("%d", &s);
        if(s==0) {scanf("%d %d", &b, &e);printf("%d\n", find_sum(b,e));}
        else{            
            scanf("%d %d %d",&s,&b,&e);
            for(int i = s;i<b+1;i++) a[i-1] = e;
        }
    }

}