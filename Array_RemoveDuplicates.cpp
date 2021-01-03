
/*
Remove Duplicates from Sorted Array

(https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/727/)

Given a sorted array nums, remove the duplicates in - place such that each element appears only once and returns the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in - place with O(1) extra memory.

Clarification:

Confused why the returned value is an integer but your answer is an array ?

Note that the input array is passed in by reference, which means a modification to the input array will be known to the caller as well.

Internally you can think of this :

    // nums is passed in by reference. (i.e., without making a copy)
    int len = removeDuplicates(nums);

// any modification to nums in your function would be known by the caller.
// using the length returned by your function, it prints the first len elements.
for (int i = 0; i < len; i++) {
    print(nums[i]);
}


Example 1:

Input: nums = [1, 1, 2]
Output : 2, nums = [1, 2]
Explanation : Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.It doesn't matter what you leave beyond the returned length.
Example 2 :
    Input : nums = [0, 0, 1, 1, 1, 2, 2, 3, 3, 4]
    Output : 5, nums = [0, 1, 2, 3, 4]
    Explanation : Your function should return length = 5, with the first five elements of nums being modified to 0, 1, 2, 3, and 4 respectively.It doesn't matter what values are set beyond the returned length.


    Constraints :

    0 <= nums.length <= 3 * 104
    - 104 <= nums[i] <= 104
    nums is sorted in ascending order.


Hints:
    
 In this problem, the key point to focus on is the input array being sorted.As far as duplicate elements are concerned, 
    what is their positioning in the array when the given array is sorted ? Look at the image above for the answer.
    If we know the position of one of the elements, do we also know the positioning of all the duplicate elements ?

We need to modify the array in - place and the size of the final array would potentially be smaller than the size of the input array.
    So, we ought to use a two - pointer approach here.One, that would keep track of the current element in the original arrayand another one for just the unique elements

Essentially, once an element is encountered, you simply need to bypass its duplicatesand move on to the next unique element.

*/

#include <iostream>
#include <vector>

using namespace std;


int removeDuplicates(vector<int>& nums) {

    if (nums.size() < 2)
    {
        return nums.size(); /// If the size is 1 or 0, return the same value back
    }

    int iIndex = 0;

    auto firstPtr = nums.begin();
    auto secondPtr = nums.begin();
    secondPtr++; // Move the position by 1
    int iCounter = 0;
    while (secondPtr != end(nums))
    {
        //cout << " Num size " << nums.size() << endl;
        if (*firstPtr == *secondPtr) // If consecutive numbers are same
        {
            iCounter++;
        }
        else if (iCounter != 0) // Case when duplicates are found and the next number is a different one
        {
            int nextVal = *secondPtr;
            secondPtr--;
            nums.erase(firstPtr, secondPtr); // Erase the range of elements
            firstPtr = nums.begin();
            secondPtr = nums.begin();


            while (*firstPtr != nextVal)
            {
                firstPtr++;
            }
            secondPtr = firstPtr;
            
            iCounter = 0;
        }
        else if (*firstPtr != *secondPtr) // Consecutive elements are not same, move the ptrs forward
        {
            firstPtr++;
        }
        if (secondPtr <= nums.end())
        {            
            secondPtr++; // Move to the next number
        }
    }
    if (iCounter != 0) // Perform any erases required at the end of the vector
    {
        secondPtr = firstPtr;
        secondPtr = firstPtr + iCounter;

        nums.erase(firstPtr, secondPtr); // Erase the range of elements
    }

    return nums.size();
}
 

int main()
{
    cout << " Test Code " << endl;

    //auto vecInt = vector<int>{ 1,1,2,3,3 };
    auto vecInt = vector<int>{ 1,1,1,1,1,1,2 };

    for (auto i : vecInt)
    {
        cout << i << endl;
    }

    cout << "Length after removeDuplicates: " << removeDuplicates(vecInt);

}