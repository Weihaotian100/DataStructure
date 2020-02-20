#include<cstdio>
#include<algorithm>
using namespace std;

	int PC[100010]={0};
//	int NC[100010]={0};
	int PP[100010]={0};
//	int NP[100010]={0};
int main(){
	int NC,NP;
	int sum=0;
//	int temp;
	scanf("%d",&NC);
	for(int i=0;i<NC;i++){
		scanf("%d",&PC[i]);
	}
	scanf("%d",&NP);
	for(int i=0;i<NC;i++){
		scanf("%d",&PP[i]);
	}
	sort(PC,PC+NC);
	sort(PP,PP+NP);

	int negC=0;
	int negP=0;
	int posC=0;
	int posP=0;
	for(int i=0;i<NC;i++){
		if(PC[i]<0){
			negC++;	
			posC++;
		}
		else if(PC[i]==0){
			posC++;
		}
		else
			break;
	}
	for(int i=0;i<NP;i++){
		if(PP[i]<0){
			negP++;
			posP++;
		}
		else if(PC[i]==0){
			posP++;
		}
		else
			break;
	}
	// -*-
	int len;
	if(negP>negC)
		len=negC;
	else
		len=negP;
	for(int i=0;i<len;i++){
		sum+=PC[i]*PP[i];
	}
	for(int i=1;(NP-i>=posP)&&(NC-i>=posC);i++){
		sum+=PC[NC-i]*PP[NP-i];
		
	}
	printf("%d\n",sum);
//	printf("%d %d",negC,posC);
//	for(int i=0;i<NC;i++){
//		printf("%d ",PC[i]);
//		if(i==NC-1)
//			printf("\n");
//	}
//	for(int i=0;i<NC;i++){
//		printf("%d ",PP[i]);
//	}
} 
