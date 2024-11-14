#include<bits/stdc++.h>
using namespace std;

// Problem 1 : Print name n times

void printName(int n){
    // base case
    if(n==0)return;
    // recursive case
    cout<<"Utkarsh"<<endl;
    printName(n-1);
}

// Problem 2 : Print linearly from 1 to n

void printNum(int n){
    if(n==0)return; // Base case
    printNum(n-1); // Recursive case
    cout<<n<<" "; 
}

// Problem 3 : Print sum from 1 to n

void printSum(int n, int sum){  // This is parameterized recursion
    // base case
    if(n==0){
        cout<<sum<<endl;
        return;
    }
    // recursive case
    printSum(n-1,sum+n);
}

int printSum2(int n){ // This is non-parameterized recursion or functional recursion
    //  base case
    if(n==0){
        return 0;
    }
    return n + printSum2(n-1);
}

int main(){
    cout<<printSum2(5);
    return 0;
}