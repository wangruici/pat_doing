#include <queue>
#include <iostream>
#include <vector>
#include <algorithm>
using std::sort;
using std::vector;
using std::priority_queue;
using std::cin;
using std::cout;
using std::endl;
bool cmp(const int &a,const int &b){
	return a<b;
}

int main(){
	vector<int> array;
	int count;
	cin>>count;
	int num=0;
	int temp;
	for(int i=0;i<count;++i){
		cin>>temp;
		if(temp>0){
			array.push_back(temp);	
			++num;
		}
	}
	sort(array.begin(),array.end(),cmp);
	int ans=0;
	if(num==0){
		ans=1;
	}
	else if(array[0]!=1){
		ans=1;
	}
	else{
		for(int i=1;i<num;++i){
			if(array[i]>array[i-1]+1){
				ans=array[i-1]+1;
				break;
			}
		}
	}
	if(ans==0){
		ans=array[num-1]+1;
	}
	printf("%d\n",ans);
	return 0;
}
