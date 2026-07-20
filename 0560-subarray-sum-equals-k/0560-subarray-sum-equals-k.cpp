class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0, sum = 0;
        unordered_map<int,int> mpp;

        for(int i=0; i<n; i++){
            if(i==0) mpp[0] = 1;

            sum += nums[i];

            if(mpp.find(sum-k) != mpp.end()){
                count += mpp[sum-k];   
            }

            mpp[sum]++;
        } 

        return count;
    }
};