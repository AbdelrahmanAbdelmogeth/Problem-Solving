class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq; 
        for(int num : nums){
            pq.push(num);
        }

        int res = 0;
        for(int i=1; i<=k; i++){
            if(i == k)
                res = pq.top();
            pq.pop();    
        }

        return res;
    }
};