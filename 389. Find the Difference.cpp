#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    char findTheDifference(string s, string t)
    {

        int n = s.length();
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        for (int i = 0; i < n; i++)
            if (s[i] != t[i])
                return t[i];

        return t[n];
    }

    char findTheDifferenceApproach2(string s, string t)
    {

        int n = s.length();

        for (int i = 0; i < n; i++)
            t[i + 1] += t[i] - s[i];

        return t[n];
    }
};

int main()
{

    Solution sl;
    string s = "abcd";
    string t = "abcde";

    cout << sl.findTheDifference(s, t);

    return 0;
}