//1.violence method

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int ans = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        for(int i = 0; i< g.size(); ++i){
            for(int j = 0; j< s.size(); ++j){
                if(g[i] <= s[j]){
                    ans++;
                    s.erase(s.begin()+j);
                    break;
                }
            }
        }
        return ans;
    }
};

//2. greed
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int i = 0, j =0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        while((i <g.size()) && (j < s.size())){
            if( g[i] <= s[j]){
                i++;
                j++;
            }
            else{
                j++;
            }
        }
        return i;
    }
};


