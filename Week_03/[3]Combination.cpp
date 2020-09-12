class Solution {
private:
    vector<vector<int>> ans;
    vector<int> path;

    void backtracking(int n, int k, int startIndex){
        //recursion terminator
        if(path.size() == k){
            ans.push_back(path);
            return ;
        }
        //process logic
        //drill down
        for(int i = startIndex; i<=n; i++){
            path.push_back(i);
            backtracking( n,  k, i+1);
            path.pop_back();
        }

        //reserve current static if needed
    }

public:
    vector<vector<int>> combine(int n, int k) {
        backtracking(n, k, 1);
        return ans;
    }
};
