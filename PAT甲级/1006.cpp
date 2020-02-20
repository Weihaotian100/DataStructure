#include<cstdio>

struct Time{
	char id[16];
	int hh;
	int mm;
	int ss;
}eTime,lTime,time;
bool moreThan(Time a,Time b);
bool lessThan(Time a,Time b);
void init(){
	eTime.hh=24;
	eTime.mm=eTime.ss=60;
	lTime.hh=lTime.mm=lTime.ss=0;
	
}
bool moreThan(Time a,Time b){
	if(a.hh!=b.hh)	return a.hh>b.hh;
	else if(a.mm!=b.mm)	return a.mm>b.mm;
	else return a.ss>=b.ss;
	
}
bool lessThan(Time a,Time b){
	if(a.hh!=b.hh)	return a.hh<b.hh;
	else if(a.mm!=b.mm)	return a.mm<b.mm;
	else return a.ss<=b.ss;
	printf("lessThan");	
}
int main(){
	int n;
	init();
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%s %d:%d:%d",time.id,&time.hh,&time.mm,&time.ss);
		if(moreThan(eTime,time)){
			eTime=time;
		}
		scanf("%d:%d:%d",&time.hh,&time.mm,&time.ss);

		if(lessThan(lTime,time)){
			lTime=time;
		}
		
	}
		printf("%s %s\n",eTime.id,lTime.id);
	return 0;
}
