#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;



class NodeC{ //节点类
    public:
        int Node[3][3];         //每个节点用一个二维数组表示
        int deep=0;                //结点深度
        int fx=0;                  //估价函数
        class NodeC *parent;     //节点的先辈节点
        class NodeC *next;       //节点的扩展节点
};

vector<NodeC> OPEN;//生成一个NodeC类型的数组OPEN
NodeC *CLOSED = new NodeC;

int calculate (NodeC &s1) //计算节点的估价函数
{

    int gx1 = s1.deep;//gx为从初始节点到该节点已经付出的代价
    int hx1 = 0;//hx为该节点到达目的节点的接近程度估计值
    int Nodeg[3][3] = {{1,2,3},{8,0,4},{7,6,5}};

    for(int i = 0; i < 3; i++){//检查结点是否时目标节点
        for(int j = 0; j < 3; j++){
            if(s1.Node[i][j] != Nodeg[i][j]){
                hx1 += 1;
            }
        }
    }
    s1.fx=gx1+hx1;
    return s1.fx;
}

bool cmp( NodeC &s1,  NodeC &s2){//sort函数的排序规则，返回估价函数值最大的节点
    return (calculate(s1)) > (calculate(s2));
}

bool IsEqual(NodeC n1,NodeC n2){//判断两个结点是不是相等
    for (int i = 0; i < 3;i++)
        for (int j = 0; j < 3;j++)
            if(n1.Node[i][j]!=n2.Node[i][j])
                return true;
    return false;
}

class A_algorithm{//A算法搜索
    public:
        A_algorithm(NodeC *S0, NodeC *Sg);        //构造函数
        int IsSg(NodeC *S) 
        {
            return IsEqual(*S,Sg);
        } // 判断是否是目标状态
        int NextNodeC(NodeC *S);                  // 扩展结点
        void algorithm();                       // A算法
        void PrintPath(NodeC *head);             // 打印路径
        void FreeCLOSED(NodeC *CLOSED);          // 释放close表
    private:

        NodeC S0;                                //初始节点
        NodeC Sg;                                //目标节点
        int Nextnum;                             //可扩展结点数
       queue<NodeC>ext;                           //扩展节点队列
};

A_algorithm::A_algorithm(NodeC *S0, NodeC *Sg){//构造函数
    memcpy(&this->S0.Node, &S0->Node, sizeof(int)*9);
    this->S0.parent = NULL;
    this->S0.next = NULL;
    this->S0.deep=0;
    memcpy(&this->Sg.Node, &Sg->Node, sizeof(int)*9);
    this->Sg.parent = NULL;
    this->Sg.next = NULL;
    this->Sg.deep=0;
}





int A_algorithm::NextNodeC(NodeC *S){//返回可扩展节点的个数
    Nextnum = 0;
    int posi, posj;
    for (int i = 0; i < 3; i++)
        for (int j = 0;j < 3; j++)
            if(S->Node[i][j] == 0){
                posi = i;posj = j;//定位到S节点的空位置处
                break;
             }
    if(posi > 0){//向上扩展
        NodeC up = *S;
        up.Node[posi][posj] = up.Node[posi-1][posj];
        up.Node[posi - 1][posj] = 0;
        up.parent = S;
        up.deep=S->deep+1;
        up.fx=calculate(up);
        ext.push(up);
        Nextnum++;
    }

    if(posi < 2){//向下扩展
        NodeC down = *S;
        down.Node[posi][posj] = down.Node[posi+1][posj];
        down.Node[posi + 1][posj] = 0;
        down.parent = S;
        down.deep=S->deep+1;
        down.fx=calculate(down);
        ext.push(down);
        Nextnum++;

    }
    if(posj > 0){//向左扩展
        NodeC left = *S;
        left.Node[posi][posj] = left.Node[posi][posj-1];
        left.Node[posi][posj - 1] = 0;
        left.parent = S;
        left.deep=S->deep+1;
        left.fx=calculate(left);
        ext.push(left);
        Nextnum++;
        
    }
    if(posj < 2){//向右扩展
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
                ext.pop();//已在CLOSE表，删除
                Nextnum--;
                }
                else{
                NodeC mid=ext.front();//重新入队
                ext.pop();
                ext.push(mid);
                }
            }
        }

        while (num)
        {
            for(int i=0 ;i<Nextnum ;i++){
            if(!IsEqual(ext.front(),OPEN[num-1])){//OPEN表替换规则
               if (ext.front().fx>=OPEN[num-1].fx)//新路径长
               {
                   ext.pop();
                   Nextnum--;
               } 
               else{
                   OPEN[num-1]=ext.front();//新路径短
               }
            }
            else{
                NodeC mid=ext.front();//不相等重新入队
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
    OPEN.push_back(S0);//把初始节点S0放入OPEN表

    while(!OPEN.empty()){
        N = new NodeC;
        *N = OPEN[OPEN.size()-1]; OPEN.pop_back();//移出OPEN表的最后一个节点
        step++;
        current->next = N;//把N放入CLOSED表中
        current = current->next;//指向N
        if(IsSg(N) == 0){       //如果目标节点Sg=N，则搜索成功，结束
            cout << "step: ";
            cout << N->deep << endl << endl;
            PrintPath(N);       //打印出N
            FreeCLOSED(CLOSED); //释放CLOSED表
            return;
        }
        int Nextnum = NextNodeC(N);//扩展N节点，并取N节点的可扩展节点数
        if(Nextnum == 0)//如果N不可扩展则继续
            continue;
        for(int i = 0; i < Nextnum; i++)
        {
            OPEN.push_back(ext.front());
            ext.pop();
        }
        sort(OPEN.begin(), OPEN.end(), cmp);//对OPEN表的节点按照估价函数的值进行从大到小排序，每次取估价函数值最小的节点即表中的最后一个节点

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
        PrintPath(head->parent);//嵌套
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

    NodeC S0 = {{{2, 3, 1}, {8, 0, 4}, {7, 6, 5}}, 0, NULL};//初始化初始节点
    NodeC Sg = {{{1, 2, 3}, {8, 0, 4}, {7, 6, 5}}, 0, NULL};//初始化目标节点
    cout << "SearchPath: ";
    A_algorithm(&S0, &Sg).algorithm();
    system("Pause");
    return 0;
}
