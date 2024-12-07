// Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

// The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the 
// frequency
//  of at least one of the chosen numbers is different.

// The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

// Example 1:

// Input: candidates = [2,3,6,7], target = 7
// Output: [[2,2,3],[7]]
// Explanation:
// 2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
// 7 is a candidate, and 7 = 7.
// These are the only two combinations.

// Approach:
// 1. We will use pick and not pick approach.   
// 2. We will start from 0th index and check if the element is less than or equal to target. If yes, we will add the element to the path and call the function recursively with the same index.
// 3. If the element is greater than target, we will not add the element to the path and call the function recursively with the next index.
// 4. We will keep on doing this until we reach the end of the array.
// 5. If the target becomes 0, we will add the path to the result.
// 6. We will keep on doing this until we reach the end of the array.
// 7. We will return the result.

#include<bits/stdc++.h>
using namespace std;

void solve(int index, vector<int>&candidates, int target, vector<int>&v, vector<vector<int>>&ans){
    if(index == candidates.size()){
        if(target == 0){
            ans.push_back(v);
        }
        return;
    }

    // Pick

    if(candidates[index] <= target){
        v.push_back(candidates[index]);
        solve(index, candidates, target-candidates[index], v, ans);
        v.pop_back();
    }

    // Not Pick

    solve(index+1, candidates, target, v, ans);
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>>ans;
    vector<int>v;
    solve(0, candidates, target, v, ans);
    return ans;
}

int main(){
    vector<int>candidates = {2, 3, 6, 7};
    int target = 7;
    vector<vector<int>>ans = combinationSum(candidates, target);
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

// Time Complexity: O(2^t * k) where t is the target, k is the average length
// Reason: Assume if you were not allowed to pick a single element multiple times, every element will have a couple of options: pick or not pick which is 2^n different recursion calls, also assuming that the average length of every combination generated is k. (to put length k data structure into another data structure)

// Space Complexity: O(k*x), k is the average length and x is the no. of combinations

 