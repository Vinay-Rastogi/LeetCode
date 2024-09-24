#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int numLen(int num) { return to_string(num).length(); }

    int longestCommonPrefix(vector<int> &arr1, vector<int> &arr2)
    {

        unordered_set<int> prefixSet;

        for (int i : arr1)
        {

            while (i > 0)
            {
                prefixSet.insert(i);
                i /= 10;
            }
        }

        int res = 0;

        for (int i : arr2)
        {

            while (i > 0)
            {
                if (prefixSet.find(i) != prefixSet.end())
                {
                    res = max(res, numLen(i));
                    break;
                }

                i /= 10;
            }
        }

        return res;
    }
};

int main()
{
    Solution sl;
    vector<int> arr1 = {1, 10, 100};
    vector<int> arr2 = {1000};

    cout << sl.longestCommonPrefix(arr1, arr2);

    return 0;
}