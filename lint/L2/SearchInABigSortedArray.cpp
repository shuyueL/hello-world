/*447: Given a big sorted array with positive integers sorted by ascending order. The array is so big so that you can not get the length of the whole array directly, and you can only access the kth number by ArrayReader.get(k) (or ArrayReader->get(k) for C++). Find the first index of a target number. Your algorithm should be in O(log k), where k is the first index of the target number.

Return -1, if the number doesn't exist in the array.*/


// mine
class Solution {
public:
    /*
     * @param reader: An instance of ArrayReader.
     * @param target: An integer
     * @return: An integer which is the first index of target.
     */
    int searchBigSortedArray(ArrayReader * reader, int target) {
        // write your code here
        int index = 1;
        while(reader->get(index - 1)<target && reader->get(index - 1) != -1){
            index = 2*index;  // good point.
        }
        int start = 0, end = index - 1;
        while(start < end) {
            int med = (start+end)/2;
            if (reader->get(med) == target) {
                end = med; // to find the first one, can not return here.
            }else if (reader->get(med) < target) {
                start = med + 1;
            } else {
                end = med - 1;
            }
        }
        if(reader->get(start) == target) {
            return start;
        }
        if(reader->get(end) == target) {
            return end;
        }
        return -1;
    }
};
