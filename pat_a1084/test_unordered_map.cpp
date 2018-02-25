#include <string>
#include <unordered_map>
#include <iostream>
#include <map>

using namespace std;


//string 的[]operator返回的是char类型,char类型是无法直接转化为string的
//因此，无法用string的元素来引用map<string ,int>
//一种解决方法是用一个null string+char就会自动转化为string
int main(){
	string m="";
	string s="hello World";
	unordered_map<string,int> a;
	a[m+s[1]]=10086;
	if(a.find(m+s[1])!=a.end()){
		cout<<a[m+s[1]]<<endl;
	}
	/*
	string s="hello world";
	for(int i=0;i!=s.size();++i){
		if(a.find(s[i])!=a.end()){
			cout<<a[s[i]]<<endl;
		}
		else{
			cout<<"no"<<endl;
		}
	}
	*/
	return 0;
}