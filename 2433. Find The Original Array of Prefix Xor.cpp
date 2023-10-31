#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> findArray(vector<int> &pref)
    {

        vector<int> res(pref.size());
        res[0] = pref[0];

        int totalXor = res[0];

        for (int i = 1; i < pref.size(); i++)
        {

            res[i] = totalXor ^ pref[i];
            totalXor = totalXor ^ res[i];
        }

        return res;
    }
};

int main()
{

    Solution sl;
    vector<int> pref = {5, 2, 0, 3, 1};
    vector<int> res = sl.findArray(pref);

    return 0;
}