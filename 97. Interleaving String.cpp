#include <iostream>
#include <vector>

using namespace std;

class Solution
{

private:
    bool helper(int i, int j, int k, string s1, string s2, string s3, vector<vector<int>> &dp)
    {

        if (k == s3.length())
            return true;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (i == s1.length() && s2[j] != s3[k])
            return false;

        if (j == s2.length() && s1[i] != s3[k])
            return false;

        if (s1[i] != s3[k] && s2[j] != s3[k])
            return false;

        if (s1[i] == s3[k] && s2[j] != s3[k])
            return dp[i][j] = helper(i + 1, j, k + 1, s1, s2, s3, dp);

        else if (s2[j] == s3[k] && s1[i] != s3[k])
            return dp[i][j] = helper(i, j + 1, k + 1, s1, s2, s3, dp);

        else
            return dp[i][j] = (helper(i + 1, j, k + 1, s1, s2, s3, dp) || helper(i, j + 1, k + 1, s1, s2, s3, dp));
    }

public:
    bool isInterleave(string s1, string s2, string s3)
    {

        if (s1.length() + s2.length() != s3.length())
            return false;

        vector<vector<int>> dp(s1.length() + 1, vector<int>(s2.length() + 1, -1));

        return helper(0, 0, 0, s1, s2, s3, dp);
    }
};

int main()
{

    Solution sl;

    string s1 = "aabcc";
    string s2 = "dbbca";
    string s3 = "aadbbcbcac";

    cout << sl.isInterleave(s1, s2, s3);

    return 0;
}