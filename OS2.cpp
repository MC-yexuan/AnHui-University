#include <iostream>
#include <vector>
#include <algorithm> 
#include <queue>
using namespace std;

const char *name = "马崔烨暄";
const char *ID = "E01914004";

//定义作业结构体的属性
struct homework
{
    char id;//进程名
    int arrive;//到达时间
    int serve;//服务时间
    int lastserve;//剩余服务时间
    int begin;//开始执行时间
    int finish;//结束时间
    int turnover;//周转时间
    double weight;//带权周转时间
    int flag=1;

};



bool cmp1(const homework& A, const homework& B)//sort函数排序
{
    return A.arrive < B.arrive;
}


void FCFS(vector<homework>& homeworks,int time)//时间片轮转调度算法
{

    sort(homeworks.begin(), homeworks.end(), cmp1);//根据到达时间从小到大排序
    int curtime = 0;
    queue<homework*> MC;//队列名字为MC
    
    int index = 0;int alltime = 0;

     for (int i = 0; i < homeworks.size(); i++)//计算总时刻
    {
        alltime=alltime+homeworks[i].serve;
    }
    
    while (curtime < alltime || !MC.empty())//没有运行完或队列不为空
    {

        while (index < homeworks.size() && homeworks[index].arrive <= curtime)//将当前时刻可以执行的进程放入队列中
        {
            MC.push(&homeworks[index]);
            while(MC.front()->id != homeworks[index].id) //将入队元素放在队首位置
            {
                MC.push(MC.front());
                MC.pop();
            }
            index++ ;
        }

        
        homework* curhomework = MC.front();//取出当前时刻队首进程
        MC.pop();//删除该元素
        if(curhomework->flag)//第一次出队
        {
            curhomework->begin = curtime;//开始时间为当前时间
            curhomework->flag--;
        }

        if( curhomework->lastserve > time )//一个时间片不够用
        {
            curhomework->lastserve = curhomework->lastserve - time;//更新剩余时间
            curtime = curtime + time;//更新现在时刻
            MC.push(curhomework);//再次入栈
        }
            
        else //可以在一个时间片服务完
        {
            curhomework->finish = curtime + curhomework->lastserve;//完成时间=当前时间+剩余服务时间
            curtime = curtime + curhomework->lastserve;//更新现在时刻
        }

    }
        for(int index=0;index<homeworks.size();index++)
        {
            homeworks[index].turnover = homeworks[index].finish - homeworks[index].arrive;//周转时间
            homeworks[index].weight = (double)homeworks[index].turnover / homeworks[index].serve;//带权周转时间
        }

    
}



void Print(vector<homework>& homeworks)//输出函数 
{
    cout << "进程名称" << '\t' << "到达时间" << '\t' << "服务时间" << '\t' << "开始执行时间" << '\t' << "完成时间" << '\t' << "周转时间" << '\t' << "带权周转时间" << endl;
    for (int i = 0; i < homeworks.size(); i++)
    {

        cout << homeworks[i].id << "\t\t" << homeworks[i].arrive << "\t\t" << homeworks[i].serve << "\t\t" << homeworks[i].begin << "\t\t" << homeworks[i].finish << "\t\t" << homeworks[i].turnover << "\t\t" << homeworks[i].weight << endl;
    }
    cout << endl << endl;
}

int main()
{
    //输入从input.txt获取
    freopen("input.txt", "r", stdin);
    cout << ID<<" "<<name << endl;
    int homeworknum,time;
    cout << "请输入进程的数量、时间片大小" << endl;
    cin >> homeworknum>>time;
    cout << "请一次输入进程的到来时间和服务时间:" << endl;
    vector<homework> homeworks(homeworknum);//建立向量
    for (int i = 0; i < homeworknum; i++)
    {
        cin >> homeworks[i].id >> homeworks[i].arrive >> homeworks[i].serve;
        homeworks[i].lastserve = homeworks[i].serve;
    }

    FCFS(homeworks,time);
    cout << "时间片轮转调度算法：时间片=" << time << endl;
    Print(homeworks);

    system("Pause");
    return 0;
}

