#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  int candy(vector<int> &ratings)
  {

    if (ratings.size() <= 1)
      return ratings.size();

    vector<int> dp(ratings.size(), 1);
    int ans = 0;

    for (int i = 1; i < ratings.size(); i++)
      if (ratings[i] > ratings[i - 1])
        dp[i] = dp[i - 1] + 1;

    for (int i = ratings.size() - 1; i > 0; i--)
      if (ratings[i] < ratings[i - 1])
        dp[i - 1] = max(dp[i] + 1, dp[i - 1]);

    for (int x : dp)
      ans += x;

    return ans;
  }
};

int main()
{

  Solution sl;

  vector<int> ratings = {1, 0, 2};

  cout << sl.candy(ratings);

  return 0;
}