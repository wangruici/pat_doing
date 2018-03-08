#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using std::sort;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::istream;
using std::ostream;
struct Record{
	string name;
	char gender;
	string id;
	int score;
};

int
operator -(const Record &r1,const Record &r2){
	return r1.score-r2.score;
}

istream& 
operator >>(istream &i,Record &r){
	i>>r.name>>r.gender>>r.id>>r.score;
	return i;
}

ostream&
operator <<(ostream &o,const Record &r){
	o<<r.name<<" "<<r.id;
}
vector<Record> ans;
bool cmp(const Record &r1,const Record &r2);
int main(){
	int num;
	cin>>num;
	Record r;
	int male=0;
	int female=0;
	for(int i=0;i<num;++i){
		cin>>r;
		if(r.gender<='F'){
			++female;
		}
		else{
			++male;
		}
		ans.push_back(r);
	}
	sort(ans.begin(),ans.end(),cmp);
	if(female==0){
		cout<<"Absent"<<endl;
	}
	else{
		cout<<ans[0]<<endl;
	}
	if(male==0){
		cout<<"Absent"<<endl;
	}
	else{
		cout<<ans[(int)ans.size()-1]<<endl;
	}
	if(male==0||female==0){
		cout<<"NA"<<endl;
	}
	else{
		cout<<ans[0]-ans[(int)ans.size()-1]<<endl;
	}
	return 0;
}

bool
cmp(const Record &r1,const Record &r2){
	if(r1.gender!=r2.gender){
		return r1.gender<r2.gender;
	}
	else{
		return r1.score>r2.score;	
	}
}


