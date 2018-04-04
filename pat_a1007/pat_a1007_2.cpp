#include <iostream>
#include <vector>
#include <algorithm>
using std::fill;
using std::cin;
using std::cout;
using std::endl;
using std::vector;

const int maxn=10010;
int dp[maxn];
int state[maxn];
void init(int *dp,int len,int init){
	fill(dp,dp+len,init);
	return;
}

int main(){
	init(dp,maxn,0);
	init(state,maxn,0);
	vector<int> array;
	int count;
	int temp;
	cin>>count;
	int flag=false;
	for(int i=0;i<count;++i){
		cin>>temp;
		if(temp>=0){
			flag=true;
		}
		array.push_back(temp);
	}
	if(flag==false){
		cout<<0<<" "<<*array.begin()<<" "<<*(array.end()-1)<<endl;
		return 0;
	}
	dp[0]=array[0];
	for(int i=1;i<count;++i){
		if(dp[i-1]<=0){
			dp[i]=array[i];
		}
		else{
			dp[i]=dp[i-1]+array[i];
		}		
	}
	int max=-99999999;
	int end_lo=-1;
	for(int i=0;i<count;++i){
		if(max<dp[i]){
			max=dp[i];
			end_lo=i;
		}
	}
	temp=end_lo;
	while(max!=0&&temp>=0){
		max-=array[temp--];	
	}
	cout<<dp[end_lo]<<" "<<array[temp+1]<<" "<<array[end_lo]<<endl;
	return 0;
}

