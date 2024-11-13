// 5 easy steps to conquer recursion
// Step 1: Identify the base case
// Step 2 : Play around with examples and visualize the problem
// Step 3: Relate hard cases to simpler cases
// Step 4: Generalize the pattern
// Step 5: Write code by combining the recursive pattern with the base case

// Example 3 : Write a unique function that takes two inputs n and m and outputs the number of unique 
// paths from top left corner to bottom right corner of a n*m grid. You can only move right or down.

#include<bits/stdc++.h>
using namespace std;

int uniquePaths(int n, int m){
    // Identify the base case
    // If there is only one row or one column then there is only one way to reach the bottom right corner i.e move right or down
    if(n == 1 || m == 1)return 1;
    // Relate hard cases to simpler cases
    // For eg :- if n = 2 and m = 2 then we can reach the bottom right corner by moving right and then down or by moving down and then right
    // Here notice that if n = 2 and m = 1 then we can reach the bottom right corner by moving right and then down i.e 1 way
    // Similarly if n = 1 and m = 2 then we can reach the bottom right corner by moving down and then right i.e 1 way
    // So point to be noticed is that if we move one step to the right of path of 2X1 grid then we will reach the bottom right corner of 2X2 grid
    // Similarly if we move one step down of path of 1X2 grid then we will reach the bottom right corner of 2X2 grid
    // This gives a pattern that to reach the bottom right corner of nXm grid we can reach there by moving to the bottom right corner of (n-1)Xm grid or nX(m-1) grid
    // Generalize the pattern
    // i.e number of ways to reach the bottom right corner of nXm grid = number of ways to reach the bottom right corner of (n-1)Xm grid + number of ways to reach the bottom right corner of nX(m-1) grid
    return uniquePaths(n-1,m) + uniquePaths(n,m-1);
}

int main(){
    int n,m;
    cout<<"Enter the number of rows and columns : "<<endl;
    cin>>n>>m;
    cout<<"Number of unique paths from top left corner to bottom right corner of a "<<n<<"X"<<m<<" grid is : "<<uniquePaths(n,m)<<endl;
    return 0;
}

