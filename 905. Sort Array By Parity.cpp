#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> sortArrayByParity(vector<int> &nums)
    {

        int i = 0;
        int j = nums.size() - 1;

        while (i < j)
        {

            if (nums[i] % 2 == 1 && nums[j] % 2 == 0)
            {
                swap(nums[i], nums[j]);
            }

            if (nums[i] % 2 == 0)
                i++;

            if (nums[j] % 2 == 1)
                j--;
        }

        return nums;
    }
};

int main()
{

    Solution sl;
    vector<int> nums = {3, 1, 2, 4};
    vector<int> ans = sl.sortArrayByParity(nums);

    return 0;
}