class Solution {
public:
    bool isPowerOfTwo(int n) {
        //get the right 1
        if(n <= 0){
            return false;
        }
        return ((n & (-n)) == n )?true:false;
    }
};
