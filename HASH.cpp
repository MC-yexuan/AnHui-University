#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <iostream>
#define OK 1
#define ERROR 0
#define overflow -2
typedef int Status;

#define m 16        //ɢ�б�ı�
typedef struct Hash{
int key;   //�ؼ�����
int otherinfo;  //����������
}HashTable [m];

int H(int key)
{
return (key%13);
} 

#define NULLKEY 0
//��ԪΪ�յı��
int SearchHash004 (HashTable HT, int key)
{//��ɢ�б�HT�в��ҹؼ���Ϊkey��Ԫ�أ������ҳɹ�������ɢ�б�ĵ�Ԫ��ţ����򷵻�-1
int H0,Hi;
H0=H(key) ;
//����ɢ�к���H (key)����ɢ�е�ַ
if (HT [H0].key==NULLKEY) return -1;
//����ԪHOΪ�գ�������Ԫ�ز�����
else if (HT[H0].key==key) return H0;
//����ԪHO��Ԫ�صĹؼ���Ϊkey,����ҳɹ�
else 
{
for(int i=1;i<m;++i){
Hi= (H0+i)%m;
//��������̽�ⷨ������һ��ɢ�е�ַHi
if (HT[Hi].key==NULLKEY) return -1; //����ԪHiΪ�գ�������Ԫ�ز�����
else if (HT[Hi] .key=-key) return Hi;} //����ԪHi��Ԫ�صĹؼ���Ϊkey,����ҳɹ�
//for
return -1;}
}
//else

int CreatHash(HashTable &HT, int key)
{
int H0,Hi;
H0=H(key) ;
//����ɢ�к���H (key)����ɢ�е�ַ
if (HT [H0].key==NULLKEY) 
HT[H0].key=key;
else 
{
for(int i=1;i<m;++i){
Hi=(H0+i)%m;
//��������̽�ⷨ������һ��ɢ�е�ַHi
if (HT[Hi].key==NULLKEY) HT[Hi].key=key; }
}
}

int main()
{
    int a,b; HashTable HT;
    printf("������ʮ�����ؼ��֣�");
    for(int i=0;i<12;i++)
    {
        scanf("%d",&a);
        CreatHash(HT,a);
    }
    printf("����Ҫ���ҵĹؼ��֣�");
    scanf("%d",&a);
    b=SearchHash004(HT,a);
    printf("λ��Ϊ%d \n",b);
    
    printf("����Ҫ���ҵĹؼ��֣�");
    scanf("%d",&a);
    b=SearchHash004(HT,a);
    printf("λ��Ϊ%d \n",b);
    
    system("pause");
    return 0;
}
