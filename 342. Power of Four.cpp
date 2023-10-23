#include <iostream>

using namespace std;

class Solution
{
public:
    bool isPowerOfFour(int n)
    {

        float x = n;

        for (int i = 4; x > 0; i * 4)
        {

            if (x == 1)
                return true;

            x = x / i;
        }

        return false;
    }
};

int main()
{

    Solution sl;
    int n = 16;

    cout << sl.isPowerOfFour(n);

    return 0;
}