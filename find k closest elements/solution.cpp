/**
Given a sorted array, two integers k and x, find the k closest elements to x in the array. The result should also be sorted in ascending order. If there is a tie, the smaller elements are always preferred.

Example 1:
Input: [1,2,3,4,5], k=4, x=3
Output: [1,2,3,4]
Example 2:
Input: [1,2,3,4,5], k=4, x=-1
Output: [1,2,3,4]
Note:
The value k is positive and will always be smaller than the length of the sorted array.
Length of the given array is positive and will not exceed 104
Absolute value of elements in the array and x will not exceed 104
**/
/**pseudocode:
    use binary search to find the closest integer to x
    keep track of two indexes, one before x, and one after x
    compare values at indices and increment appropriately until range spans k
    return the array slices using the two indices
**/

/**pseudocode:
    use binary search to find the closest integer to x
    keep track of two indexes, one before x, and one after x
    compare values at indices and increment appropriately until range spans k
    return the array slices using the two indices
**/

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> result;
        int idx0 = binaryClosestSearch(arr, x);
        int idx1 = idx0;
        int difference0, difference1;
        while(idx1 - idx0 + 1 < k){
            if(idx0 - 1 >= 0 && idx1 + 1 < arr.size()){
                difference0 = abs(arr[idx0 - 1] - x);
                difference1 = abs(arr[idx1 + 1] - x);
                if(difference0 <= difference1){
                    --idx0;
                }
                else{
                    ++idx1;
                }
            }
            else if(idx0 - 1 >= 0){
                --idx0;
            }
            else{
                ++idx1;
            }
        }
        for(int i = idx0; i <=idx1; ++i){
            result.push_back(arr[i]);
        }
        return result;
    }
    int binaryClosestSearch(vector<int>& arr, int val){
        int startIdx = 0;
        int endIdx = arr.size() - 1;
        int checkIdx;
        while(startIdx != endIdx){
            if(startIdx == endIdx - 1){
                int difference0 = abs(arr[startIdx] - val);
                int difference1 = abs(arr[endIdx] - val);
                if(difference0 <= difference1){
                    return startIdx;
                }else return endIdx;
            }
            checkIdx = (startIdx + endIdx) / 2;
            if(arr[checkIdx] == val){
                while(checkIdx > 0 && arr[checkIdx - 1] == val) --checkIdx;
                return checkIdx;
            }
            else if (arr[checkIdx] > val){
                endIdx = checkIdx - 1;
            }
            else{
                startIdx = checkIdx + 1;
            }
        }
        return endIdx;
    }
};