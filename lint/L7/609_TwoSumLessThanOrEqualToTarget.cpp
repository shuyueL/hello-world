/*Given an array of integers, find how many pairs in the array
such that their sum is less than or equal to a specific target number. 
Please return the number of pairs.

Example
Given nums = [2, 7, 11, 15], target = 24. 
Return 5. 
2 + 7 < 24
2 + 11 < 24
2 + 15 < 24
7 + 11 < 24
7 + 15 < 25*/

//jiuzhang
class Solution {
public:
    /**
     * @param nums an array of integer
     * @param target an integer
     * @return an integer
     */
    int twoSum5(vector<int> &nums, int target) {
        // Write your code here
        int n = nums.size(), cnt = 0;
        sort(nums.begin(), nums.end());
        int l = 0, r = nums.size() -1;
        while (l < r){
            if (nums[l] + nums[r] > target){
                r--;
            } else {
                cnt += r - l;
                l++;
            }
        }
        return cnt;
    }
};
