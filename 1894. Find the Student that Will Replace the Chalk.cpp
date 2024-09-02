#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int chalkReplacer(vector<int> &chalk, int k)
    {

        long long sum = 0;
        int i = 0;

        for (int i = 0; i < chalk.size(); i++)
            sum += chalk[i];

        k %= sum;

        if (k == 0)
            return 0;

        while (chalk[i] <= k)
            k -= chalk[i++];

        return i;
    }
};

int main()
{
    Solution sl;
    vector<int> chalk = {5, 1, 5};
    int k = 22;

    cout << sl.chalkReplacer(chalk, k);

    return 0;
}