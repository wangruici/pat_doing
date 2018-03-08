#include <set>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::set;

int main(){
	set<int> s;
	s.insert(10);
	s.insert(1200);
	cout<<*s.begin()<<endl;
	return 0;
}
