#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

const char *name = "马崔烨暄";
const char *ID = "E01914004";

int data_[9] = {55,58,39,18,90,160,150,38,184};
int start = 100;
int move_[9];
void FCFS(int num){
    cout << "先来先服务算法：" << endl;
    float total=0;
    for(int i = 0;i < num; i++){
        if(!i){
            move_[i]=abs(start-data_[i]);
            total += move_[i];
            }
        else {
            move_[i]=abs(data_[i]-data_[i-1]);
            total += move_[i];
        }
    }
    printf("从%d号磁道开始\n",start);
    for(int i = 0;i < num; i++){
        cout << data_[i] << "\t" << move_[i] <<endl;
    }
    float ave=total/num;
    printf("平均寻道长度：%.1f\n\n",ave);
}

void SSTF(int num)
{
    vector <int> MC(num);
    int now=0;
    int mid=9999;
    int midd=0;
    int move1_[9];
    int data1_[9];
    cout << "最短寻道优先算法：" << endl;
    float total=0;
    for(int i = 0;i < num; i++){
       MC[i]=data_[i];
   } 
    for(int i = 0;i < num; i++){
        if(!i)
            now=start;//当前地点
            for(int j = 0;j < num-i; j++){
                move_[j]=abs(now-MC[j]);
                if(mid>move_[j])
                {
                    mid=move_[j];//找最短距离
                    move1_[i]=mid;
                    midd=j;
                }
               
            }
            total += mid;
            data1_[i]=now=MC[midd];
            MC.erase(MC.begin() + midd);
            mid=9999;
   }
    printf("从%d号磁道开始\n",start);
    for(int i = 0;i < num; i++){
        cout << data1_[i] << "\t" << move1_[i] <<endl;
    }
    float ave=total/num;
    printf("平均寻道长度：%.1f\n",ave);
}







int main(){
    cout << ID<<" "<<name << endl;
    int num=9;
    FCFS(num);
    SSTF(num);
    system("pause");
    return 0;
}
