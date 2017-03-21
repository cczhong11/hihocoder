#include <cstdio>

const int NM = 1<<21;
int a[NM] = {0};

int aa;char ch;int F(){
    while(ch=getchar(),ch<48||ch>57);aa=ch-48;
    while(ch=getchar(),ch>47&&ch<58)aa=(aa<<1)*5+ch-48;return aa;
}

int min(int x,int y) {return (x<y)?x:y;}

int qt(int l,int r) {
	int res = NM;
	while(1) {
		if(l>r) break;
		if(l==r) {res = min(res,a[l]); break;}
		if((l&1)==1) {res = min(res,a[l]); l++;}
		if((r&1)==0) {res = min(res,a[r]); r--;}
		l>>=1; r>>=1;
	}
	return res;
}

void ct(int p,int v) {
	a[p] = v;
	while(1) {
		p>>=1;
		if(p==0) break;
		a[p] = min(a[p<<1],a[(p<<1)|1]);
	}
}

int main()
{
	freopen("in18.txt", "r", stdin);
	int N,Q,A,B,C;
	N = F();
	for(A=1;A<N;A<<=1); B = A+N; C = A<<1;
	for(int i = A; i < B; i++) a[i] = F();
	for(int i = B; i < C; i++) a[i] = NM;
	for(int i = A-1; i; i--) a[i] = min(a[i<<1],a[(i<<1)|1]);
	
	Q = F();
	for(int i = 0; i < Q; i++) {
		int x,y,z;
		x = F(); y = F(); z = F();
		if(x==0) printf("%d\n",qt(--y+A,--z+A));
		else ct(--y+A,z);
	}
	return 0;
}
