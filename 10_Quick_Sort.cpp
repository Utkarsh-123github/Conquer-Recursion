// Quick Sort Algorithm
// Quick Sort is a Divide and Conquer algorithm. It picks an element as pivot and partitions the given array around the picked pivot.
// There are many different versions of quickSort that pick pivot in different ways.
// 1. Always pick first element as pivot.
// 2. Always pick last element as pivot.
// 3. Pick a random element as pivot.
// 4. Pick median as pivot.
// The key process in quickSort is partition(). Target of partitions is, given an array and an element x of array as pivot, put x at its correct position in sorted array and put all smaller elements (smaller than x) before x, and put all greater elements (greater than x) after x.

// TC = O(nlogn) in average case, O(n^2) in worst case
// SC = O(1) + O(n) for recursive stack


#include<bits/stdc++.h>
using namespace std;

int partition(vector<int>&arr, int low, int high){
    int pivot = arr[low];
    int i = low;
    int j = high;
    while(i<j){
        while(arr[i]<=pivot && i<=high){
            i++;
        }
        while(arr[j]>pivot && j>=low){
            j--;
        }
        if(i<j){
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[low], arr[j]);
    return j;
}

void quickSort(vector<int>&arr, int low, int high){
    if(low<high){
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot-1);
        quickSort(arr, pivot+1, high);
    }
}

int main(){
    vector<int>arr = {10, 7, 8, 9, 1, 5};
    quickSort(arr, 0, arr.size()-1);
    for(int i=0; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
