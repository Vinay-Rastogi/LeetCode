#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {

        priority_queue<int> pq;

        for (int i = 0; i < nums.size(); i++)
            pq.push(nums[i]);

        int val;

        while (k)
        {
            val = pq.top();
            pq.pop();
            k--;
        }

        return val;
    }
};

int main()
{

    Solution sl;

    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;

    cout << sl.findKthLargest(nums, k);

    return 0;
}