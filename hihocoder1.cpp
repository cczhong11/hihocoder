
#include <string.h>
#include <cstdio>
#include <algorithm>
#define N 1000100
char s[N],b[2*N];
int f[N*2];//每个中位的最长回文串
using namespace std;
int answer(char* stra)
{		
	int n = 2;
	for (int i = 0; stra[i]; ++i)// pay attention to odd and even 
	{
		b[n++] = stra[i];
		b[n++] = '-';		
	}
	
	int lenmax = 1;//存到f[]里的临时变量
	int jmax = 1;  //代表最左侧边界的中位序号
	//int min0 = 0;   //保存搜索的起始的临时变量
	int result = 1;//保存结果	
	int jmaxlen = 1;//最远位置
	
	int maxi = 0; //最长回文序列的中心位置	
	for (int i = 1; i < n; ++i)
	{
		if(jmaxlen>i)f[i] = min(jmaxlen-i,f[2*jmax-i]);
		else f[i]=1;//
		while(b[i-f[i]]==b[i+f[i]]) f[i]++;		
		if ((i + f[i])>jmaxlen)
		{
			jmaxlen = i + f[i];
			jmax = i;
		}		
	}
	 int ans = 0;
     for(int i = 1;i < n;i ++)
            ans = max(ans, f[i]-1);
	
	return ans;
}
int main()
{
	int n;	
	scanf("%d", &n);
	s[0]='$';
	s[1]='-';
	while(n -- )
	{
		scanf("%s", s+1);
		printf("%d\n", answer(s));//s->d
	}
}