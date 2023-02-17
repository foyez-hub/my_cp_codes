#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long ull;
#define pb push_back

void f(string cur,int len,int goalsum){
    if(len==0 || goalsum<=0){

        
      cout<<cur<<" "<<goalsum<<endl;
       
        return;
    }

    for (char i ='0'; i <='9'; i++)
    {
        f(cur+i,len-1,goalsum-(i-'0'));
    }
    

    


}

int main(){
    int len;
    int goalsum;
    cin>>len>>goalsum;

    f("",len,goalsum);





}