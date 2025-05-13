class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();
        priority_queue<int> pq;
        for(int stone : stones)
            pq.push(stone);

        while(n > 1){
            int y_stone = pq.top();
            pq.pop();
            n--;
            int x_stone = pq.top();
            pq.pop();
            n--;

            if(y_stone != x_stone){
                int new_stone = y_stone - x_stone;
                pq.push(new_stone);
                n++;
            }
        }
        if(pq.empty()) return 0;
        return pq.top();
    }
};