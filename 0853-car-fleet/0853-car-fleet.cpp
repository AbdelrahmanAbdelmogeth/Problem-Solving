struct car{
    
    int pos;
    int speed; 
};

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<car> cars;
        for(int i=0; i<speed.size(); i++)
            cars.push_back({position[i], speed[i]});
        
        std::sort(cars.begin(), cars.end(),  [](const car &a, const car &b){
            return a.pos < b.pos;
        });
        
        stack <float> car_fleet_st;
        int n = cars.size();
        car_fleet_st.push(((float)(target - cars[n-1].pos)/(float)cars[n-1].speed));
        for(int i=n-2; i>=0; i--){
            float time = ((float)(target - cars[i].pos)/(float)cars[i].speed);
            float prev_top_time = car_fleet_st.top();
            car_fleet_st.push(time);
            if(car_fleet_st.size() >= 2 && time <= prev_top_time)
                car_fleet_st.pop();      
        }
        return car_fleet_st.size();
    }
};