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
int dp[1010][(1<<10) + 10];
int w[1010];
int can[1110];
int main(){
    int n,m,q;
	freopen("in08.txt","r",stdin);
    scanf("%d%d%d", &n, &m, &q);
    for(int i = 0; i < n; ++i){
        scanf("%d", w + i);
    }
    memset(dp, 0, sizeof dp);
    memset(can, 0, sizeof can);
    if(n <= m){
        int ans = 0;
        for(int i = 0; i < (1 << n); ++i){
            int cnt = 0;
            int value = 0;
            for(int j = 0; (1 << j) <= i; ++j){
                if(i & (1 << j)){
                    value += w[n - 1 - j];
                    ++cnt;
                }
            }
            if(cnt <= q){
                ans = max(value, ans);
            }
        }
        printf("%d\n",ans);
    }
    else{
        int cannum = 0;
        int ans = 0;
        for(int i = 0; i < (1 << m); ++i){
            int cnt = 0;
            int value = 0;
            for(int j = 0; (1 << j) <= i; ++j){
                if(i & (1 << j)){
                    value += w[m - 1 - j];
                    cnt ++;
                }
            }
            if(cnt <= q){
                can[cannum++] = i;
                dp[m - 1][i] = max(value, dp[m - 1][i]);
                //ans = max(ans, dp[m - 1][i]);
            }
        }
        for(int i = m; i < n; ++i){
            for(int j = 0; j < cannum; ++j){
                dp[i][can[j]] = max(dp[i - 1][can[j] >> 1], dp[i - 1][(can[j] >> 1) + (1 << (m - 1))]);
                if(can[j] & 1){
                    dp[i][can[j]] += w[i];
                }
                //ans = max(ans, dp[i][can[j]]);
            }
        }
        for(int j = 0; j < cannum; ++j){
            ans = max(ans, dp[n - 1][can[j]]);
        }
        printf("%d\n", ans);
    }
    return 0;
}