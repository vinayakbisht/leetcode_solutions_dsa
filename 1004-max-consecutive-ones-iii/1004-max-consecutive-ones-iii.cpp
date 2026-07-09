class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int countZero = 0;
        int l = 0;
        for(int r=0; r<nums.size(); r++){
            if(nums[r] == 0){
                countZero++;
            }
            if(countZero > k){
                if(nums[l] == 0){
                    countZero--;
                }
                l++;
            }
        }
        return nums.size()-l;
    }
};