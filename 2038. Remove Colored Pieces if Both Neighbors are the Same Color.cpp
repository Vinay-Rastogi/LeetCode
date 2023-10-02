#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool winnerOfGame(string colors)
    {

        if (colors.length() < 3)
            return false;

        int countA = 0;
        int countB = 0;

        for (int i = 1; i < colors.length() - 1; i++)
        {

            if (colors[i] == 'A')
            {
                if (colors[i - 1] == 'A' && colors[i + 1] == 'A')
                    countA++;
            }
            else
            {

                if (colors[i - 1] == 'B' && colors[i + 1] == 'B')
                    countB++;
            }
        }

        return (countA > countB) ? true : false;
    }
};

int main()
{

    Solution sl;
    string str = "AAABABB";

    cout << sl.winnerOfGame(str);

    return 0;
}