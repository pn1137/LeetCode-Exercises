/*
  Fizz Buzz

  Write a program that outputs the string representation of numbers from 1 to n.

  But for multiples of three it should output “Fizz” instead of the number and for the multiples of five output “Buzz”. For numbers which are multiples of both three and five output “FizzBuzz”.

  Example:

  n = 15,

  Return:
  [
      "1",
      "2",
      "Fizz",
      "4",
      "Buzz",
      "Fizz",
      "7",
      "8",
      "Fizz",
      "Buzz",
      "11",
      "Fizz",
      "13",
      "14",
      "FizzBuzz"
  ]
*/

///Runtime: 4 ms        // 85.91%
///Memory Usage: 7.8 MB // 61.09%

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> str;
        string tmp;
        
        for (int i = 1; i <= n; i++)
        {
            tmp = "";
            
            if (i % 3 == 0)
            {
                tmp += "Fizz";
            }
            
            if (i % 5 == 0)
            {
                tmp += "Buzz";
            }
            
            if (tmp == "")
            {
                tmp += to_string(i);
            }
            
            str.push_back(tmp);
        }
        
        return str;
    }
};