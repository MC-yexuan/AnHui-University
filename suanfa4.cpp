#include<fstream>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<stdlib.h>
using namespace std;

int wei[10],val[10];
int n[50],path[5],npath[50][5],n1[50];
int num,space;
ifstream in("input.txt");
ofstream out("output.txt");
typedef struct BiNode{//树的定义
    int weight=0;
    int value=0;
    struct BiNode *lchild,*rchild; 
    }BiNode,*BiTree;

    void CreateBiTree(BiTree &T,int ch){
        ch++;
        if(ch==num+2)  T=NULL;
        else{
            T=new BiNode;
            // T->weight=wei[];
            // T->value=val[];
            CreateBiTree(T->lchild,ch);
            CreateBiTree(T->rchild,ch);

        }
    } 

bool Constraint(int weight){
    if(weight>space) return false;
    else return true;
}

int j=0;
    void Backtrack(int t,BiTree T){//t是当前深度 1，n是树的深度 5;v是总价值
        if(t>num) {//cout<<T->value<<"  ";
        n[j]=n1[j]=T->value;
        for(int i=0;i<num;i++){
            //cout<<path[i]<<" ";
            npath[j][i]=path[i];
            }
            //cout<<endl;
            j++;
        }//输出可行解
        else{
            for(int i=0;i<=1;i++){//0代表有，1代表无
                if(i==0){
                    path[t-1]=1;//左子树
                    T->lchild->value=T->value+val[t-1];
                    T->lchild->weight=T->weight+wei[t-1];      
                }
                else{
                    path[t-1]=0;
                    T->rchild->value=T->value;//走右子树
                    T->rchild->weight=T->weight;//走右子树
                    Backtrack(t+1,T->rchild); 
                }
               
                if(Constraint(T->lchild->weight)&&i==0)
                    Backtrack(t+1,T->lchild);
                
            }
        }
    }

    int main(){
    int eof=in.eof();
    int k1=0;//计数
    int i1;char ch;int flag=0;
    while(!eof)
    {
        in >> i1;             //取出文件中的数字
        eof=in.eof();           //指向下一个
        in.get(ch);           //取字符
        if(!eof){
            
            if(!k1&&!flag)
                num=i1;

            else if(k1==1&&!flag)
                space=i1; 
            else{
              
                if(!flag){
                    val[k1-2]=i1;
                }
                else{
                    wei[k1-1]=i1;
                }
                if(ch=='\n'){
                    flag++;
                    k1=0;
                }
            }
        }  
        k1++;//计数      
    }
         BiTree T;
        CreateBiTree(T,0);
        Backtrack(1,T);
        sort(n,n+50);
        reverse(n,n+50);//逆序
        int max=n[0];
        cout<<max<<endl;
        out<<max<<endl;
        int a=-1,cmp=-1;  
        while(!cmp==0){
            a++;
            cmp=max-n1[a];  
        }
        for(int i=0;i<num;i++){
            cout<<npath[a][i]<<' ';
            out<<npath[a][i]<<' ';
        }
        return 0;
    }