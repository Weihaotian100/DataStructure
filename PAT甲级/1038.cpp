#include<cstdio>
#include<algorithm>
#include<iostream>
#include<string>
using namespace std;
bool cmp(string a,string b){
	return a+b<b+a;
}
int main(){
	int n;
	scanf("%d",&n);
	string str[n];

	for(int i=0;i<n;i++){
		cin>>str[i];
	}
	string ans;
	sort(str,str+n,cmp);
	for(int i=0;i<n;i++){
		ans+=str[i];
	}
	while(ans.size()!=0&&*ans.begin()=='0'){
		ans.erase(ans.begin());
	}
	if(ans.size()==0)
		printf("0");
	else
		cout<<ans;
	return 0;
} 
