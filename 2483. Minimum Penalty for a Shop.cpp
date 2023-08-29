#include <iostream>
#include <climits>
#include <string>

using namespace std;

class Solution
{
public:
    int bestClosingTime(string custom)
    {

        int y = 0, n = 0;

        for (auto i : custom)
            if (i == 'Y')
                y++;

        int minPenalty = INT_MAX, penalty;
        int ans = -1;

        for (int i = 0; i < custom.size(); i++)
        {

            penalty = y + n;

            if (penalty < minPenalty)
            {

                minPenalty = penalty;
                ans = i;
            }

            if (custom[i] == 'Y')
                y--;

            else
                n++;
        }

        penalty = y + n;

        if (penalty < minPenalty)
        {

            minPenalty = penalty;
            ans = custom.size();
        }

        return ans;
    }
};

int main()
{

    Solution sl;

    string customer = "YYNY";

    cout << sl.bestClosingTime(customer) << endl;

    return 0;
}