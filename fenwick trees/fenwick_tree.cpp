#include <bits/stdc++.h>
using namespace std;
// also known as binary indexed tree
//  in the fenwick tree array at any index we are taking the range i to j
// here j is the currentnode index and for calculating i
// we are subtracting the last set bit of j ,and then we are adding 1 to it eg: 1100-100=1000+1=1001   this is in binary

// and we are storing the range i to j in the jth index of the fenwick tree array

class fenwicktree
{
    int n;
    vector<int> tree;

public:
    fenwicktree(int n)
    {
        this->n = n;
        tree.resize(n+1,0);
    }
    int get_sum( int i) //getting the prefix sum till i
    //finding sum from 1 to i
    {
        int sum = 0;
        while (i > 0)
        {
            sum += tree[i];
            i -= (i & (-i));
        }
        return sum;
    }
    void update(int i, int val)
    {
        while (i <= n)
        {
            tree[i] += val;
            //for finding the next index which will change by updating this value , we will also update those
            i += (i & (-i));
        }
    }
    int range_sum( int i, int j) 
    {
        return get_sum( j) - get_sum( i - 1);
    }
};

int main()
{
    // remember in both arrays, the given array and the fenwick tree array
    // we must have the keep 1-based indexing
    vector<int> arr = {0, 1,2,3,4,5 ,6 ,7,8,9,10};
    
    int n = arr.size() - 1;
    fenwicktree ft(n);
    for (int i = 1; i <= n; i++)
    {
        ft.update(i, arr[i]);
    }
    //   1     2    3     4     5   
//     1-1    1-2  3-3   1-4   5-5 
//here the range in tree[1]  is from 1 to 1 just like i explain above
// in tree[2] its from 1 to 2


   
    cout<<ft.get_sum(2)<<endl;
    ft.update(2,4);
    cout<<ft.get_sum(2);





    return 0;
}