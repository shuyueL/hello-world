/* 585: Given a mountain sequence of n integers which increase firstly and then decrease, find the mountain top.*/

//mine
class Solution {
public:
    /*
     * @param nums: a mountain sequence which increase firstly and then decrease
     * @return: then mountain top
     */
    int mountainSequence(vector<int> &nums) {
        // write your code here
        int n = nums.size();
        int i = 0, j = n-1, med;
        while(i < j){
            med = (i+j)/2;
            if(nums[med] >= nums[med-1] && nums[med] >= nums[med+1]){
                return nums[med];
            }else if(nums[med]< nums[med-1]){
                j = med-1;
            }else {
                i = med+1;
            }
        }
        return nums[i];
    }
};

//jiuzhang
class Solution {
public:
    /**
     * @param nums a mountain sequence which increase firstly and then decrease
     * @return then mountain top
     */
    int mountainSequence(vector<int>& nums) {
        // Write your code here
        int left = 0, right = nums.size() - 1;
        while (left + 1 < right) {
            int m1 = left + (right - left) / 2;
            int m2 = right - (right - m1) / 2;
            if (nums[m1] < nums[m2]) {
                left = m1 + 1;
            } else if (nums[m1] > nums[m2]) {
                right = m2 - 1;
            } else {
                left = m1;
                right = m2;
            }
        }
        return nums[left] > nums[right] ? nums[left] : nums[right];
    }
};
