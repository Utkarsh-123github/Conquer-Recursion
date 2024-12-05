// MERGE SORT
// In merge sort we use the divide and conquer strategy to sort the array. We divide the array into two halves and then sort the two halves and then merge the two halves to get the sorted array.

// Algorithm:
// 1. Divide the array into two halves.
// 2. Recursively sort the two halves.
// 3. Merge the two halves.

// Time Complexity: O(nlogn)
// Space Complexity: O(n)

#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>&arr, int low, int mid, int high){
    int left = low;
    int right = mid+1;
    vector<int>temp;
    while(left<=mid && right<=high){
        if(arr[left] <= arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }

    // Copy the remaining elements
    while(left<=mid){
        temp.push_back(arr[left]);
        left++;
    }

    // Copy the remaining elements
    while(right<=high){
        temp.push_back(arr[right]);
        right++;
    }

    // Copy the elements from temp to original array
    for(int i=low; i<=high; i++){
        arr[i] = temp[i-low];
    }

}

void mergeSort(vector<int>&arr, int low, int high){
    if(low<high){
        int mid = low + (high-low)/2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);
        merge(arr, low, mid, high);
    }
}

int main(){
    vector<int>arr = {12, 11, 13, 5, 6, 7};
    mergeSort(arr, 0, arr.size()-1);
    for(auto x: arr){
        cout<<x<<" ";
    }
    return 0;
}