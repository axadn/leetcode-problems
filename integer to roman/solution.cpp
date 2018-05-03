
/**
Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999. 
**/
class Solution {
public:
    string intToRoman(int num) {
        const char * letters[4] = {
          "M",
          "CD",
          "XL",
          "IV"
        };
        stack<char> stack;
        
        int digit;
        int placeValue = 0;
        while(num > 0){
            digit = num % 10;
            if(digit == 9){
                stack.push(letters[2 - placeValue][0]);
                stack.push(letters[3 - placeValue][0]);
            }
            else if(digit > 5){
                for(int i = 0; i < digit - 5 ; ++i){
                    stack.push(letters[3 - placeValue][0]);
                }
                stack.push(letters[3 - placeValue][1]);
            }
            else if (digit == 5){
                stack.push(letters[3 - placeValue][1]);
            }
            else if (digit == 4){
                stack.push(letters[3 - placeValue][1]);
                stack.push(letters[3 - placeValue][0]);
            }
            else{
                for(int i = 0; i < digit; ++i){
                    stack.push(letters[3 - placeValue][0]);
                }
            }
            num /= 10;
            ++placeValue;
        }
        string result;
        while(!stack.empty()){
            result += stack.top();
            stack.pop();
        }
        return result;
    }
};