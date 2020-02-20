#include<cstdio>
#include<cstring>
int main(){
	char str[100];
	scanf("%s",str);
	int n=strlen(str);
	int n1,n2,n3;
	n1=n3=(n+2)/3;
	n2=n-n3-n1+2;
	for(int i=0;i<n1;i++){
		if(i!=n1-1){
			printf("%c",str[i]);
			for(int j=0;j<n2-2;j++)
				printf(" ");
			printf("%c\n",str[n-i-1]);
		}
		else{
			printf("%c",str[i]);
			for(int j=i+1;j<n-i-1;j++)
				printf("%c",str[j]);
			printf("%c\n",str[n-i-1]);			
		}

	}
	return 0;
}
