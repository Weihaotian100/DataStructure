#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
#include<iostream>
using namespace std;
vector<int> name[26*26*26*10];
int getId(string str){
	int id=0;
	for(int i=0;i<3;i++){
		id=id*26+(str[i]-'A'); 
	}
	id=id*10+(str[3]-'0');
	return id;
}
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	int count[n][k+1];
	int cNum;
	int num;
	
	for(int i=0;i<k;i++){
		scanf("%d%d",&cNum,&num);
		string str;
		for(int j=0;j<num;j++){
			cin>>str;
			int id=getId(str);
			name[id].push_back(cNum);
		}
	}
	for(int i=0;i<n;i++){
		string str;
		cin>>str;
		int id=getId(str);
		sort(name[id].begin(),name[id].end());
		cout<<str<<" "<<name[id].size();
		while(name[id].size()!=0){
			printf(" %d",*name[id].begin());
			name[id].erase(name[id].begin());
		}
		printf("\n");
	}

	
	return 0;
}
