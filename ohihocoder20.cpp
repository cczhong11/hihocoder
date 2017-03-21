#include <cstdio>

int geti() {
	int r = 0; char c = 0;	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') {r=((r<<3)+(r<<1))+(c-'0');c=getchar();}
	return r;
}

void outi(int x) {
	int i;char buf[16];
	if(x==0) {putchar('0');putchar('\n');return;}
	for(i = 0; x; i++) {buf[i] = x%10+'0';x/=10;}
	for(;i--;) putchar(buf[i]);putchar('\n');
}

int max(int a,int b) {return (a>b)?a:b;}
int min(int a,int b) {return (a<b)?a:b;}

const int NUM = (1<<(18));
struct {int sum;char lazyTag;} tr[NUM]={0};

#define L(i) ((i<<dep))
#define R(i) ((i<<dep)+(1<<dep)-1)

void modify(int a,int b,int val,int i,int dep) {
	if(a==L(i) && b == R(i)) {
		tr[i].sum = (val<<dep);
		tr[i].lazyTag = 1;return;
	}
	
	int l,r; l = i<<1; r = l+1; dep--;
	if(tr[i].lazyTag) {
		tr[i].lazyTag = 0;
		tr[l].sum = (tr[i].sum>>1);tr[l].lazyTag = 1;
		tr[r].sum = tr[l].sum;tr[r].lazyTag = 1;
	}
	
	if(a<=R(l)) modify(a,min(b,R(l)),val,l,dep);
	if(b>=L(r)) modify(max(a,L(r)),b,val,r,dep);
	tr[i].sum = tr[l].sum + tr[r].sum;
}

int query(int a,int b,int i,int dep) {
	if(a==L(i) && b == R(i)) return tr[i].sum;
	
	int ans,l,r; ans = 0; l = i<<1; r = l+1; dep--;
	if(tr[i].lazyTag) {
		tr[i].lazyTag = 0;
		tr[l].sum = (tr[i].sum>>1);tr[l].lazyTag = 1;
		tr[r].sum = tr[l].sum;tr[r].lazyTag = 1;
	}
	
	if(a<=R(l)) ans += query(a,min(b,R(l)),l,dep);
	if(b>=L(r)) ans += query(max(a,L(r)),b,r,dep);
	return ans;
}

int main()
{
	int N,Q;
	N = geti();
	int A = 1,dep = 0; while(A<N) {A<<=1;dep++;}
	for(int i = 0,j=A; i < N; i++,j++) tr[j].sum = geti();
	for(int i = A-1; i>0; i--) {
		int l,r; l = i<<1; r = l+1;
		tr[i].sum = tr[l].sum + tr[r].sum;
	}
	Q = geti();
	for(;Q--;) {
		int x,y,z;
		if(geti()) {
			x = geti(); y = geti(); z = geti();
			modify(--x+A,--y+A,z,1,dep);
		} else {
			x = geti(); y = geti();
			outi(query(--x+A,--y+A,1,dep));
		}
	}
	return 0;
}
