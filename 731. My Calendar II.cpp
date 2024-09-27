#include <iostream>
#include <map>
using namespace std;

class MyCalendarTwo {
    
    private:
        map<int, int> mp;
    
    public:
        MyCalendarTwo() {}
    
        bool book(int start, int end) {
            mp[start]++;
            mp[end]--;
            int sum = 0;
            
            for(auto it = mp.begin(); it != mp.end(); it++) {
                sum += it->second;
                
                if(sum > 2) {
                    mp[start]--;
                    mp[end]++;
                    return false;
                }
            }
            
            return true;   
        }
};

int main() {
    MyCalendarTwo* obj = new MyCalendarTwo();
    
    // Example bookings
    cout << boolalpha; // Output bools as "true" or "false"
    
    cout << "Booking (10, 20): " << obj->book(10, 20) << endl;  // Should return true
    cout << "Booking (50, 60): " << obj->book(50, 60) << endl;  // Should return true
    cout << "Booking (10, 40): " << obj->book(10, 40) << endl;  // Should return true
    cout << "Booking (5, 15): " << obj->book(5, 15) << endl;    // Should return false (overlap with 2 events)
    cout << "Booking (5, 10): " << obj->book(5, 10) << endl;    // Should return true
    cout << "Booking (25, 55): " << obj->book(25, 55) << endl;  // Should return true
    
    delete obj;
    return 0;
}
