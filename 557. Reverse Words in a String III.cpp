#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void reverse(string &str, int low, int high)
    {
        while (low <= high)
        {
            char temp = str[low];
            str[low] = str[high];
            str[high] = temp;

            low++;
            high--;
        }
    }

    string reverseWords(string s)
    {
        int start = 0;

        for (int end = 0; end < s.length(); end++)
        {
            if (s[end] == ' ')
            {
                reverse(s, start, end - 1);
                start = end + 1;
            }
        }

        reverse(s, start, s.length() - 1);

        return s;
    }
};

int main()
{

    Solution sl;
    string s = "Let's take LeetCode contest";

    cout << sl.reverseWords(s);

    return 0;
}