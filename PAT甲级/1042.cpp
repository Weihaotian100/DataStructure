#include<cstdio>
char fun(int x);
int main(){
	const int N =54;
	int k;
	int start[N+1]={0};
	int next[N+1]={0};
	int end[N+1]={0};
	scanf("%d",&k);
	for(int i=1;i<N+1;i++){
		start[i]=i;
	}
	for(int i=1;i<N+1;i++){
		scanf("%d",&next[i]);
	}
	for(int i=0;i<k;i++){
		for(int j=1;j<N+1;j++){
			end[next[j]]=start[j];
		}
		for(int l=1;l<N+1;l++){
			start[l]=end[l];
		}
	}
	int count=0;
	for(int i=1;i<N+1;i++){
		if(count!=53){
			printf("%c",fun(start[i]));
			if(start[i]%13==0)
				printf("%d ",13);
			else
				printf("%d ",start[i]%13);
		}
			
		else{
			printf("%c",fun(start[i]));
			if(start[i]%13==0)
				printf("%d",13);
			else
				printf("%d",start[i]%13);
		}
		count++;
	}
	return 0;
} 
char fun(int i){
	i=i-1;
	if(i/13==0){
		return 'S';
	}
	else if(i/13==1){
		return 'H';
	}
	else if(i/13==2){
		return 'C';
	}
	else if(i/13==3){
		return 'D';
	}
	else {
		return 'J';
	}
}
