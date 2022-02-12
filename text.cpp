#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <iostream>
#define OK 1
#define ERROR 0
#define overflow -2
typedef int Status;

#define MaxInt 32767                  //表示极大值，即∞
#define MVNum 100                   //最大顶点数 
typedef char VertexType;              	//假设顶点的数据类型为字符型 
typedef int ArcType;                  	//假设边的权值类型为整型 
typedef struct{ 
    VertexType vexs[MVNum];            //顶点表 
    ArcType arcs[MVNum][MVNum];      	 //邻接矩阵 
    int vexnum,arcnum;                	 //图的当前点数和边数 
}AMGraph; 

struct closNode{
        VertexType  adjvex;      // 最小边在U中的顶点
        ArcType  lowcost;       // 权值最小的边的权值
} closedge[MVNum];


int LocateVex004(AMGraph G,VertexType u) {//存在则返回u在顶点表中的下标;否则返回-1 
int i; 
for(i=1;i<=G.vexnum;++i) 
if(u==G.vexs[i]) return i;
 return-1; }

Status CreateUDN004(AMGraph &G){ //采用邻接矩阵表示法，创建无向网G 
int i,j,k,w; char v1,v2;
printf("输入总顶点数，总边数 "); 
scanf("%d %d",&G.vexnum,&G.arcnum);
getchar(); 
for(i=1; i<=G.vexnum; ++i) 
{printf("请输入第%d个顶点的值:",i); 
scanf("%c",&G.vexs[i]);//依次输入点的信息 
getchar();}
for(i = 1; i<=G.vexnum;++i)//初始化邻接矩阵，边的权值均置为极大值 
for(j = 1; j<=G.vexnum;++j) G.arcs[i][j] = MaxInt;
 for(k = 1; k<=G.arcnum;++k){//构造邻接矩阵 
printf("输入第%d条边依附的顶点及权值v1 v2 w(空格隔开)",k);
scanf("%c %c %d",&v1,&v2,&w); 
getchar();
i= LocateVex004(G, v1); j = LocateVex004(G, v2); //确定v1和v2在G中的位置
G.arcs[i][j] = w; //边<v1, v2>的权值置为w 
G.arcs[j][i] = G.arcs[i][j]; //置<v1, v2>的对称边<v2, v1>的权值为w
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
{//无向网G以邻接矩阵形式存储，从顶点u出发构造G的最小生成树T，输出T的各条边
int k,j; char u0,v0;
k=LocateVex004(G,u);
//k为顶点u的下标
for (j=1;j <=G.vexnum; ++j)
//对V-U的每一个顶点Vj，初始化closedge[j]
if(j!=k)  {closedge[j].adjvex=u;closedge[j].lowcost=G.arcs[k][j];}//{adjvex， lowcost
closedge[k].lowcost=0; 
//初始，U={u}
for(int i=1;i<G. vexnum; ++i)
{//选择其余n-1个顶点,生成n-1条边(n=G. vexnum)
k=Min004(G);//k是closedge序号 
//求出T的下一个结点:第k个顶点，closedge [k]中存有当前最小边
u0=closedge[k] . adjvex;
//u0 为最小边的一个顶点， u0∈U ，
v0=G.vexs[k];
//v0为最小边的另一个顶点，v0∈V-∪
printf("(%c,%c)\n",u0,v0);
//输出当前的最小边(u0，v0)
closedge [k].lowcost=0;
//第k个顶点并入u集
for (j=1;j<=G.vexnum;++j)
if (G. arcs[k] [j]<closedge[j]. lowcost) //新顶点并入 U后重新选择最小边
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
