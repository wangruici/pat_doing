#include <string>
#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::string;

void push_card(vector<string> &cards,string s,int range){
	string item;
	for(int i=1;i<=range;++i){
		if(i<10){
			item=s+(char)('0'+i);
		}
		else{
			item=s+(char)('0'+1)+(char)('0'+i-10);
		}
		cards.push_back(item);
	}
}


const int cards_num=54;

void adjust(vector<string> &cards,int sequence[],int len){
	vector<string> acards=cards;
	for(int i=0;i<len;++i){
		cards[sequence[i]-1]=acards[i];
	}
}

int main(){
	vector<string> cards;
	int sequence[cards_num];
	push_card(cards,"S",13);
	push_card(cards,"H",13);
	push_card(cards,"C",13);
	push_card(cards,"D",13);
	push_card(cards,"J",2);
	int times;
	cin>>times;
	for(int i=0;i<cards_num;++i){
		cin>>sequence[i];
	}
	for(int i=0;i<times;++i){
		adjust(cards,sequence,cards_num);
	}

	for(int i=0;i<cards_num;++i){
		cout<<cards[i];
		if(i!=cards_num-1){
			cout<<" ";
		}
		else{
			cout<<endl;
		}
	}

	return 0;
}

