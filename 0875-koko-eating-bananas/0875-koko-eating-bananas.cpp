#define BRUTE_FORCE_SOLUTION 0

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        #if BRUTE_FORCE_SOLUTION == 1
            int min_eating_speed, max_eating_speed = *max_element(piles.begin(), piles.end());
            for(int i=max_eating_speed; i>=1; i--){
                int hours_taken = 0;
                for(auto x : piles){
                    hours_taken = hours_taken + ceil((double)x / (double)i);
                    //cout<<hours_taken<<"   "<<min_eating_speed<<'\n';
                }

                if(hours_taken <= h){
                    min_eating_speed = i;
                }  

                //cout<<min_eating_speed<<"  "<<hours_taken<<'\n';
            }
            return min_eating_speed;
        
        #else
            // Binary Search Solution
            int min_eating_speed=1, max_eating_speed = *max_element(piles.begin(), piles.end());
            int res = max_eating_speed;
            while(min_eating_speed <= max_eating_speed){
                int k = min_eating_speed + (max_eating_speed - min_eating_speed)/2;
                long hours_taken = 0;
                for(auto x : piles){
                    hours_taken = hours_taken + ceil((double)x / (double)k);
                    //cout<<min_eating_speed<<"  "<<max_eating_speed<<"  "<<k<<"  "<<hours_taken<<'\n';
                }

                if(hours_taken <= h){
                    res = min(res, k);
                    max_eating_speed = k - 1;
                }else
                    min_eating_speed = k + 1;
             }
        
             return res;
        #endif
    }
};