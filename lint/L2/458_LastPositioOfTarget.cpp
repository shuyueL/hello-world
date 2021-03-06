/*458 :Find the last position of a target number in a sorted array. Return -1 if target does not exist.*/


//mine
class Solution {
public:
    /**
     * @param A an integer array sorted in ascending order
     * @param target an integer
     * @return an integer
     */
    int lastPosition(vector<int>& A, int target) {
        // Write your code here
        int n = A.size();
        int pos = -1;
        int i = 0, j = n-1, mid, number;
        if (n == 0 ||A[0] > target || A[n-1] < target) {
            return -1;
        }
        while (i +1 < j) {
            mid = i + (j - i) /2;
            number = A[mid];
            if (number <= target) {
                i = mid;
            } else {
                j = mid;
            }
        }
        if (A[j] == target) {
            return j;
        }
        if (A[i] == target) {
            return i;
        }
        return -1;
    }
};

//jiuzhang
class Solution {
public:
    /**
     * @param A an integer array sorted in ascending order
     * @param target an integer
     * @return an integer
     */
    int lastPosition(vector<int>& A, int target) {
        // Write your code here
        int n = A.size();
        if (n == 0)
            return -1;
        if (A[n-1] < target || A[0] > target)
            return -1;
        
        int l = 0, r = n - 1;
        int end = -1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (A[mid] == target)
                end = mid;
            if (A[mid] <= target) {
                l = mid + 1;
            } else
                r = mid - 1;
        }
        return end;
    }
};
