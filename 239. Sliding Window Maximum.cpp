#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {

        priority_queue<pair<int, int>> pq;
        vector<int> ans;

        for (int i = 0; i < k; i++)
            pq.push({nums[i], i});

        ans.push_back(pq.top().first);

        for (int i = k; i < nums.size(); i++)
        {

            while (!pq.empty() && pq.top().second <= (i - k))
                pq.pop();

            pq.push({nums[i], i});
            ans.push_back(pq.top().first);
        }

        return ans;
    }
};

int main()
{

    Solution sl;

    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    vector<int> result = sl.maxSlidingWindow(nums, k);

    for (int i = 0; i < result.size(); i++)
        cout << result[i] << " ";

    return 0;
}