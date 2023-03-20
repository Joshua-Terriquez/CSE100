#include<stdio.h>
#include<iostream>
#include<limits.h>

using namespace std;
//References:
// - https://www.geeksforgeeks.org/maximum-subarray-sum-using-divide-and-conquer-algorithm/#:~:text=The%20idea%20is%20simple%2C%20find%20the%20maximum%20sum,maximum%20among%20left%2C%20right%20and%20combination%20of%20both.
// - https://stackoverflow.com/questions/68327188/find-a-max-sub-array-in-array
// - https://www.alphacodingskills.com/cpp/pages/cpp-program-maximum-subarray-problem.php

int max(int a, int b) { return (a > b)? a : b; }
int max(int a, int b, int c) { return max(max(a, b), c); } 

int find_max_crossing_subarray(int arr[], int low, int mid,int high){
  int sum = 0;
  int left_sum = INT_MIN;  // values on left of mid
  for (int i = mid; i >= low; i--){
    sum += arr[i];
    left_sum = max(sum,left_sum);
  }

  sum = 0;
  int right_sum = INT_MIN;   // for values on right of mid
  for (int i = mid +1; i <= high ; i++){
    sum += arr[i];
    right_sum = max(sum,right_sum);
  }

  return max(left_sum + right_sum,left_sum,right_sum);
}
int find_maximum_subarray(int arr[], int low, int high){
  if (high == low){
    return arr[low];    //base----case
  }
  int mid = (low + high)/2;  //converted comparision done in pseudo into max funct.
  return max(max(find_maximum_subarray(arr,low,mid),find_maximum_subarray(arr,mid+1,high)),find_max_crossing_subarray(arr,low,mid,high));

}
int main(){

  int n;                    //taking inputs
  cin >> n;
  int arr[n];
  for (int i =0; i < n; i++){
    cin >> arr[i];
  }
  int max_sum = find_maximum_subarray(arr,0,n-1);
  cout << max_sum;   //printing results
  return 0;
  }
