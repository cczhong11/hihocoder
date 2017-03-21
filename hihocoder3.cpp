#include <stdio.h>
#include <string.h>
#include <iostream>
#define MAXP 10010
#define MAXS 1000010
using namespace std;
char pattern[MAXP];
char str[MAXS];
int NEXT[MAXP];
int search(char* s1, char* s2)
{
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int q = 0;
    for (int i = 1; i < len2; i++) {
        q = NEXT[i-1];
        if(s2[q]==s2[i]) NEXT[i]=NEXT[i-1]+1;
        else{NEXT[i]=(s2[i]==s2[0])?1:0;}
    }
    int p = 0 ;
    int count = 0;
    q = 0;
    for (int i= 0; i < len1; i++) {
        if(s1[i] == s2[q]){
            q++;
            if(q == len2){
                count++;
                q = NEXT[q - 1];
            }
            continue;
        }
        else{
            if(q == 0) continue;
            else{
                q = NEXT[q - 1];
                --i;
            }
        }
    }
    return count;
}
int main(){
    int N;
    scanf("%d", &N);
    NEXT[0] = 0;
    while(N--)
    {
        scanf("%s", pattern);
        scanf("%s", str);       
        printf("%d\n", search(str,pattern));
    }
}