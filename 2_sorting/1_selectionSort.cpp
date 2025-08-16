/* 
Repeatedly find the minimum element from the unsorted part of the list and move it to the beginning. 

Selection: Select the minimum from the unsorted part and swap it with the first unsorted element.
Time Complexity: O(n^2) in all cases.
Space Complexity: O(1) as it is an in-place(no extra-space needed) sorting algorithm.
Stable: No, because it may change the relative order of equal elements.
*/

/*
Pass 1: Find the minimum [64, 25, 12, 22, 11], minimum is 11, swap it with 64
[11, 25, 12, 22, 64]

Pass 2: Finf the minimum from the unsorted part [25, 12, 22, 64], minimum is 12, swap it with 25
[11, 12, 25, 22, 64]

So on... till the subarray is sorted.
*/

class Solution {
  public:
    // Function to perform selection sort on the given array.
    void selectionSort(vector<int> &arr) {
        // code here
        int n = arr.size() ;

        for (int i = 0 ; i < n - 1 ; i++ ) {
            int minIndex = i ;
            for(int j = i + 1 ; j < n ; j++ ) {
                if( arr[minIndex] >= arr[j] ) {
                    minIndex = j ;
                }
            }
            
            if( minIndex != i) {
                swap( arr[i] , arr[minIndex]) ;
            } 
        }
    }
};