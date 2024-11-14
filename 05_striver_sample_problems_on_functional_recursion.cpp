// Problem 1 : Reverse an array using recursion

#include<bits/stdc++.h>
using namespace std;

void reverseArray(vector<int>&arr, int start, int end){
    // base case 
    if(start >= end)return;
    // recursive case
    swap(arr[start],arr[end]);
    reverseArray(arr,start+1,end-1);
}

// Problem 2 : Check palindorme using recursion

bool isPalindrome(string s, int start, int end){
    // base case 
    if(start >= end)return true;
    // recursive case
    return s[start] == s[end] && isPalindrome(s,start+1,end-1);
}

int main(){
    vector<int>arr = {1,2,3,4,5};
    reverseArray(arr,0,arr.size()-1);
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}