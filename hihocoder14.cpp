#include <iostream>
#include <string>
#include <memory.h>
#include <map>
#include <cstdio>
#define MAX 100100
using namespace std;
map <string, int> name2in;
int team[MAX];
string src,dst;
int on,tw,result,flag, temp;

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
    int N;
    freopen("in14.txt","r",stdin);
    memset(team,0,sizeof(team));
    cin>>N;
    while(N--){
        cin>>flag>>src>>dst;
        on = get_map(src);
        tw = get_map(dst);
        if(flag==0){
            if(team[on]==0&&team[tw]==0){
                team[on] = on;
                team[tw] = on;
                continue;
            }
            if(team[on]==0){team[on] = team[tw];}
            else if(team[tw]==0){team[tw] = team[on];}
            else{
                temp = team[tw];
                for(int i =0;i<name2in.size()+1;i++){//lll
                    if(team[i]==temp)
                     team[i]=team[on];
                }                
            }
        }
        else{
            if((team[on]==team[tw]&&team[on]!=0)||on==tw) cout<<"yes"<<endl;//both 0
            else cout<<"no"<<endl;
        }
    }
}