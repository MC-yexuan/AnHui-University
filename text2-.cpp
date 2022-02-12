
#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
int n,k;
int visited[100005];
struct step{
	int x;
	int time;//����
};
void BFS(int x){
	int i;
	queue<step>q;
	memset(visited,0,sizeof(visited));
	step s,e;
	visited[x]=1;
	s.x=x;
	s.time=0;
	q.push(s);//����
	while(!q.empty()){//���в�Ϊ��
		s=q.front();//��һ������Ԫ��
		q.pop();//����
		if(s.x==k)printf("%d\n",s.time);
		for(i=0;i<3;i++){
			int loc;
			if(i==0)          //�����ߵķ�ʽ
				loc=s.x-1;
			else if(i==1)
				loc=s.x+1;
			else loc=s.x*2;
			if(loc<0||loc>100000)continue;
			if(visited[loc])continue;
			visited[loc]=1;
			e.x=loc;
			e.time=s.time+1;
			q.push(e);
		}
	}
}
int main()
{
	while(scanf("%d %d",&n,&k)!=EOF){
		BFS(n);
	}
	return 0;
}