#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    long long minimumReplacement(vector<int> &nums)
    {

        long long oper = 0;
        long long prev = nums[nums.size() - 1];

        for (int i = nums.size() - 2; i >= 0; i--)
        {

            long long num = nums[i];
            long long numOfTime = (num + prev - 1) / prev;

            oper += numOfTime - 1;

            prev = num / numOfTime;
        }

        return oper;
    }
};

int main()
{

    Solution sl;
    vector<int> nums = {3, 9, 3};

    cout << sl.minimumReplacement(nums);

    return 0;
}