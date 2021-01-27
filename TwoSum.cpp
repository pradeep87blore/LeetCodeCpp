/*
https://leetcode.com/problems/two-sum/
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Output: Because nums[0] + nums[1] == 9, we return [0, 1].

Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]

Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]

 

Constraints:

    2 <= nums.length <= 103
    -109 <= nums[i] <= 109
    -109 <= target <= 109
    Only one valid answer exists.

*/

#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int, int> map;        
        int iIndex = 0;
        for(int x: nums)
        {
            auto otherElementIterator = map.find(target-x);
            if(otherElementIterator != map.end())
            {
                vector<int> output {otherElementIterator->second, iIndex};
                return output;
            }
            else
            {
                pair<int, int> valueToInsert(x, iIndex++);
                map.insert(valueToInsert);
            }
        }
        vector<int> output {-1};
        return output;
    }
};

int main()
{
    vector<int> nums {2,7,11,15};

    Solution sln;
    auto output = sln.twoSum(nums, 9);

    for(int x: output)
    {
        cout << x << " ";
    }

    cout << endl;
}