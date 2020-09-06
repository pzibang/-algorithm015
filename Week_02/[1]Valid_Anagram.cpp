//1. sort the string and compare them

class Solution {
public:
    bool isAnagram(string s, string t) {
        if ( s.length() != t.length()) {
            return false;
        }

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        return (s == t);
    }
};

//2. hash table
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        
        unordered_map<char, int> umap;
        for (int i = 0; i < s.size(); ++i) {
            umap[s[i]]++;
            umap[t[i]]--;
        }

        for (auto ch : umap) {
            if (ch.second != 0) {
                return false;
            }
        }

        return true;
    }
};


