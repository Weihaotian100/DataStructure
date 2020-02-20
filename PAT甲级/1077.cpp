#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
char line[110][270];
int len[110];
int main(){
	int n;
	scanf("%d",&n);
	getchar();
	int minlen=99999; 
	for(int i=0;i<n;i++){
		cin.getline(line[i],256);
		len[i]=strlen(line[i])-1;
		if(minlen>len[i])
			minlen=len[i];
	//	printf("%s %d\n",line[i],i);
	}
	int j=0;
	for(;j<=minlen;j++){
		int mark=0;
		for(int i=0;i<n;i++){
			if(line[i][len[i]-j]==line[0][len[0]-j]){
				mark++;
			}
		}
	//	printf("%d\n",mark);
		if(mark!=n){
			//printf("%d\n",mark);
			break;
		}
	}
	if(j==0){
		printf("nai");
	}
	else{
	//	printf("%d",j);
		for(j=j-1;j>=0;j--){
			printf("%c",line[0][len[0]-j]);
		}
	}

	
	return 0;
}
