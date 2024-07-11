#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string reverseParentheses(string s)
    {

        stack<char> st;
        string ans = "";

        for (char ch : s)
        {

            if (ch == ')')
            {

                string str = "";

                while (!st.empty() && st.top() != '(')
                {
                    str += st.top();
                    st.pop();
                }
                st.pop();

                for (int i = 0; i < str.size(); i++)
                    st.push(str[i]);
            }
            else
            {
                st.push(ch);
            }
        }

        while (!st.empty())
        {
            ans = st.top() + ans;
            st.pop();
        }

        return ans;
    }
};

int main()
{

    Solution sl;
    string s = "(ed(et(oc))el)";

    cout << sl.reverseParentheses(s);

    return 0;
}