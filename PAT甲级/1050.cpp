#include<cstring>
#include<cstdio>
#include<iostream>
using namespace std;
char str1[10010];
char str2[10010];
int ascii[260]={0};
int main(){
	cin.getline(str1,10010,'\n');
	cin.getline(str2,10010,'\n');
//	printf("%s\n%s\n",str1,str2);
	int len1=strlen(str1);
	int len2=strlen(str2);
	for(int i=0;i<len2;i++){
		ascii[(int)str2[i]]=1;
	}
	for(int i=0;i<len1;i++){
		if(ascii[(int)str1[i]]!=1){
			printf("%c",str1[i]);
		}
	}
	return 0;
}
