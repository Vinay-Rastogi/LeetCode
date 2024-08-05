#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string kthDistinct(vector<string> &arr, int k)
    {
        int n = arr.size();

        map<string, int> mp;

        for (int i = 0; i < n; i++)
        {
            mp[arr[i]]++;
        }

        int count = 0;
        for (auto it : arr)
        {
            if (mp[it] == 1)
            {
                count++;

                if (count == k)
                    return it;
            }
        }

        return "";
    }
};

int main()
{
    Solution sl;
    vector<string> arr = {"d", "b", "c", "b", "c", "a"};
    int k = 2;

    cout << sl.kthDistinct(arr, k);

    return 0;
}