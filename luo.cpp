#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main(){
    printf("      @                     @@           @@@@");cout<<endl;
    printf("   @                     @      @        @");cout<<endl;
    printf(" @  @                 @      @          @@@");cout<<endl;
    printf("@      @     @            @                      @");cout<<endl;
    printf(" @    @                  @                         @");cout<<endl;
    printf("   @@                 @@@@        @@@");cout<<endl;

    printf("   @                @        @            @");cout<<endl;
    printf("   @                  @    @              @");cout<<endl;
    printf("   @                    @@                @");cout<<endl;
    printf("   @                      @                 @");cout<<endl;
    printf("   @                      @                 @");cout<<endl;
    printf("   @@@@           @                 @@@@");cout<<endl;

    printf("            @                  @@@@@@              @             @                    @@@@@          @@@ ");cout<<endl;
    printf("     @   @                  @               @             @             @                    @                        @@@");cout<<endl;
    printf("  @@@@@@          @               @             @@     @@@@              @     @               @@@");cout<<endl;
    printf("@        @                  @@@@@ @         @@            @     @            @@@@@@        @@");cout<<endl;
    printf("     @@@@@          @               @        @  @     @@@@@@            @  @  @            @@ ");cout<<endl;
    printf("           @                  @               @             @         @     @              @      @     @     ");cout<<endl;
    printf(" @@@@@@@       @@@@@@              @       @          @                 @@                  @");cout<<endl;

    int a=-1,b=-1,c=-1;
    string A;string B="放弃"; string C="求求你了我的宝";
    cout<<"宝，你知道上面是什么吗？（看懂扣1，没看懂扣0）"<<endl;
    cin>>A;
    while(1){
        if(A=="1"){
            cout<<"我不信哦，你真看懂了？那你说说是啥呀？"<<endl;
            cin>>A;
            while(A!=B){
                cout<<"不对哦，不知道就输入‘放弃’吧。"<<endl;
                cin>>A;
            }
            break;
        }
    if(A=="0"){
        break;
        }
    else{
            cout<<"不听话，不可以瞎输哦~只能输‘1’或‘0’哦"<<endl;
            cin>>A;
        }
        

    }
    cout<<"哈哈！看不出来就对啦，想知道吗？想知道就输入‘求求你了我的宝’（坏笑）"<<endl;
    cin>>A;
    while(1){
        if(A==C){
        cout<<"耶耶！好吧，那我就告诉你吧，这个窗口关掉后你会在桌面上发现一个记事本哦 OvO 打开看看~"<<endl;
        break;
        }
    else{
        cout<<"没输对？七个字哦~重新输入吧。"<<endl;
        cin>>A;
        }
    }

    ofstream out("臭宝~看这里~.txt");

    out<<"      @                     @@           @@@@"<<endl;
    out<<("   @                     @      @        @");out<<endl;
    out<<(" @  @                 @      @          @@@");out<<endl;
    out<<("@      @     @            @                      @");out<<endl;
    out<<(" @    @                  @                         @");out<<endl;
    out<<("   @@                 @@@@        @@@");out<<endl;
    
    out<<endl;
    out<<endl;

    out<<("   @                @        @            @")<<endl;
    out<<("   @                  @    @              @");out<<endl;
    out<<("   @                    @@                @");out<<endl;
    out<<("   @                      @                 @");out<<endl;
    out<<("   @                      @                 @");out<<endl;
    out<<("   @@@@           @                 @@@@");out<<endl;

    out<<endl;
    out<<endl;

    out<<("            @                  @@@@@@              @             @                    @@@@@          @@@ ")<<endl;
    out<<("     @   @                  @               @             @             @                    @                        @@@");out<<endl;
    out<<("  @@@@@@          @               @             @@     @@@@              @     @               @@@");out<<endl;
    out<<("@        @                  @@@@@ @         @@            @     @            @@@@@@        @@");out<<endl;
    out<<("     @@@@@          @               @        @  @     @@@@@@            @  @  @            @@ ");out<<endl;
    out<<("           @                  @               @             @         @     @              @      @     @     ");out<<endl;
    out<<(" @@@@@@@       @@@@@@              @       @          @                 @@                  @");out<<endl;

    out.close();
    system("Pause");
    return 0;
}


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

    