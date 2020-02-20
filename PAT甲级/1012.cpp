#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
int now=0;
int Rank[1000000][4];
struct stu{
	int id;
	int grade[4]; 
}all[2020];
bool cmp(stu a,stu b){
	return a.grade[now]>b.grade[now];
}
char chara[4]={'A','C','M','E'};
int main(){
	int N,M;
	scanf("%d%d",&N,&M);
	memset(Rank,-1,sizeof(Rank));
	for(int i=0;i<N;i++){
		scanf("%d%d%d%d",&all[i].id,&all[i].grade[1],&all[i].grade[2],&all[i].grade[3]);
		all[i].grade[0]=(int)round((all[i].grade[1]+all[i].grade[2]+all[i].grade[3])/3.0);
	}
	for(now=0;now<4;now++){
		sort(all,all+N,cmp);
		Rank[all[0].id][now]=1;
		for(int i=1;i<N;i++){
			if(all[i].grade[now]==all[i-1].grade[now]){
				Rank[all[i].id][now]=Rank[all[i-1].id][now];
			}
			else{
				Rank[all[i].id][now]=i+1;
			}
		}
		
	}
	int query;
	for(int i=0;i<M;i++){
		scanf("%d",&query);
		if(Rank[query][0]==-1)
			printf("N/A\n");
		else{
			int k=0;
			for(int j=0;j<4;j++){
				if(Rank[query][k]>Rank[query][j])
					k=j;
			}
			printf("%d %c\n",Rank[query][k],chara[k]);
		}
	}
	
	return 0;
}
