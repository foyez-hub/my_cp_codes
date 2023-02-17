#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long ull;
#define pb push_back



int main(){

    int n;
    cin>>n;
    int a[n][n];
    int srvc[n+1];
    for(int i=0;i<=10;i++){
       srvc[i] = 0;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    int count = 0;
    int val = 1;

    if(n==10){
        for(int i=0;i<n;i++){
            int j = 0;
            for(;j<n;j++){
                if(srvc[a[i][j]]<val){
                    srvc[a[i][j]] = val;
                }else{
                    break;
                }
            }
            if(j==10){
                count++;
            }
            val++;

        }
        for(int j=0;j<n;j++){
            int i = 0;
            for(;i<n;i++){
                if(srvc[a[i][j]]<val){
                    srvc[a[i][j]] = val;
                }else{
                    break;
                }
            }
            if(i==10){
                count++;
            }
            val++;

        }
    } 
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
           int k = i;
           int l = j;
           if(i+2>n || j+5>n)break;
           //cout<<i<<" "<<j<<endl;
           for(;k<i+2;k++){
               //l = j;
              for(;l<j+5;l++){
                if(srvc[a[k][l]]<val){
                    srvc[a[k][l]] = val;
                }else{
                    break;
                }
              }
           }
           if(k==i+2 && l==j+5){
               
              count++;
              
           }
           val++;
           k = i;
           l = j;
           if(i+5>n || j+2>n)break;
           for(;k<i+5;k++){
               l = j;
              for(;l<j+2;l++){
               // cout<<a[k][l]<<" ";
                if(srvc[a[k][l]]<val){
                    srvc[a[k][l]] = val;
                }else{
                    break;
                }
              }//cout<<endl;
           }
           if(k==i+5 && l==j+2){
              cout<<k<<" "<<l<<" "<<i<<" "<<j<<endl;
              count++;
             
           }
            val++;
        }
    } 
    cout<<count<<endl; 


}