#include<bits/stdc++.h>
using namespace std;
#define int long long int
inline bool valid(int y,int x,int n,vector<vector<int>> visited,vector<vector<int> >m){
    if((x>=0 && x<n) && (y>=0 && y<n) && visited[y][x]==0 && m[y][x]==1 ){
        return true;
    }
    return false;
}
void solve(vector<vector<int> >&m,int n,vector<string> &ans,int y,int x,vector<vector<int> > visited,string path){
    if(x==n-1 && y==n-1){
        ans.push_back(path);
        return ;
    }
     visited[y][x]=1;
   
    if(valid(y+1,x,n, visited,m)){
       
        solve(m,n,ans,y+1,x,visited,path+"D");
      
    } 
 
    if(valid(y-1,x,n, visited,m)){
     
        solve(m,n,ans,y-1,x,visited,path+"U");
     
    }
  
    if(valid(y,x-1,n, visited,m)){
      
        solve(m,n,ans,y,x-1,visited,path+"L");
  
    }
 
    if(valid(y,x+1,n, visited,m)){
        
       solve(m,n,ans,y,x+1,visited,path+"R");
        
    }
      visited[y][x]=0;



}
signed main()
{
    vector<vector<int> >m={ {1,0,0,0},
                            {1,1,0,1},
                            {1,1,0,0},
                            {0,1,1,1}
                        };
    int n=m.size();
    vector<string> ans;
    if(m[0][0]==0){
        cout<<"no path available\n";
    }

    int row=0;
    int column=0;
    string path="";
    vector<vector<int> >visited(n,vector<int>(n,0));
   
    solve(m,n,ans,row,column,visited,path);
    sort(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
    }
    return 0;
}
//this is another solution which shows you that you also dont need the visited vector
//https://leetcode.com/discuss/general-discussion/988908/pls-help-me-with-thisrat-in-maze-1-problem