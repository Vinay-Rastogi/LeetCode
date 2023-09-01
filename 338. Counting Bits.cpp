#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> countBits(int n)
    {

        vector<int> Res(n + 1, 0);

        for (int i = 0; i <= n; i++)
        {

            if (i % 2 == 0)
                Res[i] = Res[i / 2];

            else
                Res[i] = Res[i / 2] + 1;
        }

        return Res;
    }
};

int main()
{

    Solution sl;

    int n = 2;
    vector<int> ans = sl.countBits(n);

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";

    return 0;
}