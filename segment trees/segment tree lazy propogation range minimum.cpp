#include<bits/stdc++.h>
using namespace std;

//in lazy propogation you let the work incomplete for someone to come and then complete it

class segmenttree{
    public:
        vector<int> tree, lazy;
        segmenttree(int n){
            tree.resize(4*n,0);
            lazy.resize(4*n,0);
        }

        void build(int index, int low, int high, vector<int> &arr){

            if(low==high){
                tree[index]=arr[low];
                return ;
            }
            int mid=(low+high)/2;
            build(index*2+1,low, mid, arr);
            build(index*2+2, mid+1, high, arr);
            tree[index]= min(tree[index*2+1] ,tree[2*index+2]);
        }
        void update(int index, int low,int high, int l, int r,int val){
            //update the previous update
            //and propogate downwards
            if(lazy[index]!=0){
                tree[index]+=lazy[index];
                //if have children then assign them work
                if(low!=high){
                    lazy[2*index+1]+=lazy[index];
                    lazy[2*index+2]+=lazy[index];
                }
                lazy[index]=0;
            }
            //no overlap
            if(high<l || r<low){
                return;
            }

            //complete overlap
            if(low>=l && high<=r){
                tree[index]+=val;
                //if have children then assign them work
                if(low!=high){
                    lazy[2*index+1]+=val;
                    lazy[2*index+2]+=val;
                }
                return;
            }
            //partial overlap
            int mid=(low+high)/2;
            update(2*index+1, low,mid,l, r, val);
            update(2*index+2, mid+1,high,l, r, val);
            tree[index]=min(tree[2*index+1], tree[2*index+2]);
        }
        int query(int index, int low, int high, int l ,int r)
        {
            if(lazy[index]!=0){
                tree[index]+=lazy[index];
                //if have children then assign them work
                if(low!=high){
                    lazy[2*index+1]+=lazy[index];
                    lazy[2*index+2]+=lazy[index];
                }
                lazy[index]=0;
            }

            //no overlap
            if(high<l || r< low){
                return INT_MAX;
            }
            //complete overlap
            else if(low>=l && high<=r){
                return tree[index];
            }

            int mid=(low+high)/2;
            int left=query(index*2+1 ,low,mid, l, r);
            int right=query(index*2+2, mid+1, high, l, r);
            return min(left,right);

        }

};

int main(){

    vector<int> arr={1,2,3,4,5,6,7,8,9,10};
    segmenttree st(arr.size());
    st.build(0,0,arr.size()-1,arr);
    cout<<st.query(0,0,arr.size()-1,0,1)<<"\n";
    st.update(0,0,arr.size()-1,0,1,2);
    cout<<st.query(0,0,arr.size()-1,0,1);
    

    return 0;
}