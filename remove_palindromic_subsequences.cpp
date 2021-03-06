/*
  Remove Palindromic Subsequences

  Given a string s consisting only of letters 'a' and 'b'. In a single step you can remove one palindromic subsequence from s.

  Return the minimum number of steps to make the given string empty.

  A string is a subsequence of a given string, if it is generated by deleting some characters of a given string without changing its order.

  A string is called palindrome if is one that reads the same backward as well as forward.

   

  Example 1:

  Input: s = "ababa"
  Output: 1
  Explanation: String is already palindrome
  Example 2:

  Input: s = "abb"
  Output: 2
  Explanation: "abb" -> "bb" -> "". 
  Remove palindromic subsequence "a" then "bb".
  Example 3:

  Input: s = "baabb"
  Output: 2
  Explanation: "baabb" -> "b" -> "". 
  Remove palindromic subsequence "baab" then "b".
  Example 4:

  Input: s = ""
  Output: 0
   

  Constraints:

  0 <= s.length <= 1000
  s only consists of letters 'a' and 'b'
*/

///Runtime: 0 ms        // 100%
///Memory Usage: 6.2 MB // 68.25%

class Solution {
public:
    int removePalindromeSub(string s) {
        if (s.size() == 0) return 0;
        if (isPalindrome(s)) return 1;
        return 2;
    }
    
    bool isPalindrome (string s)
    {
        int half_size = s.size() / 2;
        string first;
        string second;
        
        if (s.size() % 2 == 0)
        {
            first = s.substr(0, half_size);
            second = s.substr(half_size);
        }
        else
        {
            first = s.substr(0, half_size);
            second = s.substr(half_size+1);
        }
        
        // Check if halves are equivalent
        for (int i = 0; i < half_size; i++)
        {
            if (first[i] != second[half_size-1-i])
            {
                return false;   // Halves not equivalent
            }
        }

        return true;    // Halves are equivalent
    }
};


// First correct attempt, removing only substrings
class Solution {
public:
    int removePalindromeSub(string s) {
        int i = 0;
        int num_chars = 0;
        string string_new = s;
        
        while (string_new.size() > 0)
        {
            num_chars = palindromeDFS(string_new);
            string_new = string_new.substr(num_chars);
            i++;
        }
        
        // Maximum is 2, ie. remove all a's and all b's
        if (i > 2) return 2;
        
        return i;
    }
    
    int palindromeDFS (string s)
    {
        if (s.size() == 1)
        {
            return 1;
        }
        
        if (isPalindrome(s))
        {
            return s.size();
        }
        
        return palindromeDFS(s.substr(0, s.size()-1));
    }
    
    bool isPalindrome (string s)
    {
        int half_size = s.size() / 2;
        string first;
        string second;
        
        if (s.size() % 2 == 0)
        {
            first = s.substr(0, half_size);
            second = s.substr(half_size);
        }
        else
        {
            first = s.substr(0, half_size);
            second = s.substr(half_size+1);
        }
        
        // Check if halves are equivalent
        for (int i = 0; i < half_size; i++)
        {
            if (first[i] != second[half_size-1-i])
            {
                return false;   // Halves not equivalent
            }
        }

        return true;    // Halves are equivalent
    }
};