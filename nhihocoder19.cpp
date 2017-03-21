#include<cstdio>

const int NM = 1<<21;
int a[NM] = {0};
int N,M,s,b,e,A,B,C;
int min(int a, int b) {return (a<b)?a:b;}
int qt(int l, int r){
    int res = NM;
    while(1){
        if(l>r) break;
		if(l==r) {res = min(res,a[l]); break;}
		if((l&1)==1) {res = min(res,a[l]); l++;}
		if((r&1)==0) {res = min(res,a[r]); r--;}
		l>>=1; r>>=1;
    }  
    return res;
}
int ct(int p, int v){
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
    scanf("%d",&N);
    for(A = 1;A<N;A<<=1);
    B = A+N; C = A<<1;
    for(int i = A;i<B;i++){scanf("%d", &a[i]);}
    for(int i = B; i < C; i++) a[i] = NM;
    for(int i = A-1;i>=0;i--){a[i]=min(a[i<<1],a[(i<<1)|1]);}
    scanf("%d",&M);
    for(int i = 0; i<M; i++)
    {
        scanf("%d %d %d", &s, &b, &e);
        if(s==0) printf("%d\n", qt(--b+A,--e+A));
        else{
            //a[--b] = e;            
            ct(--b+A,e);
        }
    }
}