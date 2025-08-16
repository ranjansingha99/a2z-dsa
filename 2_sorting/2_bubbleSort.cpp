/*
Repeatedly steps through a list, compares adjacent elements, and swaps them if they are in the wrong order. 
This way it sorts the largeest sorted part of the list to the end.

Bubble Sort: Compare adjacent elements and swap them if they are in the wrong order.
Time Complexity: O(n^2), but can be O(n) if the list is already sorted.
Space Complexity: O(1) as it is an in-place(no extra-space needed) sorting algorithm.
Stable: Yes, because it does not change the relative order of equal elements.
*/

/*
Pass 1: [5, 1, 4, 2, 8] -> [1, 5, 4, 2, 8] -> [1, 4, 5, 2, 8] -> [1, 4, 2, 5, 8] -> [1, 2, 4, 5, 8]

Pass 2: [1, 2, 4, 5, 8] -> [1, 2, 4, 5, 8] -> [1, 2, 4, 5, 8] -> [1, 2, 4, 5, 8] -> [1, 2, 4, 5, 8]

Pass 3: [1, 2, 4, 5, 8] -> [1, 2, 4, 5, 8] -> [1, 2, 4, 5, 8] -> [1, 2, 4, 5, 8] -> [1, 2, 4, 5, 8]

Passes continue until no swaps are needed.
*/

class Solution {
  public:
    void bubbleSort(vector<int>& arr) {
        // code here
        int n = arr.size();
        
        for(int i=n; i>0; i--){
            bool swapFlag = false;
            
            for(int j=0; j<i-1; j++){
                if(arr[j] > arr[j+1] ){
                    swap(arr[j], arr[j+1]);
                    swapFlag = true;
                }
            }

            if(!swapFlag) break;
        }
    }
};

