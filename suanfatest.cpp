// ����n����Ʒ��һ��������Ʒi��������wi�������bi�����ֵΪvi������������Ϊc���ݻ�Ϊd��
// ��Ӧ���ѡ��װ�뱳���е���Ʒ��ʹ��װ�뱳������Ʒ���ܼ�ֵ�����ѡ��װ�뱳������Ʒʱ����ÿ����Ʒiֻ������ѡ�񣬼�װ�뱳����װ�뱳����
// ���ܽ���Ʒiװ�뱳����Σ�Ҳ����ֻװ�벿�ֵ���Ʒi�������һ���������Ķ�̬�滮�㷨���������㷨�ļ��㸴���ԡ�

#include<iostream>
using namespace std;
#include <algorithm>
int w[6] = {0,3,4,6,1,2};			//��Ʒ������
int b[6] = {0,2,1,4,1,4};           //��Ʒ�����
int v[6] = {0,6,5,7,3,8};			//��Ʒ�ļ�ֵ
int n=5;                                    //��Ʒ����
int c = 8;	int d = 7;	 			        //������С
int m[6][9][8] = {{ { 0 } }};			        //��̬�滮�� ��ά
int item[6];					        //���Ž����
 
void findMax() {					//��̬�滮
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= c; j++) {
            for(int k = 1; k <= d; k++) {
			if (j < w[i] || k < b[i])//��һ���������װ���� 
				m[i][j][k] = m[i - 1][j][k];
			else
				m[i][j][k] = max(m[i - 1][j][k], m[i - 1][j - w[i]][k - b[i]] + v[i]);
		    }
        }
	}
}
 
void findWhat(int i, int j, int k) {				//���Ž����
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
	for (int i = 1; i <= n; i++)			//���Ž����
		cout << item[i] << ' ';
	cout << endl;
}
 
int main()
{
	findMax();//������̬�滮��
	findWhat(n, c, d);//Ѱ�����Ž�
	print();//���
    system("Pause");
	return 0;
}
