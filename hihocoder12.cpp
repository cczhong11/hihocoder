#include <cstdio>
#include <vector>
using namespace std;
vector<int> v[120];
int f[110][100];
int N,M;

void dfs(int node,int pre)
{
    if(v[node].size()==1)
    {
        return;
    }
    for(int i = 0;i<v[node].size();i++)
    {
        if(v[node][i]!=pre)
        {dfs(v[node][i],node);
        for(int m = M;m>1;m--)
        {
            for(int m_child = 1;m_child<m;m_child++)
            {
                f[node][m] = max(f[node][m],f[node][m-m_child]+f[v[node][i]][m_child]);
            }
        }
    }}

}
int main()
{   
    freopen("in12.txt","r",stdin); 
    scanf("%d %d", &N, &M);
    for(int i = 1; i< N+1; i++)
    {
        f[i][0] = 0;
        scanf("%d",&f[i][1]);
    }
    int a,b;
    for(int i =0; i< N-1; i++)
    {        
        scanf("%d%d",&a,&b);
        v[a].push_back(b);
        v[b].push_back(a);
    }    
    dfs(1,1);
    printf("%d",f[1][M]);
}