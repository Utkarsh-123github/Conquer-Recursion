// Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

// Each number in candidates may only be used once in the combination.

// Note: The solution set must not contain duplicate combinations.

// Example 1:

// Input: candidates = [10,1,2,7,6,1,5], target = 8
// Output:
// [
// [1,1,6],                 
// [1,2,5],
// [1,7],
// [2,6]
// ]

// Example 2:

// Input: candidates = [2,5,2,1,2], target = 5
// Output:
// [
// [1,2,2],
// [5]
// ]

// Constraints:

// 1 <= candidates.length <= 100
// 1 <= candidates[i] <= 50
// 1 <= target <= 30

// Approach -1 :

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
        solve(index+1,candidates,target-candidates[index],v,ans);
        v.pop_back();
    }

    // Not Pick
    solve(index+1,candidates,target,v,ans);

}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>>ans;
    vector<int>v;
    solve(0,candidates,target,v,ans);
    set<vector<int>>s;
    for(int i=0;i<ans.size();i++){
        sort(ans[i].begin(),ans[i].end());
        s.insert(ans[i]);
    }
    vector<vector<int>>res;
    for(auto it : s){
        res.push_back(it);
    }
    return res;
}


// Approach -2 : 

void solve(int index, vector<int>&arr, int target, vector<int>&v, vector<vector<int>>&ans){
    if(target == 0){
        ans.push_back(v);
        return;
    }
    for(int i = index;i<arr.size();i++){
        if(i>index && arr[i] == arr[i-1]){
            continue;
        }
        if(arr[i] > target){
            break;
        }
        v.push_back(arr[i]);
        solve(i+1,arr,target-arr[i],v,ans);
        v.pop_back();
    }
}

vector<vector<int>> combinationSums2(vector<int>& candidates, int target) {
    vector<vector<int>>ans;
    vector<int>v;
    sort(candidates.begin(),candidates.end());
    solve(0,candidates,target,v,ans);
    return ans;
}

int main(){
    vector<int>candidates = {10,1,2,7,6,1,5};
    int target = 8;
    vector<vector<int>>ans = combinationSum2(candidates, target);
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}


// Time Complexity : O(2^n*k) where n is the number of elements in the array and k is the average length of the array.
// Space Complexity : O(k*x) if we have x combinations then space will be x*k where k is the average length of the combination. 
// Link : https://takeuforward.org/data-structure/combination-sum-ii-find-all-unique-combinations/

