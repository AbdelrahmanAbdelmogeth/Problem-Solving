class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Min-heap: (distance, point)
        priority_queue<
            pair<int, vector<int>>,
            vector<pair<int, vector<int>>>,
            greater<pair<int, vector<int>>>
        > pq;

        for(vector<int> point : points){
            int distance = ((point[0])*(point[0])) + ((point[1])*(point[1]));
            pq.push({distance, point});
        }

        vector<vector<int>> res;
        for(int i=0; i<k; i++){
            vector<int> point = pq.top().second;
            res.push_back(point);
            pq.pop();
        }

        return res;
    }
};