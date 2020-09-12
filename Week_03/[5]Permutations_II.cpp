class Solution {
private:
    vector<vector<int>> ans;
    void recursion(vector<int> nums, int i, int size){
        if( i == size -1){
            ans.push_back(nums);
        }

        for(int k = i; k < size; k++){
            if(i != k && nums[i] == nums[k]){
                continue;
            }
            swap(nums[i], nums[k]);
            recursion(nums, i+1, size);
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end() );
        recursion(nums, 0, nums.size() );
        return ans;
    }
};

