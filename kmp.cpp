/*
ID: jsnjhcb1
PROG: kmp
LANG: C++
*/
/*************************************************************************
	> File Name: kmp.cpp
	> Author: UCU
	> Mail: jsnjhcb@icloud.com
	> Created Time: 五 11/18 23:27:36 2016
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
int kmpNext[10010];
char s[1000010];
char pat[10010];
int KMPcount(char x[],char y[]){
    int m = (int)strlen(x);
    int n = (int)strlen(y);
    int i,j;
    j = kmpNext[0] = -1;
    i = 0;
    while(i < m){
        while(-1 != j && x[i] != x[j]){
            j = kmpNext[j];
        }
        if(x[++i] == x[++j]) {kmpNext[i] = kmpNext[j];
            printf("%d %d %d\n",i,j, kmpNext[i]);}
        else {kmpNext[i] = j;printf("%d %d %d\n",i,j, kmpNext[i]);}
    }
    int ans = 0;
    i = j = 0;
    while(i < n){
        while(-1 != j && y[i] != x[j]) j = kmpNext[j];
        i++,j++;
        if(j >= m){
            ans ++;
            j = kmpNext[j];
        }
    }
    return ans;
}
int main(){
    int n;
    scanf("%d",&n);
    while(n--){
        scanf("%s",pat);
        scanf("%s",s);
        printf("%d\n",KMPcount(pat,s));
    }
    return 0;
}
