//703. Kth Largest Element in a Stream


class KthLargest {
public:
    int k;
    priority_queue<int,vector<int>,greater<int> > nums;
    int res;
    KthLargest(int k, vector<int>& nums) {
        this->nums = nums;
        this->k = k;
        for(int i = 0; i < nums.size(); i ++){
            priority_queue.push(nums[i]);
        }
        while(this->nums.size() > k){
            this->nums.pop();
        }
        this->res = this.top();
    }
    
    int add(int val) {
        if(this->top > val)return this->res;
        this->nums.pop();
        this->nums.push(val);
        this->res = this->nums.top();
        return this->res;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */