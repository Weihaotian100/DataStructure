#include<cstdio>
#include<cmath>
int main(){
	int a,b,c;
	scanf("%d%d",&a,&b);
	c=a+b;
	int array[10];
	int pos=0;
	if(c<0){
		c=-c;
		printf("-");
	}
	
	while(c/10!=0){
		array[pos++]=c%10;
		c=c/10;
	}
	array[pos]=c;
	for(int i=pos;i>=0;i--){
		printf("%d",array[i]);
		if(i%3==0&&i>0)
			printf(",");
	}
	return 0;
}
