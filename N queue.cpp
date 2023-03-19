#include<bits/stdc++.h>
using namespace std;
#define int long long int
class nqueue{
    private:
        int *front;
        int *rear;
        int *arr;
        int n;
        int s;
        int* next;
        int freeslot;
    public:
        nqueue(int N,int S)
        {
            s=S;
            n=N;
            arr=new int[S];
            front= new int[N];
            rear=new int[S];
            next=new int[N];
            for(int i=0;i<s;i++){
                next[i]=i+1;
            }
            next[s-1]=-1;
            for(int i=0;i<N;i++)
            {
                front[i]=-1;
                rear[i]=-1;
            }
            freeslot=0;
        }
        void push(int m,int val){
            if(freeslot==-1){
                cout<<"no space is available\n";
                return;
            }
            int index=freeslot;
            freeslot=next[index];
            if(front[m-1]==-1){
                front[m-1]=index;
                rear[m-1]=index;
            }
            else{
                next[rear[m-1]]=index;
                rear[m-1]=index;
            }
            next[index]=-1;
            arr[index]=val;
            cout<<val<<" has been pushed to queue "<<m<<"\n";
        }
        void pop(int m){
            if(front[m-1]==-1){
                cout<<"queue number "<<m<<" is empty\n";
                return ;
            }
            int index=front[m-1];
            cout<<arr[index]<<" has been popped out\n";
            front[m-1]=next[index];
            next[index]=freeslot;
            freeslot=index;
        }

};
signed main()
{
    nqueue q(3,7);
    q.push(1,5);
    q.push(1,5);
    q.push(1,5);
    q.push(1,5);
    q.push(1,5);
    q.push(1,5);
    q.push(1,5);
    q.push(1,5);
    q.push(1,5);
    q.push(1,5);
    q.push(1,5);
    q.push(1,5);
    q.push(1,5);
    q.pop(2);
    q.pop(1);
}