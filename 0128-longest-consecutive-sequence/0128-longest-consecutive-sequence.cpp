class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0 || nums.size() == 1)
            return nums.size();
        
        unordered_set<int> nums_set;
        for(auto x: nums)
            nums_set.insert(x);
        
        int curr_length = 0;
        int max_length = 0;
        int number = 0;
        for(int i=0; i<nums.size(); i++){
            number = nums[i];
            if(nums_set.find(number - 1) == nums_set.end()){ //That means there is a longer sequence checked or will be checked 
                curr_length = 1;
                while(nums_set.find(++number) !=  nums_set.end()){
                    curr_length++;
                }  
                max_length = max(curr_length,max_length);
            }  
        }
        return max_length;
    }
};