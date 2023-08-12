#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &mat)
    {

        int n = mat.size();
        int m = mat[0].size();

        int dp[n][m];

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {

                if (mat[i][j] == 1)
                    dp[i][j] = 0;

                else if (i == 0 && j == 0)
                    dp[i][j] = 1;

                else
                {
                    int up = 0, left = 0;

                    if (i > 0)
                        up = dp[i - 1][j];
                    if (j > 0)
                        left = dp[i][j - 1];

                    dp[i][j] = up + left;
                }
            }
        }

        return dp[n - 1][m - 1];
    }
};

int main()
{

    Solution sl;

    vector<vector<int>> obstacleGrid = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};

    cout << sl.uniquePathsWithObstacles(obstacleGrid);

    return 0;
}