class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        k1 = k;
        for(const auto& num : nums){
            add(num);
        }
        
    }
    
    int add(int val) {
        
        pq.push(val);
        if(pq.size()>k1){
            pq.pop();
        }
        
        return pq.top();
    }
private:
    int k1;
    priority_queue<int, vector<int>,greater<int>> pq;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */