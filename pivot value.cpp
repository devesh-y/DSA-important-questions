#include <bits/stdc++.h>
using namespace std;
#define int long long int
signed main()
{
    vector<int> nums = {5, 6, 7, 1};
    int left = 0, right = nums.size() - 1, minVal = INT_MAX;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (nums[left] <= nums[mid])
        {
            minVal = min(minVal, nums[left]);
            left = mid + 1;
        }
        else
        {
            minVal = min(minVal, nums[mid]);
            right = mid - 1;
        }
    }
    cout<<minVal<<"\n";
    
}