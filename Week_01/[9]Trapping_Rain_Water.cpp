class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        int size = height.size();
        if(size <= 2){
            return 0;
        }
        for(int i = 1; i < size -1; i++){
            int max_left = 0, max_right = 0;
            //max left
            for(int j = i; j >= 0; j--){
                if(height[j] > max_left){
                    max_left = height[j];
                }
            }

            //max right 
            for(int k = i; k < size; k++){
                if(height[k]>max_right){
                    max_right = height[k];
                }
            }

            //sum the area
            ans += min(max_left, max_right) - height[i];          
        }
        return ans;
    }
};
