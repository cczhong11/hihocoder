#include <cstdio>
# include <algorithm>
#include <cstring>
#define MAX 200005
using namespace std; 
struct edge{
    int e;
    int next;
}Edge[MAX];
int head[MAX];
int num = 0, ans = 0;
void addEdge(int s, int e)
{
    Edge[++num].e = e;
    Edge[num].next = head[s];
    head[s] = num;  
}
int dfs(int v, int pre)
{
    int i = head[v], d, first = 0, second = 0;
    while(i){
        if(Edge[i].e!=pre)
        {
            d = dfs(Edge[i].e, v) + 1;
            if(d > first)
            {
                second=first , first=d;
            }
            else if(d>second)
            {
                second = d;
            }
        }
        i = Edge[i].next;         
    }
    ans = max(ans, first+second);
    return first;
}
int main()
{
     memset(head,0,sizeof(head));
    int n,a,b;
    freopen("in11.txt", "r", stdin);
    scanf("%d", &n);
    while(--n)
    {
        scanf("%d %d", &a , &b);
        addEdge(a,b);
        addEdge(b,a);
    }
    dfs(1,0);
    printf("%d" , ans);
}