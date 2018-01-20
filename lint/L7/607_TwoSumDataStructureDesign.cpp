/*Design and implement a TwoSum class. It should support the following operations: add and find.

add - Add the number to an internal data structure.
find - Find if there exists any pair of numbers which sum is equal to the value.

add(1); add(3); add(5);
find(4) // return true
find(7) // return false*/

//jiuzhang
class TwoSum {
public:
    unordered_multiset<int> nums;
    // Add the number to an internal data structure.
    void add(int number) {
        // Write your code here
        nums.insert(number);
    }

    // Find if there exists any pair of numbers which sum is equal to the value.
    bool find(int value) {
        // Write your code here
        for (int i : nums) {
            int count = i == value - i ? 2 : 1;
            if (nums.count(value - i) >= count) {
                return true;
            }
        }
        return false;
    }
};


// Your TwoSum object will be instantiated and called as such:
// TwoSum twoSum;
// twoSum.add(number);
// twoSum.find(value);
