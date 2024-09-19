#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool isNumber(const string &s)
    {
        for (char c : s)
        {
            if (!isdigit(c) && c != '-')
            {
                return false;
            }
        }
        return true;
    }
    vector<int> diffWaysToCompute(string expression)
    {
        vector<int> ans;

        for (int i = 0; i < expression.size(); i++)
        {
            char c = expression[i];
            if (c == '+' || c == '-' || c == '*')
            {
                vector<int> left = diffWaysToCompute(expression.substr(0, i));
                vector<int> right = diffWaysToCompute(expression.substr(i + 1));

                for (int l : left)
                {
                    for (int r : right)
                    {
                        if (c == '+')
                        {
                            ans.push_back(l + r);
                        }
                        else if (c == '-')
                        {
                            ans.push_back(l - r);
                        }
                        else if (c == '*')
                        {
                            ans.push_back(l * r);
                        }
                    }
                }
            }
        }
        if (ans.empty() && isNumber(expression))
        {
            ans.push_back(stoi(expression));
        }
        return ans;
    }
};

int main()
{
    Solution sl;
    string expression = "2-1-1";

    vector<int> res = sl.diffWaysToCompute(expression);

    return 0;
}