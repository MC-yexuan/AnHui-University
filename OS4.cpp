#include<iostream>
#include<deque>
#include<cstdio>
#include <vector>
#define NONE -1
using namespace std;
 
const char *name = "马崔烨暄";
const char *ID = "E01914004";

 
deque<int> memoryList;//双向队列
deque<int> pageList;
 
void initMemory(int memorySize){//初始化
	for(int i=0;i<memorySize;i++){
		int temp;
		temp = NONE;
		memoryList.push_back(temp);
	}
 
}
 
void FIFO(int num){//先进先出算法
	float replace_count=0;
	int position=0;
	cout<<"\n页表      替换         内容\n";
	for(int i=0;i<pageList.size();i++){
        cout<<pageList[i]<<"         ";
		int j=0;
		for(j=0;j<memoryList.size();j++){
			if(memoryList[j]==NONE||memoryList[j]==pageList[i]){
				memoryList[j]=pageList[i];
				break;
			}
		}
		if(j==memoryList.size()){
			replace_count++;
			printf("%d被%d替换掉！  ", memoryList[position],pageList[i]);
			memoryList[position] = pageList[i];
			position = (position+1)%memoryList.size();
		}else{
		    printf("              ");
		}
		for(j=0;j<memoryList.size();j++){
            if(memoryList[j]!=NONE)
                cout<<memoryList[j]<<" ";
            else
                cout<<" ";
		}
		cout<<endl;
	}
	float lack =replace_count + memoryList.size();
 
	cout<<"\n置换率为："<<replace_count<<"/"<<num<<"="<<replace_count/num<<endl;
    cout<<"\n缺页率为："<<lack<<"/"<<num<<"="<<lack/num<<endl;
}

void BEST(int num){//最佳置换算法
	float replace_count=0;
	int position=0;
	cout<<"\n页表      替换         内容\n";
	for(int i=0;i<pageList.size();i++){
        cout<<pageList[i]<<"         ";//页表
		int j=0;
		for(j=0;j<memoryList.size();j++){
			if(memoryList[j]==NONE||memoryList[j]==pageList[i]){//不属于替换
				memoryList[j]=pageList[i];
				break;
			}
		}
		if(j==memoryList.size()){//需要替换
			replace_count++;
            int mid=0;
            vector<int> midd (memoryList.size());
            for(int m=i; m < pageList.size(); m++ ){//找最远未使用
                for(int n=0; n < memoryList.size(); n++){
                    if(memoryList[n] == pageList[m]){
                        if(!midd[n]){
                            mid=n;
                        }
                        midd[n]=1;//标志位
                    }
                }
            }
            for(int m=0 ; m< memoryList.size() ;m++){//是否有从未被使用的
                if(!midd[m]){
                mid = m;
                break;
                }
            }

			printf("%d被%d替换掉！  ", memoryList[mid],pageList[i]);
			memoryList[mid] = pageList[i];
		}else{
		    printf("              ");
		}
		for(j=0;j<memoryList.size();j++){
            if(memoryList[j]!=NONE)
                cout<<memoryList[j]<<" ";
            else
                cout<<" ";
		}
		cout<<endl;
	}
	float lack =replace_count + memoryList.size();
 
	cout<<"\n置换率为："<<replace_count<<"/"<<num<<"="<<replace_count/num<<endl;
    cout<<"\n缺页率为："<<lack<<"/"<<num<<"="<<lack/num<<endl;
}

void LRU(int num){//最近最久未使用算法
	float replace_count=0;
	int position=0;
	cout<<"\n页表      替换         内容\n";
	for(int i=0;i<pageList.size();i++){
        cout<<pageList[i]<<"         ";//页表
		int j=0;
		for(j=0;j<memoryList.size();j++){
			if(memoryList[j]==NONE||memoryList[j]==pageList[i]){//不属于替换
				memoryList[j]=pageList[i];
				break;
			}
		}
		if(j==memoryList.size()){//需要替换
			replace_count++;
            int mid=0;
            vector<int> midd (memoryList.size());
            for(int m=i; m >= 0; m-- ){//找最近最久未使用 
                for(int n=0; n < memoryList.size(); n++){
                    if(memoryList[n] == pageList[m]){
                        if(!midd[n]){
                            mid=n;
                        }
                        midd[n]=1;//标志位
                    }
                }
            }
            for(int m=0 ; m< memoryList.size() ;m++){//是否有从未被使用的
                if(!midd[m]){
                mid = m;
                break;
                }
            }

			printf("%d被%d替换掉！  ", memoryList[mid],pageList[i]);
			memoryList[mid] = pageList[i];
		}else{
		    printf("              ");
		}
		for(j=0;j<memoryList.size();j++){
            if(memoryList[j]!=NONE)
                cout<<memoryList[j]<<" ";
            else
                cout<<" ";
		}
		cout<<endl;
	}
	float lack =replace_count + memoryList.size();
 
	cout<<"\n置换率为："<<replace_count<<"/"<<num<<"="<<replace_count/num<<endl;
    cout<<"\n缺页率为："<<lack<<"/"<<num<<"="<<lack/num<<endl;
}

int main(){
	int num = 20;
	cout<<"输入流："<<endl;
	int arrayList[20] = {7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1};
	initMemory(3);
	for(int i=0;i<num;i++){
		pageList.push_back(arrayList[i]);
		cout<<pageList[i]<<" ";//输出输入流
	}
	cout<<endl;
    cout << ID<<" "<<name << endl;
    BEST(num);
	FIFO(num);
    LRU(num);
    
    system("Pause");
    return 0;
}