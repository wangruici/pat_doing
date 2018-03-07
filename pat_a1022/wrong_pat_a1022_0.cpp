#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <map>
#include <cstring>
#include <algorithm>
using std::sort;
using std::string;
using std::map;
using std::vector;


typedef string id;
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

vector<id> query(char index,string content){
	vector<id> ans;
	switch(index){
		case '1':
			check_clear_query<title>(content,title_book,ans);
			break;
		case '2':
			check_clear_query<author_name>(content,author_book,ans);
			break;
		case '3':
			check_clear_query<key_word>(content,key_book,ans);
			break;
		case '4':
			check_clear_query<publisher_name>(content,publisher_book,ans);
			break;
		case '5':
			check_clear_query<year_time>(content,time_book,ans);
			break;
	}
	return ans;
}

void print_ans(char index,string content,vector<id> &ans){
	printf("%c: %s\n",index,content.data());
	if(ans.size()==0){
		printf("Not Found\n");
	}
	else{
		for(int i=0;i<(int)ans.size();++i){
			printf("%s\n",ans[i].data());
		}
	}
}
int main(){
	int book_num=0;
	scanf("%d",&book_num);
	char tid[10];
	char ttitle[90];
	string sttitle;
	char tauthor[90];
	string stauthor;
	char tkeyword[20];
	char tpublisher[90];
	string stpublisher;
	char tyear[10];
	for(int i=0;i<book_num;++i){
		scanf("%s\n",tid);
		fgets(ttitle,90,stdin);
		sttitle=ttitle;
		sttitle=sttitle.substr(0,sttitle.size()-1);
		title_book[sttitle].push_back(tid);
		fgets(tauthor,90,stdin);
		stauthor=tauthor;
		stauthor=stauthor.substr(0,stauthor.size()-1);
		author_book[stauthor].push_back(tid);
		do{
			scanf("%s",tkeyword);
			key_book[tkeyword].push_back(tid);
		}while(getchar()!='\n');
		fgets(tpublisher,90,stdin);
		stpublisher=tpublisher;
		stpublisher=stpublisher.substr(0,stpublisher.size()-1);
		publisher_book[stpublisher].push_back(tid);
		scanf("%s\n",tyear);
		time_book[tyear].push_back(tid);
	}
	char index;
	int query_num;
	char query_content[90];
	string query_content_s;
	scanf("%d\n",&query_num);
	vector<id> ans;

	for(int i=0;i<query_num;++i){
		index=getchar();
		getchar();
		getchar();
		fgets(query_content,90,stdin);
		query_content_s=query_content;
		if(i!=query_num-1){
			query_content_s=query_content_s.substr(0,query_content_s.size()-1);
		}
		ans=query(index,query_content_s);
		sort(ans.begin(),ans.end());
		print_ans(index,query_content_s,ans);
	}
	return 0;
}

