#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <iostream>
#define OK 1
#define ERROR 0
#define overflow -2
typedef int Status;

#define MaxInt 32767                  //��ʾ����ֵ������
#define MVNum 100                   //��󶥵��� 
typedef char VertexType;              	//���趥�����������Ϊ�ַ��� 
typedef int ArcType;                  	//����ߵ�Ȩֵ����Ϊ���� 
typedef struct{ 
    VertexType vexs[MVNum];            //����� 
    ArcType arcs[MVNum][MVNum];      	 //�ڽӾ��� 
    int vexnum,arcnum;                	 //ͼ�ĵ�ǰ�����ͱ��� 
}AMGraph; 

struct closNode{
        VertexType  adjvex;      // ��С����U�еĶ���
        ArcType  lowcost;       // Ȩֵ��С�ıߵ�Ȩֵ
} closedge[MVNum];


int LocateVex004(AMGraph G,VertexType u) {//�����򷵻�u�ڶ�����е��±�;���򷵻�-1 
int i; 
for(i=1;i<=G.vexnum;++i) 
if(u==G.vexs[i]) return i;
 return-1; }

Status CreateUDN004(AMGraph &G){ //�����ڽӾ����ʾ��������������G 
int i,j,k,w; char v1,v2;
printf("�����ܶ��������ܱ��� "); 
scanf("%d %d",&G.vexnum,&G.arcnum);
getchar(); 
for(i=1; i<=G.vexnum; ++i) 
{printf("�������%d�������ֵ:",i); 
scanf("%c",&G.vexs[i]);//������������Ϣ 
getchar();}
for(i = 1; i<=G.vexnum;++i)//��ʼ���ڽӾ��󣬱ߵ�Ȩֵ����Ϊ����ֵ 
for(j = 1; j<=G.vexnum;++j) G.arcs[i][j] = MaxInt;
 for(k = 1; k<=G.arcnum;++k){//�����ڽӾ��� 
printf("�����%d���������Ķ��㼰Ȩֵv1 v2 w(�ո����)",k);
scanf("%c %c %d",&v1,&v2,&w); 
getchar();
i= LocateVex004(G, v1); j = LocateVex004(G, v2); //ȷ��v1��v2��G�е�λ��
G.arcs[i][j] = w; //��<v1, v2>��Ȩֵ��Ϊw 
G.arcs[j][i] = G.arcs[i][j]; //��<v1, v2>�ĶԳƱ�<v2, v1>��ȨֵΪw
 }//for 
 return OK; 
}//CreateUDN


int Min004(AMGraph G)
{
	int i;
	int min = MaxInt;
	int index = -1;
	for (i = 1; i <=G.vexnum; i++)
	{
		if (min>closedge[i].lowcost&&closedge[i].lowcost!=0)
		{
			min = closedge[i].lowcost;
			index = i;
		}
	}
	return index;
}


void MiniSpanTree_Prim004 (AMGraph G, VertexType u)
{//������G���ڽӾ�����ʽ�洢���Ӷ���u��������G����С������T�����T�ĸ�����
int k,j; char u0,v0;
k=LocateVex004(G,u);
//kΪ����u���±�
for (j=1;j <=G.vexnum; ++j)
//��V-U��ÿһ������Vj����ʼ��closedge[j]
if(j!=k)  {closedge[j].adjvex=u;closedge[j].lowcost=G.arcs[k][j];}//{adjvex�� lowcost
closedge[k].lowcost=0; 
//��ʼ��U={u}
for(int i=1;i<G. vexnum; ++i)
{//ѡ������n-1������,����n-1����(n=G. vexnum)
k=Min004(G);//k��closedge��� 
//���T����һ�����:��k�����㣬closedge [k]�д��е�ǰ��С��
u0=closedge[k] . adjvex;
//u0 Ϊ��С�ߵ�һ�����㣬 u0��U ��
v0=G.vexs[k];
//v0Ϊ��С�ߵ���һ�����㣬v0��V-��
printf("(%c,%c)\n",u0,v0);
//�����ǰ����С��(u0��v0)
closedge [k].lowcost=0;
//��k�����㲢��u��
for (j=1;j<=G.vexnum;++j)
if (G. arcs[k] [j]<closedge[j]. lowcost) //�¶��㲢�� U������ѡ����С��
{closedge[j].adjvex=G.vexs[k] ;closedge[j].lowcost=G.arcs[k][j];}
}
//for
}

int main()
{
	AMGraph G;
	CreateUDN004(G);
	MiniSpanTree_Prim004(G, '1');
	printf("\n");
    system("pause");
	return 0;
}
