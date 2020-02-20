//#include<cstdio>
//int main(){
//	int r,g,b;
//	int mr,mg,mb;
//	int arrayR[2]={0};
//	int arrayG[2]={0};
//	int arrayB[2]={0};
//	int i=0;
//	int j=0;
//	int k=0;
//	scanf("%d%d%d",&r,&g,&b);
//	while(r/13!=0){
//		arrayR[i]=r%13;
//		r=r/13;
//		i++;
//	}
//	arrayR[i]=r;
////	printf("%d%d ",arrayR[1],arrayR[0]);
//	while(g/13!=0){
//		arrayG[j]=g%13;
//		g=g/13;
//		j++;
//	}
//	arrayG[j]=g;
////	printf("%d%d ",arrayG[1],arrayG[0]);
//	while(b/13!=0){
//		arrayB[k]=b%13;
//		b=b/13;
//		k++;
//	}
//	arrayB[k]=b;
//	
////	printf("%d%d ",arrayB[1],arrayB[0]);
//	printf("#");
//
//	for(int m=0;m<2;m++){
//		if(arrayR[1-m]==12)
//			printf("C");
//		else if(arrayR[1-m]==11)
//			printf("B");
//		else if(arrayR[1-m]==10)
//			printf("A");
//		else
//			printf("%d",arrayR[1-m]);
//		}
//	
//	for(int m=0;m<2;m++){
//		if(arrayG[1-m]==12)
//			printf("C");
//		else if(arrayG[1-m]==11)
//			printf("B");
//		else if(arrayG[1-m]==10)
//			printf("A");
//		else
//			printf("%d",arrayG[1-m]);
//		}	
//	
//	for(int m=0;m<2;m++){
//		if(arrayB[1-m]==12)
//			printf("C");
//		else if(arrayB[1-m]==11)
//			printf("B");
//		else if(arrayB[1-m]==10)
//			printf("A");
//		else
//			printf("%d",arrayB[1-m]);
//		}
//
////	printf("%d%d%d%d%d%d",arrayR[1],arrayR[0],arrayG[1],arrayG[0],arrayB[1],arrayB[0]);
//	return 0;
//}
#include<cstdio>
char a[14]={'0','1','2','3','4','5','6','7','8','9','A','B','C'};
int main(){
	int r,g,b;
	scanf("%d%d%d",&r,&g,&b);
	printf("#");
	printf("%c%c",a[r/13],a[r%13]);
	printf("%c%c",a[g/13],a[g%13]);
	printf("%c%c",a[b/13],a[b%13]);
	return 0;
} 
