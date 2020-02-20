#include<cstdio>
int bets[10010]={0};
int num[100010];
int main(){
	int N;
//	int mark=1;
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%d",&num[i]);
		bets[num[i]]++;
	}
	for(int i=0;i<N;i++){
		if(bets[num[i]]==1){
			printf("%d",num[i]);
			break;
		}
		if(i==N-1){
			printf("None");
		}
	}
	return 0;
}
