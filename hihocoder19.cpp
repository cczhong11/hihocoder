#include <cstdio>
#include <algorithm>
#define MAX 1000400
using namespace std;
struct node{
    int left;
    int right;
    int ll;
    int rl;
    int value;
}Node[2*MAX];
int a[MAX];
int size = 0, N, M,qqq,qq,s,b,e, index, value;
int dfs(int l, int r, int nod){
    int le = MAX, ri = MAX;
    Node[nod].ll = l;
    Node[nod].rl = r;
    if(l==r ||r<l) 
    {
        Node[nod].left = -1;
        Node[nod].right = -1;
        Node[nod].value = a[r];//forget
        return a[r];
    }
    size++;
    Node[nod].left = size;
    le = dfs(l,(l+r)/2, size);
    size++;
    Node[nod].right = size;
    ri = dfs((l+r)/2+1,r, size);
    Node[nod].value = min(le, ri);
    return min(le, ri);
}
int update(int l, int r, int nod, int center){
    int aa = nod;
    //node cc = Node[0];//did change the memory in the first edition
    //如果这个数是替代原来那个最小的数，那么就需要替换成原来次小的数from hcb
    //int aa = 0;
    /*while(1){
        if(value<Node[aa].value)
            {Node[aa].value = value;}
        if (Node[aa].ll == Node[aa].rl) break;
        if(index > center) {aa = Node[aa].right;}
        else {aa = Node[aa].left;}     
        center = (Node[aa].ll + Node[aa].rl)/2 ;   
    }*/
    int le = MAX, ri = MAX;    
    if(l==r ||r<l) 
    {        
        return a[r];
    }
    if(index > center) {aa = Node[aa].right;ri = update((l+r)/2+1,r, aa,(Node[aa].ll + Node[aa].rl)/2);
    le = Node[Node[nod].left].value;}
        else {aa = Node[aa].left;le = update(l,(l+r)/2, aa,(Node[aa].ll + Node[aa].rl)/2);
        ri = Node[Node[nod].right].value;}
            
    Node[nod].value = min(le, ri);
    return min(le, ri);
}
int search(int l, int r, int nod){
    qqq = 100000; 
    qq = 100000;
    if(Node[nod].ll==l&&Node[nod].rl==r)  return Node[nod].value;
    if(l==r ||r<l) return a[r];
    if((Node[nod].ll+Node[nod].rl)/2>=r) qqq = search(l,r,Node[nod].left);
    else if((Node[nod].ll+Node[nod].rl)/2 < l) qqq = search(l,r,Node[nod].right);
    else{
        int ri = search(l, (Node[nod].ll+Node[nod].rl)/2, Node[nod].left);
        int le = search((Node[nod].ll+Node[nod].rl)/2+1,r, Node[nod].right);
        qq = min(ri, le);
    }
    return min(qq,qqq);
}

int main(){
    freopen("in18.txt", "r", stdin);
    scanf("%d", &N);
    for(int i = 1; i< N+1; i++) scanf("%d", &a[i]);
    dfs(1, N, 0);
    scanf("%d", &M);
    for(int i = 0; i<M; i++)
    {
        scanf("%d %d %d", &s, &b, &e);
        if(s==0) printf("%d\n", search(b,e,0));
        else{
            a[b] = e;
            index = b;
            value = e;
            update(1, N, 0, (1+N)/2);
        }
    }
}