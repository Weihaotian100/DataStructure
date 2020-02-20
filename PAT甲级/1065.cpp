#include<cstdio>
int main(){

	int n;
	long long  a,b,c;
	long long sum;
	scanf("%d",&n);
	bool flag; 
	for(int i=0;i<n;i++){
		scanf("%lld%lld%lld",&a,&b,&c);
		sum=a+b;
		if(a>0&&b>0&&sum<0)
			flag=true;
		else if(a<0&&b<0&&sum>=0)
			flag=false;
		else if(sum>c)
			flag=true;
		else
			flag=false;
		if(flag==true)
			printf("Case #%d: true\n",i+1);
		else
			printf("Case #%d: false\n",i+1);

		
	}
	return 0;
}
