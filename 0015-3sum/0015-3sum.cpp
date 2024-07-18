// Custom hash function for vectors of integers
struct VectorHash {
    size_t operator()(const std::vector<int>& v) const {
        size_t hash = 0;
        for (int val : v) {
            hash ^= std::hash<int>{}(val);
        }
        return hash;
    }
};

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_set<std::vector<int>, VectorHash> myUnorderedSet;
        //set<vector<int>> st; //we can use set as well
        vector<vector<int>> ans;
        for(int i=0; i<nums.size(); i++){
            int left_pointer = i+1, right_pointer = nums.size() - 1;
            while(left_pointer < right_pointer){
                if(nums[i] + nums[left_pointer] + nums[right_pointer] > 0){
                    right_pointer--;
                    continue;
                }else if(nums[i] + nums[left_pointer] + nums[right_pointer] < 0){
                    left_pointer++;
                    continue;
                }else{
                    myUnorderedSet.insert({nums[i], nums[left_pointer], nums[right_pointer]});
                    left_pointer++; right_pointer--;
                }
            }
        }
        for(auto x: myUnorderedSet)
           ans.push_back(x);
        
        return ans;
    }
};