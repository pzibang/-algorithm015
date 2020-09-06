class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> umap;

        for(auto s: strs){
            string tmp = s;
            sort(tmp.begin(), tmp.end());
            umap[tmp].push_back(s);
        }

        vector<vector<string>> anagrams;
        for(auto p :umap){
            anagrams.push_back(p.second);
        }

        return anagrams;
    }
};
