#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {

        vector<vector<int>> ans;

        ans.push_back({1});

        if (numRows == 1)
            return ans;

        ans.push_back({1, 1});

        for (int i = 2; i < numRows; i++)
        {

            vector<int> temp;
            temp.push_back(1);

            for (int j = 1; j < i; j++)
                temp.push_back(ans[i - 1][j - 1] + ans[i - 1][j]);

            temp.push_back(1);

            ans.push_back(temp);
        }

        return ans;
    }
};

int main()
{

    Solution sl;
    int numRows = 5;

    vector<vector<int>> ans = sl.generate(numRows);

    return 0;
}