/*
	268. Missing Number

	Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.

	Follow up: Could you implement a solution using only O(1) extra space complexity and O(n) runtime complexity?

	 

	Example 1:

	Input: nums = [3,0,1]
	Output: 2
	Explanation: n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 2 is the missing number in the range since it does not appear in nums.
	Example 2:

	Input: nums = [0,1]
	Output: 2
	Explanation: n = 2 since there are 2 numbers, so all numbers are in the range [0,2]. 2 is the missing number in the range since it does not appear in nums.
	Example 3:

	Input: nums = [9,6,4,2,3,5,7,0,1]
	Output: 8
	Explanation: n = 9 since there are 9 numbers, so all numbers are in the range [0,9]. 8 is the missing number in the range since it does not appear in nums.
	Example 4:

	Input: nums = [0]
	Output: 1
	Explanation: n = 1 since there is 1 number, so all numbers are in the range [0,1]. 1 is the missing number in the range since it does not appear in nums.
	 

	Constraints:

	n == nums.length
	1 <= n <= 104
	0 <= nums[i] <= n
	All the numbers of nums are unique.
*/

///Runtime: 44 ms					// 17.73%
///Memory Usage: 17.9 MB	// 95.35%

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        bitset<10001> bs;   // Bit representation of 10^4 + 1... "+ 1" is for 0
        bs.set();   // Set all bits
        
        for (int i = 0; i < nums.size(); i++)
        {            
            bs.reset(nums[i]);  // Reset found bits
        }
        
        for (int i = 0; i < 10001; i++)
        {
            if (bs[0] == 1) return i;   // Return the least significant set bit
            bs>>=1; // Shift right 1 bit
        }
        
        return -1;  // No set bits
    }
};

///Runtime: 20 ms					// 76.46%
///Memory Usage: 19.7 MB	// Off chart

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        bitset<10001> bs;   // Bit representation of 10^4 + 1... "+ 1" is for 0
        bs.set();   // Set all bits
        
        for (int i = 0; i < nums.size(); i++)
        {            
            bs.reset(nums[i]);  // Reset found bits
        }
        
        return (10000 - bs.to_string().rfind("1")); // Find the least significant set bit
    }
};

///sample 4 ms submission
/*
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        for(auto num : nums)
        {
            sum += num;
        }
        
        int numsLength = nums.size();
        int total = numsLength*(numsLength+1)/2;
        
        return total-sum;
    }
};
*/

///sample 17700 KB submission
/*
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
        }
        return ((nums.size()*(nums.size()+1))/2)-sum;
    }
};
*/