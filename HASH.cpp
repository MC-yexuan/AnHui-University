#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <iostream>
#define OK 1
#define ERROR 0
#define overflow -2
typedef int Status;

#define m 16        //散列表的表长
typedef struct Hash{
int key;   //关键字项
int otherinfo;  //其他数据项
}HashTable [m];

int H(int key)
{
return (key%13);
} 

#define NULLKEY 0
//单元为空的标记
int SearchHash004 (HashTable HT, int key)
{//在散列表HT中查找关键字为key的元素，若查找成功，返回散列表的单元标号，否则返回-1
int H0,Hi;
H0=H(key) ;
//根据散列函数H (key)计算散列地址
if (HT [H0].key==NULLKEY) return -1;
//若单元HO为空，则所查元素不存在
else if (HT[H0].key==key) return H0;
//若单元HO中元素的关键字为key,则查找成功
else 
{
for(int i=1;i<m;++i){
Hi= (H0+i)%m;
//按照线性探测法计算下一个散列地址Hi
if (HT[Hi].key==NULLKEY) return -1; //若单元Hi为空，则所查元素不存在
else if (HT[Hi] .key=-key) return Hi;} //若单元Hi中元素的关键字为key,则查找成功
//for
return -1;}
}
//else

int CreatHash(HashTable &HT, int key)
{
int H0,Hi;
H0=H(key) ;
//根据散列函数H (key)计算散列地址
if (HT [H0].key==NULLKEY) 
HT[H0].key=key;
else 
{
for(int i=1;i<m;++i){
Hi=(H0+i)%m;
//按照线性探测法计算下一个散列地址Hi
if (HT[Hi].key==NULLKEY) HT[Hi].key=key; }
}
}

int main()
{
    int a,b; HashTable HT;
    printf("请输入十二个关键字：");
    for(int i=0;i<12;i++)
    {
        scanf("%d",&a);
        CreatHash(HT,a);
    }
    printf("输入要查找的关键字：");
    scanf("%d",&a);
    b=SearchHash004(HT,a);
    printf("位置为%d \n",b);
    
    printf("输入要查找的关键字：");
    scanf("%d",&a);
    b=SearchHash004(HT,a);
    printf("位置为%d \n",b);
    
    system("pause");
    return 0;
}
