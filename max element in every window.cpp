#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n = nums.size();
    vector<int> res;
    deque<int> mq;

    for (int i = 0; i < n; i++)
    {

        if (mq.size() > 0 && mq.front() <= i - k)

            mq.pop_front();

        while (mq.size() > 0 && nums[i] >= nums[mq.back()])
            mq.pop_back();

        mq.push_back(i);
        if (i + 1 >= k)
            res.push_back(nums[mq.front()]);
    }

    return res;
}
