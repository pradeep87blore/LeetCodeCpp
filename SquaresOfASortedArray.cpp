/* https://leetcode.com/explore/learn/card/fun-with-arrays/521/introduction/3240/

iven an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

 

Example 1:

Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Explanation: After squaring, the array becomes [16,1,0,9,100].
After sorting, it becomes [0,1,9,16,100].

Example 2:

Input: nums = [-7,-3,2,3,11]
Output: [4,9,9,49,121]

 

Constraints:

    1 <= nums.length <= 104
    -104 <= nums[i] <= 104
    nums is sorted in non-decreasing order.

*/

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> output;
        for(auto num : nums)
        {
            output.push_back(num * num);
        }
        sort(begin(output), end(output));
        return output;
    }
};

int main()
{
    vector<int> nums({-4,-1,0,3,10});
    Solution sln;
    auto op = sln.sortedSquares(nums);

    cout << "Output array is : " << endl;

    for(auto num : op)
    {
        cout << num << endl;
    } 
}