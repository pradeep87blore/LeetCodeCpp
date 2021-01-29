/*

https://www.youtube.com/watch?v=oBt53YbR9Kk&t=156s

Grid traveller problem

If we have a grid of (m,n), we need to find the ways in which we can travel from S (m,n) to E (1,1). We can only move down or right


*/

#include <iostream>
#include <vector>

using namespace std;

vector<vector<long>> vec;

long gridTraveller(long m, long n)
{
    // Base cases
    if (m == 0 || n == 0)
    {
        return 0;
    }

    if (m == 1 && n == 1)
    {
        return 1;
    }
    if(vec[m-1][n-1] != -1)
    {
        return vec[m-1][n-1] ;
    }
    vec[m-1][n-1]  = gridTraveller(m - 1, n) + gridTraveller(m, n - 1);
    cout << "m: " << m << ", n : " << n << ", number of ways : " << vec[m-1][n-1]  << endl;
    return vec[m-1][n-1] ;
}

int main()
{
    long m = 18, n = 18;

    vec.resize(m);

    for(auto &x: vec)
    {
        x.resize(n, -1);
    }

    long num = gridTraveller(m, n);
    cout << "Number of ways to traverse the (" << m << "," << n << ") grid is " << num << endl;
}