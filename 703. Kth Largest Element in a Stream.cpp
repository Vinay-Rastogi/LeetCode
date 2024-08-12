#include <iostream>
#include <BITS/stdc++.h>

using namespace std;

class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int sz;

    KthLargest(int k, vector<int>& nums) {
        sz = k;
        for (int i = 0; i < nums.size(); i++) {
            pq.push(nums[i]);
        }
        while (pq.size() > sz) {
            pq.pop();
        }
    }

    int add(int val) {
        pq.push(val);
        while (pq.size() > sz) {
            pq.pop();
        }
        return pq.top();
    }
};

int main() {
    vector<int> nums = {4, 5, 8, 2};
    KthLargest* obj = new KthLargest(3, nums);

    cout << obj->add(3) << endl; 
    cout << obj->add(5) << endl; 
    cout << obj->add(10) << endl; 
    cout << obj->add(9) << endl; 
    cout << obj->add(4) << endl; 

}