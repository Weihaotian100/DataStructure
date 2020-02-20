#include<cstdio>
#include<algorithm>
using namespace std;
int coins[1010]={0};
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	int num[n];
	for(int i=0;i<n;i++){
		scanf("%d",&num[i]);
		coins[num[i]]++;
	}
	int v1=0;
	int v2=0;
	sort(num,num+n);
	for(int i=0;i<n;i++){
		int temp=m-num[i];
		coins[num[i]]--;
		if(coins[temp]>0){
			v1=num[i];
			v2=temp;
			break;
		}	
		coins[num[i]]++;
	}
	if(v1!=0&&v2!=0){
		printf("%d %d",v1,v2);
	}
	else
		printf("No Solution");
	return 0;
}
