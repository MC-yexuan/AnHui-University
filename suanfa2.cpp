#include<fstream>
#include<iostream>
#include<string.h>
using namespace std;
    
    int flag[128];//��¼ASCII ******
    class word
    {
    public:
        int num=0,flag1=0,flag2=0;//flag1�����ң�flag2���ҵ���
    };
    int mid[8];//��-������
    int n;//����
    char c1;
    //fg=0,��β��fg=1������fg=2��*��
    
    int main(){
    int k1=-1; int k2=-1;
    ifstream in("input.txt");//�Իس���β
    ofstream out("output.txt");
    memset(flag,-1,sizeof(flag));
    word cword[128];word lie[128];//lie��������ͬһ����ͬԪ��
    word pcword[128];//������-��flag1���ݣ�û�б�Ҫ������ֻ��Ϊ�˱��ڵ��ԣ�
    //��cword����������num���ԡ�
    for(int i=0;i<128;i++){
        lie[i].flag1=10; 
    }
    
    int eof=in.eof();
    while(!eof)
    {
        k1++;//����
        in.get(c1);             //ȡ���ļ��е���ĸ
        eof=in.eof();           //ָ����һ��
        if(c1=='+') {
            int len=k1-2;
            for(int i=0;i<=len;i++){//flag2,��ͬȡ������flag2
                cword[mid[i]].flag2=len-i;
                if(cword[mid[i]].flag2>2)
                cword[mid[i]].flag2=2;
            }
             for(int i=len;i>=0;i--){//flag2,��ͬȡ��ǰ���flag2
                lie[mid[i]].flag2=len-i;
                if(lie[mid[i]].flag2>2)
                lie[mid[i]].flag2=2;
            }
            for(int i=0;i<=len;i++){
            if(flag[mid[i]]>0){
                if(lie[mid[i]].flag1+lie[mid[i]].flag2<cword[mid[i]].flag1+cword[mid[i]].flag2){
                    cword[mid[i]].flag1=lie[mid[i]].flag1;
                    cword[mid[i]].flag2=lie[mid[i]].flag2;
                    }
                }
            }
            for(int i=0;i<128;i++){//�н���������lie.flag1,�����бȽϴ����flag�����洢����cword.flag
                lie[i].flag1=10;
                if(cword[i].flag1<pcword[i].flag1) cword[i].flag1=pcword[i].flag1;
                if(cword[i].flag2<pcword[i].flag2) cword[i].flag2=pcword[i].flag2;
                pcword[i].flag1=cword[i].flag1;
                pcword[i].flag2=cword[i].flag2;
            } 
        }
        
        else if(c1==' '){continue;}
        
        else if(c1=='\n')
        {k1=-1; k2++; memset(flag,-1,sizeof(flag));}    //���¼���

        else if(c1=='-'){       
            for(int i=k1-2;i>=0;i--)
                cword[mid[i]].num=-100;
            k2--;
            for(int i=0;i<128;i++){//�н���������lie.flag1,������cword.flag1
                lie[i].flag1=10;
                cword[i].flag1=pcword[i].flag1;
            } 
        }

        else {
            mid[k1]=(int)c1;//ASCII

            if(lie[mid[k1]].flag1>k1){//��ͬһ����Сflag1
                lie[mid[k1]].flag1=k1;
                if(lie[mid[k1]].flag1>2)
                    lie[mid[k1]].flag1=2;
                }
            //��������������������
            flag[mid[k1]]++;//��ͬԪ�ؼ�һ��
            if(!flag[mid[k1]])//�ж���ͬԪ��
            cword[mid[k1]].num++;
            else{} 
            
            if(cword[mid[k1]].flag1<k1){//��ͬһ�����flag1
            cword[mid[k1]].flag1=k1;//flag1
            if(cword[mid[k1]].flag1>2)
                cword[mid[k1]].flag1=2;
            }
            
            }
             
    }      
    in.close();
    
    word max;int maxi;
    max.num=0;
    for(int i=0;i<128;i++){
        if(cword[i].num>max.num){
        max=cword[i];
        maxi=i;
        }
        if(cword[i].num==max.num){
            if(cword[i].flag1+cword[i].flag2<max.flag1+max.flag2)
            max=cword[i];
            maxi=i;
        }
    }
    cout<<max.num<<endl;
    out<<max.num<<endl;
        
        if(cword[maxi].flag1==0);
        else if(cword[maxi].flag1==1) {
            cout<<'?';
            out<<'?';
        }
        else {cout<<'*';
            out<<'*';
        }
        cout <<(char)maxi;
        out <<(char)maxi;
        if(cword[maxi].flag2==0);
        else if(cword[maxi].flag2==1){
            cout<<'?';
            out<<'?';
        }
        else {cout<<'*';
            out<<'*';
        }
        
    
    out.close();
    return 0;
    }
//���⣺��ͬmax���ASCIIС�ģ���������̡�2.ͬһ�ַ�����ͬԪ�ػ�Ӱ�죿*(flag��������)
//����2��ֻ��- ������п��ԣ�Ӱ��Flag1����Ӱ������
