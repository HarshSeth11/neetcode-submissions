class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,double>> cars;

        for(int i=0; i<position.size(); i++) {
            double time = double(target-position[i])/speed[i];
            cars.push_back({position[i], time});
        }

        sort(cars.begin(), cars.end());
        stack<double> st;

        for(int i=speed.size()-1; i>=0; i--) {
            cout<<cars[i].second<<endl;
            if(!st.empty() && st.top() >= cars[i].second) continue;
            else st.push(cars[i].second);
        }

        return st.size();
    }
};
