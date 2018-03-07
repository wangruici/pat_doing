#include<iostream>
#include<set>
#include<map>
#include<string> 

using namespace std;


map<string,set<int> >mptitle,mpauthor,mpkeywords,mppub,mpyear;

void query(map<string,set<int> > &mp,const string &temp){
    if(mp.find(temp)==mp.end()) printf("Not Found\n");
    else{
        for(set<int>::iterator it=mp[temp].begin();it!=mp[temp].end();it++){
            printf("%07d\n",*it);
        }
    }
}

int main(){
    int n,id,m,type;
    string title,author,key,pub,year;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>id;
        getchar();
        getline(cin,title);
        mptitle[title].insert(id);
        getline(cin,author);
        mpauthor[author].insert(id);
        while(cin>>key){
            mpkeywords[key].insert(id);
            char c=getchar();
            if(c=='\n') break;
        }
        getline(cin,pub);
        mppub[pub].insert(id);
        getline(cin,year);
        mpyear[year].insert(id);
    }
    string temp;
    cin>>m;
    for(int i=0;i<m;i++){
        scanf("%d: ",&type);
        getline(cin,temp);
        cout<<type<<": "<<temp<<endl;
        if(type==1) query(mptitle,temp);
        else    if(type==2) query(mpauthor,temp);
        else    if(type==3) query(mpkeywords,temp);
        else    if(type==4) query(mppub,temp);
        else    query(mpyear,temp);
    }
}
