/**
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.

**/

class Solution {
public:
    int numDecodings(string s) {

        int solution;
        if(s.length() == 0) solution = 0;
        else{
            int prevSolution = (s[0] - 48 > 0 && s[0] - 48 < 10) ? 1 : 0;
            solution = prevSolution;
            int prevPrevSolution = prevSolution;
           int prevDigit;
            int currentDigit;

           for(string::iterator ch=s.begin() + 1; ch<s.end(); ++ch){
               prevDigit = *(ch-1) - 48;
               currentDigit = *ch - 48;
               if(prevDigit == 0){
                   if(currentDigit == 0) return 0;
                   else solution = prevSolution;
               }
               else if(currentDigit == 0){
                   if(prevDigit > 2 || prevDigit < 1) return 0;
                   else solution = prevPrevSolution;
               }
               else if(currentDigit < 0 || currentDigit > 9){
                   return 0;
               }
               else if(prevDigit != -1 && prevDigit *10 + currentDigit <= 26){
                   solution = prevSolution + prevPrevSolution;
               }
               else{
                   solution = prevSolution;
               }
               prevPrevSolution = prevSolution;
               prevSolution = solution;
           }

        }

        return solution;
    }
};
