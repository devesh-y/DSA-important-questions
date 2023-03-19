#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v={2,0,1};
    int left=0;
    int mid=0;
    int right=v.size()-1;
    while(mid<=right)
    {
        if(v[mid]==1)
        {
            mid++;
           continue;
        }
        else if(v[mid]==0)
        {
            swap(v[left],v[mid]);
            left++;
            mid++;
            continue;
        }
        else if(v[mid]==2)
        {
            swap(v[mid],v[right]);
            right--;
        }

    }
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<"  ";
    }
}