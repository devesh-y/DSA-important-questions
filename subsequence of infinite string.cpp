//string a is concatenated infinite times
//find if there is a subsequence of a which is equal to b 
//if possible , find the last index of it in string a

#include<bits/stdc++.h>
using namespace std;
int notpossible(unordered_map<int,int> check,string &a)
{
    int size2=check.size();
    int tempsize=0;
    for(int i=0;i<a.size();i++){
        if(check[a[i]-'a']){
            check[a[i]-'a']=0;
            tempsize++;
        }
    }
    if(tempsize!=size2)
    {
        return 1;
    }
    return 0;
}
int main()
{
    string a="contest";
    string b="sqono";
    unordered_map<int,int> amap;// value,times
    unordered_map<int,list<int> >indexmarking;
    for(int i=0;i<b.size();i++){
        if(amap[b[i]-'a'])
        {
            amap[b[i]-'a']++;
            indexmarking[b[i]-'a'].push_back(i+1);// i have not taken the 0th index
        }
        else{
            amap[b[i]-'a']=1;
            indexmarking[b[i]-'a'].push_back(i+1);
        }
    }

    if(notpossible(amap,a)){
        cout<<"not possible\n";
        return 0;
    }
    int tempsize=0;
    int n=a.size();
    int index=0;
    int concat=0;
    while(1){
        int & x=amap[a[index]-'a'];
        if(x!=0 && indexmarking[a[index]-'a'].front()-1==tempsize )
        {
            x--;
            tempsize++;
            indexmarking[a[index]-'a'].pop_front();
            
        }
        if(tempsize==b.size()){
            break;
        }
        index++;
        if(index==n ){
            index=0;
            concat++;
        }
        
    }
    cout<<"last index at "<<concat*a.size()+index;
}