// code structure & logic credit to GeeksforGeeks:
// https://www.geeksforgeeks.org/minimum-cost-to-reach-the-top-of-the-floor-by-climbing-stairs/

// C++ program to find the minimum cost required to reach the n-th floor 
#include <iostream>
#include <vector>
using namespace std; 
  
// function to find the minimum cost 
// to reach N-th floor 
int minCostClimbingStairs(vector<int> &cost) { 
    int n = cost.size();
    // base case 
    if (n == 1) 
        return cost[0]; 
  
    //array to hold minimum cost to get to stair at index 'i'
    int mc[n];  

    //min cost to frist and second element is to directly jump to them
    mc[0] = cost[0]; 
    mc[1] = cost[1]; 
   
   //for each successive jump, determine minimum cost
    for (int i = 2; i < n; i++) { 
        mc[i] = min(mc[i - 1], mc[i - 2]) + cost[i]; 
    } 
  
    // return the minimum for final step 
    return min(mc[n - 2], mc[n - 1]); 
} 
  
// Driver Code 
int main() 
{ 
    vector<int> vect{ 2, 23, 8, 15, 20 }; 
    cout << minCostClimbingStairs(vect)<<endl; 
    return 0; 
} 