#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool canArrange(vector<int> &arr, int k)
    {
        int n = arr.size();
        vector<int> remainders(k);
        for (int i = 0; i < n; ++i)
        {
            int remainder = arr[i] % k;
            if (remainder < 0)
            {
                remainder += k;
            }
            ++remainders[remainder];
        }
        if (remainders[0] % 2 == 1)
        {
            return false;
        }
        for (int i = 1; i <= k / 2; ++i)
        {
            if (remainders[i] != remainders[k - i])
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution sl;
    vector<int> arr = {1, 2, 3, 4, 5, 10, 6, 7, 8, 9};
    int k = 5;

    cout << sl.canArrange(arr, k);

    return 0;
}