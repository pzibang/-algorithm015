

class Solution {

private:
    vector<vector<int>> ans;
    vector<int> output;
    void backtracking(int first, int len){
        if(first == len){
            ans.push_back(output);
            return ;
        }

        for(int i = first; i <len; i++){
            swap(output[i], output[first]);
            backtracking(first+1, len);
            swap(output[i], output[first]);
        }
    }
public:

    vector<vector<int>> permute(vector<int>& nums) {
        output.assign( nums.begin(), nums.end() );
        backtracking(0, nums.size());
        return ans;
    }
};
