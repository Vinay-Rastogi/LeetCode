#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class CustomStack {
    int maxi;
    stack<int> st;
    vector<int> nums;
    
public:
    CustomStack(int maxSize) {
        maxi = maxSize;
    }
    
    void push(int x) {
        if(st.size() < maxi) {
            st.push(x);
            nums.push_back(x);
        }
    }
    
    int pop() {
        if(st.empty()) {
            return -1;
        } else {
            int top = st.top();
            st.pop();
            nums.pop_back();
            return top;
        }
    }
    
    void increment(int k, int val) {
        if(st.size() < k) {
            while(!st.empty()) {
                st.pop();
            }

            for(int i = 0; i < nums.size(); i++) {
                st.push(nums[i] + val);
                nums[i] += val;
            }

        } else {
            while(!st.empty()) {
                st.pop();
            }

            for(int i = 0; i < k; i++) {
                st.push(nums[i] + val);
                nums[i] += val;
            }

            for(int i = k; i < nums.size(); i++) {
                st.push(nums[i]);
            }
        }
    }
};

int main() {
    // Example usage of the CustomStack
    CustomStack* obj = new CustomStack(3);  // Create a stack with a max size of 3
    obj->push(5);  // Push 5 to the stack
    obj->push(10); // Push 10 to the stack
    obj->push(15); // Push 15 to the stack (stack is now full)
    
    cout << "Pop: " << obj->pop() << endl;  // Should return 15 (last inserted element)
    
    obj->increment(2, 100);  // Increment the bottom 2 elements by 100
    
    cout << "Pop: " << obj->pop() << endl;  // Should return 110 (10 + 100)
    cout << "Pop: " << obj->pop() << endl;  // Should return 105 (5 + 100)

    return 0;
}
