#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool search(vector<int> &nums, int target)
    {

        int left = 0, right = nums.size() - 1, mid;

        while (left <= right)
        {
            mid = left + (right - left) / 2;

            if (nums[mid] == target)
                return true;

            if ((nums[left] == nums[mid]) && (nums[right] == nums[mid]))
            {
                ++left;
                --right;
            }

            else if (nums[left] <= nums[mid])
            {
                if ((nums[left] <= target) && (nums[mid] > target))
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            else
            {
                if ((nums[mid] < target) && (nums[right] >= target))
                    left = mid + 1;
                else
                    right = mid - 1;
            }
        }

        return false;
    }
};

int main()
{

    Solution solution;

    vector<int> rotatedArray = {2, 5, 6, 0, 0, 1, 2};
    int target = 0;

    if (solution.search(rotatedArray, target))
    {
        cout << "Target found in the rotated array." << endl;
    }
    else
    {
        cout << "Target not found in the rotated array." << endl;
    }

    return 0;
}
