#include<iostream>
using namespace std;
#define MAX 100000
int main(){
    int n; double m;int a[100];
    cin>>n;
    if(n<1) {cout<<"error"; return 0;}
    else{
        
        int min=MAX; int max=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            if(a[i]>max) max=a[i];
            if(a[i]<min) min=a[i];          
        }
        cout<<"Min="<<min<<"£¬Max="<<max<<endl;
    }
  
    return 0;
}
