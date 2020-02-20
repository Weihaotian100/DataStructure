#include<cstdio>
const int max=1010;
double pol1[max]={0};
double pol2[max]={0};
double pol3[2*max]={0};
int main(){
	int k;
	int e1[10];
	int e2[10];
	for(int i=0;i<10;i++){
		e1[i]=-1;
		e2[i]=-1;
	}
	double c;
	int count=0;
	scanf("%d",&k);
	for(int i=0;i<k;i++){
		scanf("%d %lf",&e1[i],&c);
		pol1[e1[i]]=c;
	}
	scanf("%d",&k);
	for(int i=0;i<k;i++){
		scanf("%d %lf",&e2[i],&c);
		pol2[e2[i]]=c;
	}

	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			if(e1[i]!=-1&&e2[i]!=-1){
				pol3[e1[i]+e2[j]]+=pol1[e1[i]]*pol2[e2[j]];
			}

			//printf("pol3[%d+%d]+=%lf*%lf=%lf\n",e1[i],e2[j],pol1[e1[i]],pol2[e2[j]],pol3[e1[i]+e2[j]]);
		}
	}
	for(int i=0;i<=2000;i++){
		if(pol3[i]!=0)
			count++;
	}
	printf("%d",count);
	for(int i=2000;i>=0;i--){
		if(pol3[i]!=0){
			printf(" %d %0.1f",i,pol3[i]);
		}
	}
	return 0;
}
