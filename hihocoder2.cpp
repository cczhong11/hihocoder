#include <stdio.h>
#include <string.h>
using namespace std;
#define MAX 1000000
#define ONLINE_JUDGE
struct node{
  int next[26];
  int T;
  void init(){
    T = 0;
    memset(next,-1,sizeof(next));
  }
}Node[MAX];

char stra[20];
int size;
void insert(char* str)
{
  //int len = strlen(str);
  int p = 0;
  int i = 0;
  while(str[i])
  {
    int x = str[i]-'a';
    if(Node[p].next[x]==-1)
    {
      Node[size].init();
      Node[p].next[x] = size++;
    }
    p = Node[p].next[x];
    Node[p].T++;
    i++;
  }
}
void search(char* str)
{
  int p = 0,i=0;
  while(str[i])
  {
    int x = str[i]-'a';
    if(Node[p].next[x]==-1)
      {puts("0");
            return ;}
      p = Node[p].next[x];
      i++;
  }
  printf("%d\n",Node[p].T);

}
//1. the code have lots of duplicate tree node in the v0.1
//2. have buffer count in the scanf function
//3. pay attention to key judgement and last if statement
int main()
{
#ifndef ONLINE_JUDGE

  freopen("in02.txt", "r", stdin);
#endif
  size = 1;
  Node[0].init();
  int N, M;
  scanf("%d", &N);
  while (N--)
  {
    scanf("%s", stra);
    insert(stra);
  }
  scanf("%d", &M);
  while (M--)
  {
    scanf("%s", stra);
    search(stra);//printf("%d\n", search(stra));
  }

}
