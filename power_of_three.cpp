/*
  Power of Three

  Given an integer n, return true if it is a power of three. Otherwise, return false.

  An integer n is a power of three, if there exists an integer x such that n == 3x.

   

  Example 1:

  Input: n = 27
  Output: true
  Example 2:

  Input: n = 0
  Output: false
  Example 3:

  Input: n = 9
  Output: true
  Example 4:

  Input: n = 45
  Output: false
   

  Constraints:

  -231 <= n <= 231 - 1
   

  Follow up: Could you solve it without loops/recursion?
*/

///Runtime: 8 ms        // 89.28%
///Memory Usage: 5.9 MB // 80.89%

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n == 0)
        {
            return false;
        }
        
        if (n == 3 || n == 1)
        {
            return true;
        }
        
        if (n % 3 == 0)
        {
            return isPowerOfThree(n/3);
        }
        
         return false;
    }
};

///Runtime: 4 ms        // 97.89%
///Memory Usage: 5.8 MB // 92.04%

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0)
        {
            return false;
        }
        
        return (1162261467 % n == 0);
    }
};