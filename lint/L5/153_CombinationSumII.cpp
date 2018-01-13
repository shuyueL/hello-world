/*Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

 Notice

All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
Given candidate set [10,1,6,7,2,1,5] and target 8,

A solution set is:

[
  [1,7],
  [1,2,5],
  [2,6],
  [1,1,6]
] */

//jiuzhang
class Solution {
public:
    /**
	 * @param num: Given the candidate numbers
	 * @param target: Given the target number
	 * @return: All the combinations that sum to target
	 */
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
		// write your code here
        sort(num.begin(), num.end());
        vector<int> stack, rec; int sum=0, cur=0;
        vector<vector<int> > ans;
        while (cur<num.size() && num[cur]+sum<=target) {
			stack.push_back(num[cur]);
			rec.push_back(cur);
			sum+=num[cur++];
		}
		if (sum==target) ans.push_back(stack);
		while (rec.size()!=0) {
			cur=rec.back(); int x=num[cur];
			sum-=x; stack.pop_back(); rec.pop_back();
			for (++cur; cur<num.size(); ++cur)
				if (num[cur]!=x || sum+num[cur]>target) break;
			if (cur<num.size() && num[cur]!=x)
				while (cur<num.size() && num[cur]+sum<=target) {
					stack.push_back(num[cur]);
					rec.push_back(cur);
					sum+=num[cur++];
				}
			if (sum==target) ans.push_back(stack);
		}
		return ans;
    }
};
