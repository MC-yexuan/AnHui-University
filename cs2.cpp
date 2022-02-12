#include<fstream>
#include<iostream>
#include<string.h>
using namespace std;

 int a[7][27];int g[7];//以第i个字符打头长度不超过k的字符串个数；长度不超过k的字符串总个数

int main(){
   
    int i,k;
     //a[k][i].g[k].
    memset(a,0,sizeof(a));
    memset(g,0,sizeof(g));
    for(int j=1;j<27;j++){//长度为1的置一
        a[1][j]=1;
    }
    for(int k=2;k<7;k++){
        for(int i=1;i<27;i++){
            for(int j=i+1;j<27;j++){ //k是长度；i是字母，i=1代表a
                a[k][i]=a[k-1][j]+a[k][i];   
            }
        }
    }
    for(int k=1;k<7;k++){
        g[k]=g[k-1];
        for(int j=1;j<27;j++){
            g[k]=a[k][j]+g[k];
        }
    }
//------------------------------------------------------------------
    int cp(int k,int wd[]);//函数声明
    int k1,k2=0;char word[7];//wd记录7个字母 ******
    int num;//行数
    int wd[7];char num1,num2;//num为字符型行数，wd为字母数字
    memset(wd,0,sizeof(wd));
    // cin>>k1;
    // for(int i=1;i<=k1;i++){
    //     cin>>wd[i];
    // }
    ifstream in("input.txt");//以回车结尾
    ofstream out("output.txt");
    int eof=in.eof();
    while(!eof)
    {
        k1++;k2++;
        in.get(num2);
        eof=in.eof();
        if(eof){break;} 
        if(num2=='\n'){
            if(k2==2){k1=0;}
            else{
                cout<<endl;
                k1--;
                for(int i=1;i<=k1;i++){
                    wd[i]=word[i]-'a'+1;
                }

                int mid=cp(k1,wd);
                cout<< mid <<endl;
                out << mid <<endl;
                k1=0;
            }
        }

        else{
            if(k2==1) {num=num2-48; cout<<num<<endl;}//行数，不能超过9。
            else{
            word[k1]=num2;
            cout << word[k1];
            }
        }
    }
    in.close();
    out.close();
    return 0;
}


int cp(int k,int wd[]){//计算函数
     int num=g[k-1];
    for(int j=k;j>0;j--){
        int oder=k+1-j;//order为第几个字母
        for(int q=wd[oder]-1;q>wd[oder-1];q--){//q为当前字母减1，直到等于前一位+1
            num=num+a[j][q];
        }
    }
    return num+1;
}

