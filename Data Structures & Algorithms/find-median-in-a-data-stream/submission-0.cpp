class MedianFinder {
public:
    vector<double> v;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        double nums = double(num);
        v.push_back(nums);
    }
    
    double findMedian() {
        sort(v.begin(), v.end());
        if(v.size()%2 != 0) {
            return v[v.size()/2];
        }
        
        return (v[(v.size()/2)-1] + v[v.size()/2])/2;
    }
};
