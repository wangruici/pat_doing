#include <queue>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::queue;

//queue中的元素只是原对象的一个副本，对副本做的任何修改对原对象没有任何影响
int main(){
	int item=12;
	queue<int> q;
	q.push(item);
	int k=q.front();
	k=99999;
	cout<<item<<endl;
	return 0;
}
