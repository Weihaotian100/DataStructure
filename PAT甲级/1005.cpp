#include<cstdio>
#include<cstring>
char array[110];
using namespace std;
char output[15][15]{"zero","one","two","three","four","five","six","seven","eight","nine"};
char array2[110];
int main(){
	scanf("%s",array);
	int len=strlen(array);
	int sum=0;
	int pos=0;
	for(int i=0;i<len;i++){
		sum+=(array[i]-'0');
	}
	while(sum/10!=0){
		array2[pos++]=sum%10;
		sum/=10;
	}
	array2[pos]=sum;
	for(int i=pos;i>=0;i--){
		printf("%s",output[array2[i]]);
		if(i!=0){
			printf(" ");
		}
	}
	return 0;
}
