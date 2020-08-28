//1. violent method
//traverse the array, compare the elements
//if find the same one delete it

//2. double pointer
//fast pointer traverse and slow pointer point to 
//the last equal element 

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        //I always ignore the entrance examination
        if(nums.size() == 0){
            return 0;
        }
        //slow pointer
        int i = 0;
        //fast pointer
        for(int j = 1; j < nums.size(); j++){
            if(nums[j] != nums[i]){
                nums[++i] = nums[j];
            }
        }

        return i+1;
    }
};
