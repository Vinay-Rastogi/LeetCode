#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> fullBloomFlowers(vector<vector<int>> &flowers, vector<int> &persons)
    {

        vector<pair<int, int>> pairs;

        for (int i = 0; i < persons.size(); i++)
            pairs.push_back({persons[i], i});

        sort(pairs.begin(), pairs.end());
        sort(flowers.begin(), flowers.end());

        int l = 0;
        vector<int> ans(persons.size());
        multiset<int> ms;

        for (int i = 0; i < pairs.size(); i++)
        {

            while (l < flowers.size() && pairs[i].first >= flowers[l][0])
            {
                ms.insert(flowers[l][1]);
                l++;
            }

            while (ms.size() && (*(ms.begin()) < pairs[i].first))
                ms.erase(ms.begin());

            ans[pairs[i].second] = ms.size();
        }

        return ans;
    }
};

int main()
{

    Solution sl;
    vector<vector<int>> flowers{{1, 6}, {3, 7}, {9, 12}, {4, 13}};
    vector<int> persons = {2, 3, 7, 11};
    vector<int> ans = sl.fullBloomFlowers(flowers, persons);

    return 0;
}