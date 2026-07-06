class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, right = 0;
        int minLength = INT_MAX;
        int currSum = 0;

        while(right < nums.size()){
            currSum += nums[right];
            while(currSum >= target){
                int length = (right-left) + 1;
                minLength = min(minLength, length);
                currSum -= nums[left];
                left++;
            }
            right++;
        }

        return minLength == INT_MAX ? 0 : minLength ;
    }
};