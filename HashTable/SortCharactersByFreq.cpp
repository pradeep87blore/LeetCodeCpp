/* 

https://leetcode.com/problems/sort-characters-by-frequency/

Given a string, sort it in decreasing order based on the frequency of characters.

Example 1:

Input:
"tree"

Output:
"eert"

Explanation:
'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.

Example 2:

Input:
"cccaaa"

Output:
"cccaaa"

Explanation:
Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
Note that "cacaca" is incorrect, as the same characters must be together.

Example 3:

Input:
"Aabb"

Output:
"bbAa"

Explanation:
"bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.


*/

#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{

public:
    string frequencySort(string s)
    {
        unordered_map<char, int> map;

        for (auto c : s)
        {
            map[c]++;
        }

        multimap<int, char> forSorting;

        for(auto x: map)
        {
            forSorting.insert(pair<int, const char>(x.second, x.first));
        }

       string retStr;
       retStr.reserve(s.size());

       for(auto x: forSorting)
       {
           retStr.append(x.first, x.second);           
       }
  
        reverse(retStr.begin(), retStr.end());

        return retStr;
    }
};

int main()
{
    string s = "tree";
    Solution sln;
    cout << sln.frequencySort(s) << endl;
}