#include<fstream>
#include<iostream>
#include<string.h>
using namespace std;

 int a[7][27];int g[7];//�Ե�i���ַ���ͷ���Ȳ�����k���ַ������������Ȳ�����k���ַ����ܸ���

int main(){
   
    int i,k;
     //a[k][i].g[k].
    memset(a,0,sizeof(a));
    memset(g,0,sizeof(g));
    for(int j=1;j<27;j++){//����Ϊ1����һ
        a[1][j]=1;
    }
    for(int k=2;k<7;k++){
        for(int i=1;i<27;i++){
            for(int j=i+1;j<27;j++){ //k�ǳ��ȣ�i����ĸ��i=1����a
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
    int cp(int k,int wd[]);//��������
    int k1,k2=0;char word[7];//wd��¼7����ĸ ******
    int num;//����
    int wd[7];char num1,num2;//numΪ�ַ���������wdΪ��ĸ����
    memset(wd,0,sizeof(wd));
    // cin>>k1;
    // for(int i=1;i<=k1;i++){
    //     cin>>wd[i];
    // }
    ifstream in("input.txt");//�Իس���β
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
            if(k2==1) {num=num2-48; cout<<num<<endl;}//���������ܳ���9��
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


int cp(int k,int wd[]){//���㺯��
     int num=g[k-1];
    for(int j=k;j>0;j--){
        int oder=k+1-j;//orderΪ�ڼ�����ĸ
        for(int q=wd[oder]-1;q>wd[oder-1];q--){//qΪ��ǰ��ĸ��1��ֱ������ǰһλ+1
            num=num+a[j][q];
        }
    }
    return num+1;
}

