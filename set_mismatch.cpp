/*
  645. Set Mismatch
  
  You have a set of integers s, which originally contains all the numbers from 1 to n. Unfortunately, due to some error, one of the numbers in s got duplicated to another number in the set, which results in repetition of one number and loss of another number.

  You are given an integer array nums representing the data status of this set after the error.

  Find the number that occurs twice and the number that is missing and return them in the form of an array.

   

  Example 1:

  Input: nums = [1,2,2,4]
  Output: [2,3]
  Example 2:

  Input: nums = [1,1]
  Output: [1,2]
   

  Constraints:

  2 <= nums.length <= 104
  1 <= nums[i] <= 104
*/

///Runtime: 32 ms         // 79.31%
///Memory Usage: 21.4 MB  // 75.28%

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int val;
        int size = nums.size()-1;
        vector<int> solution (2, 0);
        bool dupFound = false;
        bool misFound = false;
        
        std::sort(nums.begin(), nums.end());        
        
        // If 0th element is not 1, then 1 is missing
        if (nums[0] != 1)
        {
            solution[1] = 1;
            misFound = true;
        }
        
        for (int i = 0; i < size; i++)
        {
            val = nums[i+1] - nums[i];
            
            if (val == 0) // duplicate
            {
                solution[0] = nums[i];
                dupFound = true;
                
                // The last two elements are duplicates and final element is missing
                if (i == size-1 && !misFound)
                {                    
                    solution[1] = nums[i] + 1;
                    break;
                }
            }
            else if (val == 2)  // missing
            {
                solution[1] = nums[i] + 1;
                misFound = true;
            }
            
            if (dupFound && misFound)
            {
                break;
            }
        }
        
        if (!misFound) { solution[1] = size+1; }
        
        return solution;
    }
};

///sample 12 ms submission
/*
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 0);
        for (int i = 1; i <= n; i++)
        {
            while (nums[i] != i && nums[i] <= n+1 && nums[i] != nums[nums[i]])
            {
                swap(nums[i], nums[nums[i]]);
            }
        }
        for (int i = 1; i <= n; i++)
        {
            if (nums[i]!=i)
                return {nums[i], i};
        }
        return {-1, -1};
    }
};
*/