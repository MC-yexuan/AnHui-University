#include <iostream>
#include <vector>
#include <algorithm> 
#include <queue>
using namespace std;

const char *name = "马崔烨暄";
const char *ID = "E01914004";

//定义进程结构体的属性
struct process
{
    char id;//进程名
    int Max[3];//最资源大需求
    int Allocation[3];//已分配资源
    int Need[3];//还需要多少资源
};

int Available[3];//剩余可用资源
queue<char> safeue;//安全队列

void BA(vector<process>& processes)//银行家算法
{

    queue<process*> MC;//队列名字为MC
    int safe=1;//系统安全标志位
    for (int i = 0; i < processes.size(); i++)
    {
        MC.push(&processes[i]);//所有进程以指针形式入队
    }

    while (!MC.empty())//队列非空
    {
        int size=MC.size();//保存当前队列大小
        
        for (int i = 0; i < size; i++)
        {   
            int flag=1;//标志位 判断进程是否可以得到资源分配
            for(int j = 0; j < 3; j++)
            {
                if(MC.front()->Need[j] > Available[j])//可分配资源不足
                {
                    flag=0;//标志位置0，表示该进程不可被分配资源
                    break;//跳出for循环
                }      
            }

            if(flag)//进程可被分配
            {
                for(int j = 0; j < 3;j++)
                {
                    Available[j] = Available[j]+processes[i].Allocation[j];//更新可分配资源
                }
                safeue.push(MC.front()->id);
                MC.pop();//队列中删除该进程
            }
            else //未被分配，重新入队
            {
                process *mid=MC.front();
                MC.pop();
                MC.push(mid);
            }
        }
        if(MC.size()==size)//没有任何进程出队,系统不安全
            {
                safe=0;
                break;
            } 
    }

    if(safe)
        {
            cout<<"安全序列为：";
            while (!safeue.empty())
            {
                cout << safeue.front() << ' ';
                safeue.pop();
            }
            cout << endl;
        }
    else
        {
            cout<<"该系统不安全"<<endl;
        }
}

void Print(vector<process>& processes)//输出函数 
{
    cout << "ID" << '\t' << " Max " << '\t' << "Allocation" << '\t' << "Need" << endl;
    for (int i = 0; i < processes.size(); i++)
    {

        cout << processes[i].id << "\t" ;
        for(int j = 0;j < 3; j++){
            cout << processes[i].Max[j] << " " ;
        }
        cout << "\t" ;
           for(int j = 0;j < 3; j++){
            cout << processes[i].Allocation[j] << " " ;
        }
        cout << "\t" ;
           for(int j = 0;j < 3; j++){
            cout <<  processes[i].Need[j] << " ";
        }
        cout << endl;
    }
    cout << endl << endl;
}


int main()
{
    //输入从input.txt获取
    freopen("input.txt", "r", stdin);
    cout << ID<<" "<<name << endl;
    int processnum;
    cout << "请输入进程的数量" << endl;
    cin >> processnum;
    cout << "请先输入可利用资源，之后依次输入一个进程的名字、已分配资源和还需资源:" << endl;
    vector<process> processes(processnum);//建立向量
    for (int i = 0; i < 3; i++)
    {
        cin >> Available[i];
    }
    
    for (int i = 0; i < processnum; i++)
    {
        cin >> processes[i].id ;
        for(int j = 0; j < 3; j++)
        {
            cin >> processes[i].Allocation[j];
        }
        for(int j = 0; j < 3; j++)
        {
            cin >> processes[i].Need[j];
            processes[i].Max[j] = processes[i].Allocation[j] + processes[i].Need[j];
        }  
    }

    cout << "银行家算法："<< endl;  
    BA(processes);
    Print(processes);
    system("Pause");
    return 0;
}

