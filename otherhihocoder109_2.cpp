#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_WALLET = 200000000;

class Node {
public:
    int p,q,pt,qt,vis;
    vector<int> sons;
    Node() {
        vis = 0;
    }
};

vector<Node> nodes;

void dfs(int rt) {
    nodes[rt].vis = 1;
    int wallet = MAX_WALLET;
    int minWallet = MAX_WALLET;
    vector<int> sons;
    for(int i : nodes[rt].sons) {
        if(nodes[i].vis) continue;
        dfs(i);
        sons.push_back(i);
    }
    sort(sons.begin(),sons.end(),[](int a,int b){
        return nodes[a].qt > nodes[b].qt;
    });
    wallet -= nodes[rt].p;
    minWallet = min(minWallet,wallet);
    wallet += nodes[rt].q;

    for(int i : sons) {
        wallet -= nodes[i].pt;
        minWallet = min(minWallet,wallet);
        wallet += nodes[i].qt;
    }

    nodes[rt].pt = MAX_WALLET- minWallet;
    nodes[rt].qt = wallet    - minWallet;
    // cout << rt << " " << nodes[rt].pt << " " << nodes[rt].qt << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    nodes.assign(n,Node());
    for (int i = 0; i < n; i++) {
        cin >> nodes[i].p >> nodes[i].q;
    }
    for (int i = 0; i < n-1; i++) {
        int a,b;
        cin >> a >> b;
        a--; b--;
        nodes[a].sons.push_back(b);
        nodes[b].sons.push_back(a);
    }

    dfs(0);

    cout << nodes[0].pt << endl;
    
	return 0;
}
