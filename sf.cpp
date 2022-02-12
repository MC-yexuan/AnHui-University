#include<fstream>
#include<iostream>
#include<string.h>
using namespace std;
    
    int k1,k2=0;char word[501];//记录n个字母 ******
    int num;//元素个数
    int all=0;
    char num2;
    ofstream out("output.txt");
    
    int main(){
    ifstream in("input.txt");//以回车结尾
    int eof=in.eof();
    while(!eof)
    {
        k1++;k2++;//计数
        if(k2==1){
            in >> num;//读出元素个数n
            k1=-2;//从零开始
            eof=in.eof();//指向下一个
        }
        else if(k2==2){//规避回车
            in.get(num2);
            eof=in.eof();
        }
        else{
        in.get(num2);//取出文件中的字母
        eof=in.eof();//指向下一个
        if(num2=='\n'){eof=1;cout<<endl;}
        if(eof){break;} //到文件末尾退出
        word[k1]=num2;
        cout << word[k1];
        }      
    }      
    in.close();
    void Perm (char word[],int k,int m);
    Perm(word,0,num-1);
    cout<<all;
    out<<all;
    out.close();
    return 0;
    }

    inline void Swap(char &a,char &b);

    void Perm (char word[],int k,int m){
        if(k==m){
            for(int i=0;i<=m;i++){
            cout<<word[i];
            out<<word[i];
            }
            all++;
            cout<<endl;
            out<<endl;
        }
        else{
            for(int i=k;i<=m;i++){
                //----------------------------------------
                int flag=0;
                for(int j=k;j<i;j++){
                    if(word[i]==word[j]){
                    flag=1;
                    break;
                    }
                }
                if(flag==0){
                //-----------------------------------------
                Swap(word[k],word[i]);
                Perm(word,k+1,m);
                Swap(word[k],word[i]);
                }
            }
        }
    }

    inline void Swap(char &a,char &b){
        char temp=a;
        a=b;
        b=temp;
    }