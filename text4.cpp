#include <iostream>

using namespace std;

int main()
{
   long long M,N,r=1;
   long long all=0;
   cin>>N>>M;
   long long *a=new long long[N];
   for(long long i=0;i<N;i++)
   {
       cin>>a[i];
   }
   for(long long j=0;j<M;j++)
   {
        for(long long i=0;i<N;i++)
        {
            if(a[i])
            {
                all++;
                a[i]--;
            }
            if(all==M) 
            {
                cout<<r;
                delete []a;
                return 0;
            }
        }
   r++;
   }   
}