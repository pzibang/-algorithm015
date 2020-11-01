

class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> ans(26, 0);
        int len = s.length();

        for(int i = 0; i < len; i++){
            ans[s[i] - 'a'] += 1;
        }

        for(int j = 0; j < len; j++){
            if(ans[s[j] - 'a'] == 1){
                return j;
            }
        }

        return -1;
    }
};


class Solution {
public:
    int firstUniqChar(string s) {
        map<char, int> ans;
        int len = s.length();

        for(int i = 0; i < len; i++){
            if(ans.find(s[i]) == ans.end()){
                ans[s[i]] = 1;
            }
            else{
                ans[s[i]] += 1;
            }
        }

        for(int j = 0; j < len; j++){
            if(ans[s[j]] == 1){
                return j;
            }
        }

        return -1;
    }
};
