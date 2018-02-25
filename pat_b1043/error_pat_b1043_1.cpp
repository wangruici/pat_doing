//so many errors
//i should have thought about the algorithm before coding.
#include <algorithm>
#include <string>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
#include <utility>
#include <cassert>

using std::sort;

using std::string;

using std::cin;
using std::cout;
using std::flush;
using std::endl;

using std::map;

using std::unordered_map;

using std::vector;

using std::pair;

bool cmp(pair<string,int> r1,pair<string,int> r2){
	return r1.second<r2.second;
}

int
main(){
	const string nullStr="";
	const int dict_len=6;
	const char dict[dict_len]={'P','A','T','e','s','t'};
	vector<string> v_dict={nullStr+'P',nullStr+'A',nullStr+'T',nullStr+'e',nullStr+'s',nullStr+'t'};
	unordered_map<string,int> result={{"P",0},{"A",0},{"T",0},{"e",0},{"s",0},{"t",0}};
	vector<pair<string,int>> result2;
	string str;
	cin>>str;
	for(auto c:str){
		if(result.find(nullStr+c)!=result.cend()){
			++result[nullStr+c];
		}
	}

	cout<<"-------------------------"<<endl;
	for(auto c:result){
		cout<<"first: "<<c.first<<" second:"<<c.second<<endl;
	}
	cout<<"--------------------------"<<endl;
	for(unordered_map<string,int>::iterator r=result.begin();r!=result.end();++r){
		result2.push_back((*r));
	}

	sort(result2.begin(),result2.end(),cmp);
	
	cout<<"-------------------------"<<endl;
	for(auto c:result2){
		cout<<"first: "<<c.first<<" second:"<<c.second<<endl;
	}
	cout<<"--------------------------"<<endl;
	for(auto c:v_dict){
		cout<<c<<endl;
	}
	cout<<"--------------------------"<<endl;
	int temp=0;
	for(auto &c:result2){
		c.second=c.second-temp;
		vector<string>::iterator index;
		for(int i=0;i<c.second;++i){
			for(auto j=v_dict.begin();j!=v_dict.end();++j){
				cout<<(*j);
				if((*j)==c.first){
					index=j;
				}
			}
		}		
		if(index>=v_dict.begin()&&index<v_dict.end())
		{
			v_dict.erase(index);
		}
		temp+=c.second;
	}
	cout<<endl;
	return 0;
}


