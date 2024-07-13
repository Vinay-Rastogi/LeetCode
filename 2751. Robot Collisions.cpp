#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> survivedRobotsHealths(vector<int> &positions,
                                      vector<int> &healths, string directions)
    {
        int n = positions.size();
        vector<int> indices(n), result;
        stack<int> stack;

        for (int index = 0; index < n; ++index)
        {
            indices[index] = index;
        }

        sort(indices.begin(), indices.end(),
             [&](int lhs, int rhs)
             { return positions[lhs] < positions[rhs]; });

        for (int currentIndex : indices)
        {
            if (directions[currentIndex] == 'R')
            {
                stack.push(currentIndex);
            }
            else
            {
                while (!stack.empty() && healths[currentIndex] > 0)
                {

                    int topIndex = stack.top();
                    stack.pop();

                    if (healths[topIndex] > healths[currentIndex])
                    {
                        healths[topIndex] -= 1;
                        healths[currentIndex] = 0;
                        stack.push(topIndex);
                    }
                    else if (healths[topIndex] < healths[currentIndex])
                    {
                        healths[currentIndex] -= 1;
                        healths[topIndex] = 0;
                    }
                    else
                    {
                        healths[currentIndex] = 0;
                        healths[topIndex] = 0;
                    }
                }
            }
        }

        for (int index = 0; index < n; ++index)
        {
            if (healths[index] > 0)
            {
                result.push_back(healths[index]);
            }
        }
        return result;
    }
};

int main()
{

    Solution sl;
    vector<int> healths = {10, 10, 15, 12};
    vector<int> positions = {3, 5, 2, 6};
    string directions = "RLRL";

    vector<int> res = sl.survivedRobotsHealths(positions, healths, directions);

    return 0;
}