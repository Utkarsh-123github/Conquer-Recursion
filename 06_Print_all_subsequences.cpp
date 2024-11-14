// Problem : Print all subsequences of an array
// Subsequence is defined as a sequence that can be derived from an array by deleting some or no elements without changing the order of the remaining elements.

// For example :- The subsequences of [1,2,3] are [1], [2], [3], [1,2], [1,3], [2,3], [1,2,3], []

// Approach: Here we will use the concept of recursion to solve this problem. We will use a helper function to generate all the subsequences of the array using pick and not pick strategy.

// 1. We will create a helper function that will take the input array, the current index, and the current subsequence as input.
// 2. If the current index is equal to the size of the array, then we will print the current subsequence.
// 3. Otherwise, we will call the helper function recursively with the current index + 1 and the current subsequence
// 4. Now while backtracking we have to pop the last array element inserted since now we have to implement the non-pick condition and then move to next index.

#include<bits/stdc++.h>
using namespace std;

void printSubSequences(vector<int>&arr, int index, vector<int>&subsequence){
    if(index == arr.size()){
        for(auto it : subsequence){
            cout<<it<<" ";
        }
        cout<<endl;
        return;
    }

    // Pick the element 
    subsequence.push_back(arr[index]);
    printSubSequences(arr, index+1, subsequence);

    // Non-pick the element
    subsequence.pop_back();
    printSubSequences(arr, index+1, subsequence);

}

int main(){
    vector<int>arr = {1,2,3};
    vector<int>subsequence;
    printSubSequences(arr, 0, subsequence);
    return 0;
}

