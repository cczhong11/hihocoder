#include <cstdio>
#include <vector>
#include <map>
#include <cstring>
#include <iostream>
using namespace std;
map <string, int> name2in;
string src,dst;
int one,two,minnode, minle, result,flag, minnode2;
struct node{
    int level;
    vector<int> next;
}Node[110];
int get_map(string one)
{
    if(name2in.find(one) == name2in.end()){
        int num = name2in.size();
        name2in[one] = num+1;
        return num+1;
    }    
    return name2in[one];
}
int dfs(int nod, int pre)
{
    if(Node[nod].level<minle)
    {
        minle = Node[nod].level;
        minnode = nod;
    }
    if(nod == two)
    {
        flag = 1;
        return minnode;
    }    
    
    for(int i = Node[nod].next.size() -1;i >-1 ;i--){//wrong here
        if(Node[nod].next[i]!=pre)//wrong here
        {result = dfs(Node[nod].next[i],nod);
        if(flag == 1)
        {return result;}}
    }
    return -1;
}
int main()
{
    int N,M;
    freopen("in13.txt","r",stdin); 
    scanf("%d", &N);
    Node[0].level = 0;    
    while(N--)
    {
        cin>>src>>dst;
        if(name2in.find(src) == name2in.end())
        {
            int a = get_map(src);
            if(name2in.find(dst) == name2in.end())
            {            
            Node[a].level = 1; }
            else{
                Node[a].level = Node[get_map(dst)].level-1;
            }
        }
        one = get_map(src);
        two = get_map(dst);
        Node[one].next.push_back(two);
        if(Node[two].next.size()==0)
        {Node[two].level = Node[one].level+1;}
        else
        {Node[one].level = Node[two].level-1;}
        Node[two].next.push_back(one);
    }
    scanf("%d", &M);
   
    while(M--)
    {
        map<std::string, int>::iterator it = name2in.begin();
        minle = 1000;
        flag = 0;
        cin>>src>>dst;
        int num = name2in.size();
        one = get_map(src);
        two = get_map(dst);
        if(one>num||two>num)
        {
            cout<<"-1"<<endl;
            continue;
        }
        if(Node[one].level<Node[two].level)
        {
            minnode2 = two;
            two = one;
        }
        else{
            minnode2 = one;
        }
        
        int answer = dfs(minnode2,0);        
        if(answer==-1)
        {
            cout<<"-1"<<endl;
            continue;
        }
        while(it!=name2in.end())
        {
            if(it->second==answer)
            {
                cout<<it->first<<endl;
                break;
            }
            it++;
        }
        
    }
}