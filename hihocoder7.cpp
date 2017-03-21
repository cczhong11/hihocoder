#include <stdio.h>
int main()
{
  freopen("in06.txt", "r", stdin);
  int f[100001],need,value;
  int N,M;
  scanf("%d %d", &N, &M);  
  for (int i = 0; i < M+1; i++) {
    f[i] = 0;
  }
  for (int i = 0; i < N; i++)
  {
    scanf("%d %d", &need,&value);
    for (int j = need; j <= M; j++) {
      f[j] = f[j]>(f[j-need]+value)?f[j]:(f[j-need]+value);
    }
  }
  int max = 0;
  for (int i = 0; i < M+1; i++) {
    if(f[i]>max)
    {
      //printf("%d\n", f[i]);
      max = f[i];
    }
  }
  printf("%d\n", max);
}
