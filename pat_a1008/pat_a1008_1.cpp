#include <iostream>
#include <string>
#include <vector>
const int twait=5;
const int tup=6;
const int tdown=4;
using std::cin;
using std::cout;
using std::flush;
using std::endl;
using std::string;
using std::vector;



int main(){
	int counter;
	cin>>counter;
	int nowLocation=0;
	int objLocation=0;
	int total_time=0;

	while(counter--){
		cin>>objLocation;
		if(objLocation>nowLocation){
			total_time+=(objLocation-nowLocation)*tup;
		}
		else if(objLocation<nowLocation){
			total_time+=(nowLocation-objLocation)*tdown;
		}
		else if(objLocation==nowLocation){
			;
		}
		nowLocation=objLocation;
		total_time+=twait;
	}
	cout<<total_time<<endl;
	return 0;
}
