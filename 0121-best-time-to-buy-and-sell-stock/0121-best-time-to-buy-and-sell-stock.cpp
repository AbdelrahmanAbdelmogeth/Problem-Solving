class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 1)
            return 0;
        
        int max_profit = 0;
        int profit =0;
        int left_pointer = 0, right_pointer = 1;
        while(right_pointer < prices.size()){
            if(prices[left_pointer] < prices[right_pointer]){
                 profit = prices[right_pointer] - prices[left_pointer];
                 max_profit = max(profit, max_profit);
            }
            else
                left_pointer = right_pointer;
            
            right_pointer++;
        }
        return max_profit;
        
    }
};