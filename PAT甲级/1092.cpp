#include<cstdio>
#include<cstring>
char sell[1010];
char wantBuy[1010];
int array[260]={0};
int main(){
	scanf("%s%s",sell,wantBuy);
	int lenS=strlen(sell);
	int lenB=strlen(wantBuy);
	int mark=1;
	int missed=0;
	for(int i=0;i<lenS;i++){
		array[(int)sell[i]]++;
	}
	for(int i=0;i<lenB;i++){
		array[(int)wantBuy[i]]--;
	}
	for(int i=0;i<260;i++){
		if(array[i]<0){
			mark=0;
			missed+=array[i];
		}		
	}
	if(mark==1)
		printf("Yes %d",lenS-lenB);
	else{
		printf("No %d",-1*missed);
	}
	return 0;
}
