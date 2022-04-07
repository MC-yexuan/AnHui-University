#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
using namespace std;
#define RAND(X) (rand()%(X))//限制随机数范围
//可修改数据*******************
#define PATH "F:\\TSP.txt"
#define CITY	(16)//城市的个数
#define GENERATIONS	(500)//迭代次数
#define MAX	(50)
float	pm = 0.1;//变异概率
float	pc = 0.5;//交配概率
//可修改数据*******************

typedef struct _Group{//染色体的结构
	int city[CITY];//城市的顺序
	int adapt;//适应度(总距离)
	float p;//在种群中的幸存概率 
}Group;
 
 

struct city{
	int number; //无代码意义，相当于Group中的city[]值，距离通过距离矩阵查找
    //坐标
	int x;
	int y;
}; 
 

Group g_Group[MAX];//结构体数组
struct city cities[CITY];  
int bestsolution;//最优染色体
int i,j;
int cityDistance[CITY][CITY];//城市之间的距离
 
void change(int &a, int &b) // 交换ab值
{
	int c;//中间变量 
	c = a;
	a = b;
	b = c;
}

int round_double(double number) // 四舍五入
{
    return(number > 0.0) ? (number + 0.5) : (number - 0.5); 
}

void init() // 初始化
{
	srand((unsigned int)time(NULL));//使用当前时钟作为随机数种子,产生随机数
	
	FILE * fp;
	fp = fopen(PATH,"r");
	for(i = 0; i < CITY; i++){
		fscanf(fp,"%d %d %d",&cities[i].number,&cities[i].x,&cities[i].y);
		
	}
 
	//计算距离
	for(i = 0; i < CITY; i++){
		for(j = i+1; j < CITY; j++){
			cityDistance[i][j] = round_double ( sqrt((cities[i].x - cities[j].x) * (cities[i].x - cities[j].x) + 
            (cities[i].y - cities[j].y) * (cities[i].y - cities[j].y)) );
			cityDistance[j][i] = cityDistance[i][j];
		}
	}

	for(i = 0; i < CITY; i++){
		cityDistance[i][i] = 0;
	}

	printf("城市的距离矩阵如下：\n");
    for (int i = 0; i < CITY; i++)//打印距离矩阵
	{
		cout << '[' << i << ']' << '\t';
        for (int j = 0; j < CITY; j++)
		{
			if (j < i )
				printf("    ");
			else
				printf("%3d ", cityDistance[i][j]);
		}
		printf("\n");
	}

	for (int i = 0; i < MAX; i++) // 初始化样本数列
	{
		for (int j = 0; j < CITY; j++)
		{
			g_Group[i].city[j] = j+1;//按城市序号顺序排列
		}
	}

	for (int i = 0; i < MAX; i++) // 打乱顺序
	{
		for (int j = 0; j < CITY; j++)
		{
            int r;
			r = RAND(CITY);
			change(g_Group[i].city[j], g_Group[i].city[r]);//交换 
		}
	}

	printf("产生初始种群如下：\n");
	for (int i = 0; i < MAX; i++)
	{
		printf("第%d个个体:\n", i + 1);
		for (int j = 0; j < CITY; j++)
		{
			printf("%3d ", g_Group[i].city[j]);
		}
		printf("\n");
	}
}
 
void getfitness(Group &group) // 计算适应度函数
{
	int distance = 0;//总距离
	for (int i = 1; i < CITY; i++)
	{
		distance += cityDistance[group.city[i - 1]][group.city[i]];//每条染色体的路径总和
	}
	group.adapt = distance;//种群的总路径
	group.p = 1 / (float)distance;//取倒数，路径越小，概率越大
}
 
void getp() // 存活率
{
	float totalAlive = 0;
	//		选择最优部分
	for (int i = 0; i < MAX; i++) // 计算个体适应值
	{
		getfitness(g_Group[i]);
		totalAlive += g_Group->p;
	}
	for (int i = 0; i < MAX; i++) // 矫正个体存活率 让总和为1
	{
		g_Group[i].p /= totalAlive;
	}
	bestsolution = 0;//最优染色体 
	for (int i = 0; i < MAX; i++)
	{
		if (g_Group[i].p > g_Group[bestsolution].p)//若城市i的存活率高于bestsolution的 
			bestsolution = i;
	}
	printf("目前最佳个体为：%d, 其距离为%d,其轨迹如下：\n", bestsolution+1, g_Group[bestsolution].adapt);
	for (int i = 0; i < CITY; i++)//打印最佳个体 
		printf("%d ", g_Group[bestsolution].city[i]);
	printf("\n");
}

int judge(int num, int Array[CITY], int pos1, int pos2) 
// num是否在Array[]的pos1到pos2之间
{
	for (int i = pos1; i <= pos2; i++)
	{
		if (Array[i] == num)
			return i;
	}
	return -1;
}
 
void change(int s1,int s2,int pos1, int pos2) // 交叉算法
{
	int temp;
	for (int i = pos1; i <= pos2; i++)//在pos1~pos2中的城市互换 
	{
		temp = g_Group[s1].city[i];
		g_Group[s1].city[i] = g_Group[s2].city[i];//染色体s1与s2交换 
		g_Group[s2].city[i] = temp;
	}
	int pos;
	//printf("开始矫正重复值\n");
	int times = 0;
	for (int i = 0; i < CITY; i++) // 矫正重复值
	{
		times = 0;
		if (i >= pos1 && i <= pos2)//如果i到达pos1与pos2之间
		{
			i = pos2;//则直接跳转到pos2 
			
			continue;
		}
		
        //矫正s1中的重复值      
        do 
		{
			times++;  
			pos = judge(g_Group[s1].city[i], g_Group[s1].city, pos1, pos2);//pos记录下重复的位置 
			if (pos != -1)
			{
				g_Group[s1].city[i] = g_Group[s2].city[pos];//pos位置上染色体s1替换为s2 
			}
		} while (pos != -1);
		//矫正s2中的表达式
        do
		{
			pos = judge(g_Group[s2].city[i], g_Group[s2].city, pos1, pos2);//pos记录下重复的位置
			if (pos != -1)
			{
				g_Group[s2].city[i] = g_Group[s1].city[pos];//pos位置上染色体s2替换为s1 
			}
		} while (pos != -1);
	}
//	printf("交叉互换过程完毕\n");
}


void mutation(int s, int pos1,int pos2)//变异算法
{
    change(g_Group[s].city[pos1], g_Group[s].city[pos2]);	
}

void produce() // 产生下一代种群
{
	int max = 0, min = 0;	
	for (int i = 0; i < MAX; i++)
	{
		if (g_Group[i].p > g_Group[max].p)
			max = i;
		if (g_Group[i].p < g_Group[max].p)
			min = i;
	}
	g_Group[min] = g_Group[max]; // 使最大直接替换最小 （加快最优解生成）
	int sNum;
	int maxTimes = 0, nowTimes = 0;
	int canSelected[MAX]; // 可以用于交叉的个体
	bool isCanSelected[MAX];
	//选择
    for (int i = 0; i < MAX; i++)
	{
		if (i == max) // 不让最优秀的个体参与配对
			continue;
		else if ((RAND(100)) / 100.0 < pc) // 选择算子，轮盘赌
		{
			canSelected[maxTimes++] = i;
		}
	}
    //交叉
    for (int i = 0; i < maxTimes; i++)
	{
		sNum = RAND(maxTimes);//随机选择个体进行交换 
 
		change(canSelected[i], canSelected[sNum]);
	}
	int pos1, pos2;
	for (int i = 0; i < maxTimes; i+=2)
	{
		sNum = i + 1;
		if (sNum >= maxTimes)
			break;
		pos1 = RAND(CITY); // 随机选定交叉位置
		pos2 = RAND(CITY - pos1) + pos1;
		if (pos1 == pos2)//特殊情况
		{
			if (pos1 > 0)
				pos1--;
			else
				pos2++;
		}
		change(canSelected[i], canSelected[sNum], pos1, pos2);//交叉互换 
	}
	// 突变
	for (int i = 0; i < MAX; i++)
	{
		if (i == max || i == min)
		{
			continue;
		}//最优解不突变
		if (RAND(100) / 100.0 < pm) // 符合突变概率
		{
			pos1 = RAND(CITY); // 选择位置
			pos2 = RAND(CITY - pos1) + pos1;
			if (pos1 == pos2)
			{
				if (pos1 > 0)
					pos1--;
				else
					pos2++;
			}
			mutation(i, pos1, pos2);
		}
	}
}

void go()
{
	int n = 0;
	while (n < GENERATIONS) 
	{
		printf("第%d代种群\n", n + 1);
		getp();// 计算存活率
		produce();// 根据遗传规律得到下一代
		n++;
	} 
	printf("经过%d次繁衍，得到的优秀个体为:\n", n);
	printf("第%d个个体，其距离为%d,其轨迹如下：\n", bestsolution , g_Group[bestsolution].adapt);
	for (int i = 0; i < CITY; i++)
		printf("%d ", g_Group[bestsolution].city[i]);
	printf("\n");
	// printf("其他个体如下：\n");
	// for (int i = 0; i < MAX; i++)
	// {
	// 	printf("其距离为%d,其轨迹如下：\n", g_Group[i].adapt);
	// 	for (int j = 0; j < CITY; j++)
	// 	{
	// 		printf("%d ", g_Group[i].city[j]);
	// 	}
	// 	printf("\n");
	// }
}
int main()
{
	init();
	go();
    system("Pause");
	return 0;
}
