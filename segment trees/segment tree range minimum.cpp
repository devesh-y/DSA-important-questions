#include<bits/stdc++.h>
using namespace std;
//here this is for finding minimum in a range


// in segment tree array, it has been seen that 4*n size is preferred 

void build (vector<int> &arr, vector<int> &tree, int low,int high, int index){

    if(low==high){
        tree[index]=arr[low];
        return;
    }
    int mid=(low+high)/2;
    build(arr,tree, low, mid, 2*index+1 );
    build(arr,tree,mid+1, high, index*2+2 );

    tree[index]= min(tree[2*index+1],tree[2*index+2]);
    tree[index]=min(tree[index*2+1],tree[index*2+2]);

}
void update(int index, int low,int high, int l, int r, int i, int val,vector<int> &tree){

    if(low==high){
        tree[index]=val;
        return;
    }

    int mid=(low+high)/2;
    if(i<=mid && i>=low){
        update(2*index+1, low,mid,l, r, i, val,tree);
    }
    else{
        update(2*index+2, mid+1,high,l, r, i, val,tree);
    }


}
int query(vector<int> &tree, int low, int high, int l, int r, int index ){
    //if no overlap
    if( l>high || r<low ){
        return INT_MAX;
    }
    //complete overlap
    else if(l<=low && r>=high){
        return tree[index];
    }
    //partial overlap

    int mid=(low+high)/2;
    int left=query(tree,low,mid, l,r, index*2+1);
    int right=query(tree, mid+1, high,l,r ,index*2+2);

    return min(left,right);
}

int main()
{
    vector<int> arr={2,1,0,5,4,3};
    vector<int> tree(4*arr.size(),0);

    build(arr,tree,0,arr.size()-1,0);
    cout<<query(tree,0, arr.size()-1, 3,5,0);
}