/** adan's basic idea:
   
   like binary search, but checking the first, middle, and last element for the current range we are considering
   
   if the middle is less than the first, check left side
   if the end is less than the middle, check right side
   else return first element in the array
   
   This is a logarithmic solution

**/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int first = 0;
        int last = nums.size() - 1;
        int middle = (first + last)/2;
        if(nums.size() == 2){
            return(nums[0] < nums[1] ? nums[0] : nums[1]);
        }
        else if (nums.size() == 1) return nums[0];
        while(true){
            if(nums[middle] < nums[first]){
                if(middle == first + 1) return nums[middle];
                last = middle;
                middle = (first + last)/2;
            }
            else if(nums[last] < nums[middle]){
                if(last == middle + 1) return nums[last];
                first = middle;
                middle = (first + last)/2;
            }
            else{
                return nums[0];
            }
        }
    }
};