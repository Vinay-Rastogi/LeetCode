#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class MountainArray {
    public:
    
      int get(int index);
      int length();

};

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) 
    {
        int start = 0;
        int end = mountainArr.length()-1;
        int mid ;

        while(start < end)
        {
            mid = start + (end - start)/2;

            if(mountainArr.get(mid) < mountainArr.get(mid+1))
                start = mid +1;
            else 
                end = mid;
            
        }

        int peak = start;
        int left = -1, right = -1;

        start = 0;
        end = peak;
   

        while(start <= end)
        {

            mid = start + (end - start)/2;

            int middle = mountainArr.get(mid);
            if(middle == target)
                left = mid;
            if(middle < target )
                start = mid + 1;
            else 
                end = mid - 1;
            
        }
        
        start = peak;
        end = mountainArr.length()-1;
       
        while(start <= end)
        {
             mid = start + (end - start)/2;

            int middle = mountainArr.get(mid);

            if(middle == target)
                right = mid;
            if(middle > target )
                start = mid + 1;
            else 
                end = mid - 1;
            
        }

        if(left == right)
            return left;
        else if(left != -1 )
            return left;
        else
            return right; 
    }
};

int main(){



    return 0;
}