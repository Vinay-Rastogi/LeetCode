#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int getLastMoment(int n, vector<int> &left, vector<int> &right)
    {

        if (left.size() == 0 && right.size() == 0)
            return 0;

        sort(left.begin(), left.end());
        sort(right.begin(), right.end());

        if (left.size() == 0)
            return (n - right[0]);

        if (right.size() == 0)
            return (left[left.size() - 1]);

        return max(left[left.size() - 1], n - right[0]);
    }
};

int main()
{

    Solution sl;

    int n = 4;

    vector<int> left = {4, 3};
    vector<int> right = {0, 1};

    cout << sl.getLastMoment(n, left, right);

    return 0;
}