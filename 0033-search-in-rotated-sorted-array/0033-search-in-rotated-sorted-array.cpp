class Solution {
public:

    int pivot(vector<int>& nums){

        //pivot is the min value index

        int low = 0, high = nums.size()-1;

        while(low < high){
            int mid = low+(high-low)/2;

            if(nums[mid] > nums[high]){
                low = mid+1;
            }else if(nums[mid] < nums[high]){
                high = mid;
            }
        }

        return high;  
    }
    int binarySearch(vector<int>& nums ,int low, int high, int target){
        
        while(low <= high){
            int mid = low+(high-low)/2;

            if(nums[mid] == target) return mid;
            else if(nums[mid] > target){
                high = mid-1;
            } else{
                low = mid+1;
            }
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        int n = nums.size();

        if(target > nums[n-1] && target <nums[0]) return -1;
        int pivotIdx = pivot(nums);

        // applying binary search on two parts

        int idx = binarySearch(nums, 0, pivotIdx - 1, target );

        if(idx != -1){
            return idx;
        }
        
        int idx2 = binarySearch(nums, pivotIdx, n-1, target);

        return idx2;
    }
};