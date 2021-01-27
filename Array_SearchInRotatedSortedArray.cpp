/*

https://leetcode.com/problems/search-in-rotated-sorted-array/

You are given an integer array nums sorted in ascending order (with distinct values), and an integer target.

Suppose that nums is rotated at some pivot unknown to you beforehand (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

If target is found in the array return its index, otherwise, return -1.

 

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1

Example 3:

Input: nums = [1], target = 0
Output: -1

 

Constraints:

    1 <= nums.length <= 5000
    -104 <= nums[i] <= 104
    All values of nums are unique.
    nums is guaranteed to be rotated at some pivot.
    -104 <= target <= 104

*/


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        

       return -1;
    }
};

int main()
{
    vector<int> nums {4,5,6,7,0,1,2};
    Solution sln;

    cout << "Number found at index " << sln.search(nums, 0) << endl;
}