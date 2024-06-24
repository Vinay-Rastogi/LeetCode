#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int minKBitFlips(vector<int> &nums, int k)
    {
        int ans = 0, flips = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if ((nums[i] + flips) % 2 == 0)
            {
                if (i > nums.size() - k)
                {
                    return -1;
                }
                else
                {
                    ans++;
                    flips++;
                    nums[i] = -1;
                }
            }
            if (i + 1 >= k)
            {
                flips -= (nums[i - k + 1] < 0);
            }
        }
        return ans;
    }
};

int main()
{

    Solution sl;
    vector<int> A = {0, 1, 0};
    int k = 1;

    cout << sl.minKBitFlips(A, k);

    return 0;
}