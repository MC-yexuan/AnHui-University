//概率最大的两个文件之间的距离最小
#include<fstream>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<stdlib.h>
using namespace std;
    
    int path[10];float lpath[10];
    int k1=0;
    char c1;
    int i1,num;
    int main(){
           
    ifstream in("input.txt");
    ofstream out("output.txt");
    memset(path,0,sizeof(path));
    memset(lpath,0,sizeof(path));
    int eof=in.eof();
    while(!eof)
    {
        in >> i1;             //取出文件中的数字
        eof=in.eof();           //指向下一个
        if(!eof){
            if(!k1)
                num=i1;
            else
            path[k1]=i1; 
        }  
        k1++;//计数      
    }
    sort(path,path+10);
    reverse(path,path+10);//逆序
    
    int*p=path;
    int all=0;//求和
    while(*p){
        all=all+*p;
        p++;
    }

    int mid=num/2;int midd=mid;
    int lmid=mid; int rmid=mid;
    for(int i=0;i<num;i++){//确定存储位置
        if(i&&(i%2)){
            lmid--;
            midd=lmid;
            }
        if(i&&!(i%2)){
            rmid++;
            midd=rmid;
            }
        lpath[midd]=float(path[i]/(all*1.0));      
    }
    float result=0.0;
    for(int i=0;i<num;i++){
        for(int j=i+1;j<num;j++){
            result=lpath[i]*lpath[j]*(j-i)+result;
        }
    }
    out<<result;
    in.close();
    out.close();
    return 0;
    }


