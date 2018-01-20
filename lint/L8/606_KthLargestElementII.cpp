/*Find K-th largest element in an array. and N is much larger than k.

 Notice

You can swap elements in the array

Example
In array [9,3,2,4,8], the 3rd largest element is 4.

In array [1,2,3,4,5], the 1st largest element is 5, 2nd largest element is 4, 3rd largest element is 3 and etc.*/


//jiuzhang
class Solution {
public:
    /**
     * @param nums an integer unsorted array
     * @param k an integer from 1 to n
     * @return the kth largest element
     */
    int kthLargestElement2(vector<int> nums, int k) {
        // Write your code here
        priority_queue<int, vector<int>, greater<int> > que;
        int n = nums.size();
        for(int i = 0; i < n; i ++) {
            if(que.size() == k) {
                if(nums[i] > que.top()) {
                    que.pop();
                    que.push(nums[i]);
                }
            }else {
                que.push(nums[i]);
            }
        }
        return que.top();
    }
};
