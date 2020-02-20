#include<cstdio>
#include<algorithm>
using namespace std;
struct station{
	double prise;
	double dis;
}all[510];
bool cmp(station a,station b){
	return a.dis<b.dis;
}
int main(){
	double Cmax;
	double D;
	double Davg;
	int N;
	scanf("%lf%lf%lf%d",&Cmax,&D,&Davg,&N); 
	for(int i=0;i<N;i++){
		scanf("%lf%lf",&all[i].prise,&all[i].dis);
	} 
	sort(all,all+N,cmp);
//	for(int i=0;i<N;i++){
//		printf("%0.2lf %0.2lf\n",all[i].prise,all[i].dis);
//	}
	int station=0;
	double sum=0;
	double MaxDis=Davg*Cmax;
	double Cnow=0;
	all[N].prise=0;
	all[N].dis=D;
	int isFinish=0;//0 stand for can reach the distination
	double Max=0;//Maxdistance from hangzhou
	if(all[0].dis!=0){
		isFinish=-1;
	}
	else 
	for(int i=0;i<N;i++){
		if(all[i+1].dis-all[i].dis>MaxDis){
			isFinish=1;
			Max=all[i].dis+MaxDis;
			break;
		}
	}
	if(isFinish==0)
	while(station!=N){
	int i;
	double cheapest=99999;
	int mark=-1;
	for(i=station+1;all[i].dis-all[station].dis<=MaxDis&&i<=N;i++){
		if(cheapest>all[i].prise){
			cheapest=all[i].prise;
			mark=i;
		}
		if(all[i].prise<all[station].prise){
			if(Cnow>=(all[i].dis-all[station].dis)/Davg)
				Cnow=Cnow-(all[i].dis-all[station].dis)/Davg;
			else{
				sum+=all[station].prise*((all[i].dis-all[station].dis)/Davg-Cnow);
				Cnow=0;
			}		
			station=i;
			break;
		}
	}
	if(all[i].dis-all[station].dis>MaxDis){
		sum+=all[station].prise*(Cmax-Cnow);
		Cnow=Cmax-(all[mark].dis-all[station].dis)/Davg;
		station=mark;
	}
}
	if(isFinish==0)
		printf("%0.2lf",sum);
	else
		printf("The maximum travel distance = %0.2lf",Max);
	return 0;
}
