#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX 1000010
int m[MAX][20];
int main()
{
    freopen("in16.txt","r",stdin);
    int N,M,k,src,dst;
    scanf("%d", &N);
    for(int i = 1; i < N+1; i++)
    {
        scanf("%d", &m[i][0]);
    }      
    for(int i = 1; (1<<i)<=N;i++)
    {
        for (int j = 0; j<N+1;j++)//no add
        {
            if(j+(1<<(i-1))>N)
            {m[j][i] = m[j][i-1];continue;}
            m[j][i] = min(m[j][i-1], m[j+(1<<(i-1))][i-1]);
            k = m[j][i];
        }
    }
    scanf("%d", &M);
    for(int j = 0; j < M; j++)
    {
        scanf("%d %d", &src, &dst);
        int s = dst - src;
        int I=0;
        while(s/2>=1)
        {s = s/2; I++;}                
        printf("%d\n",min(m[src][I], m[dst - (1<<I)+1][I]));
    }
    
}
