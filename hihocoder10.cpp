#include <cstdio>
#include <string>
#include <stack>
#include <iostream>
using namespace std;
struct Node{
    int left;
    int right;
    void init() {
		left = -1;
        right = -1;
    }
}node[26];

void buildtree(string str1,string str2)
{
    if(str1.length()<=1)
    {
        if(str1.length()==1)
        {
            node[str1[0]-'A'].init();
        }
       return;
    }
    int root = str1[0]-'A';//new root
    node[root].init();
      
    int rootI = str2.find(str1[0]);
    if(rootI == 0)
    {
        node[root].left = -1;
    }
   
    else{
    node[root].left = str1[1]-'A';       
    }
    if(rootI == str2.length()-1)
    {
        node[root].right = -1;
        buildtree(str1.substr(1,str1.length()),str2.substr(0,rootI));
    }
    else
    {
    for(int i = 1; i<str1.length(); i++)
    {
        int flg = 0;
        for(int j = rootI; j<str2.length();j++)
        {
            if(str1[i]==str2[j])
            {
                node[root].right = str1[i]-'A';   
                buildtree(str1.substr(1,i-1),str2.substr(0,rootI));
                buildtree(str1.substr(i,str1.length()-1),str2.substr(rootI+1,str2.length()));                
                flg = 1;
                break;
            }
            
        }if(flg == 1)
            {break;}
    }
    }
   
}
stack<int> mystack;
void buildstack(int root)
{
    
    if(root==-1) return;
    mystack.push(root);
    buildstack(node[root].right);
    buildstack(node[root].left);
    
}
void output(int root){
    buildstack(root);
   
    while (!mystack.empty())
  {
     printf("%c",'A'+mystack.top());
     mystack.pop();
  }
}
int main()
{
    
    freopen("in10.txt", "r", stdin);
    string str01,str02;
    cin>>str01;
    cin>>str02;
    
    buildtree(str01, str02);
    int root = str01[0]-'A';
    output(root);
}