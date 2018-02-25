#include <iostream>
#include <set>
#include <iomanip>

using std::flush;
using std::set;
using std::cin;
using std::cout;
using std::greater;
using std::setw;

double poly[1000];
set<int,greater<int>> mst;
int main(){
	int k,n;
	double c;
	cin>>k;
	while(k--){
		cin>>n>>c;
		poly[n]+=c;
		mst.insert(n);
	}
	cin>>k;
	while(k--){
		cin>>n>>c;
		poly[n]+=c;
		if(poly[n]==0){
			mst.erase(n);
		}
		else{
			mst.insert(n);
		}
	}
	cout<<mst.size();
	for(auto x:mst){
		cout<<" "<<x<<" "<<setw(1)<<poly[x];
	}
	cout<<flush;
	return 0;
}