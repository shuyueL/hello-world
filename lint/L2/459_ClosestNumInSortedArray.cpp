/* 459: Given a target number and an integer array A sorted in ascending order, 
find the index i in A such that A[i] is closest to the given target.
Return -1 if there is no element in the array. 
There can be duplicate elements in the array, and we can return any of the indices with same value.*/


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


// jiuzhang soln
class Solution {
public:
    /**
     * @param A an integer array sorted in ascending order
     * @param target an integer
     * @return an integer
     */
    int closestNumber(vector<int>& A, int target) {
        // Write your code here
        int l = 0, r = A.size() - 1;
        if (r < 0)
            return -1;
        int ans = abs(A[0] - target);
        int index = 0;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (ans > abs(A[mid] - target)) {
                ans = abs(A[mid] - target);
                index = mid;
            }
            if (A[mid] >= target)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return index;
    }
};
