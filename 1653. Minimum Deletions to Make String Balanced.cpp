#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int minimumDeletions(string s)
    {
        int n = s.size();

        int ans = 0;
        int count_b = 0;

        for (int i = 0; i < n; i++)
        {

            if (s[i] == 'b')
                count_b++;

            else
                ans = min(ans + 1, count_b);
        }
        return ans;
    }
};

int main()
{
    Solution sl;
    string s = "aababbab";

    cout << sl.minimumDeletions(s);

    return 0;
}