#include<fstream>
#include<iostream>
#include<string.h>
using namespace std;
const char *name = "�������";
const char *ID = "E01914004";

class homework{
    public:
    homework();
    homework(int a,int b,char c);
    homework(const homework &r); //�������캯��
    ~homework();

    char name;
    int arrive;
    int serve;
    };

homework::homework(){
    arrive=0;
    serve=0;
    name='0';
}

homework::homework(int a,int b,char c){
    arrive=a;
    serve=b;
    name=c;
}

homework::~homework(){;}


float finish[5],turnover[5],weight[5];//�������



int main(void) {
    
    cout << name<<" "<<ID << endl;
    char array[5];
    int serve1[5];int arrive1[5];
    for(int i=0;i<5;i++){
        cin>>array[i]>>arrive1[i]>>serve1[i];
    }
    homework a[5];
    for(int i=0;i<5;i++){
       a[i]={array[i],arrive1[i],serve1[i]};  
    }
    homework mid;
    for(int i=0;i<5;i++){
        if(a[i].arrive>a[i+1].arrive){a[i]=a[i+1];}
    }

    // for(int i=0;i<5;i++){
    //    cout<<a[i].name<<" "<< a[i].serve<<" "<<a[i].arrive<<endl; 
    // }

    cout<<"������  "<<"\t";  
    for(int i=0;i<5;i++){
        cout<<array[i]<<'\t';
    }
    cout<<endl;

    cout<<"���ʱ��"<<"\t";
    int all=0;//��������
    for(int i=0;i<5;i++){//���ʱ��
        all=all+serve1[i];
        finish[i]=all;
        cout<< finish[i]<<'\t';
    }
    cout<<endl;

    cout<<"��תʱ��"<<"\t";
    for(int i=0;i<5;i++){//��תʱ��
        turnover[i]=finish[i]-arrive1[i];
        cout<< turnover[i]<<'\t';
    }
    cout<<endl;

    cout<<"��Ȩ��תʱ��"<<"\t";
    for(int i=0;i<5;i++){//��Ȩ��תʱ��
        weight[i]=turnover[i]/serve1[i];
        cout<< weight[i]<<'\t';
    }
    cout<<endl;

    

    system("Pause");
    return 0;
    }

    