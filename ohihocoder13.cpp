#include <cstdio>
#include <cstring>
#include <memory.h>

const int maxn = 309;

int n, m, d[maxn], fa[maxn], tn;
char a[maxn][maxn], fn[maxn], sn[maxn];

int getNum(char* x) {
	for (int i = 1; i <= tn; i ++)
		if (strcmp(x, a[i]) == 0)
			return i;
	strcpy(a[++ tn], x);
	return tn;
}

void dfs(int p) {
	static int stc[maxn];
	int ts = 1;
	stc[1] = p;
	while (fa[stc[ts]])
		stc[ts + 1]= fa[stc[ts]], ts ++;
	d[stc[ts]] = 1;
	while (-- ts)
		d[stc[ts]] = d[fa[stc[ts]]] + 1;
}

void buildTree() {
	memset(d, 0, sizeof(d));
	for (int i = 1; i <= tn; i ++)
		if (!d[i])
			dfs(i);
}

int lca(int p, int q) {
	while (p && q && (p ^ q))
		if (d[p] > d[q])
			p = fa[p];
		else
			q = fa[q];
	if (!p || !q)
		return -1;
	else
		return p;
}

int main() {

	freopen("in13.txt", "r", stdin);


	memset(fa, 0, sizeof(fa));
	scanf("%d", &n);
	tn = 0;
	for (int i = 0; i < n; i ++) {
		scanf("%s%s", fn, sn);
		int nf = getNum(fn);
		int ns = getNum(sn);
		fa[ns] = nf;
	}
	buildTree();
	scanf("%d", &m);
	while (m --) {
		scanf("%s%s", fn, sn);
		int nf = getNum(fn);
		int ns = getNum(sn);
		int ath = lca(nf, ns);
		if (ath == -1)
			puts("-1");
		else
			puts(a[ath]);
	}
}

