class Solution {
public:
    /**
     * @param A an integer array sorted in ascending order
     * @param target an integer
     * @return an integer
     */
    int closestNumber(vector<int>& A, int target) {
        // Write your code here
        int len = A.size();
        if (len == 0) {
            return -1;
        }
        int i = 0, j = len-1, temp;
        if(A[i]>= target) {
            return i;
        }
        if (A[j] <= target) {
            return j;
        }        
        while (1) {
            temp = (i + j) / 2;
            if (A[temp] == target) {
                return temp;
            } 
            if (A[temp]<target){
                i = temp;
            } else {
                j = temp;
            }
            if(j-i <= 1) {
                return abs(A[j]-target) > abs(A[i]-target) ? i:j;
            }
        }
    }
};
