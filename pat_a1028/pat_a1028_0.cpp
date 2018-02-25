#include <algorithm>
#include <iostream>
#include <string>
//使用c++的io导致运行超时
using std::sort;
using std::cin;
using std::cout;
using std::endl;
using std::string;


struct Student{
	string id;
	string name;
	int grade;
};


bool cmp1(const Student &a,const Student &b){
	return a.id<b.id;
}

bool cmp2(const Student &a,const Student &b){
	return (a.name==b.name)?(a.id<b.id):(a.name<b.name);
}

bool cmp3(const Student &a,const Student &b){
	return (a.grade==b.grade)?(a.id<b.id):(a.grade<b.grade);
}


int main(){
	int c,n;
	cin>>c>>n;
	Student* students=new Student[c];
	string id;
	string name;
	int grade;
	for(int i=0;i<c;++i){
		cin>>id>>name>>grade;
		students[i].id=id;
		students[i].name=name;
		students[i].grade=grade;
	}
	switch(n){
		case 1:
			sort(students,students+c,cmp1);
			break;
		case 2:
			sort(students,students+c,cmp2);
			break;
		case 3:
			sort(students,students+c,cmp3);
	}
	for(int i=0;i<c;++i){
		cout<<students[i].id<<" ";
		cout<<students[i].name<<" ";
		cout<<students[i].grade<<endl;
	}
	delete []students;
	return 0;
}