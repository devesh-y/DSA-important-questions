#include <bits/stdc++.h>
using namespace std;
#define int long long int
bool check(vector<int> &arr,int n, int m,int mid){
        int students=1;
        int sum=0;
        for(int i=0;i<n;i++){
            if(sum+arr[i]<=mid){
                sum+=arr[i];
            }
            else{
                students++;
                if(students>m || arr[i]>mid){
                    return false;
                }
                sum=arr[i];
            }
        }
    
       
        return true;
    }
int findPages(vector<int> &arr, int n, int m) 
{
    if(m>n){
        return -1;
    }
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    int ans=-1;
    int left=0;
    int right=sum;
    int mid=left+(right-left)/2;
    while(left<=right){
        if(check(arr,n,m,mid)){
            right=mid-1;
            ans=mid;
        }
        else{
            left=mid+1;
            
        }
        mid=left+(right-left)/2;
    }
    return ans;
    
}
signed main()
{ 
    vector<int> arr={13, 31, 37, 45, 46, 54 ,55 ,63 ,73 ,84 ,85};
    int m=10;
    int n=arr.size();
    cout<<findPages(arr,n,m);
    

}
