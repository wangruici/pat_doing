/*
 *
 *要注意输出的项为0的情况，末尾不能有多余的空格被输出
 *很容易发生错误
 *
 *
 *
 */
#include <map>
#include <iomanip>
#include <string>
#include <iostream>
#include <algorithm>
using std::setprecision;
using std::less;
using std::map;
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::greater;
int main(){
	map<int,double,greater<int> > expon_coeff;
	
	int k;
	cin>>k;
	int expon;
	double coeff;
	while(k--){
		cin>>expon;
		cin>>coeff;
		expon_coeff[expon]+=coeff;
	}
	cin>>k;
	while(k--){
		cin>>expon;
		cin>>coeff;
		expon_coeff[expon]+=coeff;
	}
	int counter=0;
	for(auto it=expon_coeff.begin();it!=expon_coeff.end();++it){
		if(it->second==0){
			continue;
		}
		else{
			++counter;
		}
	}
	printf("%d",counter);
	for(auto &x:expon_coeff){
		if(x.second!=0){
			printf(" %d %.1lf",x.first,x.second);
		}
	}
	printf("\n");
/*
	printf("%d ",counter);
	int i=0;
	for(auto &x:expon_coeff){
		if(x.second!=0){
			++i;
			printf("%d %.1lf",x.first,x.second);
		}
		if(i!=counter){
			printf(" ");
		}
		else{
			printf("\n");
		}
	}
*/
	return 0;
}
