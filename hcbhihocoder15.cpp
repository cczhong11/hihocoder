/*
ID: jsnjhcb1
PROG: hiho15
LANG: C++
*/
/*************************************************************************
	> File Name: hiho15.cpp
	> Author: UCU
	> Mail: jsnjhcb@icloud.com
	> Created Time: 四  2/ 2 10:49:27 2017
 ************************************************************************/

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
map<string, int> imap;
map<int, string> rmap;
int num;
int insert(string s){
    if(imap[s] == 0){
        imap[s] = ++num;
        rmap[num] = s;
    }
    return imap[s];
}
int fa[100010];
vector<int> v[100010];
vector<pair<int, int> > q[100010];
int ans[100010];
int dsu[100010];
void init(int n){
    for(int i = 1; i <= n; ++i){
        dsu[i] = i;
    }
}
int _find(int x){
    if(dsu[x] == x) return x;
    else return dsu[x] = _find(dsu[x]);
}
void make_union(int x, int y){
    int a = _find(x);
    int b = _find(y);
    dsu[a] = dsu[b] = x;
}
int color[100010];// 白色0,灰色1,黑色2
void dfs(int now, int fa){
    color[now] = 1;
    for(int i = 0; i < q[now].size(); ++i){
        int &t = q[now][i].first;
        int &num = q[now][i].second;
        if(color[t] == 1){
            ans[num] = t;
        }
        else if(color[t] == 2){
            ans[num] = _find(t);
        }
    }
    for(int i = 0; i < v[now].size(); ++i){
        int &t = v[now][i];
        if(t == fa) continue;
        dfs(t, now);
    }
    color[now] = 2;
    if(fa != 0){
        make_union(fa, now);
    }
}
int main(){
    int n, m;
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; ++i){
        string s1, s2;
        cin >> s1 >> s2;
        int k1 = insert(s1);
        int k2 = insert(s2);
        v[k1].push_back(k2);
        v[k2].push_back(k1);
        fa[k2] = k1;
    }
    cin >> m;
    for(int i = 0; i < m; ++i){
        string s1, s2;
        cin >> s1 >> s2;
        int k1 = imap[s1];
        int k2 = imap[s2];
        q[k1].push_back(make_pair(k2, i));
        q[k2].push_back(make_pair(k1, i));
    }
    init(num);
    dfs(1, 0);
    for(int i = 0; i < m; ++i){
        cout << rmap[ans[i]] << endl;
    }
    return 0;
}