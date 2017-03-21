#include<iostream>
#include<vector>
#include<algorithm>
#include <cstring>
#include<cstdio>
#define N 10010
using namespace std;
int num = 0;

int p[N], qt[N], pt[N];
int q[N];
bool vis[N];
vector <int> wl[N];
bool cmp(int a, int b) {
	return qt[a]>qt[b];
}
int DFS(int index)
{
	long long int wallet = 200000000;
	long long int minwallet = 200000000;
	vis[index] = true;
	for (int i = 0; i < wl[index].size(); i++)
	{
		int &t = wl[index][i];
		if (!vis[t]) {
			DFS(t);
			vis[t] = false;
		}
	}
	sort(wl[index].begin(), wl[index].end(), cmp);
	wallet = wallet - p[index];
	if (minwallet > wallet) {
		minwallet = wallet;
	}
	wallet = wallet + q[index];
	for (int i = 0; i < wl[index].size(); i++)
	{
		int &t = wl[index][i];
		if (!vis[t]) {
			wallet -= pt[t];
			minwallet = min(minwallet, wallet);
			wallet += qt[t];
		}
	}
	pt[index] = 200000000 - minwallet;
	qt[index] = wallet - minwallet;
}


int main()
{
	
	cin >> num;	

	memset(vis, false, sizeof(vis));
	int n = num;	
	while (n--)
	{		
		cin >> p[num - n] >> q[num - n];
	}
	n = num;
	int index = 0;
	int sub = 0;
	while (--n)
	{
		cin >> index>>sub;
		wl[index].push_back(sub);
		wl[sub].push_back(index);
	}
	DFS(1);
	cout << pt[1];
}

