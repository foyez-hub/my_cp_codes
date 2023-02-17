#include <bits/stdc++.h>
using namespace std;


struct times
{
    int starttimes;
    int endtimes;
    int acivityNUM;

};

bool comp(times a1,times a2){

     return a1.endtimes<a2.endtimes;
}

int main(){

    int start[] = {1, 3, 0, 5, 8, 5};
    int  finish[] = {2, 4, 6, 7, 9, 9};

    int sz = sizeof(start) / sizeof(int);

    times arr[100];
    for (int i = 0; i < sz; i++)
    {
        arr[i].starttimes=start[i];
        arr[i].endtimes=finish[i];
        arr[i].acivityNUM=i+1;
        
    }
    //Sort the activities based on their completion time
     sort(arr,arr+sz,comp);
     //Pick the first activity to print from the sorted array.
     times previously_selected=arr[0];
     cout<<" Activity num-> "<<arr[0].acivityNUM<<" Starts at "<<arr[0].starttimes<<", Finishes at "<<arr[0].endtimes<<endl;

     int ans=1;
     for (int i = 1; i < sz; i++)
     {
        //Select this activity and print it if the start time of this activity 
        //is greater than or equal to the end time
       //of the previously selected activity
        if(previously_selected.endtimes<=arr[i].starttimes){
            cout<<" Activity num-> "<<arr[i].acivityNUM<<" Starts at "<<arr[i].starttimes<<", Finishes at "<<arr[i].endtimes<<endl;
            ans++;
            previously_selected=arr[i];

        }

     }

     cout<<"Total acivity selected-> "<<ans<<endl;


     

    

    

}