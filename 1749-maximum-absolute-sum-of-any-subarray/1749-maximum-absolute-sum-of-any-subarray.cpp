class Solution {
public:

    int maxAbsoluteSum(vector<int>& nums) {
        
        int maxSum = nums[0];
        int minSum = nums[0];

        int currSumMax = nums[0];
        int currSumMin = nums[0];

        for(int i=1; i<nums.size(); i++){
            currSumMax = max(currSumMax + nums[i], nums[i]);
            currSumMin = min(currSumMin + nums[i], nums[i]);

            maxSum = max(maxSum, currSumMax);
            minSum = min(minSum, currSumMin);
        }

        return max( maxSum, abs(minSum) );
    }
};