#include <iostream>
#include <time.h>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

const char *name = "�������";
const char *ID = "E01914004";
const int MAX = 99999;
const int MIN = -99999;
//�̶�������Դ
//������̽ṹ�������
struct process
{
    char id;           //������
    int Max[3];        //�����Դ������
    int Allocation[3]; //�ѷ�����Դ
    int Need[3];       //����Ҫ������Դ
    int Time[3];       //ռ��ʱ��
};

struct allsafeue //��ȫ����
{
    queue<char> safe;
    int alltime;
};
vector<allsafeue> safeues;

int Available[3]; //ʣ�������Դ
int time1[3];      //��Դռ��ʱ��
int processnum;   //�û�����
int safeflag = 0; //ϵͳ��ȫ��־λ

int findmintime(vector<process> &processes)
{ //�ҵ�ʣ����Сʱ��
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
{ //�ҵ�ʣ�����ʱ��
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

void Print(vector<process> &processes) //�������
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

bool cmp(const allsafeue &a, const allsafeue &b) //��С��������
{
    if (a.alltime != b.alltime)
        return a.alltime < b.alltime;
}

void BA(vector<process> &processes, vector<process> &processes2, int Available[3], queue<char> safeue, int timeline) //���м��㷨��processes��������
{                                                                                                                  
    int ceaseflag = 0;                                                                                               
    int size = processes2.size();
    int flag2 = 0;       //��ʾ��ʱ�ö����Ƿ�ȫ
    int midAvailable[3]; //������ӻ�������
    for (int i = 0; i < 3; i++)
    {
        midAvailable[i] = Available[i];
    }
    for (int i = 0; i < size; i++)
    {
        int flag = 1; //��־λ �жϽ����Ƿ���Եõ���Դ����
        for (int j = 0; j < 3; j++)
        {
            if (processes2[i].Need[j] > midAvailable[j]) //�ɷ�����Դ����
            {
                flag = 0; //��־λ��0����ʾ�ý��̲��ɱ�������Դ
                break;    //����forѭ��
            }
        }

        if (flag) //���̿ɱ�����
        {
            flag2 = 1; //��־Ŀǰ�����Ƿ�ɷ���
            int Available2[3];
            for (int j = 0; j < 3; j++)
            {
                Available2[j] = midAvailable[j] - processes2[i].Need[j]; //���¿ɷ�����Դ
                int allsize = processes.size();
                for (int k = 0; k < allsize; k++)
                { //Ѱ����ͬ�û���
                    if (processes[k].id == processes2[i].id)
                    {
                        processes[k].Time[j] = time1[j];
                    }
                }
            }
            safeue.push(processes2[i].id);                                    //ѹ�밲ȫ����
            vector<process> processes3(processes2.begin(), processes2.end()); //����
            processes3.erase(processes3.begin() + i);                         //������ɾ����Ԫ��
            if (!processes3.empty())
            {
                BA(processes, processes3, Available2, safeue, timeline); //�ݹ�������м��㷨
                for (int i = 0; i < safeue.size() - 1; i++)
                { // pop�����һ��Ԫ��
                    char mid = safeue.front();
                    safeue.pop();
                    safeue.push(mid);
                }
                safeue.pop();
            }
        }
    }
    if (flag2 == 0) //û�з�����κν���,Ŀǰ����ȫ
    {
        int mintime = findmintime(processes); //�漰��Time������processes
        int allsize = processes.size();
        if (mintime == MAX) //����
        {
            ceaseflag = 1;
        }
        else
        {
            timeline = timeline + mintime;
            int Available3[3]; //�ݹ�׼��
            for (int i = 0; i < 3; i++)
            {
                Available3[i] = midAvailable[i]; //��Ҫ��ʼ�� ���������һλһλ���£�
            }
            for (int i = 0; i < allsize; i++) //����ʱ�����
            {
                for (int j = 0; j < 3; j++)
                {
                    processes[i].Time[j] = processes[i].Time[j] - mintime;
                    if (processes[i].Time[j] == 0)
                    {                                                          //������Сʱ��
                        Available3[j] = midAvailable[j] + processes[i].Max[j]; //���¿�����Դ
                    }
                    if (processes[i].Time[j] < 0)
                    { //ԭ��Ϊ0����ԭ
                        processes[i].Time[j] = 0;
                    }
                }
            }
            BA(processes, processes2, Available3, safeue, timeline); //�ݹ�������м��㷨
        }
    }

    //��ʱ��ȫ���㷨�ж����
    if (safeue.size() == processnum) //�����ȫ����
    {
        safeflag = 1;
        int maxt = findmaxtime(processes);
        timeline = timeline + maxt;
        allsafeue midsafeue;
        midsafeue.alltime = timeline;       
        cout << "��ȫ����Ϊ��";
        while (!safeue.empty())
        {
            cout << safeue.front() << ' ';
            midsafeue.safe.push(safeue.front());
            safeue.pop();
        }
        cout << "time:" << timeline << endl;
        safeues.push_back(midsafeue); //����allsafeue�����У��ȴ�����
    }
}

int main()
{
    cout << ID << " " << name << endl;
    cout << "��������̵�����" << endl;
    srand((unsigned)time(NULL));//�����������
    
    processnum = rand()%6+1;//�û���1-6
    cout << "���������������Դ����Ӧ��Դռ��ʱ�䣬֮����������һ�����̵����֡��ѷ�����Դ�ͻ�����Դ:" << endl;
    vector<process> processes(processnum); //��������
    for (int i = 0; i < 3; i++)
    {
        Available[i] =rand()%5+1; //������Դ1-5
    }
    for (int i = 0; i < 3; i++)
    {
        time1[i] = rand()%3+1;//ռ��ʱ��1-3
    }
    for (int i = 0; i < processnum; i++)
    {
        processes[i].id = 65+i;//����ΪA\B\C...
        for (int j = 0; j < 3; j++)
        {
            processes[i].Allocation[j] = rand()%5;//�ѷ���0-4
        }
        for (int j = 0; j < 3; j++)
        {
            processes[i].Need[j] = rand()%4;//����0-3
            processes[i].Max[j] = processes[i].Allocation[j] + processes[i].Need[j]; //����������
        }
        for (int j = 0; j < 3; j++) //��ʼ��ʱ�����
        {
            processes[i].Time[j] = 0;
        }
    }
    cout << "���м��㷨��" << endl;
    queue<char> safeue; //��ʼ��ȫ����
    int timeline = 0;
    Print(processes);
    BA(processes, processes, Available, safeue, timeline); //ʹ������processesΪ�˱�������ʱ�����
    if (safeflag)
    { //ϵͳ��ȫ������
        int n = safeues.size();
        sort(safeues.begin(), safeues.end(), cmp);
        cout << endl;
        cout << "�����İ�ȫ����Ϊ��" << endl; //���
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
    if (!safeflag) //����ȫ������
    {
        cout << "Alarm����ϵͳ����ȫ������" << endl;
    }
    system("pause");
    return 0;
}
