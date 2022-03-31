class FreqStack {
public:
    int maxFreq = 0;
    unordered_map<int, int> val_freq;
    unordered_map<int, vector<int>> freq_stack;

    FreqStack() {
        
    }
    
    void push(int val) {
        int temp = ++val_freq[val];
        maxFreq = maxFreq > temp ? maxFreq : temp;
        freq_stack[temp].push_back(val);    
    }
    
    int pop() {
        int res = freq_stack[maxFreq].back();
        val_freq[res]--;
        freq_stack[maxFreq].pop_back();
        if(freq_stack[maxFreq].empty())maxFreq--;
        return res;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */