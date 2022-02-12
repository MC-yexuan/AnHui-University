#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;



class NodeC{ //�ڵ���
    public:
        int Node[3][3];         //ÿ���ڵ���һ����ά�����ʾ
        int deep=0;                //������
        int fx=0;                  //���ۺ���
        class NodeC *parent;     //�ڵ���ȱ��ڵ�
        class NodeC *next;       //�ڵ����չ�ڵ�
};

vector<NodeC> OPEN;//����һ��NodeC���͵�����OPEN
NodeC *CLOSED = new NodeC;

int calculate (NodeC &s1) //����ڵ�Ĺ��ۺ���
{

    int gx1 = s1.deep;//gxΪ�ӳ�ʼ�ڵ㵽�ýڵ��Ѿ������Ĵ���
    int hx1 = 0;//hxΪ�ýڵ㵽��Ŀ�Ľڵ�Ľӽ��̶ȹ���ֵ
    int Nodeg[3][3] = {{1,2,3},{8,0,4},{7,6,5}};

    for(int i = 0; i < 3; i++){//������Ƿ�ʱĿ��ڵ�
        for(int j = 0; j < 3; j++){
            if(s1.Node[i][j] != Nodeg[i][j]){
                hx1 += 1;
            }
        }
    }
    s1.fx=gx1+hx1;
    return s1.fx;
}

bool cmp( NodeC &s1,  NodeC &s2){//sort������������򣬷��ع��ۺ���ֵ���Ľڵ�
    return (calculate(s1)) > (calculate(s2));
}

bool IsEqual(NodeC n1,NodeC n2){//�ж���������ǲ������
    for (int i = 0; i < 3;i++)
        for (int j = 0; j < 3;j++)
            if(n1.Node[i][j]!=n2.Node[i][j])
                return true;
    return false;
}

class A_algorithm{//A�㷨����
    public:
        A_algorithm(NodeC *S0, NodeC *Sg);        //���캯��
        int IsSg(NodeC *S) 
        {
            return IsEqual(*S,Sg);
        } // �ж��Ƿ���Ŀ��״̬
        int NextNodeC(NodeC *S);                  // ��չ���
        void algorithm();                       // A�㷨
        void PrintPath(NodeC *head);             // ��ӡ·��
        void FreeCLOSED(NodeC *CLOSED);          // �ͷ�close��
    private:

        NodeC S0;                                //��ʼ�ڵ�
        NodeC Sg;                                //Ŀ��ڵ�
        int Nextnum;                             //����չ�����
       queue<NodeC>ext;                           //��չ�ڵ����
};

A_algorithm::A_algorithm(NodeC *S0, NodeC *Sg){//���캯��
    memcpy(&this->S0.Node, &S0->Node, sizeof(int)*9);
    this->S0.parent = NULL;
    this->S0.next = NULL;
    this->S0.deep=0;
    memcpy(&this->Sg.Node, &Sg->Node, sizeof(int)*9);
    this->Sg.parent = NULL;
    this->Sg.next = NULL;
    this->Sg.deep=0;
}





int A_algorithm::NextNodeC(NodeC *S){//���ؿ���չ�ڵ�ĸ���
    Nextnum = 0;
    int posi, posj;
    for (int i = 0; i < 3; i++)
        for (int j = 0;j < 3; j++)
            if(S->Node[i][j] == 0){
                posi = i;posj = j;//��λ��S�ڵ�Ŀ�λ�ô�
                break;
             }
    if(posi > 0){//������չ
        NodeC up = *S;
        up.Node[posi][posj] = up.Node[posi-1][posj];
        up.Node[posi - 1][posj] = 0;
        up.parent = S;
        up.deep=S->deep+1;
        up.fx=calculate(up);
        ext.push(up);
        Nextnum++;
    }

    if(posi < 2){//������չ
        NodeC down = *S;
        down.Node[posi][posj] = down.Node[posi+1][posj];
        down.Node[posi + 1][posj] = 0;
        down.parent = S;
        down.deep=S->deep+1;
        down.fx=calculate(down);
        ext.push(down);
        Nextnum++;

    }
    if(posj > 0){//������չ
        NodeC left = *S;
        left.Node[posi][posj] = left.Node[posi][posj-1];
        left.Node[posi][posj - 1] = 0;
        left.parent = S;
        left.deep=S->deep+1;
        left.fx=calculate(left);
        ext.push(left);
        Nextnum++;
        
    }
    if(posj < 2){//������չ
        NodeC right = *S;
        right.Node[posi][posj] = right.Node[posi][posj+1];
        right.Node[posi][posj + 1] = 0;
        right.parent = S;
        right.deep=S->deep+1;
        right.fx=calculate(right);
        ext.push(right);
        Nextnum++;
    }


        int num=OPEN.size();
        NodeC *current = CLOSED;
        NodeC *mid;

        while (current->next!=NULL)
        {
            current=current->next;
            for(int i=0 ;i<Nextnum ;i++){
                if(!IsEqual(ext.front(),*current)){
                ext.pop();//����CLOSE��ɾ��
                Nextnum--;
                }
                else{
                NodeC mid=ext.front();//�������
                ext.pop();
                ext.push(mid);
                }
            }
        }

        while (num)
        {
            for(int i=0 ;i<Nextnum ;i++){
            if(!IsEqual(ext.front(),OPEN[num-1])){//OPEN���滻����
               if (ext.front().fx>=OPEN[num-1].fx)//��·����
               {
                   ext.pop();
                   Nextnum--;
               } 
               else{
                   OPEN[num-1]=ext.front();//��·����
               }
            }
            else{
                NodeC mid=ext.front();//������������
                ext.pop();
                ext.push(mid);
            }
          }
          num--;
        }
    return Nextnum;
}

void A_algorithm::algorithm(){
    int step = 0;
    NodeC *current = CLOSED;
    NodeC *N;
    OPEN.push_back(S0);//�ѳ�ʼ�ڵ�S0����OPEN��

    while(!OPEN.empty()){
        N = new NodeC;
        *N = OPEN[OPEN.size()-1]; OPEN.pop_back();//�Ƴ�OPEN������һ���ڵ�
        step++;
        current->next = N;//��N����CLOSED����
        current = current->next;//ָ��N
        if(IsSg(N) == 0){       //���Ŀ��ڵ�Sg=N���������ɹ�������
            cout << "step: ";
            cout << N->deep << endl << endl;
            PrintPath(N);       //��ӡ��N
            FreeCLOSED(CLOSED); //�ͷ�CLOSED��
            return;
        }
        int Nextnum = NextNodeC(N);//��չN�ڵ㣬��ȡN�ڵ�Ŀ���չ�ڵ���
        if(Nextnum == 0)//���N������չ�����
            continue;
        for(int i = 0; i < Nextnum; i++)
        {
            OPEN.push_back(ext.front());
            ext.pop();
        }
        sort(OPEN.begin(), OPEN.end(), cmp);//��OPEN��Ľڵ㰴�չ��ۺ�����ֵ���дӴ�С����ÿ��ȡ���ۺ���ֵ��С�Ľڵ㼴���е����һ���ڵ�

    }
    cout << "Failed." << endl;
    FreeCLOSED(CLOSED);
    return;
}

void A_algorithm::PrintPath(NodeC *head){
    if(head == NULL){
        return;
    }
    else{
        PrintPath(head->parent);//Ƕ��
        for(int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++) {
                if (head->Node[i][j] == 0)
                    cout << "  ";
                else
                    cout << head->Node[i][j]<<" ";
            }
            cout << endl;
        }
        cout <<endl;
    }
}

void A_algorithm::FreeCLOSED(NodeC *CLOSED){
    NodeC *current;
    while(CLOSED != NULL){
        current = CLOSED->next;
        free(CLOSED);
        CLOSED = current;
    }
}

int main() {

    NodeC S0 = {{{2, 3, 1}, {8, 0, 4}, {7, 6, 5}}, 0, NULL};//��ʼ����ʼ�ڵ�
    NodeC Sg = {{{1, 2, 3}, {8, 0, 4}, {7, 6, 5}}, 0, NULL};//��ʼ��Ŀ��ڵ�
    cout << "SearchPath: ";
    A_algorithm(&S0, &Sg).algorithm();
    system("Pause");
    return 0;
}
