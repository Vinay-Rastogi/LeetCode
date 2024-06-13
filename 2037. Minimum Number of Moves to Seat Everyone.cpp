#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        
        sort(seats.begin(),seats.end());
        sort(students.begin(),students.end());
        int ans = 0;

        for(int i=0;i<seats.size();i++)
        ans += abs(seats[i]-students[i]);

       return ans; 
    }
};

int main()
{

    Solution sl;
    vector<int> seats = {3,1,5};
    vector<int> students = {2,7,4};

    int ans = sl.minMovesToSeat(seats,students);
  
    cout << ans << endl;
   

    return 0;
}