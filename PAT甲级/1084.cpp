#include<cstdio>
#include<cstring>
int array[130]={0};
void hashfun(char a[]){
	int id;
	for(int i=0;i<strlen(a);i++){
		id=(int)a[i];
		array[id]++;
	}
}
int main(){
	char a[90];
	char b[90];
	scanf("%s%s",a,b);
	hashfun(b);
	int id;
	for(int i=0;i<strlen(a);i++){
		id=(int)a[i];
	//	printf(" %d",id);
		if(array[id]==0){
			if(id>=97&&id<=97+25){
				printf("%c",(char)(id-32));
				array[id-32]=1;
			}				
			else if(id>=65&&id<=90){
				printf("%c",(char)id);
				array[id+32]=1;
			}
				
			else if(id>='0'&&id<='9')
				printf("%d",id-'0');
			else
				printf("_");
			array[id]=1;
		}
	}
	return 0;
} 
