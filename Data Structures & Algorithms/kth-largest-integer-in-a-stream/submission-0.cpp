class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int k;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(int i=0; i<nums.size(); i++) {
            pq.push(nums[i]);
            if(this->k < pq.size()) {
                pq.pop();
            }
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(this->k < pq.size()) {
            pq.pop();
        }
        return pq.top();
    }
};
