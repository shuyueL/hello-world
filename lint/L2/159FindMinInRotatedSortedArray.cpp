/* 159: Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.*/

//mine
class Solution {
public:
    /*
     * @param nums: a rotated sorted array
     * @return: the minimum number in the array
     */
    int findMin(vector<int> nums) {
        // write your code here
        int n = nums.size();
        cout<<n;
        if (n == 0){
            return -1;
        }
        int start = 0, end = n - 1, med;
        while (start + 1 < end){  // a little bit different from former one.
            med = (start + end) / 2;
            if ( nums[start] < nums[end]) {
                return nums[start];
            } else if (nums[med] > nums[start]){
                start = med;
            } else {
                end = med;
            }
        }
        return min(nums[start], nums[end]);
    }
};


// jiuzhang
class Solution {
public:
    /**
     * @param nums: a rotated sorted array
     * @return: the minimum number in the array
     */
    int findMin(vector<int> &nums) {
        // write your code here
        int left = 0, right = nums.size() - 1;
        while (nums[left] > nums[right]) {
            int mid = (left + right) / 2;

            if (nums[mid] >= nums[left] && nums[mid] > nums[right])
                left = mid+1;
            else
                right = mid;
        }

        return nums[left];
    }
};
