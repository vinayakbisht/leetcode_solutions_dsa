class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mpp; 
        int count= 0, i=0 , i_bada=0;

        for(int j=0; j<n; j++){
            mpp[nums[j]]++;
            //handle invalid subarray - Shrink
            while(mpp.size() > k){
                if(--mpp[nums[i]] == 0){
                    mpp.erase(nums[i]);
                };
                i++;
                i_bada = i;
            };
            //handle to find the smallest valid subarray ending at j - By shrinking
            while( mpp[nums[i]] > 1) {
                mpp[nums[i]]--;
                i++;
            }
            if(mpp.size() == k){
                count += (i-i_bada) + 1;
            }
            
        }
        return count;
    }

};