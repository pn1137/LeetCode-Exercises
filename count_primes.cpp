/*
  Count Primes
  
  Count the number of prime numbers less than a non-negative number, n.

   

  Example 1:

  Input: n = 10
  Output: 4
  Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
  Example 2:

  Input: n = 0
  Output: 0
  Example 3:

  Input: n = 1
  Output: 0
   

  Constraints:

  0 <= n <= 5 * 106
*/

///Runtime: 12 ms       // 99.19%
///Memory Usage: 6.2 MB // 88.50%

class Solution {
public:
    int countPrimes(int n) {
        if (n < 3)
        {
            return 0;
        }
        
        /* Sieve of Eratosthenes */        
        vector<bool> is_prime(n, true);
        int primeCount = n-2;   // 1 and n are not included
        int sqrt_n = sqrt(n);
        
        for (int i = 2; i <= sqrt_n; i++)
        {
            if (is_prime[i])
            {
                for (int j = i*i; j < n; j+=i)
                {
                    if (is_prime[j])
                    {
                        is_prime[j] = false;
                        primeCount--;
                    }
                }
            }
        }
        
        return primeCount;
    }
};