/*
  Integer to Roman

  Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

  Symbol       Value
  I             1
  V             5
  X             10
  L             50
  C             100
  D             500
  M             1000
  For example, 2 is written as II in Roman numeral, just two one's added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

  Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

  I can be placed before V (5) and X (10) to make 4 and 9. 
  X can be placed before L (50) and C (100) to make 40 and 90. 
  C can be placed before D (500) and M (1000) to make 400 and 900.
  Given an integer, convert it to a roman numeral.

   

  Example 1:

  Input: num = 3
  Output: "III"
  Example 2:

  Input: num = 4
  Output: "IV"
  Example 3:

  Input: num = 9
  Output: "IX"
  Example 4:

  Input: num = 58
  Output: "LVIII"
  Explanation: L = 50, V = 5, III = 3.
  Example 5:

  Input: num = 1994
  Output: "MCMXCIV"
  Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
   

  Constraints:

  1 <= num <= 3999
*/

///Runtime: 0 ms      // 100%
///Memory Usage: 6 MB // 79.99%

class Solution {
public:
    string intToRoman(int num) {
        string str;
        
        while (num > 0)
        {
            if (num >= 900)
            {
                if (num < 1000)
                {
                    str.push_back('C');
                    num += 100;
                }

                str.push_back('M');
                num -= 1000;
            }

            else if (num >= 400)
            {
                if (num < 500)
                {
                    str.push_back('C');
                    num += 100;
                }

                str.push_back('D');
                num -= 500;
            }

            else if (num >= 90)
            {
                if (num < 100)
                {
                    str.push_back('X');
                    num += 10;
                }

                str.push_back('C');
                num -= 100;
            }

            else if (num >= 40)
            {
                if (num < 50)
                {
                    str.push_back('X');
                    num += 10;
                }

                str.push_back('L');
                num -= 50;
            }

            else if (num >= 9)
            {
                if (num < 10)
                {
                    str.push_back('I');
                    num += 1;
                }

                str.push_back('X');
                num -= 10;
            }

            else if (num >= 4)
            {
                if (num < 5)
                {
                    str.push_back('I');
                    num += 1;
                }

                str.push_back('V');
                num -= 5;
            }
            
            else
            {
                str.push_back('I');
                num -= 1;
            }
        }
        return str;
    }
};