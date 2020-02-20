#include<cstdio>
#include<set>
using namespace std;
set<int> sets[60];
int getCommen(set<int> a,set<int> b){
	int num=0;
	set<int>::iterator itA=a.begin();
	set<int>::iterator itB=b.begin();
	for(;itA!=a.end();itA++){
		for(;itB!=b.end();itB++){
			if(*itA==*itB)
				num++;
			else if(*itA>*itB);
			else
				break;
		}
	}
	return num;
}
int main(){
	int n;
	int num;
	int size[60];
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",size+i);
		for(int j=0;j<size[i];j++){
			scanf("%d",&num);
			sets[i].insert(num);
		}
	}
	for(int i=0;i<n;i++){
		set<int>::iterator it=sets[i].begin();
		for(;it!=sets[i].end();it++)
			printf("%d ",*it);
		printf("set[%d]:%d\n",i,sets[i].size());
	}
	int queryNum;
	scanf("%d",&queryNum);
//	printf("%d",queryNum);
	int set1,set2;
	for(int i=0;i<queryNum;i++){
		scanf("%d%d",&set1,&set2);
		int comm=getCommen(sets[set1-1],sets[set2-1]);
		printf("%0.1lf",comm*100.0/((sets[set1-1].size()+sets[set2-1].size()-comm)));
		printf("%\n");
		//printf("%lf",(comm/(sets[set1].size()+sets[set2].size()-comm)));
		//printf("%\n");
	}
	return 0;
}
