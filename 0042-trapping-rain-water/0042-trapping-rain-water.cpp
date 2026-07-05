class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int totalWater = 0;
        int left = 0, right = n-1;
        int leftMax=height[left] , rightMax = height[right];

        while(left < right){
            if(leftMax < rightMax){
                left++;
                leftMax = max(leftMax, height[left]);
                totalWater += leftMax - height[left];
            } else {
                right--;
                rightMax = max(rightMax, height[right]);
                totalWater += rightMax - height[right];
            }
        }
        return totalWater;
    }
};