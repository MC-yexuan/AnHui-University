#include<iostream>
using namespace std;
int main()
{
    int M,N,sum,k,r,all=0;

   cin>>M>>N;

    for(int i=M;i<=N;++i)
    {
        sum=0;
        k=i/2;
        for(int j=1;j<=k;++j)
        {
            r=i%j;
            if(r==0)
            sum+=j;
        }
        if(sum==i)
        {
            all++;        
        }
    }
    cout<<all;
    return 0;

}