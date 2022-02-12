#include<fstream>
#include<iostream>
#include<string.h>
using namespace std;
const char *name = "马崔烨暄";
const char *ID = "E01914004";

class homework{
    public:
    homework();
    homework(int a,int b,char c);
    homework(const homework &r); //拷贝构造函数
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


float finish[5],turnover[5],weight[5];//结果数组



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

    cout<<"进程名  "<<"\t";  
    for(int i=0;i<5;i++){
        cout<<array[i]<<'\t';
    }
    cout<<endl;

    cout<<"完成时间"<<"\t";
    int all=0;//辅助变量
    for(int i=0;i<5;i++){//完成时间
        all=all+serve1[i];
        finish[i]=all;
        cout<< finish[i]<<'\t';
    }
    cout<<endl;

    cout<<"周转时间"<<"\t";
    for(int i=0;i<5;i++){//周转时间
        turnover[i]=finish[i]-arrive1[i];
        cout<< turnover[i]<<'\t';
    }
    cout<<endl;

    cout<<"带权周转时间"<<"\t";
    for(int i=0;i<5;i++){//带权周转时间
        weight[i]=turnover[i]/serve1[i];
        cout<< weight[i]<<'\t';
    }
    cout<<endl;

    

    system("Pause");
    return 0;
    }

    