#include <cstdio>
#include <vector>
#include <map>
#include <cstring>
#include <iostream>
#include <memory.h>
using namespace std;
map <string, int> name2in;
int Node[300];
string src,dst;
int on,tw,i1, i2, result,flag, minnode2;

int get_map(string one)
{
    if(name2in.find(one) == name2in.end()){
        int num = name2in.size();
        name2in[one] = num+1;
        return num+1;
    }    
    return name2in[one];
}

int main()
{
    int N,M;
    freopen("in13.txt","r",stdin); 
    scanf("%d", &N);  
    memset(Node,0,sizeof(Node));     
    while(N--)
    {
        cin>>src>>dst;        
        on = get_map(src);
        tw = get_map(dst);
        Node[tw] = on;
    }
    scanf("%d", &M);
    vector<int> one;
    vector<int> two;
    while(M--)
    {
        map<std::string, int>::iterator it = name2in.begin();
        one.clear();
        two.clear();
        cin>>src>>dst;   
        on = get_map(src);
        tw = get_map(dst);
        one.push_back(on);        
        two.push_back(tw);
        flag = 0;
        on = Node[on];
        while(on!=0)
        {one.push_back(on);on = Node[on];}
        tw = Node[tw];
        while(tw!=0)
        {two.push_back(tw);tw = Node[tw];}
        i1 = one.size()-1;
        i2 = two.size()-1;
        //for(int i = i1;i>-1;i--){cout<<one[i];}
        //for(int i = i2;i>-1;i--){cout<<two[i];}
        
        while(one[i1]==two[i2])
        {i1--;i2--;
        if(i1<0||i2<0) break;}
        if(i1==one.size()-1&&i2==two.size()-1)
        {
            cout<<"-1"<<endl;
            continue;
        }
        
        result = one[++i1];
        
        while(it!=name2in.end())
        {
            if(it->second==result)
            {
                flag = 1;
                cout<<it->first<<endl;
                break;
            }
            it++;
        }
        if(flag==0)
        {cout<<-1<<endl;}
    }
}