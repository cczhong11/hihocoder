#include<iostream>
using namespace std;
//bool used[] = {false,false,false,false}; 
int nownumber[] ={0,0,0,0};
int ops[] = {0,0,0}; 
int optype[] = {1,2,3,4,5,6};
int calc1(int *nownumber,int *ops);
int calc2(int *nownumber,int *ops);
double calcs(double a,double b, int op);
bool makeOperation(int depth);
bool makeNumber(int depth,int *number,bool *used)
{
    if(depth>=4)
        {
    return makeOperation(0);}
    for(int i = 0;i<4;i++)
    {
        if(!used[i])
        {
            nownumber[depth] = number[i];
            used[i] = true;            
            if(makeNumber(depth+1,number,used))
                return true;
            used[i] = false;
        }
    }
    return false;
}
bool makeOperation(int depth)
{
    if(depth>=3)
        {	if(calc1(nownumber,ops)==24)
            return true;
        if(calc2(nownumber,ops)==24)
            return true;
        return false;}
    for(int i = 0;i<6;i++)
    {
        ops[depth] = optype[i];
        if(makeOperation(depth+1))
            return true;
        
    }
    return false;
}
int calc1(int *nownumber,int *ops)
{
    double s = calcs(nownumber[0],nownumber[1],ops[0]);
    s = calcs(s,nownumber[2],ops[1]);
    s = calcs(s,nownumber[3],ops[2]);
   // cout<<s<<endl;
    return s;
}
int calc2(int *nownumber,int *ops)
{
    double s = calcs(nownumber[0],nownumber[1],ops[0]);
    double s2 = calcs(nownumber[2],nownumber[3],ops[1]);
    s = calcs(s,s2,ops[2]);
    return s;
}
double calcs(double a,double b, int op)
{
    switch(op)
    {
        case 1:return a+b;
        case 2:return a-b;
        case 3:return double(a*b);
        case 4:return double(a*1.0/b);
        case 5:return b-a;
        case 6:return double(b*1.0/a);
    }
}
int main()
{
    int N= 0;
    cin>>N;
    int number[N][4];// = {0};
    int a = N;
    int i = 0;
   
    while(N--)
    {
        cin>>number[i][0]>>number[i][1]>>number[i][2]>>number[i][3];
        //cout<<number[i][0]<<number[i][1]<<number[i][2]<<number[i][3];
        i++;
       	
     }
       
     while(a--)
     {
     	
        bool used[] = {false,false,false,false}; 
        if(makeNumber(0,number[i-a-1],used))
            cout<<"Yes"<<endl;
        else 
            cout<<"No"<<endl;
    }
}