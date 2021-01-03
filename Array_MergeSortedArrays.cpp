/*

https://leetcode.com/explore/learn/card/fun-with-arrays/525/inserting-items-into-an-array/3253/

Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

The number of elements initialized in nums1 and nums2 are m and n respectively. You may assume that nums1 has enough space (size that is equal to m + n) to hold additional elements from nums2.

 

Example 1:

Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]

Example 2:

Input: nums1 = [1], m = 1, nums2 = [], n = 0
Output: [1]

 

Constraints:

    0 <= n, m <= 200
    1 <= n + m <= 200
    nums1.length == m + n
    nums2.length == n
    -109 <= nums1[i], nums2[i] <= 109

*/

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // We need to loop through nums1 and check if each value is lesser than the current iterator value in nums2
        // If nums2 value is not lesser, insert that into the current iterator position in the nums1 and update the iterator by begin(nums1) + index
        
        nums1.resize(m);
        int index = 0;
        auto nums2Iterator = begin(nums2);
        auto iterator = begin(nums1);
        for(; (iterator != end(nums1)) && (nums2Iterator != end(nums2));)
        {
            index++;
            if (*iterator < *nums2Iterator)
            {
                iterator++;
                continue;
            }
            nums1.insert(iterator, *nums2Iterator);
            iterator = begin(nums1) + index;
            nums2Iterator++;
        }

        for(; nums2Iterator != end(nums2); nums2Iterator++)
        {
            nums1.push_back(*nums2Iterator);
        }

    }
};

int main()
{
    vector<int> nums1 {1,2,3,0,0,0}, nums2 {4,5,6};
    Solution sln;
    sln.merge(nums1, 3, nums2, 3);

    for(int x: nums1)
    {
        cout << x << " ";
    }
    cout << endl;
}