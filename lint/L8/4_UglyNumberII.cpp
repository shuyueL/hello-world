/*Ugly number is a number that only have factors 2, 3 and 5.

Design an algorithm to find the nth ugly number. The first 10 ugly numbers are 1, 2, 3, 4, 5, 6, 8, 9, 10, 12...

 Notice

Note that 1 is typically treated as an ugly number.

Example
If n=9, return 10.*/

//jiuzhang
class Solution {
public:
    /*
     * @param n an integer
     * @return the nth prime number as description.
     */
    int nthUglyNumber(int n) {
        int *uglys = new int[n];
        uglys[0] = 1;
        int next = 1;
        int *p2 = uglys;
        int *p3 = uglys;
        int *p5 = uglys;
        while (next < n){
            int m = min(min(*p2 * 2, *p3 * 3), *p5 * 5);
            uglys[next] = m;
            while (*p2 * 2 <= uglys[next])
                *p2++;
            while (*p3 * 3 <= uglys[next])
                *p3++;
            while (*p5 * 5 <= uglys[next])
                *p5++;
            next++;
        }
        int uglyNum = uglys[n - 1];
        delete[] uglys;
        return uglyNum;
    }
};
