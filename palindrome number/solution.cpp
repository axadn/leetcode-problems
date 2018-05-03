/**
Determine whether an integer is a palindrome. Do this without extra space.

click to show spoilers.

Some hints:
Could negative integers be palindromes? (ie, -1)

If you are thinking of converting the integer to string, note the restriction of using extra space.

You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow. How would you handle such case?

There is a more generic way of solving this problem.
**/
class Solution {
public:
    bool isPalindrome(int x) {
        if( x < 0) return false;
        int numDigits = log10(x) + 1;
        for(int i = 0; i < numDigits ; ++i){
            if(x / (int)pow(10, i) % 10 !=
              x / (int)pow(10, numDigits - 1 - i) % 10){
                return false;
            }
        }
        return true;
    }
};