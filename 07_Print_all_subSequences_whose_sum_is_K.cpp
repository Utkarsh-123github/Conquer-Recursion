// Problem : Print all sub sequences whose sum is K
// Approach : Pick and not pick strategy

#include <bits/stdc++.h>
using namespace std;

void printSubSeq(vector<int>&arr, int sum, int k, int index, vector<int>&subseq){
    if(index == arr.size()){
        if(sum == k){
            for(auto x: subseq){
                cout<<x<<" ";
            }
            cout<<endl;
        }
        return;
    }
    subseq.push_back(arr[index]);
    printSubSeq(arr, sum+arr[index], k, index+1, subseq);
    subseq.pop_back();
    printSubSeq(arr, sum, k, index+1, subseq);
}

int main() {
    vector<int>arr = {1, 2, 3};
    int k = 3;
    vector<int>subseq;
    printSubSeq(arr, 0, k, 0, subseq);
    return 0;
}