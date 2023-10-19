#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool backspaceCompare(string s, string t)
    {

        string p;
        string q;

        for (int i = 0; i < s.length(); i++)
        {

            if (s[i] == '#')
            {
                if (p.size())
                    p.pop_back();
            }
            else
                p.push_back(s[i]);
        }

        for (int i = 0; i < t.length(); i++)
        {

            if (t[i] == '#')
            {
                if (q.size())
                    q.pop_back();
            }
            else
                q.push_back(t[i]);
        }

        return p == q;
    }
};

int main()
{

    Solution sl;
    string s = "ab#c";
    string t = "ad#c";

    cout << sl.backspaceCompare(s, t);

    return 0;
}