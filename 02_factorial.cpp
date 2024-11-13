// 5 easy steps to conquer recursion
// Step 1: Identify the base case
// Step 2 : Play around with examples and visualize the problem
// Step 3: Relate hard cases to simpler cases
// Step 4: Generalize the pattern
// Step 5: Write code by combining the recursive pattern with the base case


// Example 2 : Write a recursive code to calculate factorial of a number

#include<bits/stdc++.h>
using namespace std;

long long recFactorial(int n){
    // Identify the base case
    // 0! = 1 and 1! = 1 so if n = 0 or n = 1 then return 1
    if(n == 0 || n == 1)return 1;
    // Relate hard cases to simpler cases
    // For eg :- if n = 2 then we know 2! = 2*1 so if we know 1! then we can easily calculate 2! by doing 2*1!
    // Similarly to calculate 5! we can do 5*4!
    // Generalize the pattern
    // i.e n!  = n*(n-1)!
    return n*recFactorial(n-1);
}

int main(){
    int n;
    cin>>n;
    cout<<"Factorial of "<<n<<" is : "<<recFactorial(n)<<endl;
    return 0;
}