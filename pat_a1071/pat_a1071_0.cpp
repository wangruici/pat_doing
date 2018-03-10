#include <string>
#include <map>
#include <iostream>
#include <ctype.h>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::flush;
using std::getline;

int main(){
	map<string,int> count;
	string message;
	getline(cin,message);
	int i=0;
	int message_len=(int)message.size();
	while(i<message_len){
		string word;
		while(i<message_len&&isalnum(message[i])){
			if(isupper(message[i])){
				message[i]=tolower(message[i]);
			}
			word+=message[i];
			++i;
		}
		while(i<message_len&&!isalnum(message[i])){
			++i;
		}
		if(word==""){
			continue;
		}
		if(count.find(word)==count.end()){
			count[word]=1;	
		}
		else{
			++count[word];	
		}

	}
	int max_count=0;
	string max_frequency_word;
	for(auto it=count.begin();it!=count.end();++it){
		if(it->second>max_count){
			max_count=it->second;
			max_frequency_word=it->first;
		}
	}
	cout<<max_frequency_word<<" "<<max_count<<endl;
	return 0;
}
