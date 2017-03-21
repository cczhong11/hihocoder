#include <stdio.h>
int sum[210][210];
int main()
{
  freopen("in04.txt","r",stdin);
  int N,reward,max=0;
  scanf("%d\n", &N);
  scanf("%d\n", &sum[0][0]);
  if(N==1){max = sum[0][0];}//must consider this kind of condition
  for(int i = 1;i<N;i++)
    for(int j = 0;j<i+1;j++)
    {scanf("%d", &reward);
    if(j==0)
    {sum[i][j]=sum[i-1][j]+reward;
    }else{
      sum[i][j]=(sum[i-1][j]>sum[i-1][j-1]?sum[i-1][j]:sum[i-1][j-1])+reward;
    }
    if(i==N-1){
      if(sum[i][j]>max){max = sum[i][j];}
      }
  }
  printf("%d\n", max);
}
