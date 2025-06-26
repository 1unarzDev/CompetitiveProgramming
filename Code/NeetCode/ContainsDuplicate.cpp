#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int> has;
        for(int i = 0; i < nums.size(); i++){
            if(has.find(nums[i]) != has.end()) return true;
            else has.insert(nums[i]);
        }
        return false;
    }
};