#include <iostream>
#include <string>
#include <vector>
#include <set>
//指定格式化输入的库
#include <iomanip>

using std::endl;//换行并且刷新缓冲
using std::ends;//末尾插入null,刷新缓冲
using std::flush;//刷新缓冲区，不添加任何数据
using std::set;
using std::cin;
using std::cout;
using std::string;
using std::vector;
using std::greater;
//设定总的输出宽度，既包括小数点前的，又包括小数点后面的
//setprecision对直到下一个setprecision的输出都有效
//setw只对下一个输出有效
using std::setprecision;
using std::setw;
using std::setiosflags;

double poly[1000];
//由小到大排列
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
		//cout<<" "<<x<<" "<<setprecision(1)<<poly[x];
		//cout<<" "<<x<<" "<<poly[x];
		cout<<" "<<x<<" "<<setw(1)<<poly[x];
	}
	cout<<flush;
	return 0;
}