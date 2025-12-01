class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> timemap;

    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        timemap[key].push_back({ timestamp, value });
    }
    
    string get(string key, int timestamp) {
        vector<pair<int,string>>& entries = timemap[key];
        int left = 0;
        int right = entries.size() - 1;
        string result = "";

        while (left <= right) {
            int mid = (left + right) / 2;
            if (entries[mid].first <= timestamp) {
                result = entries[mid].second;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return result;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */