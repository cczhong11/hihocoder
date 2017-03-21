#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int N=10010;
const int M=200000000;
int q[N],p[N],qt[N],pt[N]; 
bool vis[N];
int n;

vector<int> tr[N];
bool cmp(int a,int b){
	return qt[a]>qt[b];
}
void dfs(int rt){
	int minW=M,W=M;
	vis[rt]=true;
	for(int i=0;i<tr[rt].size();i++){
		int &t=tr[rt][i];
		if(!vis[t]){
			dfs(t);
			vis[t]=false;
		} 
	}
	sort(tr[rt].begin(),tr[rt].end(),cmp);
	W-=p[rt];
	minW=min(minW,W);
	W+=q[rt];
	for(int i=0;i<tr[rt].size();i++){
		int &t=tr[rt][i];
		if(!vis[t]){
			W-=pt[t];
			minW=min(minW,W);
			W+=qt[t];
		}
	}
	pt[rt]=M-minW;
	qt[rt]=W-minW;
}
int main(int argc, char** argv) {
	while(scanf("%d",&n)==1){
		memset(vis,false,sizeof(vis));
		for(int i=1;i<=n;i++){
			scanf("%d %d",&p[i],&q[i]);
			tr[i].clear();
		}
		for(int i=1;i<n;i++){
			int a,b;
			scanf("%d %d",&a,&b);
			tr[a].push_back(b);
			tr[b].push_back(a);
		}
		dfs(1);
		printf("%d\n",pt[1]);
	}
	return 0;
}