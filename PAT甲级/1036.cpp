#include<cstdio>
struct stu{
	char name[15];
	char id[15];
	int grade;
	char gender;
}male,female,temp;
void init(){
	male.grade=100;
	female.grade=0;
	female.gender='F';
	male.gender='M';
}
int main(){
	init();
	int n;
	int countf=0;
	int countm=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%s %c %s %d",temp.name,&temp.gender,temp.id,&temp.grade);
		if(temp.gender=='M'){
			countm++;
			if(male.grade>temp.grade){
				male=temp;
			}
		}
		if(temp.gender=='F'){
			countf++;
			if(female.grade<temp.grade){
				female=temp;
			}
		}
		
	}
//	printf("%d %d\n",countf,countm);
		if(countf==0)
			printf("Absent\n");
		else
			printf("%s %s\n",female.name,female.id);
		if(countm==0)
			printf("Absent\n");
		else
			printf("%s %s\n",male.name,male.id);
		if(countf==0||countm==0)
			printf("NA\n");
		else
			printf("%d\n",female.grade-male.grade);
			
//	}


		//}
	
	
	return 0;
} 
