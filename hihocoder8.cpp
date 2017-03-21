#include <stdio.h>
#include <cmath>
#include <algorithm>
using namespace std;
bool could(int k,int qsize)
{
    int q = 0;
    while(q<qsize)
    {
        if (k%2==1)
           q++;            
        k/= 2;
        if (k == 0)
        {if(q<=qsize)
            return true;
         else
          break;
        }
    }
    return false;
}
int main()
{
    freopen("in08.txt","r",stdin);
    int best[1124],w[1124],lastk[1124];
    bool couldbe[1124];
    int N,M,Q;
    scanf("%d %d %d",&N,&M,&Q);
    for (int i = 0; i < exp2(M); ++i)
    {
        couldbe[i] = could(i,Q);
        //printf("%d %d\n", i,couldbe[i]);
    }
    for (int i = 0; i < N; ++i)
    {
        scanf("%d",&w[i]);
        //printf("%d %d\n", i,w[i]);
    }
    int max0 = 0;
    best[0] = 0;
    best[1] = w[0];
    for (int i = 1; i < M; ++i)
    {
        for (int k = 0; k < exp2(i); ++k)
        {
            if (couldbe[k+int(exp2(i))])
            {
                best[k+int(exp2(i))] = best[k]+w[i];

            }
           
        }
    }
    for (int k = 0; k < exp2(M); ++k)
        {
           if(couldbe[k])
		   lastk[k] = best[k];
	   //printf("%d %d\n",k,best[k]);
        }
    for (int i = M; i < N; ++i)
    {
        for (int k = 0; k < exp2(M); ++k)
        {if(couldbe[k]){
            if (couldbe[int(k/2+exp2(M-1))])
            {
                best[int(k/2+exp2(M-1))] = max(best[int(k/2+exp2(M-1))],lastk[k]+w[i]);
                 best[k/2] = max(best[k/2],lastk[k]);
				 //printf("%d %d %d\n", i,k,best[k/2+int(exp2(M-1))]);
            }
            else{
				
                best[k/2] = max(best[k/2],lastk[k]);
            }
		}
        }
		//printf("%d \n",i);
		for (int k = 0; k < exp2(M); ++k)
        {
          
		   if(couldbe[k])
		   {lastk[k] = best[k];
		   //printf("%d %d\n",k,best[k]);
        }}
    }
    for (int i = 0; i < exp2(M); ++i)
    {
		if(couldbe[i])
			
        {//printf("%d %d\n",i,best[i]);
			if (best[i]>max0 )
        {
            max0 = best[i];
        }}
    }
    printf("%d\n", max0);
}
