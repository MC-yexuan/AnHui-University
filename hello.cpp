#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <iostream>
#define OK 1
#define ERROR 0
#define overflow -2
typedef int Status;

#define MAXSIZE 100     //图书表可能达到的最大长度
typedef struct {           //图书信息定义
char no[10];            //书号
char name [50] ;         //书名
int price;               //价格
}book;

typedef struct {
book *elem;            //存储空间的基地址
int length;             //图书表中当前图书个数
}SqList;


Status InitList004(SqList &L){ //初始化 
	L.elem=new book[MAXSIZE];
	if(!L.elem) return(overflow);
	L.length=0;
	return OK;
}

Status ListInsert004(SqList &L,int i,book e) //插入元素 
{
	int j;
	if((i<1)||(i>L.length+1)) return ERROR;
	if(L.length==MAXSIZE) return ERROR;
	for(j=L.length-1;j>=i-1;j--)
	  L.elem[j+1]=L.elem[j];
	L.elem[i]=e;
	++L.length;
	return OK;
}

void input004 (SqList L){ //输出表 
    int i=1;
    while(L.length!=i-1){
    	printf("%s %s %d\n",L.elem[i].no,L.elem[i].name,L.elem[i].price);
        i++;	
	}
	printf("\n");
 }

void InsertSort004 (SqList L){//对顺序表L做直接插入排序
int i,j;
for(i-2;i<=L.length;++i)
if(L.elem[i].price>L.elem[i-1].price) //“>",需将r[i]插入有序子表
{
L.elem[0]=L.elem[i];
//将待插人的记录暂存到监视哨中
L.elem[i]=L.elem[i-1];
//r[i-1]后移
for(j=i-2; L.elem[0].price>L.elem[j].price; --j) //从后向前寻找插入位置
L.elem[j+1]=L.elem[j];
//记录逐个后移， 直到找到插人位置
L.elem [j+1]=L.elem[0];
//将r[0)即原r[1].插人到正确位置
}//if
}

int SearchBin004 (SqList L, int i)
{//在有序表ST中折半查找其关键字等于key的数据元素。若找到，则函数值为该元素在表中的位置，否则为0
int low,high,mid;
low=1;high=L.length;
//置查找区间初值
while (low<=high)
{mid= (low+high) /2;
if (i==L.elem[mid].price) return mid;
//找到待查元素
else if (i>L.elem[mid].price) high=mid-1;
//继续在前一子表进行查找
else low=mid+1;}
//继续在后一子表进行查找
//while
return 0;}
//表中不存在待查元素


int main()   //主函数 
 {
  SqList Sq;
	InitList004(Sq);
	int i,j,p;
  book a[8];
  printf("请输入书号、书名、价格（用空格分隔）\n");
  for(i=0;i>=0;i++)
  {scanf("%s %s %d",&a[i].no,&a[i].name,&a[i].price);
  if(a[i].price==0) break; 
   ListInsert004(Sq,i+1,a[i]);
  }
printf("(2)图书本数: %d\n图书信息：\n",Sq.length);
input004(Sq);

printf("(3)按照价格降序排序的图书信息：\n");
InsertSort004(Sq);
input004(Sq);  

printf("(4)折半查找\n");
for(j=0;j>=0;j++)
{scanf("%d",&p);
if(p==0) break;
i=SearchBin004(Sq,p);
if(i==0) printf("抱歉，该价格的图书不存在\n");	
else printf("%s %s %d\n",Sq.elem[i].no,Sq.elem[i].name,Sq.elem[i].price);
}

  
system("pause");
return 0;
}