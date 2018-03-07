#include <iostream>
#include <string>
using namespace std;
int array_num[21];
int mutiply_num[21];
int flag[10];
int flag1[10];

int main(int argc, const char * argv[])
{

    int i;
    int len;
    int tmp;
    int success_flag;
    string str;
    cin>>str;
    len = str.size();
    for (i =0; i < 10; i++) {
        flag[i] = 0;
        flag1[i] = 0;
    }

    for (i = 0; i <21; i++) {
        mutiply_num[i] = 0;
    }

    for (i= len-1; i >=0; i--) {
        if (str[len-1-i]>='0' && str[len-1-i] <='9') {
            array_num[i] = str[len-1-i] - '0';
            flag[array_num[i]]++;
         }
    }
 
    
    for (i=len-1;i>=0 ; i--) {
        tmp = array_num[i] *2;
        if(tmp <10){
            mutiply_num[i] = tmp;
        }
        else
        {
            mutiply_num[i] = tmp%10;
            mutiply_num[i+1] += 1;
        }
        
    }
    
    if (mutiply_num[len]!=0) {
        success_flag = 0;
        cout<<"No"<<endl;
        for (i =len; i>=0; i--) {
            cout<<mutiply_num[i];
        }
        cout<<endl;
        return 0;
    }
    else
    {
        for(i = len -1; i>=0; i--)
        {
            flag1[mutiply_num[i]]++;
        }
        for(i= 0; i<10;i++)
        {
            if (flag[i] != flag1[i]) {
                success_flag = 0;
                break;
            }
            
            
        }
        if (i == 10) {
            success_flag = 1;
        }
    }
    
    if (!success_flag) {
        cout<<"No"<<endl;
    }
    else if(success_flag == 1){
        cout<<"Yes"<<endl;
    }
    
    for (i = len-1; i >=0; i--) {
        cout<<mutiply_num[i];
    }
    
    cout<<endl;
    
    return 0;
    
}
