#include <algorithm>
#include <vector>
#include <set>
#include <cstdio>
#define RM 1000000010
#define MAX 100020
#define LL long long
using namespace std;
LL index_R[MAX], index_L[MAX];
int c[2*MAX],lazy[2*MAX];
vector<LL> v;
set<int> ss;
int getid(int x)  
{  
    return lower_bound(v.begin(),v.end(),x)-v.begin()+1;  
}  
void push_up(int rt)
{
    if(c[rt<<1]!=c[rt<<1|1])
        c[rt]=-1;
}
void push_down(int rt)
{
    if(lazy[rt])
    {
        lazy[rt<<1] = lazy[rt<<1|1] = lazy[rt];
        c[rt<<1] = c[rt<<1|1] = c[rt];
        lazy[rt] = 0;
    }
}
void build(int l, int r)
{
    for(int i = l;i<r+1; i++)
    {
        c[i] = -1;
        lazy[i] = 0;
    }
}
void update(int L, int R, int c0, int l, int r, int rt)
{
    if(L<=l && r<=R)
    {
        lazy[rt] = c0;
        c[rt] = c0;
        return;
    }
    push_down(rt);
    int m = (l+r) >> 1;
    if(L<=m) update(L,R,c0,l,m,rt<<1);
    if(m< R) update(L,R,c0,m+1,r,rt<<1|1);
    push_up(rt);
}
int query(int siz)
{
    ss.clear(); 
    for(int i = 1; i < siz+1;i++)
    {
        if(c[i]!=-1)
            ss.insert(c[i]);
    }
    return ss.size();
}
int main()
{
    int N,M;  
    freopen("in21.txt", "r", stdin);
    //memset(tree,0,sizeof(tree));  
    
    v.clear();   
    scanf("%d %d",&N,&M);  
    
    for(int i=0;i<N;i++)  
    {  
        scanf("%d %d",&index_L[i],&index_R[i]);  
        v.push_back(index_L[i]);  
        v.push_back(index_R[i]);  
    }  
    sort(v.begin(),v.end());  
    v.erase(unique(v.begin(),v.end()),v.end());  
    int N2=v.size();  
    build(1,2*N2);
    for(int i=0;i<N;i++)  
    {  
        update(getid(index_L[i]),getid(index_R[i]),i+1,1,M,1);  
    }
    int result = query(2*N2);
    printf("%d\n", result);
}
