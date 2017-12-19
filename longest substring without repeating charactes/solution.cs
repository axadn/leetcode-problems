/**
Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
**/

using System.Collections.Generic;
public class Solution {
    //pwwkew
   //012234
    public int LengthOfLongestSubstring(string s) {
        char currentChar;
        char removedChar;
        int startIndex = 0;
        int numDups = 0;
        int countOfChar;
        Queue<char> queue = new Queue<char>();
        Dictionary<char, int> dict = new Dictionary<char, int> ();

        while(startIndex + queue.Count < s.Length){
            currentChar = s[startIndex + queue.Count];
            queue.Enqueue(currentChar);
            if(dict.ContainsKey(currentChar)){
                ++numDups;
                dict[currentChar] += 1;
            }
            else{
                dict[currentChar] = 1;
            }

            if(numDups > 0){
                removedChar = queue.Dequeue();
                countOfChar = dict[removedChar];
                if(countOfChar > 1){
                    --numDups;
                }
                ++startIndex;
                dict[removedChar] -= 1;
                if(countOfChar == 1){
                    dict.Remove(removedChar);
                }
          }
        }
        return queue.Count;
    }
}
