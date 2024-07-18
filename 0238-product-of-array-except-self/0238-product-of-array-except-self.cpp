class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> answer(nums.size());
        int n = nums.size();
        
        //the loop for the prefix
        int prefix = 1; //make it neutral
        for(int i=0; i<n; i++){
            answer[i] = prefix;
            prefix = nums[i] * prefix;
        }
        
        
        //the loop that multiblies the postfix 
        int postfix = 1;
        for(int i=n-1; i>=0; i--){
            answer[i] *= postfix;
            postfix = nums[i] * postfix;
        }
       
        return answer;
    }
};