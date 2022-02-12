// 给定n种物品和一背包。物品i的重量是wi，体积是bi，其价值为vi，背包的容量为c，容积为d。
// 问应如何选择装入背包中的物品，使得装入背包中物品的总价值最大？在选择装入背包的物品时，对每种物品i只有两种选择，即装入背包或不装入背包。
// 不能将物品i装入背包多次，也不能只装入部分的物品i。试设计一个解此问题的动态规划算法，并分析算法的计算复杂性。

#include<iostream>
using namespace std;
#include <algorithm>
int w[6] = {0,3,4,6,1,2};			//商品的重量
int b[6] = {0,2,1,4,1,4};           //商品的体积
int v[6] = {0,6,5,7,3,8};			//商品的价值
int n=5;                                    //商品个数
int c = 8;	int d = 7;	 			        //背包大小
int m[6][9][8] = {{ { 0 } }};			        //动态规划表 三维
int item[6];					        //最优解情况
 
void findMax() {					//动态规划
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= c; j++) {
            for(int k = 1; k <= d; k++) {
			if (j < w[i] || k < b[i])//有一个不满足就装不了 
				m[i][j][k] = m[i - 1][j][k];
			else
				m[i][j][k] = max(m[i - 1][j][k], m[i - 1][j - w[i]][k - b[i]] + v[i]);
		    }
        }
	}
}
 
void findWhat(int i, int j, int k) {				//最优解情况
	if (i > 0) {
		if (m[i][j][k] == m[i - 1][j][k]) {
			item[i] = 0;
			findWhat(i - 1, j, k);
		}
		else if ((j - w[i] >= 0) && (k - b[i] >=0 ) && (m[i][j][k] == m[i - 1][j - w[i]][k - b[i]]  + v[i])) {
			item[i] = 1;
			findWhat(i - 1, j - w[i],k - b[i]);
		}
	}
}
 
void print() {
    	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= c; j++) {
            for(int k = 1; k <= d; k++) {
                cout<< m[i][j][k]<<' ';
		    }
        cout<<endl;}
	cout<<endl;}
    cout<<m[n][c][d]<<endl;
	for (int i = 1; i <= n; i++)			//最优解输出
		cout << item[i] << ' ';
	cout << endl;
}
 
int main()
{
	findMax();//构建动态规划表
	findWhat(n, c, d);//寻找最优解
	print();//输出
    system("Pause");
	return 0;
}
