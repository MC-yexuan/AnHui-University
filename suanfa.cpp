#include<fstream>
#include<iostream>
#include<string.h>
using namespace std;
    
    int k1,k2=-1;int flag[127];//��¼ASCII ******
    class word
    {
    public:
        int num,flag1,flag2;//flag1�����ң�flag2���ҵ���
    };
    int mid[8];//��-������
    int n;//����
    char c1;
    //fg=0,��β��fg=1������fg=2��*��
    int main(){
    ifstream in("input.txt");//�Իس���β
    ofstream out("output.txt");
    memset(flag,-1,sizeof(flag));
    word cword[127];
    int eof=in.eof();
    while(!eof)
    {
        k1++;//����
        in.get(c1);             //ȡ���ļ��е���ĸ
        eof=in.eof();           //ָ����һ��
        if(c1==' '||c1=='+') continue;
        else if(c1=='\n')
        {k1=-1; k2++; memset(flag,-1,sizeof(flag));}    //���¼���
        else if(c1=='-'){       
            for(int i=k1-1;i>=0;i--)
                cword[mid[i]].num=-100;
            k2--;  
        }
        else {
            mid[k1]=(int)c1;//ASCII
            flag[mid[k1]]++;//��ͬԪ�ؼ�һ��
            if(cword[mid[k1]].flag1<k1)
            cword[mid[k1]].flag1=k1;//flag1
            if(!flag[mid[k1]])
            cword[mid[k1]].num++;
            }
             
    }      
    in.close();
    for(int i=0;i<128;i++){
        if(cword[i].num==k2){
            if(cword[i].flag1==0);
            else if(cword[i].flag1==1) cout<<'?';
            else cout<<'*';
            cout <<(char)i<<endl;
            out <<(char)i;
        }
    }
    out.close();
    return 0;
    }

    