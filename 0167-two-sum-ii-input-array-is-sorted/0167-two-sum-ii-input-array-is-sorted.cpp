class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left_pointer = 0;
        int right_pointer = numbers.size() - 1;
        
        while(numbers[left_pointer] + numbers[right_pointer] != target){
            if(numbers[left_pointer] + numbers[right_pointer] > target){
                right_pointer--;
                continue;
            }
            if(numbers[left_pointer] + numbers[right_pointer] < target){
                left_pointer++;
                continue;
            }
                
        }
        
        vector<int> ans{++left_pointer, ++right_pointer};
        
        return ans;
    }
};