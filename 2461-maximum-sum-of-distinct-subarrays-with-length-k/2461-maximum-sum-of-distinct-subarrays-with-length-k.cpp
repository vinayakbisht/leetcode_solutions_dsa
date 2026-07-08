class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        int n = nums.size();
        long long maxSum = 0, currSum = 0;
        int i=0, j=0;

        while(j<n){
            currSum += nums[j];
            mpp[nums[j]]++;

            if(j-i+1 == k){
                if(mpp.size() == k){
                    maxSum = max(maxSum, currSum);
                }

                currSum -= nums[i];
                if(--mpp[nums[i]] == 0){
                    mpp.erase(nums[i]);
                }
                i++;
            }
            j++;
        }
        return maxSum;
    }
};