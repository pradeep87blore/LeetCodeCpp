/* 

https://leetcode.com/problems/valid-parentheses/

Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

    Open brackets must be closed by the same type of brackets.
    Open brackets must be closed in the correct order.

 

Example 1:

Input: s = "()"
Output: true

Example 2:

Input: s = "()[]{}"
Output: true

Example 3:

Input: s = "(]"
Output: false

Example 4:

Input: s = "([)]"
Output: false

Example 5:

Input: s = "{[]}"
Output: true

 

Constraints:

    1 <= s.length <= 104
    s consists of parentheses only '()[]{}'.



*/

#include <iostream>
#include <stack>

using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> stk;

        for (auto c : s)
        {
            if (c == '(' || c == '[' || c == '{')
            {
                stk.push(c);
            }
            else
            {
                if (stk.empty())
                    return false;

                if ((c == ')' && stk.top() != '(') ||
                    (c == ']' && stk.top() != '[') ||
                    (c == '}' && stk.top() != '{'))
                    return false;

                stk.pop();
            }
        }
        if (!stk.empty())
        {
            return false;
        }
        return true;
    }
};

int main()
{
    string s = "{[]}";
    Solution sln;

    if (sln.isValid(s))
    {
        cout << "Is Valid" << endl;
    }
    else
    {
        cout << "Is Not Valid" << endl;
    }
}
