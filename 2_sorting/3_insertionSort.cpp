// https://www.geeksforgeeks.org/problems/insertion-sort/1

/*
Imagine you're holding a few cards in your hand, and they're already sorted. Someone hands you a new card. 
To keep your hand sorted, you take the new card and compare it with the cards you're already holding, from right to left, 
until you find the correct spot to insert it. You shift the other cards over to make space and slide the new card in.

It iterates through an array, considering one element at a time, 
and "inserts" it into its correct position(by shifting the other other elements first) within the already sorted part of the array.

Time Complexity: O(n^2) in the worst case, but can be O(n) if the array is already sorted.
Space Complexity: O(1) as it is an in-place sorting algorithm.
Stable: Yes, because it does not change the relative order of equal elements.
*/

/*
[5, 2, 4, 6, 1, 3], [5] is already sorted

Pass 1: [2, 5, 4, 6, 1, 3], select 2 and insert it in already sorted part [5] -> [2, 5]

Pass 2: [2, 4, 5, 6, 1, 3], select 4 and insert it in already sorted part [2, 5] -> [2, 4, 5]

Pass 3: [2, 4, 5, 6, 1, 3], select 6 and insert it in already sorted part [2, 4, 5] -> [2, 4, 5, 6]

So on till the last element.
*/

class Solution {
public:
    void insertionSort(std::vector<int>& arr) {
        int n = arr.size();

        // Start from the second element initially, as the first element is consisdered sorted
        for (int i = 1; i < n; i++) {
            int key = arr[i]; // The element to be inserted
            int j = i - 1;    // The last element of the sorted part

            // Move elements of arr[0..j] that are greater than key
            // to one position next of their current position
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }
            // Place the key at its correct sorted position
            arr[j + 1] = key;
        }
    }
};

