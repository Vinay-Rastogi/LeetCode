#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    bool repeatedSubstringPattern(string str)
    {

        int n = str.size();
        for (int i = 1; i <= n / 2; i++)
        {
            if (n % i == 0)
            {
                string pat;
                for (int j = 0; j < n / i; j++)
                    pat += str.substr(0, i);
                if (str == pat)
                    return true;
            }
        }

        return false;
    }
};

int main()
{

    Solution sl;

    string str = "abab";

    cout << sl.repeatedSubstringPattern(str);

    return 0;
}