#include<iostream>
using namespace std;
#define MAX 100001
int step[101][101];
char a[101][101];
int q1, q2, z1, z2;//��㣬�յ�
int n;
int jud(int i, int j){//�жϳ�������ϰ�
	if (i < 0 || j < 0 || i >= n || j >= n || a[i][j] == '#')
		return 0;
	return 1;
}
void bfs(int i, int j){
	int x = step[i][j];
	//�ĸ�����
    if (jud(i + 1, j)){//����
		if (x + 1 < step[i + 1][j]){
			step[i + 1][j] = x + 1;
			bfs(i + 1, j);
		}
	}
	if (jud(i, j+1)) {
		if (x + 1 < step[i][j + 1]){
			step[i][j + 1] = x + 1;
			bfs(i, j + 1);
		}
	}
	if (jud(i - 1, j)){
		if (x + 1 < step[i - 1][j]) {
			step[i - 1][j] = x + 1;
			bfs(i - 1, j);
		}
	}
	if (jud(i, j - 1)){
		if (x + 1 < step[i][j - 1]){
			step[i][j - 1] = x + 1;
			bfs(i, j - 1);
		}
	}
}
int main(){
		for (int i = 0; i < 101; i++){
			for (int j = 0; j < 101; j++)
				step[i][j] = MAX;
		}
	
		scanf("%d", &n);
		getchar();
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++)	{
				cin >> a[i][j];
				if (a[i][j] == 's') {
					q1 = i;
					q2 = j;
				}
				if (a[i][j] == 'e') {
					z1 = i;
					z2 = j;
				}
			}
		}
		step[q1][q2] = 0;
		bfs(q1, q2);
		if (step[z1][z2] == MAX)//��δ�����յ�
			printf("-1");
		else
		printf("%d", step[z1][z2]);
return 0;
}
	
	

