
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int redEnd = 0;
        int blueStart = nums.size();
        int whiteEnd = 0;
        int tmp;
        while(whiteEnd < blueStart){
            switch(nums[whiteEnd]){
                case 0:
                    tmp = nums[redEnd];
                    nums[redEnd] = 0;
                    nums[whiteEnd] = tmp;
                    ++redEnd;
                    ++whiteEnd;
                    break;
                case 1:
                    ++whiteEnd;
                    break;
                case 2:
                    tmp = nums[blueStart - 1];
                    nums[blueStart - 1] = 2;
                    nums[whiteEnd] = tmp;
                    --blueStart;
                    break;
            }
        }
    }
};

