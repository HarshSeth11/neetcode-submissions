class TimeMap {
public:
    unordered_map<string, vector<pair<int,string>>> mp;
    TimeMap() {
        mp = {};
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        vector<pair<int,string>> values = mp[key];
        int n = values.size();

        int l = 0;
        int r = n-1;

        string ans = "";

        while(l <= r) {
            int mid = l + (r-l)/2;

            if(values[mid].first == timestamp) {
                ans = values[mid].second;
                return ans;
            }
            else if(values[mid].first < timestamp) {
                ans = values[mid].second;
                l = mid+1;
            }
            else r = mid-1;
        }

        return ans;
    }
};
 