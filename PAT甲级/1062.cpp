#include<cstdio>
#include<algorithm>
using namespace std;
struct man{
	int id;
	int vGrade;
	int tGrade;
}firStuf[100010],secStuf[100010],thdStuf[100010],forthStuf[100010],temp;
bool cmp(man a,man b){
	if((a.tGrade+a.vGrade)==(b.tGrade+b.vGrade)){
		if(a.vGrade==b.vGrade){
			return a.id<b.id;
		}
		else
			return a.vGrade>b.vGrade;
	}
	else
		return (a.tGrade+a.vGrade)>(b.tGrade+b.vGrade);
}
int main(){
	int N,L,H;
	int M=0;
	int p1=0;
	int p2=0;
	int p3=0;
	int p4=0;
	scanf("%d%d%d",&N,&L,&H);
	for(int i=0;i<N;i++){
		scanf("%d%d%d",&temp.id,&temp.vGrade,&temp.tGrade);
		if(temp.vGrade>=L&&temp.tGrade>=L){
			M++;
			if(temp.tGrade>=H&&temp.vGrade>=H){
				firStuf[p1++]=temp;
			}
			else if(temp.vGrade>=H){
				secStuf[p2++]=temp;
			}
			else if(temp.vGrade>=temp.tGrade){
				thdStuf[p3++]=temp;
			}
			else
				forthStuf[p4++]=temp;
		}	
	}
	sort(firStuf,firStuf+p1,cmp);
	sort(secStuf,secStuf+p2,cmp);
	sort(thdStuf,thdStuf+p3,cmp);
	sort(forthStuf,forthStuf+p4,cmp);
	printf("%d\n",M);
	for(int i=0;i<p1;i++){
		printf("%d %d %d\n",firStuf[i].id,firStuf[i].vGrade,firStuf[i].tGrade);
	}
	for(int i=0;i<p2;i++){
		printf("%d %d %d\n",secStuf[i].id,secStuf[i].vGrade,secStuf[i].tGrade);
	}
	for(int i=0;i<p3;i++){
		printf("%d %d %d\n",thdStuf[i].id,thdStuf[i].vGrade,thdStuf[i].tGrade);
	}
	for(int i=0;i<p4;i++){
		printf("%d %d %d\n",forthStuf[i].id,forthStuf[i].vGrade,forthStuf[i].tGrade);
	}
	
	return 0;
} 
