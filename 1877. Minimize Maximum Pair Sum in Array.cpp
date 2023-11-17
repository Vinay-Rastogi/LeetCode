#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int minPairSum(vector<int> &nums)
    {

        sort(nums.begin(), nums.end());

        int left = 0, right = nums.size() - 1;

        int minMaxPairSum = INT_MIN;

        while (left < right)
        {
            int currentPairSum = nums[left] + nums[right];

            minMaxPairSum = std::max(minMaxPairSum, currentPairSum);

            left++;
            right--;
        }

        return minMaxPairSum;
    }
};

int main()
{

    Solution sl;
    vector<int> nums{3, 5, 4, 2, 4, 6};

    cout << sl.minPairSum(nums);

    return 0;
}