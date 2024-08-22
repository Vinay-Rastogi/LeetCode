#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int findComplement(int num)
    {

        string ans = "";

        while (num)
        {

            int n = !(num & 1);
            ans += to_string(n);

            num = num >> 1;
        }

        reverse(ans.begin(), ans.end());
        return stoi(ans, 0, 2);
    }
};

int main()
{
    Solution sl;
    int n = 5;

    cout << sl.findComplement(n);

    return 0;
}