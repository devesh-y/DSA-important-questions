#include<bits/stdc++.h>
using namespace std;
#define int long long int
void heapify(int arr[],int n,int i)
{
    int smallest=i;
    int left=2*i;
    int right=2*i +1;
    if(left<=n && arr[smallest]>arr[left]){
        smallest=left;
    }
    if(right<=n && arr[smallest]>arr[right])
    {
        smallest=right;
    }
    if(smallest!=i){
        swap(arr[smallest],arr[i]);
        heapify(arr,n,smallest);
    }
}
class heap{
    public:
        int arr[100];
        int size;
        heap(){
            arr[0]=-1;
            size=0;
        }
        void insert(int val)
        {
            size++;
            int index=size;
            arr[index]=val;
            while(index>1)
            {
                int parent=index/2;
                if(arr[parent]>arr[index])
                {
                    swap(arr[parent],arr[index]);
                    index=parent;
                }
                else
                {
                    return ;
                }
            }
        }
        void print()
        {
            for(int i=1;i<=size;i++){
                cout<<arr[i]<<" ";
            }
            cout<<"\n";
        }
        void deletion()
        {
            if(size==0){
                cout<<"nothing to delete\n";
                return ;
            }
            arr[1]=arr[size];
            size--;
            int i=1;
            heapify(arr,size,1);
        }
};
void heapsort(int arr[],int n){
    int size=n;
    while(size>1)
    {
        swap(arr[size],arr[1]);
        size--;
        heapify(arr,size,1);
    }
}


signed main()
{
    
    heap h;
    h.insert(60);
    h.insert(50);
    h.insert(55);
    h.insert(20);
    h.insert(30);
    h.print();

    h.deletion();
    h.print();

    int arr[6]={-1,1,2,3,5,4};
    int n=5;
    //starting from n/2 because after n/2 there are all leaf nodes
    for(int i=n/2;i>=1;i--){
        heapify(arr,n,i);
    }
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
    heapsort(arr,n);
    for(int i=1;i<=n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";

}