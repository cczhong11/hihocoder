#include<iostream>
#include<math.h>
using namespace std;
bool judge(int x)
{
    if(x%2==0)
    return false;
    else{
        for (int i =3;i<=sqrt(x)+1;i+=2)
        {
            if(x/i>1 && x%i==0)
            {
                return false;
            }
        }
        return true;
    }
}
int main()
{
    int x = 0;
    int num = 0;
    cin>>num;
    int i =0;
    long int *one = new long int[num];
    while(i<num)
    {
       cin>>x;
       one[i] = x;
       i++;
    }
    for (int i = 0; i < num; ++i)
    {
      if(judge(one[i]))
        cout<<"Yes"<<endl;
        else
        cout<<"No"<<endl;
    }

}
