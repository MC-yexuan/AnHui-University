#include<fstream>
#include<iostream>
#include<string.h>
using namespace std;
    
    int k1,k2=0;char word[501];//��¼n����ĸ ******
    int num;//Ԫ�ظ���
    int all=0;
    char num2;
    ofstream out("output.txt");
    
    int main(){
    ifstream in("input.txt");//�Իس���β
    int eof=in.eof();
    while(!eof)
    {
        k1++;k2++;//����
        if(k2==1){
            in >> num;//����Ԫ�ظ���n
            k1=-2;//���㿪ʼ
            eof=in.eof();//ָ����һ��
        }
        else if(k2==2){//��ܻس�
            in.get(num2);
            eof=in.eof();
        }
        else{
        in.get(num2);//ȡ���ļ��е���ĸ
        eof=in.eof();//ָ����һ��
        if(num2=='\n'){eof=1;cout<<endl;}
        if(eof){break;} //���ļ�ĩβ�˳�
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