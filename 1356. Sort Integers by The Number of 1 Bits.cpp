#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int countSetBits(int n)
    {

        int count = 0;

        while (n)
        {
            if (n & 1)
                count++;

            n = n >> 1;
        }

        return count;
    }
    vector<int> sortByBits(vector<int> &arr)
    {

        bool isZero = false;
        vector<pair<int, int>> v;

        for (int i = 0; i < arr.size(); i++)
            v.push_back({countSetBits(arr[i]), arr[i]});

        sort(v.begin(), v.end());

        for (int i = 0; i < arr.size(); i++)
            arr[i] = v[i].second;

        return arr;
    }
};

int main()
{

    Solution sl;
    vector<int> arr = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    vector<int> ans = sl.sortByBits(arr);

    return 0;
}