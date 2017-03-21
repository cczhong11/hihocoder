#include<iostream>
using namespace std;
int gcd(long a,long b)
{
    if(a%b==0)
    return b;
    return gcd(b,a%b);
}
struct answer{
    int x;
    int y;
    answer(int x0,int y0)
    {
        x = x0;
        y = y0;
    }
};
answer e_gcd(int A,int B)
{
    if(A%B==0)
    return answer(0,1);
    answer a = e_gcd(B,A%B);
    long x = a.y;
    long y = a.x - (A/B)*a.y;
    return answer(x,y);
}
int main()
{
   
    long m[1000];
    long r[1000];
    long N;
    cin>>N;
    long I = 0; 
    while(N--)
    {
        cin>>m[I]>>r[I];
        I++;
    }
    long M = m[0];
    long R = r[0];
    //cout<<I<<endl;
    for(int i = 1; i<I; i++)
    {
        long d = gcd(M,m[i]);
        long c = r[i] - R;
        if(c%d)
            cout<<-1;
        answer a = e_gcd(M/d , m[i]/d);
        long k1 = (c/d*a.x)%(m[i]/d);
        R = R + k1*M;
        M = M/d*m[i];
        
        R = R%M;
    }
    if(R<0)
        R = R+M;
    cout<<R;
}