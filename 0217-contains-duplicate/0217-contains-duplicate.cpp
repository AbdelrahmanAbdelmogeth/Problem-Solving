class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if(nums.size() == 1)
            return false;
        unordered_map<int,int> nums_map;  
        for(auto x: nums){
            nums_map[x]++;
            if(nums_map[x] == 2)
                return true;  
        } 
        return false;
    }
};