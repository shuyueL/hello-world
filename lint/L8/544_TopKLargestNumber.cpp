/*Given an integer array, find the top k largest numbers in it.

Example
Given [3,10,1000,-99,4,100] and k = 3.
Return [1000, 100, 10].*/

//jiuzhang
bool cmp(const int& a, const int& b) {
    return a > b;
}

class Solution {
public:
    /*
     * @param nums an integer array
     * @param k an integer
     * @return the top k largest numbers in array
     */
    vector<int> topk(vector<int>& nums, int k) {
        // Write your code here
        priority_queue<int, vector<int>, greater<int>> queue;
        int n = nums.size();
        for (int i = 0; i < k; ++i)
            queue.push(nums[i]);

        for (int i = k; i < n; i ++) {
            if(nums[i] > queue.top()) {
                queue.pop();
                queue.push(nums[i]);
            }
        }

        vector<int> topk;
        for (int i = 0; i < k; ++i) {
            topk.push_back(queue.top());
            queue.pop();
        }

        sort(topk.begin(), topk.end(), cmp);
        return topk;
    }
};
