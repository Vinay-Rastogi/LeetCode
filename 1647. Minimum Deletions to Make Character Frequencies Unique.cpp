#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int minDeletions(string s)
    {

        unordered_map<char, int> mp;

        for (char c : s)
            mp[c]++;

        priority_queue<int> pq;

        for (auto it : mp)
            pq.push(it.second);

        int ans = 0;

        while (pq.size() != 1)
        {

            int top = pq.top();
            pq.pop();

            if (pq.top() == top && top != 0)
            {
                ans++;
                pq.push(top - 1);
            }
        }

        return ans;
    }
};

int main()
{

    Solution sl;
    string s = "aaabbbcc";

    cout << sl.minDeletions(s);

    return 0;
}