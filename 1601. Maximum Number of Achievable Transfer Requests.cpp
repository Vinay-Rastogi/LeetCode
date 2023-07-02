class Solution
{
public:
    void helper(int ind, vector<vector<int>> &requests, int l, vector<int> &temp, int &ans)
    {

        if (ind == requests.size())
        {

            for (auto x : temp)
                if (x != 0)
                    return;

            ans = max(ans, l);

            return;
        }

        helper(ind + 1, requests, l, temp, ans);

        temp[requests[ind][0]]--;
        temp[requests[ind][1]]++;

        helper(ind + 1, requests, l + 1, temp, ans);

        temp[requests[ind][0]]++;
        temp[requests[ind][1]]--;
    }

    int maximumRequests(int n, vector<vector<int>> &requests)
    {

        vector<int> temp(n, 0);
        int ans = INT_MIN;

        helper(0, requests, 0, temp, ans);

        return ans;
    }
};