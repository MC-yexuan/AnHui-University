#include <iostream>
#include <vector>
#include <algorithm> 
#include <queue>
using namespace std;

const char *name = "�������";
const char *ID = "E01914004";

//������ҵ�ṹ�������
struct homework
{
    char id;//������
    int arrive;//����ʱ��
    int serve;//����ʱ��
    int lastserve;//ʣ�����ʱ��
    int begin;//��ʼִ��ʱ��
    int finish;//����ʱ��
    int turnover;//��תʱ��
    double weight;//��Ȩ��תʱ��
    int flag=1;

};



bool cmp1(const homework& A, const homework& B)//sort��������
{
    return A.arrive < B.arrive;
}


void FCFS(vector<homework>& homeworks,int time)//ʱ��Ƭ��ת�����㷨
{

    sort(homeworks.begin(), homeworks.end(), cmp1);//���ݵ���ʱ���С��������
    int curtime = 0;
    queue<homework*> MC;//��������ΪMC
    
    int index = 0;int alltime = 0;

     for (int i = 0; i < homeworks.size(); i++)//������ʱ��
    {
        alltime=alltime+homeworks[i].serve;
    }
    
    while (curtime < alltime || !MC.empty())//û�����������в�Ϊ��
    {

        while (index < homeworks.size() && homeworks[index].arrive <= curtime)//����ǰʱ�̿���ִ�еĽ��̷��������
        {
            MC.push(&homeworks[index]);
            while(MC.front()->id != homeworks[index].id) //�����Ԫ�ط��ڶ���λ��
            {
                MC.push(MC.front());
                MC.pop();
            }
            index++ ;
        }

        
        homework* curhomework = MC.front();//ȡ����ǰʱ�̶��׽���
        MC.pop();//ɾ����Ԫ��
        if(curhomework->flag)//��һ�γ���
        {
            curhomework->begin = curtime;//��ʼʱ��Ϊ��ǰʱ��
            curhomework->flag--;
        }

        if( curhomework->lastserve > time )//һ��ʱ��Ƭ������
        {
            curhomework->lastserve = curhomework->lastserve - time;//����ʣ��ʱ��
            curtime = curtime + time;//��������ʱ��
            MC.push(curhomework);//�ٴ���ջ
        }
            
        else //������һ��ʱ��Ƭ������
        {
            curhomework->finish = curtime + curhomework->lastserve;//���ʱ��=��ǰʱ��+ʣ�����ʱ��
            curtime = curtime + curhomework->lastserve;//��������ʱ��
        }

    }
        for(int index=0;index<homeworks.size();index++)
        {
            homeworks[index].turnover = homeworks[index].finish - homeworks[index].arrive;//��תʱ��
            homeworks[index].weight = (double)homeworks[index].turnover / homeworks[index].serve;//��Ȩ��תʱ��
        }

    
}



void Print(vector<homework>& homeworks)//������� 
{
    cout << "��������" << '\t' << "����ʱ��" << '\t' << "����ʱ��" << '\t' << "��ʼִ��ʱ��" << '\t' << "���ʱ��" << '\t' << "��תʱ��" << '\t' << "��Ȩ��תʱ��" << endl;
    for (int i = 0; i < homeworks.size(); i++)
    {

        cout << homeworks[i].id << "\t\t" << homeworks[i].arrive << "\t\t" << homeworks[i].serve << "\t\t" << homeworks[i].begin << "\t\t" << homeworks[i].finish << "\t\t" << homeworks[i].turnover << "\t\t" << homeworks[i].weight << endl;
    }
    cout << endl << endl;
}

int main()
{
    //�����input.txt��ȡ
    freopen("input.txt", "r", stdin);
    cout << ID<<" "<<name << endl;
    int homeworknum,time;
    cout << "��������̵�������ʱ��Ƭ��С" << endl;
    cin >> homeworknum>>time;
    cout << "��һ��������̵ĵ���ʱ��ͷ���ʱ��:" << endl;
    vector<homework> homeworks(homeworknum);//��������
    for (int i = 0; i < homeworknum; i++)
    {
        cin >> homeworks[i].id >> homeworks[i].arrive >> homeworks[i].serve;
        homeworks[i].lastserve = homeworks[i].serve;
    }

    FCFS(homeworks,time);
    cout << "ʱ��Ƭ��ת�����㷨��ʱ��Ƭ=" << time << endl;
    Print(homeworks);

    system("Pause");
    return 0;
}

