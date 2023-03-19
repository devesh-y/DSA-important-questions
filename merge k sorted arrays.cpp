#include<queue>
#include<bits/stdc++.h>
using namespace std;
class node{
    public:
        int data;
        int i,j;
    node(int data,int i,int j){
        this->data=data;
        this->i=i;
        this->j=j;
    }
};
class comp{
    public:
    bool operator()(node *&a,node *&b){
        return a->data>b->data;
    }
};
vector<int> mergeKSortedArrays(vector<vector<int>>&arr, int k)
{
    vector<int> ans;
    priority_queue<node* ,vector<node*> ,comp > q;
        for(int i=0;i<k;i++){
            node * x=new node(arr[i][0],i,0);
            q.push(x);
        }
        while(q.size()>0){
            node * temp=q.top();
             q.pop();
           ans.push_back(temp->data);
            int tempi=temp->i;
             int tempj=temp->j+1;
            if(tempj<=arr[tempi].size()-1){
                node *x=new node(arr[tempi][tempj],tempi,tempj);
                q.push(x);
            }
            
        }
    return ans;
}