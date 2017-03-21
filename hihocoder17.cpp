#include <cstdio>
#include <iostream>
#include <vector>
#include <map>

#define MAX 100100
using namespace std;
map <string, int> name2in;
vector<int> v[MAX];
int ind[MAX],depth[MAX];
map<int, string> rmap;//new
int s1,s2,flag,temp,M,N,k1,k2, answer, min_i, min_d;
string src,dst;
vector<int> vall;
int get_map(string one)
{
    if(name2in.find(one) == name2in.end()){
        int num = name2in.size();
        name2in[one] = num+1;
        rmap[num+1] = one;
        return num+1;
    }    
    return name2in[one];
}

void dfs(int cur, int pre)
{ 
    vall.push_back(cur);
    ind[cur] = vall.size()-1;
    for(int i = 0; i < v[cur].size(); i++)
    {
        if(v[cur][i]!=pre)
        {            
            dfs(v[cur][i], cur);
            vall.push_back(cur);
            ind[cur] = vall.size()-1;
        }
    }
}
int main(){
    //freopen("in15.txt","r",stdin);  
    ios::sync_with_stdio(false);  
    cin>>N;
    for(int i=0;i<N;i++)
    {
        cin>>src>>dst;
        s1 = get_map(src);
        s2 = get_map(dst);
        v[s1].push_back(s2);
        depth[s2] = depth[s1] + 1;
        v[s2].push_back(s1);        
    }
    cin>>M;
    int sizem = name2in.size();  
    vall.push_back(1);
    ind[1] = 0;
    depth[1] = 0;
    dfs(1,0);
    for(int i=0;i<M;i++)
    {                       
        cin>>src>>dst;
        k1 = name2in[src];
        k2 = name2in[dst];
        if(k1==k2)
            answer= k1;      
        else
        {
            min_d = MAX+1;
            min_i = 0;
            for(int i = min(ind[k1],ind[k2]);i<max(ind[k1],ind[k2])+1;i++){
                if(depth[vall[i]]<min_d){
                    min_d = depth[vall[i]];
                    min_i = vall[i];
                }
            }
            answer = min_i;
        }
        cout<<rmap[answer]<<endl;
    }
      
}