#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int minOperations(vector<string> &logs)
    {

        int ans = 0;

        for (string str : logs)
        {
            if (str == "./")
                continue;

            if (str == "../")
                ans += ans > 0 ? -1 : 0;

            else
                ans++;
        }

        return ans;
    }
};

int main()
{

    Solution sl;

    vector<string> logs = {"d1/", "d2/", "./", "d3/", "../", "d31/"};

    cout << sl.minOperations(logs);

    return 0;
}