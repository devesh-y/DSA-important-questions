//https://practice.geeksforgeeks.org/problems/maximum-product-subarray3604/1

long long maxProduct(vector<int> arr, int n) {
        long long maxsub = arr[0];
        long long minsub = arr[0];
        long long ans = arr[0];
      
        for (long long i = 1; i < n; i++) 
        {
            if(arr[i]<0 ){
                swap(maxsub,minsub);
            }
            maxsub=max(arr[i]*maxsub,(long long)arr[i]);
            minsub=min(arr[i]*minsub,(long long)arr[i]);
            
            ans=max(ans,maxsub);
        }
        return ans;
	}