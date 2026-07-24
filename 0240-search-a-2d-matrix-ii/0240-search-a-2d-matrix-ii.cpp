class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int rowIndex = 0, colIndex = n-1;

        while(rowIndex < m && colIndex >= 0){

            int el = matrix[rowIndex][colIndex];

            if(el == target) return true;
            else if(el > target){
                colIndex--;
            }
            else{
                rowIndex++;
            }
        }
        return  false;
    }
};