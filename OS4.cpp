#include<iostream>
#include<deque>
#include<cstdio>
#include <vector>
#define NONE -1
using namespace std;
 
const char *name = "�������";
const char *ID = "E01914004";

 
deque<int> memoryList;//˫�����
deque<int> pageList;
 
void initMemory(int memorySize){//��ʼ��
	for(int i=0;i<memorySize;i++){
		int temp;
		temp = NONE;
		memoryList.push_back(temp);
	}
 
}
 
void FIFO(int num){//�Ƚ��ȳ��㷨
	float replace_count=0;
	int position=0;
	cout<<"\nҳ��      �滻         ����\n";
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
			printf("%d��%d�滻����  ", memoryList[position],pageList[i]);
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
 
	cout<<"\n�û���Ϊ��"<<replace_count<<"/"<<num<<"="<<replace_count/num<<endl;
    cout<<"\nȱҳ��Ϊ��"<<lack<<"/"<<num<<"="<<lack/num<<endl;
}

void BEST(int num){//����û��㷨
	float replace_count=0;
	int position=0;
	cout<<"\nҳ��      �滻         ����\n";
	for(int i=0;i<pageList.size();i++){
        cout<<pageList[i]<<"         ";//ҳ��
		int j=0;
		for(j=0;j<memoryList.size();j++){
			if(memoryList[j]==NONE||memoryList[j]==pageList[i]){//�������滻
				memoryList[j]=pageList[i];
				break;
			}
		}
		if(j==memoryList.size()){//��Ҫ�滻
			replace_count++;
            int mid=0;
            vector<int> midd (memoryList.size());
            for(int m=i; m < pageList.size(); m++ ){//����Զδʹ��
                for(int n=0; n < memoryList.size(); n++){
                    if(memoryList[n] == pageList[m]){
                        if(!midd[n]){
                            mid=n;
                        }
                        midd[n]=1;//��־λ
                    }
                }
            }
            for(int m=0 ; m< memoryList.size() ;m++){//�Ƿ��д�δ��ʹ�õ�
                if(!midd[m]){
                mid = m;
                break;
                }
            }

			printf("%d��%d�滻����  ", memoryList[mid],pageList[i]);
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
 
	cout<<"\n�û���Ϊ��"<<replace_count<<"/"<<num<<"="<<replace_count/num<<endl;
    cout<<"\nȱҳ��Ϊ��"<<lack<<"/"<<num<<"="<<lack/num<<endl;
}

void LRU(int num){//������δʹ���㷨
	float replace_count=0;
	int position=0;
	cout<<"\nҳ��      �滻         ����\n";
	for(int i=0;i<pageList.size();i++){
        cout<<pageList[i]<<"         ";//ҳ��
		int j=0;
		for(j=0;j<memoryList.size();j++){
			if(memoryList[j]==NONE||memoryList[j]==pageList[i]){//�������滻
				memoryList[j]=pageList[i];
				break;
			}
		}
		if(j==memoryList.size()){//��Ҫ�滻
			replace_count++;
            int mid=0;
            vector<int> midd (memoryList.size());
            for(int m=i; m >= 0; m-- ){//��������δʹ�� 
                for(int n=0; n < memoryList.size(); n++){
                    if(memoryList[n] == pageList[m]){
                        if(!midd[n]){
                            mid=n;
                        }
                        midd[n]=1;//��־λ
                    }
                }
            }
            for(int m=0 ; m< memoryList.size() ;m++){//�Ƿ��д�δ��ʹ�õ�
                if(!midd[m]){
                mid = m;
                break;
                }
            }

			printf("%d��%d�滻����  ", memoryList[mid],pageList[i]);
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
 
	cout<<"\n�û���Ϊ��"<<replace_count<<"/"<<num<<"="<<replace_count/num<<endl;
    cout<<"\nȱҳ��Ϊ��"<<lack<<"/"<<num<<"="<<lack/num<<endl;
}

int main(){
	int num = 20;
	cout<<"��������"<<endl;
	int arrayList[20] = {7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1};
	initMemory(3);
	for(int i=0;i<num;i++){
		pageList.push_back(arrayList[i]);
		cout<<pageList[i]<<" ";//���������
	}
	cout<<endl;
    cout << ID<<" "<<name << endl;
    BEST(num);
	FIFO(num);
    LRU(num);
    
    system("Pause");
    return 0;
}