//1. violent method 
//time complexity: O(n*k)
// move the tail element to the front for three times


class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int last = nums.size()-1;
        for(int i = 0; i < k; i++){
            //rearward 
            int tmp = nums[last];
            for(int j = last; j > 0 ; j--){
                nums[j] = nums[j-1];
            }
            nums[0] = tmp;
        }
    }
};


//2. extra array

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
       int len = nums.size();
       vector<int> ans(len, 0);

       for(int i = 0; i< len; i++){
           ans[ (i+k)%len] = nums[i];
       }

       for(int i = 0; i< len; i++){
           nums[i] = ans[i];
       }
    }
};
