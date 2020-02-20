#include<cstdio>
struct cur{
	int galleon;
	int sickle;
	int knut;
}A,B,ans;
void init(){
	ans.galleon=ans.knut=ans.sickle=0;
}
int main(){
	init();
	scanf("%d.%d.%d %d.%d.%d",&A.galleon,&A.sickle,&A.knut,&B.galleon,&B.sickle,&B.knut);
	if(A.knut+B.knut>=29){
		ans.knut=(A.knut+B.knut)%29;
		ans.sickle++;
	}
	else{
		ans.knut=(A.knut+B.knut);
	}
	
	if(A.sickle+B.sickle>=17){
		ans.sickle+=((A.sickle+B.sickle)%17);
		ans.galleon++;
	}
	else{
		ans.sickle+=(A.sickle+B.sickle);
	}
	ans.galleon+=(A.galleon+B.galleon);
	printf("%d.%d.%d",ans.galleon,ans.sickle,ans.knut);
	return 0;
} 
