/*
	1780. Check if Number is a Sum of Powers of Three

	Given an integer n, return true if it is possible to represent n as the sum of distinct powers of three. Otherwise, return false.

	An integer y is a power of three if there exists an integer x such that y == 3x.

	 

	Example 1:

	Input: n = 12
	Output: true
	Explanation: 12 = 31 + 32
	Example 2:

	Input: n = 91
	Output: true
	Explanation: 91 = 30 + 32 + 34
	Example 3:

	Input: n = 21
	Output: false
	 

	Constraints:

	1 <= n <= 107
*/

///Runtime: 0 ms
///Memory Usage: 5.9 MB

class Solution {
public:
    bool checkPowersOfThree(int n) {
        int i = n;
        int j;
        while (i > 0)
        {
            j = 1;
            while (true)
            {
                if (j * 3 > i) {break;}
                j *= 3;
            }
            
            i -= j;
            
            if (i - j >= 0)
            {
                return false;
            }
            
            if (i == 2)
            {
                return false;
            }
        }
        return true;
    }
};