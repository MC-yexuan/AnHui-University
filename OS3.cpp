#include <iostream>
#include <vector>
#include <algorithm> 
#include <queue>
using namespace std;

const char *name = "�������";
const char *ID = "E01914004";

//������̽ṹ�������
struct process
{
    char id;//������
    int Max[3];//����Դ������
    int Allocation[3];//�ѷ�����Դ
    int Need[3];//����Ҫ������Դ
};

int Available[3];//ʣ�������Դ
queue<char> safeue;//��ȫ����

void BA(vector<process>& processes)//���м��㷨
{

    queue<process*> MC;//��������ΪMC
    int safe=1;//ϵͳ��ȫ��־λ
    for (int i = 0; i < processes.size(); i++)
    {
        MC.push(&processes[i]);//���н�����ָ����ʽ���
    }

    while (!MC.empty())//���зǿ�
    {
        int size=MC.size();//���浱ǰ���д�С
        
        for (int i = 0; i < size; i++)
        {   
            int flag=1;//��־λ �жϽ����Ƿ���Եõ���Դ����
            for(int j = 0; j < 3; j++)
            {
                if(MC.front()->Need[j] > Available[j])//�ɷ�����Դ����
                {
                    flag=0;//��־λ��0����ʾ�ý��̲��ɱ�������Դ
                    break;//����forѭ��
                }      
            }

            if(flag)//���̿ɱ�����
            {
                for(int j = 0; j < 3;j++)
                {
                    Available[j] = Available[j]+processes[i].Allocation[j];//���¿ɷ�����Դ
                }
                safeue.push(MC.front()->id);
                MC.pop();//������ɾ���ý���
            }
            else //δ�����䣬�������
            {
                process *mid=MC.front();
                MC.pop();
                MC.push(mid);
            }
        }
        if(MC.size()==size)//û���κν��̳���,ϵͳ����ȫ
            {
                safe=0;
                break;
            } 
    }

    if(safe)
        {
            cout<<"��ȫ����Ϊ��";
            while (!safeue.empty())
            {
                cout << safeue.front() << ' ';
                safeue.pop();
            }
            cout << endl;
        }
    else
        {
            cout<<"��ϵͳ����ȫ"<<endl;
        }
}

void Print(vector<process>& processes)//������� 
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
    //�����input.txt��ȡ
    freopen("input.txt", "r", stdin);
    cout << ID<<" "<<name << endl;
    int processnum;
    cout << "��������̵�����" << endl;
    cin >> processnum;
    cout << "���������������Դ��֮����������һ�����̵����֡��ѷ�����Դ�ͻ�����Դ:" << endl;
    vector<process> processes(processnum);//��������
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

    cout << "���м��㷨��"<< endl;  
    BA(processes);
    Print(processes);
    system("Pause");
    return 0;
}

