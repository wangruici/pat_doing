//纯c++版本的
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>

using std::vector;
using std::sort;
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::flush;

const int longlive=200;
struct Person{
	string name;
	int money;
	int age;
};

bool cmp(Person a,Person b){
	if(a.money!=b.money) return a.money>b.money;
	else if(a.age!=b.age) return a.age<b.age;
	else return a.name<b.name;
}

int main(){
	int allPeople_num,querry_num;
	cin>>allPeople_num>>querry_num;
	Person* bill=new Person[allPeople_num];
	Person* bill100=new Person[allPeople_num];
	int* ages=new int[longlive];
	for(int i=0;i<longlive;++i){
		ages[i]=0;
	}
	for(int i=0;i<allPeople_num;++i){
		cin>>bill[i].name>>bill[i].age>>bill[i].money;
	}
	sort(bill,bill+allPeople_num,cmp);
	int bill100_num=0;
	//根据题意将数组bill进行预处理保存到bill100中去，因为各年龄段财富值在100以外的永远也不可能被输出
	for(int i=0;i<allPeople_num;++i){
		if(ages[bill[i].age]<=100){
			++ages[bill[i].age];
			bill100[bill100_num++]=bill[i];
		}
	}
	int maxAge,minAge;
	int maxOutput_num;
	for(int i=1;i<=querry_num;++i){
		cin>>maxOutput_num;
		cin>>minAge>>maxAge;
		cout<<"Case #"<<i<<":"<<endl;
		int k=0;
		for(int j=0;j<bill100_num&&k<maxOutput_num;++j){
			if(bill100[j].age>=minAge&&bill100[j].age<=maxAge){
				++k;
				cout<<bill100[j].name<<" "<<bill100[j].age<<" "<<bill100[j].money<<endl;
			}
		}
		if(k==0){
			cout<<"None"<<flush;
		}
	}
	delete []bill;
	delete []bill100;
	delete []ages;
	return 0;

}
