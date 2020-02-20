#include<cstdio>
//#include<algorithm>
//using namespace std;
int arr[100010];
void swap(int b){
	int temp=arr[0];
	arr[0]=arr[b];
	arr[b]=temp;
}
int main(){
	int n;
	scanf("%d",&n);
	int num;
	int left=n-1;
	int ans=0;
	for(int i=0;i<n;i++){
		scanf("%d",&num);
		arr[num]=i;
		if(num==i&&num!=0){
			left--;
			//
		}
	}
//	printf("%d\n",left);
//	for(int i=0;i<n;i++){
//		printf("%d\n",arr[i]);
//	}
	int k=1;
	while(left>0){
		if(arr[0]==0){
			while(k<n){
				if(arr[k]!=k){
					swap(k);
					ans++;
					break;
				}
				k++;
			}

			
		}
		while(arr[0]!=0){
			swap(arr[0]);
			left--;
			ans++;
		}
	}
	printf("%d",ans);
	
}
