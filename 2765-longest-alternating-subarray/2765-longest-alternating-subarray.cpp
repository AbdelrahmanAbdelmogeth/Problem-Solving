class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
        int max_length = -1; // If no valid subarray, this will be the output
        int n = nums.size();
        
        for (int i = 0; i < n - 1; ++i) {
            int length = 1;
            bool expect_increase = true;
            
            for (int j = i + 1; j < n; ++j) {
                if (expect_increase && nums[j] == nums[j - 1] + 1) {
                    length++;
                    expect_increase = false;
                } else if (!expect_increase && nums[j] == nums[j - 1] - 1) {
                    length++;
                    expect_increase = true;
                } else {
                    break;
                }
            }
            
            if (length > 1) {
                max_length = max(max_length, length);
            }
        }
        
        return max_length;
    }
};
