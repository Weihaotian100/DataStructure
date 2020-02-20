#include<cstdio>
double maxNumber(double a[]);
char maxBetChar(double b[]);
int main(){
	double gameBet[3][3];
	char maxBet[3];
	double maxBetNumber[3]={0};
	for(int i=0;i<3;i++){
		scanf("%lf %lf %lf",&gameBet[i][0],&gameBet[i][1],&gameBet[i][2]);
		maxBetNumber[i]=maxNumber(gameBet[i]);
		maxBet[i]=maxBetChar(gameBet[i]);
	}
	double profit=(maxBetNumber[0]*maxBetNumber[1]*maxBetNumber[2]*0.65-1)*2;
	printf("%c %c %c %0.2lf",maxBet[0],maxBet[1],maxBet[2],profit);
	return 0;
} 
double maxNumber(double a[]){
	double max=0;
	for(int i=0;i<3;i++){
		if(max<a[i])
			max=a[i];
	}
	return max;
}
char maxBetChar(double b[]){
	//char flag;
	if(b[0]==maxNumber(b))
		return 'W';
	else if(b[1]==maxNumber(b))
		return 'T';
	else 
		return 'L';
	
}
