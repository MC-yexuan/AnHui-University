#include <iostream>
#include<cmath>

using namespace std;

int prime(int num)   //ÅĞ¶ÏËØÊı 
{
	if ( num == 3)
		return 1;
	if (num % 6 != 1 && num % 6 != 5)
		return 0;
	int tmp = sqrt(num);
	for (int i = 5; i <= tmp; i += 6)
		if (num % i == 0 || num % (i + 2) == 0)
			return 0;
	return 1;
}

int main()
{
    int M,N;
    cin>>N;
    if(N==1){
        M=0;
    }
    if(N==2){
        M=1;
    }
    else{
        if(prime(N)){
            M=N-1;
        }
        else M=2;
    }
    cout<<M;
    return 0;
}