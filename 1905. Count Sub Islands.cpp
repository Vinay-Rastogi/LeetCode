#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n, m;
    bool flag;
    bool vst[505][505];
    vector<vector<int>> grid_i, grid_ii;

    void dfs(int i, int j) {
        if (i < 0 || j < 0 || i >= n || j >= m || !grid_ii[i][j] || vst[i][j]) return;

        vst[i][j] = true;
        if (!grid_i[i][j]) flag = false;

        dfs(i + 1, j);
        dfs(i, j + 1);
        dfs(i - 1, j);
        dfs(i, j - 1);
    }
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int ans = 0;
        grid_i = grid1;
        grid_ii = grid2;
        n = grid1.size();
        m = grid1[0].size();
        memset(vst, false, sizeof(vst));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vst[i][j] && grid_ii[i][j]) {
                    flag = true;
                    dfs(i, j);
                    ans += flag;
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid1 = {
        {1, 1, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 1, 1},
        {1, 0, 0, 0, 0},
        {1, 1, 0, 1, 1}
    };
    vector<vector<int>> grid2 = {
        {1, 1, 0, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 1, 1},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 1}
    };

    int result = sol.countSubIslands(grid1, grid2);
    cout << "Number of sub-islands: " << result << endl;

    return 0;
}
