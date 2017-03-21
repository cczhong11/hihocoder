#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <memory.h>
#define MAX 100100
using namespace std;
map <string, int> name2in;
vector<int> v[MAX];
map<int, string> rmap;//new
vector< pair<int, int> > q[MAX];
int color[MAX], father[MAX], answer[MAX];
int s1,s2,flag,temp,M,N,k1,k2;
string src,dst;

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
    for(int i = 0; i < q[cur].size(); ++i){
        int &s2 = q[cur][i].first;
        int &num = q[cur][i].second;
        if(color[s2] == 1){
            answer[num] = s2;
        }
        else if(color[s2] == 2){
            int t = father[s2];
            while(color[t]!=1)
            {s2 = father[s2];
            t = father[s2];
            }
                answer[num] = father[s2];            
        }
    }
  /*  if(cur==s1){//must be first visited
        if(color[s2]!=0){
            if(color[s2]==1)
            {
                flag = 1;
                answer = s2; 
                return;
            }
            if(color[s2]==2){
                flag = 1;
                while(color[father[s2]]!=1){s2 = father[s2];}
                answer = father[s2];
                return;
            }
        }
        else{temp = s2;s2=s1;s1=temp;}        
    }*/
    for(int i = 0; i < v[cur].size(); i++)
    {
        if(v[cur][i]!=pre)
        {
            color[v[cur][i]]++;
            dfs(v[cur][i], cur);
                     
            father[v[cur][i]] = cur;
            color[v[cur][i]]++;
        }
    }
}
int main(){
    freopen("in15.txt","r",stdin);  
    ios::sync_with_stdio(false);  
    cin>>N;
    for(int i=0;i<N;i++)
    {
        cin>>src>>dst;
        s1 = get_map(src);
        s2 = get_map(dst);
        v[s1].push_back(s2);
        v[s2].push_back(s1);        
    }
    cin>>M;
    int sizem = name2in.size();  

    flag= 0;
    
    for(int i=0;i<M;i++)
    {
                       
        cin>>src>>dst;
        k1 = name2in[src];
        k2 = name2in[dst];
        if(k1==k2)
            answer[i] = k1;
        q[k1].push_back(make_pair(k2, i));
        q[k2].push_back(make_pair(k1, i));      
    }
    color[1]=1;
    dfs(1,0);
    for(int i = 0;i<M;i++)
    {
        cout<<rmap[answer[i]]<<endl;
    }
}