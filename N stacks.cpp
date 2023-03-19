class NStack
{
    private:
    int *arr;
    int * top;
    int *next;
    //it will be -1 for those element which has stack size is only one , that is themselves
    //otherwise it will point to that index which is next value of that stack
    int n , s;
    int freeslot;
public:
    
    NStack(int N, int S) //N is the number of stack and S is the number of elemnets in array
    {
        n=N;
        s=S;
        arr= new int[s];
        top=new int[n];
        next=new int[s];
        for(int i=0;i<n;i++){
            top[i]=-1;
        }
        //initilaly next means the next free element in array
        for(int i=0;i<s;i++){
             next[i]=i+1;
        }
        next[s-1]=-1;
        freeslot=0;// it is the free space index in array
    }
    bool push(int x, int m)
    {
        if(freeslot==-1){
            return false;
        }
        int index=freeslot;
        freeslot=next[index];
        arr[index]=x;
        next[index]=top[m-1];
        top[m-1]=index;
        return true;
    }
    int pop(int m)
    {
        if(top[m-1]==-1){
            return -1;
        }
        int index=top[m-1];
        top[m-1]=next[index];
        next[index]=freeslot;
        freeslot=index;
        return arr[index];
    }
};