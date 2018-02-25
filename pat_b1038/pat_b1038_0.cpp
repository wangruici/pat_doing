#include <iostream>
#include <string>
#include <unordered_map>

using std::cin;
using std::cout;
using std::endl;

using std::unordered_map;
using std::string;

int main(){
	unordered_map<int,int> scores;
	int num;
	cin>>num;
	int temp_score;
	for(int i=0;i<num;++i){
		cin>>temp_score;
		scores[temp_score]++;
	}
	cin>>num;
	if(num>=1){	
		cin>>temp_score;
		cout<<scores[temp_score];
	}
	for(int i=1;i<num;++i){
		cin>>temp_score;
		cout<<" "<<scores[temp_score];
	}
	return 0;
}