#include<bits/stdc++.h>
class SpecialStack {
     int arr[30001];
        int topp;
        int mini;

    public:
        SpecialStack(){
            topp=-1;
            mini=INT_MAX;
        }
    void push(int data) {
        if(topp==-1)
        {
            arr[++topp]=data;
            mini=data;
        }
        else{
            if(data<mini){
                arr[++topp]=2*data-mini;
                mini=data;
            }
            else{
                arr[++topp]=data;
            }
        } 
    }

    int pop() {
        int curr=arr[topp];
        topp--;
        if(curr>mini){
            return curr;
        }
        else{
            int prevmin=mini;
            int val=2*mini-curr;
            mini=val;
            return prevmin;
            
        }
    }

    int top() {
        if (topp==-1){
            return -1;
        }
        else{
            int curr=arr[topp];
            if(curr<mini){
                return mini;
            }
            else{
                return curr;
            }
        }
    }

    bool isEmpty() {
        if(topp==-1){
            return true;
        }
        else{
            return false;
        }
    }

    int getMin() {
        if(topp==-1){
            return -1;
        }
        return mini;
    }  
};