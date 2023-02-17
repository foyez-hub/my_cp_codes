#include <bits/stdc++.h>
using namespace std;
struct node
{
    int val;
    int index;
};

node MIN(node a,node b){
    if(a.val<=b.val){
         return a;
    }
    else return b;
}

node MM;


node FindRotationCount(node arr[],int l,int r){

    if(l>r){
        return MM;
    }
    if(l==r){
        return arr[l];
    }

    int mid=(l+r)/2;
    return MIN( FindRotationCount(arr,l,mid),
    FindRotationCount(arr,mid+1,r) );

}
int main(){
    MM.val=INT_MAX;
    MM.index=-1;
    cout<<"Give array size"<<endl;
    int n;
    cin>>n;
    cout<<"Give a rotated sorted array of distinct integers of size -> "<<n<<endl;
    node arr[n];
    for (int i = 0; i < n; i++)
    {
          cin>>arr[i].val;
          arr[i].index=i;
    }
    node ans=FindRotationCount(arr,0,n-1);
    cout<<"Rotation Count is : "<< ans.index<<endl;
    

}