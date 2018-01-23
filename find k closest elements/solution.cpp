/**pseudocode:
    use binary search to find the closest integer to x
    keep track of two indexes, one before x, and one after x
    compare values at indices and increment appropriately until range spans k
    return the array slices using the two indices
**/
/** in-progress **/
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> result;
        result.push_back(binaryClosestSearch(arr, x));
        return result;
    }
    int binaryClosestSearch(vector<int>& arr, int val){
        int startIdx = 0;
        int endIdx = arr.size() - 1;
        int checkIdx;
        while(startIdx != endIdx){
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