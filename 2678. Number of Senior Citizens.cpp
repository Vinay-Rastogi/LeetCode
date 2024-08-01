#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int countSeniors(vector<string> &details)
    {

        int ans = 0;

        for (string str : details)
        {
            int age = (str[11] - '0') * 10 + (str[12] - '0');

            cout << age << endl;
            if (age > 60)
                ans++;
        }

        return ans;
    }
};

int main()
{
    Solution sl;
    vector<string> details = {"7868190130M7522", "5303914400F9211", "9273338290F4010"};

    cout << sl.countSeniors(details);

    return 0;
}