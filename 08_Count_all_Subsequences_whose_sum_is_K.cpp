// Problem : Count all sub sequences whose sum is K
// Approach : Pick and not pick strategy
// Basic structure for counting subsequences prblm   **IMP**

// int f(index,sum,k,arr){
//     if base case condition satisfies then return 1
//     if base case condition not statisfies then return 0

//     int pick = f(index+1, sum+arr[index], k, arr);
//     int notpick = f(index+1, sum, k, arr);
//     return pick+notpick;
// }

#include <bits/stdc++.h>
using namespace std;

int countSubSeq(int index, int sum, int k, vector<int>&arr, vector<int>subseq){
    if(index == arr.size()){
        if(sum == k){
            return 1;
        }
        return 0;
    }
    subseq.push_back(arr[index]);
    int pick = countSubSeq(index+1, sum+arr[index], k, arr, subseq);
    subseq.pop_back();
    int notpick = countSubSeq(index+1, sum, k, arr, subseq);
    return pick+notpick;
}

int main(){
    vector<int>arr = {1, 2, 3};
    int k = 3;
    vector<int>subseq;
    cout<<countSubSeq(0, 0, k, arr, subseq);
    return 0;
}