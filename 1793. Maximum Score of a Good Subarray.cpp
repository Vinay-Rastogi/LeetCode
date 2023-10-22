#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maximumScore(vector<int> &nums, int k)
    {

        int left = k, right = k;
        int min_val = nums[k];
        int max_score = min_val;

        while (left > 0 || right < nums.size() - 1)
        {
            if (left == 0 || (right < nums.size() - 1 && nums[right + 1] > nums[left - 1]))
            {
                right++;
            }
            else
            {
                left--;
            }
            min_val = min(min_val, min(nums[left], nums[right]));
            max_score = max(max_score, min_val * (right - left + 1));
        }

        return max_score;
    }
};

int main()
{

    Solution sl;
    int k = 3;
    vector<int> nums = {1, 4, 3, 7, 4, 5};

    cout << sl.maximumScore(nums, k);

    return 0;
}