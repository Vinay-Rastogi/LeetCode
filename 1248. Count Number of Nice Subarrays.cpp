#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
private:

int atMost(vector<int>& A, int k) {

        int res = 0, i = 0, n = A.size();
        
        for (int j = 0; j < n; j++) {
            k -= A[j] % 2;
            while (k < 0)
                k += A[i++] % 2;
            res += j - i + 1;
        }
        return res;
    }

public:
        int numberOfSubarrays(vector<int>& A, int k) {
        return atMost(A, k) - atMost(A, k - 1);
    }
};

int main()
{

    Solution sl;
    vector<int> A = {1,1,2,1,1};
    int k = 3;

    cout << sl.numberOfSubarrays(A,k);

    return 0;
}