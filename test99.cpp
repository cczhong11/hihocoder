//2016.5.27
#include<iostream>
#include <string>
#include <queue>
#include <math.h>
using namespace std;
int getindex(int a)
{
	int i = 0;
	int sum = 0;
	int s = 0;
	while (a > 0)
	{
		s = a % 10;
		sum = sum + (s-1) *pow(8,i);
		i++;
		a = a / 10;
	}
	return sum;
}
int change(string a, string b, string c)
{
	int s0 = (a[0] - 'A' + 1) * 10 + a[1] - '0';
	int s1 = (b[0] - 'A' + 1) * 10 + b[1] - '0';
	int s2 = (c[0] - 'A' + 1) * 10 + c[1] - '0';
	return s0 * 10000 + s1 * 100 + s2;
}
int movesmallstep(int now, int step)
{
	switch (step)
	{
	case 1://右上
	{
		if (now % 10>6 || now / 10>7)
		{
			return now;
		}
		else
		{
			return now + 10 + 2;
		}}
	case 2:
	{
		if (now % 10>7 || now / 10>6)
		{
			return now;
		}
		else
		{
			return now + 20 + 1;
		}
	}
	case 3:
	{
		if (now % 10>6 || now / 10<2)
		{
			return now;
		}
		else
		{
			return now - 10 + 2;
		}
	}
	case 4:
	{
		if (now % 10>7 || now / 10<3)
		{
			return now;
		}
		else
		{
			return now - 20 + 1;
		}
	}
	case 5://down
	{
		if (now % 10<3 || now / 10>7)
		{
			return now;
		}
		else
		{
			return now + 10 - 2;
		}}
	case 6:
	{
		if (now % 10<2 || now / 10>6)
		{
			return now;
		}
		else
		{
			return now + 20 - 1;
		}
	}
	case 7:
	{
		if (now % 10<3 || now / 10<2)
		{
			return now;
		}
		else
		{
			return now - 10 - 2;
		}
	}
	case 8:
	{
		if (now % 10<2 || now / 10<3)
		{
			return now;
		}
		else
		{
			return now - 20 - 1;
		}
	}
	}
}
int move(int now, int indexi, int step)
{
	if (indexi == 1)
	{
		int s = now / 10000;
		s = movesmallstep(s, step);
		return (s * 10000 + now % 10000);
	}
	if (indexi == 2)
	{
		int s = (now / 100) % 100;
		s = movesmallstep(s, step);
		
		return ((now / 10000) * 10000 + s * 100 + now % 100);
	}
	if (indexi == 3)
	{
		int s = now % 100;
		s = movesmallstep(s, step);
		return ((now / 100) * 100 + s);
	}
}
bool check(int s)
{
	int a = s / 10000;
	int b = (s / 100) % 100;
	int c = s % 100;
	if (a == b)
		if (b == c)
			return true;
	return false;
}
int bfs(int initalstep)
{
	if (check(initalstep))
		return 0;
	bool visit[262144];
	int step[262144];
	for (int i = 0; i<262144; i++)
	{
		visit[i] = false;
		step[i] = 0;
	}
	
	queue<int> q;
	q.push(initalstep);
	while (!q.empty())
	{
		int now = q.front();
		int now2 = getindex(now);
		visit[now2] = true;
		q.pop();
		for (int i = 1; i<4; i++)
		{
			for (int j = 1; j<9; j++)
			{
				int next = move(now, i, j);
				int next2 = getindex(next);				
				if (!visit[next2])
				{
					visit[next2] = true;
					step[next2] = step[now2] + 1;
					q.push(next);
					if (check(next))
						return step[next2];
				}
			}
		}
	}
}
int main()
{
	int N;
	cin>>N;
	string a,b,c;
	int inital[10];
	int i =0 ;
	while(N--)
	{
		cin>>a>>b>>c;
		inital[i] = change(a,b,c);
		i++;
		
	}
	for (int j = 0;j<i;j++)
	{
	    cout<<bfs(inital[j])<<endl;
	}
}