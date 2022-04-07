#include <iostream>
#include <time.h>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

const char *name = "马崔烨暄";
const char *ID = "E01914004";
const int MAX = 99999;
const int MIN = -99999;
//固定三种资源
//定义进程结构体的属性
struct process
{
    char id;           //进程名
    int Max[3];        //最大资源大需求
    int Allocation[3]; //已分配资源
    int Need[3];       //还需要多少资源
    int Time[3];       //占用时间
};

struct allsafeue //安全队列
{
    queue<char> safe;
    int alltime;
};
vector<allsafeue> safeues;

int Available[3]; //剩余可用资源
int time1[3];      //资源占用时间
int processnum;   //用户个数
int safeflag = 0; //系统安全标志位

int findmintime(vector<process> &processes)
{ //找到剩余最小时间
    int size = processes.size();
    int mintime = MAX;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (processes[i].Time[j] > 0 && processes[i].Time[j] < mintime)
            {
                mintime = processes[i].Time[j];
            }
        }
    }
    return mintime;
}

int findmaxtime(vector<process> &processes)
{ //找到剩余最大时间
    int size = processes.size();
    int maxtime = MIN;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (processes[i].Time[j] > maxtime)
            {
                maxtime = processes[i].Time[j];
            }
        }
    }
    return maxtime;
}

void Print(vector<process> &processes) //输出函数
{
    cout << "Available: ";
    for (int i = 0; i < 3; i++)
    {
        cout << Available[i] << " ";
    }
    cout << endl;
    cout << "Time: ";
    for (int i = 0; i < 3; i++)
    {
        cout << time1[i] << " ";
    }
    cout << endl;
    cout << "ID" << '\t' << " Max" << '\t' << "Alloc" << '\t' << "Need" << endl;
    for (int i = 0; i < processes.size(); i++)
    {

        cout << processes[i].id << "\t";
        for (int j = 0; j < 3; j++)
        {
            cout << processes[i].Max[j] << " ";
        }
        cout << "\t";
        for (int j = 0; j < 3; j++)
        {
            cout << processes[i].Allocation[j] << " ";
        }
        cout << "\t";
        for (int j = 0; j < 3; j++)
        {
            cout << processes[i].Need[j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool cmp(const allsafeue &a, const allsafeue &b) //从小到大排序
{
    if (a.alltime != b.alltime)
        return a.alltime < b.alltime;
}

void BA(vector<process> &processes, vector<process> &processes2, int Available[3], queue<char> safeue, int timeline) //银行家算法，processes是完整的
{                                                                                                                  
    int ceaseflag = 0;                                                                                               
    int size = processes2.size();
    int flag2 = 0;       //表示此时该队列是否安全
    int midAvailable[3]; //数组可视化，复制
    for (int i = 0; i < 3; i++)
    {
        midAvailable[i] = Available[i];
    }
    for (int i = 0; i < size; i++)
    {
        int flag = 1; //标志位 判断进程是否可以得到资源分配
        for (int j = 0; j < 3; j++)
        {
            if (processes2[i].Need[j] > midAvailable[j]) //可分配资源不足
            {
                flag = 0; //标志位置0，表示该进程不可被分配资源
                break;    //跳出for循环
            }
        }

        if (flag) //进程可被分配
        {
            flag2 = 1; //标志目前队列是否可分配
            int Available2[3];
            for (int j = 0; j < 3; j++)
            {
                Available2[j] = midAvailable[j] - processes2[i].Need[j]; //更新可分配资源
                int allsize = processes.size();
                for (int k = 0; k < allsize; k++)
                { //寻找相同用户名
                    if (processes[k].id == processes2[i].id)
                    {
                        processes[k].Time[j] = time1[j];
                    }
                }
            }
            safeue.push(processes2[i].id);                                    //压入安全队列
            vector<process> processes3(processes2.begin(), processes2.end()); //复制
            processes3.erase(processes3.begin() + i);                         //容器中删除该元素
            if (!processes3.empty())
            {
                BA(processes, processes3, Available2, safeue, timeline); //递归调用银行家算法
                for (int i = 0; i < safeue.size() - 1; i++)
                { // pop出最后一个元素
                    char mid = safeue.front();
                    safeue.pop();
                    safeue.push(mid);
                }
                safeue.pop();
            }
        }
    }
    if (flag2 == 0) //没有分配给任何进程,目前不安全
    {
        int mintime = findmintime(processes); //涉及到Time矩阵用processes
        int allsize = processes.size();
        if (mintime == MAX) //结束
        {
            ceaseflag = 1;
        }
        else
        {
            timeline = timeline + mintime;
            int Available3[3]; //递归准备
            for (int i = 0; i < 3; i++)
            {
                Available3[i] = midAvailable[i]; //必要初始化 下面更新是一位一位更新，
            }
            for (int i = 0; i < allsize; i++) //更新时间矩阵
            {
                for (int j = 0; j < 3; j++)
                {
                    processes[i].Time[j] = processes[i].Time[j] - mintime;
                    if (processes[i].Time[j] == 0)
                    {                                                          //等于最小时间
                        Available3[j] = midAvailable[j] + processes[i].Max[j]; //更新可用资源
                    }
                    if (processes[i].Time[j] < 0)
                    { //原本为0，复原
                        processes[i].Time[j] = 0;
                    }
                }
            }
            BA(processes, processes2, Available3, safeue, timeline); //递归调用银行家算法
        }
    }

    //此时安全性算法判断完成
    if (safeue.size() == processnum) //输出安全序列
    {
        safeflag = 1;
        int maxt = findmaxtime(processes);
        timeline = timeline + maxt;
        allsafeue midsafeue;
        midsafeue.alltime = timeline;       
        cout << "安全序列为：";
        while (!safeue.empty())
        {
            cout << safeue.front() << ' ';
            midsafeue.safe.push(safeue.front());
            safeue.pop();
        }
        cout << "time:" << timeline << endl;
        safeues.push_back(midsafeue); //存入allsafeue数组中，等待排序。
    }
}

int main()
{
    cout << ID << " " << name << endl;
    cout << "请输入进程的数量" << endl;
    srand((unsigned)time(NULL));//产生随机种子
    
    processnum = rand()%6+1;//用户数1-6
    cout << "请先输入可利用资源、对应资源占用时间，之后依次输入一个进程的名字、已分配资源和还需资源:" << endl;
    vector<process> processes(processnum); //建立向量
    for (int i = 0; i < 3; i++)
    {
        Available[i] =rand()%5+1; //可用资源1-5
    }
    for (int i = 0; i < 3; i++)
    {
        time1[i] = rand()%3+1;//占用时间1-3
    }
    for (int i = 0; i < processnum; i++)
    {
        processes[i].id = 65+i;//依次为A\B\C...
        for (int j = 0; j < 3; j++)
        {
            processes[i].Allocation[j] = rand()%5;//已分配0-4
        }
        for (int j = 0; j < 3; j++)
        {
            processes[i].Need[j] = rand()%4;//需求0-3
            processes[i].Max[j] = processes[i].Allocation[j] + processes[i].Need[j]; //计算最大矩阵
        }
        for (int j = 0; j < 3; j++) //初始化时间矩阵
        {
            processes[i].Time[j] = 0;
        }
    }
    cout << "银行家算法：" << endl;
    queue<char> safeue; //初始安全队列
    int timeline = 0;
    Print(processes);
    BA(processes, processes, Available, safeue, timeline); //使用两次processes为了保留完整时间矩阵
    if (safeflag)
    { //系统安全，排序
        int n = safeues.size();
        sort(safeues.begin(), safeues.end(), cmp);
        cout << endl;
        cout << "排序后的安全序列为：" << endl; //输出
        for (int i = 0; i < n; i++)
        {
            while (!safeues[i].safe.empty())
            {
                cout << safeues[i].safe.front() << ' ';
                safeues[i].safe.pop();
            }
            cout << "time:" << safeues[i].alltime << endl;
        }
    }
    if (!safeflag) //不安全，报错
    {
        cout << "Alarm！该系统不安全！！！" << endl;
    }
    system("pause");
    return 0;
}
