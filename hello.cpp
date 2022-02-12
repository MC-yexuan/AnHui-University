#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <iostream>
#define OK 1
#define ERROR 0
#define overflow -2
typedef int Status;

#define MAXSIZE 100     //ͼ�����ܴﵽ����󳤶�
typedef struct {           //ͼ����Ϣ����
char no[10];            //���
char name [50] ;         //����
int price;               //�۸�
}book;

typedef struct {
book *elem;            //�洢�ռ�Ļ���ַ
int length;             //ͼ����е�ǰͼ�����
}SqList;


Status InitList004(SqList &L){ //��ʼ�� 
	L.elem=new book[MAXSIZE];
	if(!L.elem) return(overflow);
	L.length=0;
	return OK;
}

Status ListInsert004(SqList &L,int i,book e) //����Ԫ�� 
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

void input004 (SqList L){ //����� 
    int i=1;
    while(L.length!=i-1){
    	printf("%s %s %d\n",L.elem[i].no,L.elem[i].name,L.elem[i].price);
        i++;	
	}
	printf("\n");
 }

void InsertSort004 (SqList L){//��˳���L��ֱ�Ӳ�������
int i,j;
for(i-2;i<=L.length;++i)
if(L.elem[i].price>L.elem[i-1].price) //��>",�轫r[i]���������ӱ�
{
L.elem[0]=L.elem[i];
//�������˵ļ�¼�ݴ浽��������
L.elem[i]=L.elem[i-1];
//r[i-1]����
for(j=i-2; L.elem[0].price>L.elem[j].price; --j) //�Ӻ���ǰѰ�Ҳ���λ��
L.elem[j+1]=L.elem[j];
//��¼������ƣ� ֱ���ҵ�����λ��
L.elem [j+1]=L.elem[0];
//��r[0)��ԭr[1].���˵���ȷλ��
}//if
}

int SearchBin004 (SqList L, int i)
{//�������ST���۰������ؼ��ֵ���key������Ԫ�ء����ҵ�������ֵΪ��Ԫ���ڱ��е�λ�ã�����Ϊ0
int low,high,mid;
low=1;high=L.length;
//�ò��������ֵ
while (low<=high)
{mid= (low+high) /2;
if (i==L.elem[mid].price) return mid;
//�ҵ�����Ԫ��
else if (i>L.elem[mid].price) high=mid-1;
//������ǰһ�ӱ���в���
else low=mid+1;}
//�����ں�һ�ӱ���в���
//while
return 0;}
//���в����ڴ���Ԫ��


int main()   //������ 
 {
  SqList Sq;
	InitList004(Sq);
	int i,j,p;
  book a[8];
  printf("��������š��������۸��ÿո�ָ���\n");
  for(i=0;i>=0;i++)
  {scanf("%s %s %d",&a[i].no,&a[i].name,&a[i].price);
  if(a[i].price==0) break; 
   ListInsert004(Sq,i+1,a[i]);
  }
printf("(2)ͼ�鱾��: %d\nͼ����Ϣ��\n",Sq.length);
input004(Sq);

printf("(3)���ռ۸��������ͼ����Ϣ��\n");
InsertSort004(Sq);
input004(Sq);  

printf("(4)�۰����\n");
for(j=0;j>=0;j++)
{scanf("%d",&p);
if(p==0) break;
i=SearchBin004(Sq,p);
if(i==0) printf("��Ǹ���ü۸��ͼ�鲻����\n");	
else printf("%s %s %d\n",Sq.elem[i].no,Sq.elem[i].name,Sq.elem[i].price);
}

  
system("pause");
return 0;
}