#include <cstdio>
char pre[30], in[30];
void postorder(int i, int j, int k) {
	int t;
	if(!in[j] || j >= k)
		return;
	for(t = j; pre[i] != in[t]; t++);
	postorder(i+1, j, t);
	postorder(i+t-j+1, t+1, k);
	printf("%c", pre[i]);
}
int main() {
	freopen("in10.txt", "r", stdin);
    scanf("%s%s", pre, in);
	postorder(0, 0, 26);
	printf("\n");
	return 0;
}
