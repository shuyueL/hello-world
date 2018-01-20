/*Given an array nums of n integers, find two integers in nums such that the sum is closest to a given number, target.

Return the difference between the sum of the two integers and the target.

Example
Given array nums = [-1, 2, 1, -4], and target = 4.

The minimum difference is 1. (4 - (2 + 1) = 1).*/


//jiuzhang
class Solution {
public:
    /**
     * @param nums an integer array
     * @param target an integer
     * @return the difference between the sum and the target
     */
    int twoSumClosest(vector<int>& nums, int target) {
        // Write your code here
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int j = n - 1;
        int diff = 0x7fffffff;
        for (int i = 0; i < n; ++i) {
            while (i < j && nums[i] + nums[j] > target) {
                if (nums[i] + nums[j] - target < diff)
                    diff = nums[i] + nums[j] - target;
                j --;
            }
            
            if (i >= j)
                break;

            if (target - nums[i] - nums[j] < diff)
                diff = target - nums[i] - nums[j];
        }

        return diff;
    }
};

