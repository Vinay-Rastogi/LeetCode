#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2)
    {

        map<int, int> mp;
        vector<int> Res;

        for (int i = 0; i < arr1.size(); i++)
            mp[arr1[i]]++;

        for (int i = 0; i < arr2.size(); i++)
        {
            while (mp[arr2[i]] > 0)
            {
                Res.push_back(arr2[i]);
                mp[arr2[i]]--;
            }
        }

        for (auto it : mp)
        {
            while (it.second > 0)
            {
                Res.push_back(it.first);
                (it.second)--;
            }
        }

        return Res;
    }
};
int main()
{

    Solution sl;
    vector<int> arr1 = {2, 3, 1, 3, 2, 4, 6, 7, 9, 2, 19};
    vector<int> arr2 = {2, 1, 4, 3, 9, 6};
    vector<int> ans = sl.relativeSortArray(arr1, arr2);

    for (int x : ans)
        cout << x << " ";
}