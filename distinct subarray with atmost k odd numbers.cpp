//https://www.codingninjas.com/codestudio/problems/count-distinct-subarrays-with-at-most-k-odd-elements_1069335?leftPanelTab=0


int distinctSubKOdds(vector<int> arr, int n, int k)
{
    set<vector<int> > s;
   
    for(int i=0;i<n;i++)
    {
        int odd=0;
        vector<int> temp;
        for(int j=i;j<n;j++)
        {
            if(arr[j]&1){
                odd++;
             }
            if(odd>k){
                break;
            }
            temp.push_back(arr[j]);
            s.insert(temp);
        }
    }
	return s.size();
}