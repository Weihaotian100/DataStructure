#include<cstdio>
#include<cstring>
char name[1010][15];
char password[1010][15];
int modified[1010];
int main(){
	int n,m=0;
	int pos=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%s%s",name[i],password[i]);
		int len=strlen(password[i]);
		int mark=0;
		for(int j=0;j<len;j++){
			switch(password[i][j]){
				case '1':
					password[i][j]='@';
					mark=1;
					break;
				case '0':
					password[i][j]='%';
					mark=1;
					break;
				case 'l':
					password[i][j]='L';
					mark=1;
					break;
				case 'O':
					password[i][j]='o';
					mark=1;
					break;
				default :
					//printf("error");
					break;
			}
			
		}
		if(mark==1){
			m++;
			modified[pos++]=i;	
		}
	}
	if(n==1){
		printf("There is 1 account and no account is modified");
	}
	else if(m==0){
			printf("There are %d accounts and no account is modified",n);
	}
	else{
		printf("%d\n",m);
		for(int i=0;i<pos;i++){
			printf("%s %s",name[modified[i]],password[modified[i]]);
			if(i!=pos-1){
				printf("\n");
			}
		}
	}
	return 0;
} 
