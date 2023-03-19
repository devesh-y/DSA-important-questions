#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v={0,1,1,0,1,0,0};
    int i=0;
    int j=v.size()-1;
    while(i<j){
        if(v[i]==0){
            i++;
            continue;
        }
        else if(v[j]==0){
            swap(v[i],v[j]);
            j--;
            continue;
        }
        else if(v[j]==1){
            j--;
        }
    }
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<"  ";
    }
}