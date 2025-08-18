// https://www.geeksforgeeks.org/problems/quick-sort/1

/*
Divide & Conquer:
Its genius lies in a step called partitioning. It picks an element as a pivot and rearranges the array so that all elements smaller than 
the pivot are on its left, and all elements greater are on its right.

Time Complexity:
Best: O(n log n)
Average: O(n log n)
Worst: O(n^2) - when the smallest or largest element is always picked as pivot.
Space Complexity: O(log n) - for recursive stack space.
Stable: No - because it does not preserve the order of equal elements.
In-place: Yes - it requires only a constant amount of additional space.
*/

/*
Pivot picking is random, but the code logic changes based on the pivot chosen. (solved using the first or/ last element as pivot)

[7, 2, 1, 6, 8, 5, 3, 4]

Pick pivot 4 -> [2, 1, 3, 4, 8, 5, 7, 6] : 4 is now in its final position.
Now, recursively apply quicksort to the left and right subarrays.

[2, 1, 3] and [8, 5, 7, 6]

Pick pivot 3 -> [2, 1, 3] : 3 is now in its final position.
Pick pivot 6 -> [5, 6, 7, 8] : 6 is now in its final position.

So on...
*/

class Solution
{
    public:
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
    {
        // Base case: if the segment has more than one element
        if (low < high) {
        int pIndex = partition(arr, low, high);
        quickSort(arr, low, pIndex - 1);
        quickSort(arr, pIndex + 1, high);
        }
    }
    
    public:
    int partition (int arr[], int low, int high)
    {
        // Choosing the first element as pivot
        int pivot = arr[low];
        int i = low;
        int j = high;

        while (i < j) {
            while (arr[i] <= pivot && i <= high - 1) {
                    i++;
                }
            
            while (arr[j] > pivot && j >= low + 1) {
                    j--;
                }
            if (i < j) swap(arr[i], arr[j]);
        }

        swap(arr[low], arr[j]);

        return j;

    //     // Choosing the last element as pivot
    //     int pivot = arr[high];
        
    //     // Index of the smaller element's boundary
    //     int i = (low - 1);

    //     // Iterate through the array from the 'low' index up to 'high-1'
    //     for (int j = low; j < high; ++j) {
    //         // If the current element is smaller than or equal to the pivot
    //         if (arr[j] <= pivot) {
    //             i++; // Increment the boundary of the smaller element region
    //             std::swap(arr[i], arr[j]);
    //         }
    //     }
    
    // // After the loop, place the pivot in its correct sorted position
    // std::swap(arr[i + 1], arr[high]);
    
    // // Return the partition index
    // return (i + 1);

    }
};