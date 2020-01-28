#include <iostream>
#include <vector>

using namespace std;

/*
Given a sorted array arr of distinct integers, write a function indexEqualsValueSearch that returns the lowest index i for which arr[i] == i. Return -1 if there is no such index. Analyze the time and space complexities of your solution and explain its correctness.
  */

int indexEqualsValueSearch(const vector<int> &arr) 
{
  int n = arr.size();
  int low = 0, high = n - 1, ans = -1;
  while(low <= high) {
    int mid = low + (high - low) / 2;
    if(arr[mid] >= mid) {
      ans = mid;
      high = mid - 1;
    }
    else {
      low = mid + 1;
    }
  }
  return arr[ans] == ans ? ans : -1;
}       

int main() {
  return 0;
}
