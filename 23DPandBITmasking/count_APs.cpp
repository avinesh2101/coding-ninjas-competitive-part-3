/*Number of APs
Send Feedback
Given an array of n positive integers. The task is to count the number of Arithmetic Progression subsequences in the array. As the answer could be very large, output it modulo 100001.
Note: Empty sequence or single element sequence is Arithmetic Progression.
Input Format:
First Line: N (the size of the array)
Second Line: Elements of the array separated by spaces.
Output:
 Print total number of subsequences
Input Constraints:
1 <= arr[i] <= 1000
1 <= sizeof(arr) <= 1000
Sample Input 1 :
3
1 2 3
Sample output:
8
Sample Output Explanation:
Total subsequence are: {}, { 1 }, { 2 }, { 3 }, { 1, 2 }, { 2, 3 }, { 1, 3 }, { 1, 2, 3 }
Sample Input 2:
7
1 2 3 4 5 9 10
Sample Output:
37*/
#include <iostream>
#include <stdio.h>
using namespace std;

int numofAP(int *arr, int n){
    /*
    Return all possible AP subsequences formed from the given integer array. You donot need to take input or print anything.
    Just return the ans.
    */
        int ans = n+1;
        int**dp = new int[1000];
        for(int i=0;i<n;i++)
        {
            dp[i] = new int[1000];
            
        }
}

int main(){

    int N;
    cin >> N;

    int *arr = new int[N+1];
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    cout << numofAP(arr, N) << endl;

    return 0;
}
