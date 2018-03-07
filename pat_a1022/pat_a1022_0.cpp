#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <map>
#include <cstring>
#include <algorithm>
#include <iostream>
using std::sort;
using std::string;
using std::map;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::flush;
using std::getline;


typedef int id;
typedef string title;
typedef string author_name;
typedef string key_word;
typedef string publisher_name;
typedef string year_time;

map<title,vector<id> > title_book;
map<author_name,vector<id> > author_book;
map<key_word,vector<id> > key_book;
map<publisher_name,vector<id> > publisher_book;
map<year_time,vector<id> >time_book;

template <typename T>
void check_clear_query(string content,map<T,vector<id> > &books,vector<id> &ans){
	if(books.find(content)==books.end()){
		ans.clear();
	}
	else{
		ans=books[content];
	}
}

vector<id> query(int index,string content){
	vector<id> ans;
	switch(index){
		case 1:
			check_clear_query<title>(content,title_book,ans);
			break;
		case 2:
			check_clear_query<author_name>(content,author_book,ans);
			break;
		case 3:
			check_clear_query<key_word>(content,key_book,ans);
			break;
		case 4:
			check_clear_query<publisher_name>(content,publisher_book,ans);
			break;
		case 5:
			check_clear_query<year_time>(content,time_book,ans);
			break;
	}
	return ans;
}

void print_ans(int index,string content,vector<id> &ans){
	printf("%d: %s\n",index,content.data());
	if(ans.size()==0){
		printf("Not Found\n");
	}
	else{
		for(int i=0;i<(int)ans.size();++i){
			printf("%07d\n",ans[i]);
		}
	}
}
int main(){
	int book_num=0;
	scanf("%d",&book_num);
	string ttitle;
	string tauthor;
	string tpublisher;
	int tid;
	string tkeyword;
	string tyear;
	for(int i=0;i<book_num;++i){
		cin>>tid;
		getchar();
		getline(cin,ttitle);
		title_book[ttitle].push_back(tid);
		getline(cin,tauthor);
		author_book[tauthor].push_back(tid);
		do{
			cin>>tkeyword;
			key_book[tkeyword].push_back(tid);
		}while(getchar()!='\n');
		getline(cin,tpublisher);
		publisher_book[tpublisher].push_back(tid);
		cin>>tyear;
		time_book[tyear].push_back(tid);
	}
	int index;
	int query_num;
	string query_content;
	scanf("%d\n",&query_num);
	vector<id> ans;

	for(int i=0;i<query_num;++i){
		scanf("%d: ",&index);
		getline(cin,query_content);
		ans=query(index,query_content);
		sort(ans.begin(),ans.end());
		print_ans(index,query_content,ans);
	}
	return 0;
}

