class TimeMap {
private:
    unordered_map<string, map<int, string>> key_timestamp_value;
public:
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        key_timestamp_value[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        if (key_timestamp_value.find(key) == key_timestamp_value.end()) {
            return "";
        }
        
        auto it = key_timestamp_value[key].upper_bound(timestamp);
        if (it == key_timestamp_value[key].begin()) {
            return "";
        }
        
        --it;
        return it->second;
    }
};
/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */