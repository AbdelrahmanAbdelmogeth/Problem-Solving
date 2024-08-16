class TimeMap {
private:
    // unordered map with key=key --> value = map of timestamp --> value 
    // This stores a map for each key, where the inner map’s key is the timestamp and the value is the corresponding value.
    unordered_map<string, map<int, string>> key_timestamp_value;
public:
    TimeMap() {
    }
    //inserts the value in the inner map of the given key and timestamp
    void set(string key, string value, int timestamp) {
        key_timestamp_value[key][timestamp] = value;
    }

    // This method finds the closest previous timestamp if the exact timestamp doesn’t exist.
    string get(string key, int timestamp) {
        //Here check for the key at first if it doesn't exist return an empty string
        if (key_timestamp_value.find(key) == key_timestamp_value.end()) {
            return "";
        }
        //This line finds the first element in the map whose key is greater than the given timestamp 
        auto it = key_timestamp_value[key].upper_bound(timestamp);
        //if the iterator points to the start of the map why?
        //it means that all elements in the map have keys greater than the given timestamp. 
        //In other words, no elements with keys less than or equal to the given timestamp exist.
        if (it == key_timestamp_value[key].begin()) {
            return "";
        }

        --it; //This line moves the iterator one step back to point to the largest key that is less than or equal to the given timestamp
        return it->second; //return the value with keys less than or equal to the given timestamp
    }
};
/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
