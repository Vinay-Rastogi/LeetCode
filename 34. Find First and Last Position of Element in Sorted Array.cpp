#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int firstOcc(vector<int> nums, int target)
    {

        int ans = -1;
        int s = 0, e = nums.size() - 1;
        int mid = s + (e - s) / 2;

        while (s <= e)
        {
            if (nums[mid] == target)
            {
                ans = mid;
                e = mid - 1;
            }

            else if (nums[mid] > target)
            {
                e = mid - 1;
            }

            else
            {
                s = mid + 1;
            }

            mid = s + (e - s) / 2;
        }

        return ans;
    }

    int lastOcc(vector<int> nums, int target)
    {

        int ans = -1;
        int s = 0, e = nums.size() - 1;
        int mid = s + (e - s) / 2;

        while (s <= e)
        {
            if (nums[mid] == target)
            {
                ans = mid;
                s = mid + 1;
            }

            else if (nums[mid] > target)
            {
                e = mid - 1;
            }

            else
            {
                s = mid + 1;
            }

            mid = s + (e - s) / 2;
        }

        return ans;
    }

    vector<int> searchRange(vector<int> &nums, int target)
    {

        return {firstOcc(nums, target), lastOcc(nums, target)};
    }
};

int main()
{

    Solution sl;
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    vector<int> res = sl.searchRange(nums, 8);

    return 0;
}