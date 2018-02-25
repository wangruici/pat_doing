#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using std::string;
using std::sort;
using std::cin;
using std::cout;
using std::endl;
using std::flush;

const int maxn=10010;
string str[maxn];

bool cmp(string a,string b){
	return a+b<b+a;
}

int main(){
	int count;
	cin>>count;
	for(int i=0;i<count;++i){
		cin>>str[i];
	}
	sort(str,str+count,cmp);

	string ans;
	for(int i=0;i<count;++i){
		ans+=str[i];
	}
	while(ans.size()!=0&&ans[0]=='0'){
		ans.erase(ans.begin());
	}
	if(ans.size()==0) cout<<0;
	else cout<<ans;
	return 0;
}
