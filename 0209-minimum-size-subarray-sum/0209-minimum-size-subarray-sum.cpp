class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0;
        int minLength = INT_MAX;
        int sum = 0;

        for(int r=0; r<nums.size(); r++){
            sum += nums[r];
            while(sum >= target){
                int length = r-l + 1;
                minLength = min(minLength, length);
                sum -= nums[l];
                l++;
            }
        }

        return minLength == INT_MAX ? 0 : minLength ;
    }
};