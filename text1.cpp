#include<iostream>
using namespace std;

long long fac(long long x)   //�ݹ麯��  
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

    cout<<fac(i);//�ڴ˲�����䣬���i����ֵ������ֵ�ⲻҪ���������Ϣ��

    

    return 0;

}