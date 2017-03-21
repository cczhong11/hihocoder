#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cctype>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<list>
#include<string>
#include<cstdlib>
#include<queue>
#include<cmath>
#include<iomanip>
#include<climits>
#include<fstream>
using namespace std;
vector<int> iv[100010];
int num;
int max_step = 0;
int rt_flag = 0;
void dfs(int rt, int pre, int step){
    if(step > max_step){
        max_step = step;
        rt_flag = rt;
    }
    for(int i = 0; i < iv[rt].size(); ++i){
        if(iv[rt][i] != pre){
            dfs(iv[rt][i], rt, step + 1);
        }
    }
}
int main(){
    scanf("%d", &num);
    int rt = 1;
    for(int i = 1; i < num; ++i){
        int u, v;
        scanf("%d%d", &u, &v);
        rt = u;
        iv[u].push_back(v);
        iv[v].push_back(u);
    }
    max_step = 0;
    dfs(1, 1, 0);
    max_step = 0;
    dfs(rt_flag, rt_flag, 0);
    printf("%d\n", max_step);
    return 0;
}