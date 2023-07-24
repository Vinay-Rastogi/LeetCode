class Solution
{
public:
    double myPow(double x, int n)
    {

        if (n == 0)
            return 1;

        if (x == 1)
            return 1;

        long long n1 = n;
        double res = 1.0;

        if (n < 0)
        {
            n1 = n1 * (-1);
        }

        while (n1)
        {
            if (n1 % 2 == 0)
            {
                x = x * x;
                n1 = n1 / 2;
            }

            else
            {
                res = res * x;
                n1--;
            }
        }

        if (n < 0)
        {
            res = 1 / res;
        }

        return res;
    }
};