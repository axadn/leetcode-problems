/**
 * Given a non-negative integer represented as a non-empty array of digits, plus one to the integer.

You may assume the integer do not contain any leading zero, except the number 0 itself.

The digits are stored such that the most significant digit is at the head of the list.
**/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool carry = true;
        
        int idx = digits.size() - 1;
        int newVal;
        while(carry == true){
            if(idx == -1){
                digits.insert(digits.begin(), 1);
                break;
            }
            newVal = digits[idx] + 1;
            if(newVal >= 10){
                digits[idx] = newVal - 10;
                carry = true;
            }
            else{
                digits[idx] = newVal;
                carry = false;
            }
            --idx;
        }
        return digits;
    }
};