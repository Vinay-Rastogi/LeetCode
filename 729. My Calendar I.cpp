#include <iostream>
#include <map>

using namespace std;

class MyCalendar
{
private:
    map<int, int> M;

public:
    MyCalendar() {}

    bool book(int start, int end)
    {
        M[start]++;
        M[end]--;
        int sum = 0;

        for (auto it = M.begin(); it != M.end(); it++)
        {
            sum += it->second;
            if (sum > 1)
            {
                M[start]--;
                M[end]++;
                return false;
            }
        }

        return true;
    }
};

int main()
{
    MyCalendar *obj = new MyCalendar();

    // Test cases
    if (obj->book(10, 20))
    {
        cout << "Booking (10, 20) successful.\n";
    }
    else
    {
        cout << "Booking (10, 20) failed.\n";
    }

    if (obj->book(15, 25))
    {
        cout << "Booking (15, 25) successful.\n";
    }
    else
    {
        cout << "Booking (15, 25) failed.\n";
    }

    if (obj->book(20, 30))
    {
        cout << "Booking (20, 30) successful.\n";
    }
    else
    {
        cout << "Booking (20, 30) failed.\n";
    }

    delete obj;
    
    return 0;
}
