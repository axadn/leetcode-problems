/**
Given two strings representing two complex numbers.

You need to return a string representing their multiplication. Note i2 = -1 according to the definition.

Example 1:
Input: "1+1i", "1+1i"
Output: "0+2i"
Explanation: (1 + i) * (1 + i) = 1 + i2 + 2 * i = 2i, and you need convert it to the form of 0+2i.
Example 2:
Input: "1+-1i", "1+-1i"
Output: "0+-2i"
Explanation: (1 - i) * (1 - i) = 1 + i2 - 2 * i = -2i, and you need convert it to the form of 0+-2i.
Note:

The input strings will not have extra blank.
The input strings will be given in the form of a+bi, where the integer a and b will both belong to the range of [-100, 100]. And the output should be also in this form.
**/

#include <sstream>
class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        stringstream convertAReal(extractReal(a));
        stringstream convertAIm(extractImaginary(a));
        stringstream convertBReal(extractReal(b));
        stringstream convertBIm(extractImaginary(b));
        int realA, realB, imaginaryA, imaginaryB;
        convertAReal >> realA;
        convertBReal >> realB;
        convertBIm >> imaginaryB;
        convertAIm >> imaginaryA;
        
        int resultReal = realA * realB + (-1 * imaginaryA * imaginaryB);
        int resultImaginary = realA * imaginaryB + realB * imaginaryA;
        std::stringstream ss;
        ss << resultReal << "+" << resultImaginary << "i";
        cout << realB;
        return ss.str();
    }
    
    string extractReal(string input){
        for(int i = 0; i < input.length(); ++i){
            if(input[i] == '+'){
                return input.substr(0, i);
            }
        }
        return "";
    }
    
    string extractImaginary(string input){
        for(int i = 0; i < input.length(); ++i){
            if(input[i] == '+'){
                return input.substr(i + 1, input.length() - i - 2);
            }
        }
        return "";
    }
};