/*There is an integer array which has the following features:

The numbers in adjacent positions are different.
A[0] < A[1] && A[A.length - 2] > A[A.length - 1].
We define a position P is a peek if:

A[P] > A[P-1] && A[P] > A[P+1]
Find a peak element in this array. Return the index of the peak.
It's guaranteed the array has at least one peak.
The array may contain multiple peeks, find any of them.
The array has at least 3 numbers in it.*/


//mine
class Solution {
public:
    /*
     * @param A: An integers array.
     * @return: return any of peek positions.
     */
    int findPeak(vector<int>& A) {
        // write your code here
        int n = A.size();
        int start = 0, end = n - 1, med;
        while( start +1 < end) {
            med = (start +end) / 2;
            if (A[med] > A[med-1] && A[med] > A[med+1]){
                return med;
            }
            if (A[med] < A[med-1]){
                end = med;
            } else {
                start = med;
            }
        }
        return (start+end)/2;
    }
}; 
