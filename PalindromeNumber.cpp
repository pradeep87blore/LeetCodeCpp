/* 
https://leetcode.com/problems/palindrome-number/
Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.

Follow up: Could you solve it without converting the integer to a string?

 

Example 1:

Input: x = 121
Output: true

Example 2:

Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.

Example 3:

Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.

Example 4:

Input: x = -101
Output: false

 

Constraints:

    -231 <= x <= 231 - 1

*/

#include <stack>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false; // Negative numbers cant be palindromes since there cant be a - on the right extreme end
        
        long originalNum = x;
        long revNum = 0;
        while(x > 0)
        {
            int rem = x % 10;
            x = x/10;
            revNum = (revNum * 10) + rem;
            if(originalNum < revNum) // This is to break off at the mid way mark. If the original number is now lesser than the reversed number, we are the mid way mark
                break;
        }
        return (originalNum == revNum);
    }
};

int main()
{
    Solution sln;
    int iNum = -123321;

    if(sln.isPalindrome(iNum))
    {
        cout << iNum << " is a palindrome";
    }
    else
    {
        cout << iNum <<  " is not a palindrome";
    }
    cout << endl;

}