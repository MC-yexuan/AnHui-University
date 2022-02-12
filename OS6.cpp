#include <iostream>
#include <vector>
#include<algorithm>
#include <stdlib.h>
using namespace std;

const char *name = "马崔烨暄";
const char *ID = "E01914004";

int data_[10] = {100,55,58,39,18,90,160,150,38,184};
int start = 100;
int move_[9];
void CSCAN(int num){
    cout << "循环扫描算法：" << endl;
    sort(data_,data_+10);//排序
    float total=0;
    int flag,mid=0;
    int data1_[9];
    for(int i = 0;i < num; i++){
        if(data_[i]==start){
            mid=i;
            flag=1;
            }
        if(flag)
        {
            data1_[i-mid]=data_[i+1];
            move_[i-mid]=abs(data_[i+1]-data_[i]);
            total += move_[i-mid];
        } 
    }
     for(int i = 0;i < mid; i++){
        if(!i)
        {
            move_[num-mid+i]=abs(data_[num]-data_[0]);
            total += move_[num+i-mid]; 
            data1_[num-mid+i]=data_[0];
        }
        else{
            move_[num-mid+i]=abs(data_[i]-data_[i-1]);
            total += move_[num+i-mid];
            data1_[num-mid+i]=data_[i];
        }

    }
    printf("从%d号磁道开始\n",start);
    for(int i = 0;i < num; i++){
        cout << data1_[i] << "\t" << move_[i] <<endl;
    }
    float ave=total/num;
    printf("平均寻道长度：%.1f\n\n",ave);
}

void SCAN(int num){
    cout << "扫描算法：" << endl;
    sort(data_,data_+10);//排序
    float total=0;
    int flag=0;int mid=0;
    int data1_[9];
    int move1_[9];
    for(int i = 0;i < num; i++){
        if(data_[i]==start){
            mid=i;
            flag=1;
            }
        if(flag)
        {
            data1_[i-mid]=data_[i+1];
            move1_[i-mid]=abs(data_[i+1]-data_[i]);
            total += move_[i-mid];
        } 
    }
     for(int i = mid-1;i >= 0; i--){
        if(i==mid-1)
        {
            move1_[num-1-i]=abs(data_[num]-data_[i]);
            total += move1_[num-1-i]; 
            data1_[num-1-i]=data_[i];
        }
        else{
            move1_[num-1-i]=abs(data_[i+1]-data_[i]);
            total += move1_[num-1-i];
            data1_[num-1-i]=data_[i];
        }

    }
    printf("从%d号磁道开始\n",start);
    for(int i = 0;i < num; i++){
        cout << data1_[i] << "\t" << move1_[i] <<endl;
    }
    float ave=total/num;
    printf("平均寻道长度：%.1f\n\n",ave);
}





int main(){
    cout << ID<<" "<<name << endl;
    int num=9;
    CSCAN(num);
    SCAN(num);
    system("pause");
    return 0;
}