class CountSquares {
public:
    map<pair<int,int>, int> ptsCount;
    vector<vector<int>> pts;
    CountSquares() {
        
    }
    
    void add(vector<int> point) {
        ptsCount[{point[0], point[1]}]++;
        pts.push_back(point);
    }
    
    int count(vector<int> point) {
        int px = point[0];
        int py = point[1];

        int res = 0;

        for(vector<int> pt : pts) {
            int x = pt[0];
            int y = pt[1];

            if(abs(px-x) != abs(py-y) || px == x || py == y) continue;

            res += ptsCount[{x, py}] * ptsCount[{px, y}];

        }
        return res;
    }
};
