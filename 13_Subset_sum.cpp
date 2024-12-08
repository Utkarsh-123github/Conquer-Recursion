// Given a array arr of integers, return the sums of all subsets in the list.  Return the sums in any order.

// Example 1:

// Input: arr = [1,2,3]
// Output: [0,1,2,3,4,5,6]
// Explanation: The resulting sums are: [0,1,2,3,4,5,6]. Note that the order of the output does not matter.
// Example 2:

// Input: arr = [1,2]
// Output: [0,1,2,3]

// Constraints:
// 1 ≤ arr.size() ≤ 15
// 0 ≤ arr[i] ≤ 10^4

// Approach: Pick and not Pick strategy

#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &arr, int index, int sum, vector<int> &ans)
{
    if (index == arr.size())
    {
        ans.push_back(sum);
        return;
    }
    // Pick
    solve(arr, index + 1, sum + arr[index], ans);
    // Not Pick
    solve(arr, index + 1, sum, ans);
}

vector<int> subsetSums(vector<int> &arr)
{
    // code here
    vector<int> ans;
    solve(arr, 0, 0, ans);
    return ans;
}

int main()
{
    vector<int> arr = {1, 2, 3};
    vector<int> ans = subsetSums(arr);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}


// Time Complexity: O(2^n). Each index has two ways. You can either pick it up or not pick it. So, it is 2*2*2*2... n times = 2^n.

// Space Complexity: O(2^n) for storing subset sums, since 2^n subsets can be generated for an array of size n.