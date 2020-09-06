class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int ,int> counts;
        priority_queue<int, vector<int>, greater<int>> max_k;
        for(int i: nums){
            ++counts[i];
        }

        for(auto & j: counts){
            max_k.push(j.second);
            while(max_k.size() > k) max_k.pop();
        }

        vector<int> res;
        for(auto & k: counts){
            if(k.second >= max_k.top()){
                res.push_back(k.first);
            }
        }

        return res;
    }
};
