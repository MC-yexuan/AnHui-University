#include<iostream>
using namespace std;

long long fac(long long x)   //递归函数  
{  
    long long f;  
  
    if(x==0 || x==1)  
        f=1;  
    else  
        f=fac(x-1)*x;  
  
    return f;  
} 

 

int main()

{

    long long i;

    scanf("%d",&i);

    cout<<fac(i);//在此补充语句，输出i！的值，除此值外不要输出其他信息。

    

    return 0;

}