#include<fstream>
#include<iostream>
#include<string.h>
using namespace std;
    
    int flag[128];//记录ASCII ******
    class word
    {
    public:
        int num=0,flag1=0,flag2=0;//flag1从左到右，flag2从右到左。
    };
    int mid[8];//‘-’回溯
    int n;//行数
    char c1;
    //fg=0,首尾；fg=1，？；fg=2，*；
    
    int main(){
    int k1=-1; int k2=-1;
    ifstream in("input.txt");//以回车结尾
    ofstream out("output.txt");
    memset(flag,-1,sizeof(flag));
    word cword[128];word lie[128];//lie用来区分同一行相同元素
    word pcword[128];//用来‘-’flag1回溯（没有必要！！！只是为了便于调试）
    //除cword其他都不用num属性。
    for(int i=0;i<128;i++){
        lie[i].flag1=10; 
    }
    
    int eof=in.eof();
    while(!eof)
    {
        k1++;//计数
        in.get(c1);             //取出文件中的字母
        eof=in.eof();           //指向下一个
        if(c1=='+') {
            int len=k1-2;
            for(int i=0;i<=len;i++){//flag2,相同取最后面的flag2
                cword[mid[i]].flag2=len-i;
                if(cword[mid[i]].flag2>2)
                cword[mid[i]].flag2=2;
            }
             for(int i=len;i>=0;i--){//flag2,相同取最前面的flag2
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
            for(int i=0;i<128;i++){//行结束，重置lie.flag1,进行行比较存最大flag，并存储本次cword.flag
                lie[i].flag1=10;
                if(cword[i].flag1<pcword[i].flag1) cword[i].flag1=pcword[i].flag1;
                if(cword[i].flag2<pcword[i].flag2) cword[i].flag2=pcword[i].flag2;
                pcword[i].flag1=cword[i].flag1;
                pcword[i].flag2=cword[i].flag2;
            } 
        }
        
        else if(c1==' '){continue;}
        
        else if(c1=='\n')
        {k1=-1; k2++; memset(flag,-1,sizeof(flag));}    //重新计数

        else if(c1=='-'){       
            for(int i=k1-2;i>=0;i--)
                cword[mid[i]].num=-100;
            k2--;
            for(int i=0;i<128;i++){//行结束，重置lie.flag1,并回溯cword.flag1
                lie[i].flag1=10;
                cword[i].flag1=pcword[i].flag1;
            } 
        }

        else {
            mid[k1]=(int)c1;//ASCII

            if(lie[mid[k1]].flag1>k1){//记同一行最小flag1
                lie[mid[k1]].flag1=k1;
                if(lie[mid[k1]].flag1>2)
                    lie[mid[k1]].flag1=2;
                }
            //——————————
            flag[mid[k1]]++;//相同元素记一次
            if(!flag[mid[k1]])//判断相同元素
            cword[mid[k1]].num++;
            else{} 
            
            if(cword[mid[k1]].flag1<k1){//记同一行最大flag1
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
//问题：相同max输出ASCII小的，而不是最短。2.同一字符串相同元素会影响？*(flag计数问题)
//问题2：只有- 在最后几行可以，影响Flag1（不影响结果）
