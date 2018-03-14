#include <vector>
#include <iostream>
#include <algorithm>
using std::sort;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::floor;

int main(){
	int total_num;
	cin>>total_num;
	vector<double> rope_length;
	double sum=0;
	double temp;
	for(int i=0;i<total_num;++i){
		cin>>temp;
		rope_length.push_back(temp);
	}
	sort(rope_length.begin(),rope_length.end());
	sum=rope_length[0];
	for(int i=1;i<total_num;++i){
		sum=sum/2+rope_length[i]/2;
	}
	int ans=floor(sum);
	cout<<ans<<endl;
	return 0;
}
