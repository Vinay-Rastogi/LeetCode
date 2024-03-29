
#include <iostream>
#include <bits/stdc++.h>


using namespace std;

// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation

class NestedInteger {
   public:
     // Return true if this NestedInteger holds a single integer, rather than a nested list.
     bool isInteger() const;

     // Return the single integer that this NestedInteger holds, if it holds a single integer
     // The result is undefined if this NestedInteger holds a nested list
     int getInteger() const;

     // Return the nested list that this NestedInteger holds, if it holds a nested list
     // The result is undefined if this NestedInteger holds a single integer
     const vector<NestedInteger> &getList() const;
 };


class NestedIterator {
public:

        vector<int> res;
        int idx = 0;

    void helper(vector<NestedInteger>& v){

        for(int i = 0;i<v.size();i++){

            if(v[i].isInteger())
                res.push_back(v[i].getInteger());
            
            else
              helper(v[i].getList());
        }

    };

    NestedIterator(vector<NestedInteger> &nestedList) {

          for(int i = 0; i < nestedList.size();i++){

              if(nestedList[i].isInteger())
               res.push_back(nestedList[i].getInteger());

              else
                helper(nestedList[i].getList());

          }
        
    }

 
    int next() {
        
        return res[idx++];
    }
    
    bool hasNext() {
        
        return idx < res.size();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */