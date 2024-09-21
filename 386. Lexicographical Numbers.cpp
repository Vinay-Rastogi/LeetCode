#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> lexicalOrder(int n)
    {

        vector<string> s;

        for (int i = 1; i <= n; i++)
            s.push_back(to_string(i));

        sort(begin(s), end(s));

        vector<int> nums;

        for (auto v : s)
            nums.push_back(stoi(v));

        return nums;
    }
};

int main()
{
    Solution sl;
    int n = 13;
    vector<int> res = sl.lexicalOrder(n);

    for (int i : res)
        cout << i << " ";

    return 0;
}