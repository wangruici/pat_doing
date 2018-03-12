#include <iostream>
#include <algorithm>
#include <vector>
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::flush;
using std::sort;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	int num;
	int temp;
	cin>>num;
	vector<int> array;
	for(int i=0;i<num;++i){
		cin>>temp;
		array.push_back(temp);

	}
	sort(array.begin(),array.end(),cmp);
	
	int i=0;
	int ans=0;
	while(ans<=num&&array[i]>i+1){
		++ans;
		++i;
	}
	printf("%d\n",ans);
}

