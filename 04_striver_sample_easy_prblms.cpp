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

int main(){
    printNum(5);
    return 0;
}