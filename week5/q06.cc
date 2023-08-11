class TimeMap {
public:
    map<string, vector<pair<int, string>>> t;

    TimeMap() {
    }

    void log(vector<pair<int, string>>& bucket) {

        cout << "=-=-=-=\n";
        for (auto [time, val] : bucket) {
            cout << time << ":" << val << "\n";
        }

    }
    
    void set(string key, string value, int timestamp) {
        // sorted insert 
        if (t.find(key) == t.end()) t[key] = {};

        vector<pair<int, string>>& bucket = t[key];

        bucket.push_back({timestamp, value});

    }
    
    string get(string key, int timestamp) {
        // binary search 
        if (t.find(key) == t.end()) return "";
        auto& bucket = t.at(key);

        int l = 0, r = bucket.size()-1;
        string res = "";
        while (l <= r) {
            int m = l + floor((r-l)/2);

            if (bucket.at(m).first <= timestamp) {
                res = bucket.at(m).second;
                l = m+1;
            } else {
                r = m-1;
            }
        }

        return res;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
