/* 28: Write an efficient algorithm that searches for a value in an m x n matrix.

This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.*/


// mine
class Solution {
public:
    /**
     * @param matrix, a list of lists of integers
     * @param target, an integer
     * @return a boolean, indicate whether matrix contains target
     */
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // write your code here
        if(matrix.empty()){
            return false;
        }
        int m = matrix.size();
        if(target < matrix[0].front() || target > matrix[m-1].back()){
            return false;
        }
        int i = 0, j = m-1, row = -1;
        while( i <= j){
            int mid = (i+j)/2;
            if(target < matrix[mid].front()){
                j = mid -1;
            }else if(target > matrix[mid].back()){
                i = mid + 1;
            }else{
                row = mid;
                break;
            }
        }
        if(row == -1){
            return false;
            }
        i =0, j = matrix[row].size()-1;
        while( i <= j){
            int mid = (i+j)/2;
            if(target < matrix[row][mid]){
                j = mid-1;
            }else if(target > matrix[row][mid]){
                i = mid+1;
            }else{
                return true;
            }
        }
        return false;
    }
};


// jiuzhang
class Solution {
public:
    /**
     * @param matrix, a list of lists of integers
     * @param target, an integer
     * @return a boolean, indicate whether matrix contains target
     */
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int n = matrix.size();
        if (n == 0) {
            return false;
        }
        
        int m = matrix[0].size();
        if (m == 0) {
            return false;
        }
        
        int start = 0, end = n * m - 1;
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            int row = mid / m;
            int col = mid % m;
            
            if (matrix[row][col] < target) {
                start = mid;
            } else {
                end = mid;
            }
        }
        
        if (matrix[start / m][start % m] == target) {
            return true;
        }
        
        if (matrix[end / m][end % m] == target) {
            return true;
        }
        
        return false;
    }
};

