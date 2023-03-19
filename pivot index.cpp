#include<bits/stdc++.h>
using namespace std;
#define int long long int
signed main()
{
    vector<int> v={2,3,4,1};
    int left=0;
    int right=v.size()-1;
    while(left<right){
        int mid=left+ (right-left)/2;
        if(v[mid]>=v[0]){
            left=mid+1;
        }
        else{
            right=mid;
        }

    }
    if(v[0]<v[left]){
        cout<<"0";
    }else{
        cout<<left;
    }
    
}