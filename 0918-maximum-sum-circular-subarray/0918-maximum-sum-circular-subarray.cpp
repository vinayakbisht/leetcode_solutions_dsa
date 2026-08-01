class Solution {
public:
    int maxSubarraySum(vector<int> &nums){
        int n = nums.size();
        int maxSum = nums[0];
        int sum = nums[0];
        for(int i=1; i<n; i++){
            sum = max(sum+nums[i], nums[i]);
            maxSum = max(maxSum, sum);
        }
        return maxSum;
    } 
    int minSubarraySum(vector<int> &nums){
        int n = nums.size();
        int minSum = nums[0];
        int sum = nums[0];
        for(int i=1; i<n; i++){
            sum = min(sum+nums[i], nums[i]);
            minSum = min(minSum, sum);
        }
        return minSum;
    } 

    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        //1 
        int totalSum = accumulate(begin(nums), end(nums), 0);
        
        //2
        int maxSum = maxSubarraySum(nums);    // case 1
        
        //3
        int minSum = minSubarraySum(nums);

        // 4
        int circular_sum = totalSum - minSum ;      // case 2 

        if(maxSum > 0){
          return  max(circular_sum, maxSum);
        }
        return maxSum;
    }
};