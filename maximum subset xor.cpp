//https://practice.geeksforgeeks.org/problems/maximum-subset-xor/1

class Solution
{
    public:
    int maxSubarrayXOR(int arr[], int n)
    {
        int maxel=INT_MIN;
        for(int i=0;i<n;i++){
            if(arr[i]>maxel){
                maxel=arr[i];
            }
        }
        int msb=0;
        for(int i=31;i>=0;i--){
            if((1<<i)&maxel){
                msb=i;
                break;
            }
        }
        //have founded the max index of msb of all numbers above
        
        int index=0;
        for(int i=msb;i>=0;i--)
        {
            int maxindex=index;
            int maxelement=INT_MIN;
            for(int j=index;j<n;j++)
            {
                if((arr[j]&(1<<i) ) && arr[j]>maxelement ){
                    maxindex=j;
                    maxelement=arr[j];
                }
            }
            if(maxelement==INT_MIN){
                continue;
            }
            swap(arr[index],arr[maxindex]);//we are taking the max to out of the next loop 
            //so that this time we took another maximum
            maxindex=index;
            for(int j=0;j<n;j++){
                if(j!=maxindex && arr[j] &(1<<i)){
                    arr[j]^=arr[maxindex];
                }
            }
            index++;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans^=arr[i];
        }
        return ans;
        
    }
};