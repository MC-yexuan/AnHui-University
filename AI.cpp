//��ע��ȥ����ΪA*�㷨
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

class NodeC{ //�ڵ���
    public:
        int Node[3][3];         //ÿ���ڵ���һ����ά�����ʾ
        class NodeC *parent;     //�ڵ���ȱ��ڵ�
        class NodeC *next;       //�ڵ����չ�ڵ�
};

bool cmp(const NodeC &s1, const NodeC &s2){//sort������������򣬷��ع��ۺ���ֵ���Ľڵ�
    int gx1 = 0, gx2 = 0;//gxΪ�ӳ�ʼ�ڵ㵽�ýڵ��Ѿ������Ĵ���
    int hx1 = 0, hx2 = 0;//hxΪ�ýڵ㵽��Ŀ�Ľڵ�Ľӽ��̶ȹ���ֵ
    const NodeC *ptr1 = &s1;
    const NodeC *ptr2 = &s2;
    int Nodeg[3][3] = {{1,2,3},{8,0,4},{7,6,5}};
    while(ptr1 != NULL){
        gx1 += 1;
        ptr1 = ptr1->parent;
    }
    while(ptr2 != NULL){
        gx2 += 1;
        ptr2 = ptr2->parent;
    }
    for(int i = 0; i < 3; i++){//������Ƿ�ʱĿ��ڵ�
        for(int j = 0; j < 3; j++){
            if(s1.Node[i][j] != Nodeg[i][j]){
                hx1 += 1;
            }
            if(s2.Node[i][j] != Nodeg[i][j]){
                hx2 += 1;
            }
        }
    }
    return (gx1+hx1) > (gx2+hx2);
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
        NodeC ext[4];                           //��չ�ڵ�
};

A_algorithm::A_algorithm(NodeC *S0, NodeC *Sg){//���캯��
    memcpy(&this->S0.Node, &S0->Node, sizeof(int)*9);
    this->S0.parent = NULL;
    this->S0.next = NULL;
    memcpy(&this->Sg.Node, &Sg->Node, sizeof(int)*9);
    this->Sg.parent = NULL;
    this->Sg.next = NULL;
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
        ext[Nextnum] = up;
        ext[Nextnum].parent = S;
        Nextnum++;

    }
    if(posi < 2){//������չ
        NodeC down = *S;
        down.Node[posi][posj] = down.Node[posi+1][posj];
        down.Node[posi + 1][posj] = 0;
        ext[Nextnum] = down;
        ext[Nextnum].parent = S;
        Nextnum++;

    }
    if(posj > 0){//������չ
        NodeC left = *S;
        left.Node[posi][posj] = left.Node[posi][posj-1];
        left.Node[posi][posj - 1] = 0;
        ext[Nextnum] = left;
        ext[Nextnum].parent = S;
        Nextnum++;
        
    }
    if(posj < 2){//������չ
        NodeC right = *S;
        right.Node[posi][posj] = right.Node[posi][posj+1];
        right.Node[posi][posj + 1] = 0;
        ext[Nextnum] = right;
        ext[Nextnum].parent = S;
        Nextnum++;

    }
    return Nextnum;
}

void A_algorithm::algorithm(){
    int step = 0;
    vector<NodeC> OPEN;//����һ��NodeC���͵�����OPEN
    NodeC *CLOSED = new NodeC;
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
            PrintPath(N);       //��ӡ��N
            FreeCLOSED(CLOSED); //�ͷ�CLOSED��
            return;
        }
        int Nextnum = NextNodeC(N);//��չN�ڵ㣬��ȡN�ڵ�Ŀ���չ�ڵ���
        if(Nextnum == 0)//���N������չ�����
            continue;
        for(int i = 0; i < Nextnum; i++)
   
            OPEN.push_back(ext[i]);
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
        PrintPath(head->parent);
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

    NodeC S0 = {{{2, 3, 1}, {8, 0, 4}, {7, 0, 5}}, 0, NULL};//��ʼ����ʼ�ڵ�
    NodeC Sg = {{{1, 2, 3}, {8, 0, 4}, {7, 6, 5}}, 0, NULL};//��ʼ��Ŀ��ڵ�
    cout << "SearchPath: " << endl<<endl;
    A_algorithm(&S0, &Sg).algorithm();
    return 0;
}
