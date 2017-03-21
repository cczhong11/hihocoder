#include <stdio.h>
using namespace std;
int sum[1000][5][2148]={0};
int main()
{
	//freopen("in09.txt","r",stdin);
	int N, M,sj,sj1,sjm,js,j1s,jms,o=1e9+7;
	scanf("%d %d",&N,&M);
	for (int i = N-1; i >= 0; --i)
	{
		for (int j = M-1; j >= 0; j--)
		{
			for (int s = (1<<(2*M))-1; s >-1; s--)
			{
				js = 1<<j;//<< is lower than +
				j1s= 1<<(j+1);
				jms= 1<<(j+M);
				sj = s&js;
				sj1= s&j1s;
				sjm= s&jms;
				if((i==N-1)&&s>(1<<M)){continue;}
				if(((s==(1<<(2*M))-1)&&i>N-3)||(i==(N-1)&&s==(1<<M)-1))
				{
					sum[i][j][s] = 1;
					continue;
				}				
				if (sj==0)
				{
					if((j==(M-1)||sj1)&&(i==(N-1)||sjm))
					{
						sum[i][j][s] = 0;
					}
					if((j<(M-1)&&(sj1==0))&&(i==(N-1)||sjm))
					{

						sum[i][j][s] = sum[i][j][s+js+j1s];
					}
					if((j==(M-1)||(sj1))&&(i<(N-1)&&sjm==0))
					{

						sum[i][j][s] = sum[i][j][s+js+jms];
					}
					if((j<(M-1)&&(sj1==0))&&(i<(N-1)&&(sjm==0)))
					{											
						sum[i][j][s] = (sum[i][j][s+js+jms]+sum[i][j][s+js+j1s])%o;
					}
				}
				else{
					if(j<(M-1)){
						sum[i][j][s] = sum[i][j+1][s];
					}
					if(j==(M-1)&&i<(N-1)){
						sum[i][j][s] = sum[i+1][0][s>>M];//need to focus 
					}
				}
			}
		}
	}
	int a = sum[0][0][0]%1000000007;
	printf("%d\n", a);
}