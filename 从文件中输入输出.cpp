#include<fstream>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<stdlib.h>
using namespace std;

int greedy(int x[],int n,int k){//k=k+1
    int sum=0;int k1=0;
    for(int i=0;i<k;i++){
        sum=sum+x[i];
        if(sum>n){
            k1++;
            sum=0;
            i--;     
        }
    }
    return k1;
}


int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");
    int i1; int n; int path[10];int k=0;int k1=0;
    memset(path,0,sizeof(path));
    int eof=in.eof();
    while(!eof)
    {
        in >> i1;             //取出文件中的数字
        eof=in.eof();           //指向下一个
        if(!eof){
            if(!k1)
                n=i1;
            else if(k1==1){
                k=i1+1;
            }
            else
            path[k1-2]=i1; 
        }  
        k1++;//计数      
    }
    out<<greedy(path,n,k)<<endl;
    return 0;
}
