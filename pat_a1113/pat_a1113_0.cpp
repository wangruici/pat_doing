#include <vector>
#include <iostream>
#include <algorithm>

using std::sort;
using std::cin;
using std::cout;
using std::endl;
using std::flush;
using std::vector;

bool cmp(int a,int b){
	return a>b;
}
int main(){
	int minus,sum;
	vector<int> ans;
	int counter;
	cin>>counter;
	if(counter%2==1){
		minus=1;
	}
	else{
		minus=0;
	}
	sum=0;
	int ans_count;
	if(minus){
		ans_count=counter/2+1;
	}
	else{
		ans_count=counter/2;
	}
	int temp;
	for(int i=0;i<counter;++i){
		cin>>temp;
		ans.push_back(temp);
	}
	sort(ans.begin(),ans.end(),cmp);
	for(int i=0;i<ans_count;++i){
		sum+=ans[i];
	}
	for(int i=ans_count;i<(int)ans.size();++i){
		sum-=ans[i];
	}
	cout<<minus<<" "<<sum<<endl;
	return 0;
}
