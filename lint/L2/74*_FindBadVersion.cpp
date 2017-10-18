/* The code base version is an integer start from 1 to n. One day, someone committed a bad version in the code case, 
so it caused this version and the following versions are all failed in the unit tests. 
Find the first bad version.
You can call isBadVersion to help you determine which version is the first bad one. 
The details interface can be found in the code's annotation part.*/

//mine: time limit exceeded, only one line different with JiuZhang answer
class Solution {
public:
    /**
     * @param n: An integers.
     * @return: An integer which is the first bad version.
     */
    int findFirstBadVersion(int n) {
        // write your code here
        int start = 1, end = n, med;
        while (start + 1< end) {
            med = (start + end)/2;
            if (SVNRepo::isBadVersion(med)){
                end = med;
            } else {
                start = med +1;  // different
            }
        }
        if (SVNRepo::isBadVersion(start)){
            return start;
        }
        return end;
    }
};


//jiuzhang:
class Solution {
public:
    /**
     * @param n: An integers.
     * @return: An integer which is the first bad version.
     */
    int findFirstBadVersion(int n) {
        int start = 1, end = n;
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (SVNRepo::isBadVersion(mid)) {
                end = mid;
            } else {
                start = mid;
            }
        }
        
        if (SVNRepo::isBadVersion(start)) {
            return start;
        }
        return end;
    }
};
