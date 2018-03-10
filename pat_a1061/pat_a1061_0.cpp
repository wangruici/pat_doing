#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
using namespace std;
int main(){
   int i,j;
	string stra,strb,strc,strd;
	cin>>stra>>strb>>strc>>strd;
	for(i=0;stra[i]!='\0'&&strb[i]!='\0';i++){
       if(stra[i]==strb[i]&&('A'<=stra[i]&&stra[i]<='G')){
             if(stra[i]=='A')  cout<<"MON"<<" ";
             else if(stra[i]=='B') cout<<"TUE"<<" "; 
             else if(stra[i]=='C')  cout<<"WED"<<" ";
             else if(stra[i]=='D')  cout<<"THU"<<" ";
             else if(stra[i]=='E')  cout<<"FRI"<<" ";
             else if(stra[i]=='F')  cout<<"SAT"<<" ";
             else if(stra[i]=='G')  cout<<"SUN"<<" "; 
             break;                                                  
       }                                      
   }
   
   for(++i;stra[i]!='\0'&&strb[i]!='\0';i++){
       if(stra[i]==strb[i]&&(('0'<=stra[i]&&stra[i]<='9')||('A'<=stra[i]&&stra[i]<='N'))){
             if('0'<=stra[i]&&stra[i]<='9') cout<<"0"<<stra[i]<<":"; 
             else  cout<<((stra[i]-'A')+10)<<":"; 
             break;                                                  
       }                                      
   }
   for(j=0;strc[j]!='\0'&&strd[j]!='\0';j++){
        if(strc[j]==strd[j]&&(('a'<=strc[j]&&strc[j]<='z')||('A'<=strc[j]&&strc[j]<='Z')))  break;                                   
   }
   if(j<10) cout<<"0"<<j<<endl;
   else cout<<j<<endl;
	system("pause");
	return 0;
}

