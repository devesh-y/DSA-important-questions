#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> arr={-2, -3, 4, -1, -2, 1, 5, -3};
    int tempans=arr[0];
    int ans=arr[0];
    int start=0;
    int end=0;
    int s=0;
    int e=0;
    for(int i=1;i<arr.size();i++){

        if(arr[i]>=(tempans+arr[i])){  //if that particular value greater than previous subarray + that element then mark this value as the start
            s=i;
            e=i; 
        }

        tempans=max(arr[i],tempans+arr[i]);
        if(tempans>ans){
            ans=tempans;
            e=i;
            start=s;
            end=i;
        }
    }
    cout<<"the maximum sum of the subarray is "<<ans;
    cout<<"\nstart index is "<<start;
    cout<<"\nend index is "<<end;
}