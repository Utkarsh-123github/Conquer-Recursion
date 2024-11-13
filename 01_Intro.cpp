// 5 easy steps to conquer recursion
// Step 1: Identify the base case
// Step 2 : Play around with examples and visualize the problem
// Step 3: Relate hard cases to simpler cases
// Step 4: Generalize the pattern
// Step 5: Write code by combining the recursive pattern with the base case

// Example 1 : Write a recursive code to calculate sum till n

#include<bits/stdc++.h>
using namespace std;

int recSum(int n){
    // Identify the base case
    if(n == 0 || n == 1)return n;
    // Relate hard cases to simpler cases
    // For eg : if n = 5 then if somehow we know answer for n = 4 then we can easily calculate for n = 5 by doing (5 + ans of n = 4)
    // i.e sum will be equal to n + sum of n-1
    // Generalize the pattern
    return n + recSum(n-1);
}

int main(){
    int n;
    cin>>n;
    cout<<"Sum of first "<<n<<" natural numbers is : "<<recSum(n)<<endl;
    return 0;
}