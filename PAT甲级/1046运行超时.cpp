#include<cstdio>
const int Kn=100010;
const int Km=10010;
int arrayN[Kn]={0};
int arrayM[Km][2]={{0}};
int main(){
	int n,m;
	scanf("%d",&n);
	for(int i=1;i<n+1;i++){
		scanf("%d",&arrayN[i]);
	}
	scanf("%d",&m);
	for(int i=0;i<m;i++){
		scanf("%d",&arrayM[i][0]);
		scanf("%d",&arrayM[i][1]);
	}
	int dis=0;
	int temp=0;
	int start;
	int end;
	for(int i=0;i<m;i++){
		start=arrayM[i][0]>arrayM[i][1]?arrayM[i][1]:arrayM[i][0];
		end=arrayM[i][0]>arrayM[i][1]?arrayM[i][0]:arrayM[i][1];
		for(int j=start;j<end;j++){
			dis+=arrayN[j];
		}
		if(start!=1){
		
			for(int j=start-1;j>0;j--){
				temp+=arrayN[j];
			}
		}
		for(int j=n;j>end-1;j--){
			temp+=arrayN[j];
		}
		if(dis>temp){
			dis=temp;
		}
		printf("%d\n",dis);
		temp=0;
		dis=0;
	
	}
	
	return 0;
}
