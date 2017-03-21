#include <iostream>
#include <queue>

using namespace std;
void move(int *num,int i);
int foo(int n)
{
	if(n<1)
		return 1;
	int s = 1;
	do	{
		s*=n;
	}while(--n);
	return s;
}
int Cantor(int num[])
{
	int X = 0;
	for (int i = 0; i < 9; ++i)
	{
		int tp=0;
		for (int j = i+1; j < 9; ++j)
		{
			if(num[j]<num[i])
				tp++;
		}
		X += tp*foo(9-i-1);
	}
	return X;
}
void unCantor(int Num[],int X)
{
	int a[9];
	int num[9];
	bool used[9];
	for (int i = 0; i < 9; ++i)
	{
		used[i] = false;
	}
	for (int i = 0; i < 9; ++i)
	{
		a[i] = X/foo(9-i-1);
		X = X%foo(9-i-1);
		int cnt = 0;
		for (int j = 0; j < 9; ++j)
		{			
			if(!used[j])
			{
				cnt++;
				if(cnt==a[i]+1)
				{
					num[i]=j;
					used[j]=true;
					break;
				}
			}
		}
	}
	for (int i = 0; i < 9; ++i)
	{
		Num[i] = num[i];
		
	}
	
}
void switchslot(int *num,int i, int j)
{
	int temp = num[i];
	num[i] = num[j];
	num[j] = temp;
}
void move(int num[],int step)
{
	int index = -1;
	for (int i = 0; i < 9; ++i)
	{
		
		if(num[i]==0)
			index=i;
	}
	
	switch(step)
	{
		case 0://up
		{
			if(index>2)
			{
				switchslot(num,index,index-3);
			}
			break;
		}
		case 1://up
		{
			if(index<6)
			{
				switchslot(num,index,index+3);
			}
			break;
		}
		case 2://left
		{
			if(index%3>0)
			{
				switchslot(num,index,index-1);
			}
			break;
		}
		case 3://right
		{
			if(index%3<2)
			{
				switchslot(num,index,index+1);
			}
		}
	}
}
int search_bfs(int num[])
{
	
	const int N = foo(9);
	bool visit[N];
	int step[N];
	for (int i = 0; i < N; ++i)
	{
		visit[i] = false;
	}
	int inital = Cantor(num);
	if(inital==46233)
	{
		return 0;
	}	
	queue<int> q;
	q.push(inital);
	visit[inital] = true;
	while(!q.empty())
	{
		int now = q.front();
		q.pop();
		visit[now] = true;
		for (int i = 0; i < 4; ++i)
		{
			int now_num[9];			
			unCantor(now_num,now);
			move(now_num,i);
			int next =Cantor(now_num); 
			if(!visit[next])
			{q.push(next);
			visit[next]=true;
			step[next] = step[now]+1;
			//cout<<"ss000"<<step[now]<<endl;
			if(next==46233)
			{
				return step[next];
			}}	
		}
	}
	return -1;
}
int main()
{
	int N =0 ;
	cin>>N;

	while(N--)
	{
		int *inital = new int[9];
		cin>>inital[0]>>inital[1]>>inital[2];
		cin>>inital[3]>>inital[4]>>inital[5];
		cin>>inital[6]>>inital[7]>>inital[8];
		int answer = search_bfs(inital);
		if(answer==-1)
			cout<<"No Solution!"<<endl;
		else{
			cout<<answer<<endl;
		}
	}
		//int inital[] = {8, 0, 1,5, 7, 4,3, 6, 2};
		//cout<<search_bfs(inital);

	
}