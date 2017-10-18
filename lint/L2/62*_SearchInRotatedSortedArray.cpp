/*Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.*/

//mine
class Solution {
public:
    /*
     * @param A: an integer rotated sorted array
     * @param target: an integer to be searched
     * @return: an integer
     */
    int search(vector<int> &A, int target) {
        // write your code here
        int n = A.size();
        if (n == 0){
            return -1;
        }
        int start = 0, end = n-1, med;
        while (start + 1 < end){
            med = (start + end)/2;
            if (A[med] == target){
                return med;
            }
            if (target >= A[0]){
                if (A[med]<A[0]) {
                    end = med;
                } else if(A[med] < target) {
                    start = med;
                } else {
                    end = med;
                }
            } else {
                if (A[med] > A[0]) {
                    start = med;
                } else if ( A[med] < target) {
                    start = med;
                } else {
                    end = med;
                }
            }
        }
        if (A[start] == target) {
            return start;
        }
        if (A[end] == target) {
            return end;
        }
        return -1;
    }
};

//jiuzhang
#include <vector>

using namespace std;

class Solution {
    /** 
     * param A : an integer ratated sorted array
     * param target :  an integer to be searched
     * return : an integer
     */
private:
int find(vector<int> &A, int l, int r, int target) {
        if (l > r) {
            return -1;
        }
        int idx = -1;
        if (A[l] <= A[r]) {
            int left = l, right = r, mid = 0;
            while (left <= right) {
                mid = (left + right) >> 1;
                if (A[mid] == target) {
                    idx = mid;
                    break;
                }
                else if (A[mid] > target) {
                    right = mid - 1;
                }
                else {
                    left = mid + 1;
                }
            }
        }
        else {
            int mid = (l + r) >> 1;
            if (A[mid] == target) {
                idx = mid;
            }
            else {
                idx = find(A, l, mid - 1, target);
                idx = idx == -1 ? find(A, mid + 1, r, target) : idx;               
            }
        }        
        return idx;
}
public:
    int search(vector<int> &A, int target) {
        // write your code here
        int n = A.size();
        return find(A,0,n-1,target);
    }
};

