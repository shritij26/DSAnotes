/*                         "Those who forget the past
                                are condemed to repeat it"                                                */

/*
Dynamic Programming (DP)

Dynamic Programming is a method for solving complex problems by breaking them down into simpler subproblems.
It is applicable when the problem has overlapping subproblems and optimal substructure properties.

1. Key Concepts
----------------
a) Overlapping Subproblems:
   - The problem can be broken down into subproblems which are reused several times.
   - Example: Fibonacci sequence, where fib(n) = fib(n-1) + fib(n-2).

b) Optimal Substructure:
   - The optimal solution of the problem can be constructed from optimal solutions of its subproblems.
   - Example: Shortest path problems.

2. Approaches
--------------
a) Top-Down (Memoization):
   - Recursion + caching results (usually with a map or array).
   - Avoids recomputation by storing results.

b) Bottom-Up (Tabulation):
   - Iterative approach.
   - Solve all subproblems and build up the solution.

3. Steps to Solve DP Problems
------------------------------
a) Identify if the problem can be broken into subproblems.
b) Define the state (parameters that define a subproblem).
c) Write the recurrence relation.
d) Decide memoization (top-down) or tabulation (bottom-up).
e) Implement base cases.

4. Example Problems and Codes
------------------------------

A) Fibonacci Numbers
---------------------   
// Top-Down (Memoization)
#include <iostream>
#include <vector>
using namespace std;

int fib(int n, vector<int>& dp) {
    if (n <= 1) 
        return n;
    if (dp[n] != -1) 
        return dp[n];
    return dp[n] = fib(n-1, dp) + fib(n-2, dp);
}

int main() {
    int n = 10;
    vector<int> dp(n+1, -1);
    cout << "Fibonacci of " << n << " is " << fib(n, dp) << endl;
    return 0;
}

// Bottom-Up (Tabulation)
#include <iostream>
#include <vector>
using namespace std;

int fib(int n) {
    vector<int> dp(n+1, 0);
    dp[0] = 0; dp[1] = 1;
    for (int i = 2; i <= n; ++i)
        dp[i] = dp[i-1] + dp[i-2];
    return dp[n];
}

int main() {
    int n = 10;
    cout << "Fibonacci of " << n << " is " << fib(n) << endl;
    return 0;
}

B) 0/1 Knapsack Problem
------------------------
// Given weights and values, maximize value with weight limit W
#include <iostream>
#include <vector>
using namespace std;

int knapsack(int n, int W, vector<int>& wt, vector<int>& val, vector<vector<int>>& dp) {
    if (n == 0 || W == 0) return 0;
    if (dp[n][W] != -1) return dp[n][W];
    if (wt[n-1] <= W)
        return dp[n][W] = max(val[n-1] + knapsack(n-1, W-wt[n-1], wt, val, dp),
    knapsack(n-1, W, wt, val, dp));
    else
        return dp[n][W] = knapsack(n-1, W, wt, val, dp);
}

int main() {
    int n = 3, W = 50;
    vector<int> wt = {10, 20, 30};
    vector<int> val = {60, 100, 120};
    vector<vector<int>> dp(n+1, vector<int>(W+1, -1));
    cout << "Max value: " << knapsack(n, W, wt, val, dp) << endl;
    return 0;
}

5. Common DP Problems
----------------------
- Fibonacci Numbers
- Climbing Stairs
- 0/1 Knapsack
- Coin Change
- Longest Common Subsequence (LCS)
- Edit Distance
- Subset Sum
- Matrix Chain Multiplication

6. Tips
--------
- Always define the state clearly.
- Think about base cases.
- Use memoization for recursion-heavy problems.
- Use tabulation for space/time efficiency.
- Optimize space if possible (sometimes only previous row/column is needed).

7. When NOT to use DP
----------------------
- If subproblems are not overlapping.
- If optimal substructure does not exist.
*/