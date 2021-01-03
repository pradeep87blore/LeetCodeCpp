/* https://leetcode.com/explore/learn/card/fun-with-arrays/521/introduction/3238/

Given a binary array, find the maximum number of consecutive 1s in this array.

Example 1:

Input: [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s.
    The maximum number of consecutive 1s is 3.

Note:

    The input array will only contain 0 and 1.
    The length of input array is a positive integer and will not exceed 10,000

*/

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int iMaxConsecutiveOnes = 0;

        int iCurrentConsecutiveCount = 0;
        for(int iIndex = 0; iIndex < nums.size(); iIndex++)
        {
            if(nums[iIndex] == 0)
            {
                iCurrentConsecutiveCount = 0;
                continue;
            }
            iCurrentConsecutiveCount++;
            if(iCurrentConsecutiveCount > iMaxConsecutiveOnes)
            {
                iMaxConsecutiveOnes = iCurrentConsecutiveCount;
            }
        }
        return iMaxConsecutiveOnes;
    }
};

int main()
{
    vector<int> nums ({1,1,0,1,1,0});
    Solution sln;
    cout << "Max consecutive ints are :" << sln.findMaxConsecutiveOnes(nums) << endl;
}
