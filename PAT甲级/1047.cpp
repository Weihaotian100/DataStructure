#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
#include<iostream> 
using namespace std;
vector<string> cNum[2510];
bool cmp(string a,string b){
	return a<b;
}
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	int numC,c;//the number of course      course number
	string str;
	for(int i=0;i<n;i++){
		cin>>str;
		scanf("%d",&numC);
		for(int j=0;j<numC;j++){
			scanf("%d",&c);
			cNum[c].push_back(str);
		}
	}
	for(int i=1;i<=k;i++){
		sort(cNum[i].begin(),cNum[i].end(),cmp);
		printf("%d %d\n",i,cNum[i].size());
		for(vector<string>::iterator j=cNum[i].begin();j!=cNum[i].end();j++){
			cout<<*j<<"\n";
		}
	}
	return 0;
} 
