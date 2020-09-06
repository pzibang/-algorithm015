
//1. violent method 
//traverse the array and plus two elements
//if the sum equal the target ,break
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        if (nums.size() == 0) {
            return {};
        }

        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }

        return {};
    }
};


//2. hash table
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> umap;

        for (int i = 0; i < nums.size(); i++) {
            umap[nums[i]] = i;
        }

        for (int i = 0; i < nums.size(); i++) {
            int comment = target - nums[i];
            if ( (umap.find(comment) != umap.end()) && ( umap[comment] != i) ) {
                return { i,umap[comment] };
            }
        }
        return {};
    }
};
