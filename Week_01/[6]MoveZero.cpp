//1. violent method 
//put the no zero elements in the array and count the
//number of zero 
// put zero at the end of array

//2. snow ball method
//
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int SnowBallSize = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0){
                SnowBallSize++;
            }
            else if(SnowBallSize > 0){
                int tmp = nums[i];
                nums[i] = 0;
                nums[i- SnowBallSize] = tmp;
            }
        }
    }
};

//3. double pointers
//fast pointer traverse 
//slow pointer pointer to zero
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int SnowBallSize = 0;
        int j = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != 0){
                int tmp = nums[i];
                nums[i] = nums[j];
                nums[j++] = tmp;
            }
        }
    }
};
