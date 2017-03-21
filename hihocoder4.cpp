#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;
#define MAX 1000010
char a[MAX];
char ab[MAX];
struct node
{
	int trie;
	int NextT[26];
	int next[26];
	int parent;
	int bian;
	bool tag;
	void init() {
		trie = 0;
		parent = 0;
		bian = -1;
		tag = false;
		memset(next, 0, sizeof(next));
		memset(NextT, 0, sizeof(NextT));
	}
}Node[MAX];
int size;
void insert(char* str)
{
	int i = 0, p = 0;
	int len = strlen(str);
	while (str[i])
	{
		int x = str[i] - 'a';
		if (Node[p].next[x] == 0)
		{
			Node[size].init();
			Node[size].parent = p;
			Node[size].bian = x;
			Node[p].next[x] = size++;
		}
		p = Node[p].next[x];
		if (i == len - 1)
		{
			Node[p].tag = true;
		}i++;
	}


}
void change()
{//bfs
	queue<int> q;
	q.push(0);
	while(!q.empty())
	{
		int p = q.front();
		q.pop();
		node a = Node[p];
		if(a.parent == 0 )//handle special
		{
			a.trie = 0;
		}
		else {
			a.trie = Node[Node[a.parent].trie].NextT[a.bian];

		}
		for (int j = 0; j < 26; j++) {
			if (a.next[j] == 0)
			{
				a.NextT[j] = Node[a.trie].NextT[j];
			}
			else { a.NextT[j] = a.next[j];
			q.push(a.next[j]);}
		}
		Node[p] = a;//value back
	}
}
int search(char* s)
{
	int i = 0, p = 0, x;
	while (s[i]) {
		x = s[i] - 'a';
		p = Node[p].NextT[x];
		if (Node[p].tag)
		{
			printf("YES \n");
			return 0;
		}
		i++;
	}
	printf("NO\n");
	return 0;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("in04.txt", "r", stdin);
#endif
	int n;
	Node[0].init();
	size = 1;
	scanf("%d", &n);
	while (n--)
	{
		scanf("%s", a);
		insert(a);
	}
	change();
	scanf("%s", ab);//dont use a
	search(ab);
}
