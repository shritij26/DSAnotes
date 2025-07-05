// Greedy Algorithm - Simple Explanation

/*
Theory:
A greedy algorithm is an approach for solving problems by choosing the best option available at each step,
with the hope of finding the global optimum. It makes a sequence of choices, each of which looks best at the moment,
without worrying about the future consequences.

Important Points:
- Greedy algorithms do not always give the optimal solution for all problems.
- They work well when a problem has the "greedy-choice property" (a global optimum can be reached by choosing the best local option).
- They are usually faster and simpler than other algorithms like dynamic programming.

Common Examples:
1. Coin Change Problem (using minimum coins)
2. Activity Selection Problem
3. Fractional Knapsack Problem
*/

// Example 1: Coin Change Problem (Minimum Coins)
/*
Given coins of different denominations and a total amount, find the minimum number of coins needed to make up that amount.
Greedy approach: Always pick the largest coin that is less than or equal to the remaining amount.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void minCoins(int amount, vector<int> &coins)
{
    sort(coins.rbegin(), coins.rend()); // Sort coins in descending order
    vector<int> result;
    for (int coin : coins)
    {
        while (amount >= coin)
        {
            amount -= coin;
            result.push_back(coin);
        }
    }
    if (amount != 0)
    {
        cout << "Cannot make the amount with given coins.\n";
    }
    else
    {
        cout << "Coins used: ";
        for (int c : result)
            cout << c << " ";
        cout << endl;
    }
}

// Example 2: Activity Selection Problem
/*
Given start and end times of activities, select the maximum number of activities that don't overlap.
Greedy approach: Always pick the next activity that finishes earliest.
*/

struct Activity
{
    int start, end;
};

bool compare(Activity a, Activity b)
{
    return a.end < b.end;
}

void activitySelection(vector<Activity> &activities)
{
    sort(activities.begin(), activities.end(), compare);
    cout << "Selected activities (start, end): ";
    int lastEnd = -1;
    for (auto act : activities)
    {
        if (act.start >= lastEnd)
        {
            cout << "(" << act.start << "," << act.end << ") ";
            lastEnd = act.end;
        }
    }
    cout << endl;
}

int main()
{
    // Example 1: Coin Change
    vector<int> coins = {1, 2, 5, 10};
    int amount;
    cout << "Enter the amount: ";
    cin >> amount;
    cout << "Coin Change:\n";
    minCoins(amount, coins);

    // Example 2: Activity Selection
    vector<Activity> acts = {{1, 3}, {2, 5}, {0, 6}, {5, 7}, {8, 9}, {5, 9}};
    cout << "\nActivity Selection Example:\n";
    activitySelection(acts);

    //********************************************************

    cout << "\nHere is an example where greedy fails:\n";
    // Suppose we want to reach sum 6 using coins {1, 3, 4}
    // Greedy picks 4 first, then 1, 1 (total 3 coins), but optimal is 3+3 (2 coins)
    vector<int> coins2 = {1, 3, 4};
    int amount2 = 6;
    cout << "Trying to make 6 with coins {1, 3, 4} using greedy:\n";
    minCoins(amount2, coins2);
    // Greedy gives coins: 4 1 1 (3 coins), but optimal is 3 3 (2 coins)
    cout << "Greedy fails here because it does not give the minimum number of coins.\n";
}

/*
Summary:
- Greedy algorithms are simple and fast.
- They work best when the problem has the greedy-choice property.
- Always check if greedy works for your problem before using it.
*/