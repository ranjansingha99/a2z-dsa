/*
Divide: If the list has more than one item, split it in half. 
Keep splitting the halves until you're left with lists that contain only a single item. A list with one item is, by definition, already sorted.

Merge (and Conquer): Now, start merging these single-item lists back together. When you merge two lists, you create a new, sorted list. 
You repeat this process, merging the sorted lists, until you're back to a single, fully sorted list.
*/

/*
Divide: [8, 3, 5, 4, 7, 6, 1, 2] -> [8, 3, 5, 4] [7, 6, 1, 2] -> [8,3] [5, 4] [7, 6] [1, 2] -> [8] [3] [5] [4] [7] [6] [1] [2]

Merge: [8] [3] -> [3, 8] ; [5] [4] -> [4, 5] ; [7] [6] -> [6, 7] ; [1] [2] -> [1, 2]
       [3, 8] [4, 5] -> [3, 4, 5, 8] ; [6, 7] [1, 2] -> [1, 2, 6, 7]
       [1, 2, 3, 4, 5, 6, 7, 8]

Time Complexity: O(n log n), as we are dividing the array into halves (log n) and merging them back together (O(n)).
Space Complexity: O(n), as we are using extra space for the temporary subarrays, the recursion stack space is O(log n) in the worst case.

Stable: Yes, because it preserves the order of equal elements.
In-place: No, because it requires additional space for the temporary arrays.
*/

class Solution {
  public:
    
    void merge(vector<int>& arr, int left, int mid, int right){
        // Create 2 temporary subarrays, which can hold the elements
        int size1 = mid - left + 1;
        int size2 = right - mid;
        
        vector<int> leftArr(size1);
        vector<int> rightArr(size2);
        
        // Copying the elements into the temporary subarrays
        for(int i=0; i<size1; i++){
            leftArr[i] = arr[left+i];
        }
        for(int j=0; j<size2; j++){
            rightArr[j] = arr[mid+1+j];
        }
        
        // Compare the elements of the 2 subarrays, and put them into the main array in sorted order
        int i=0;    // start of left subarray
        int j=0;    // start of right subarray
        int k=left; // the position of the main array from where the elements will be inserted
        
        while(i<size1 && j<size2){
            if(leftArr[i] >= rightArr[j]){
                arr[k] = rightArr[j];
                j++;
            }else{
                arr[k] = leftArr[i];
                i++;
            }
            k++;
        }
        
        // copy the rest elements of the subarray, when other subarray's are copied completely
        while(i < size1){
            arr[k] = leftArr[i];
            i++;
            k++;
        }
        while(j < size2){
            arr[k] = rightArr[j];
            j++;
            k++;
        }
        
    }
  
    void mergeSort(vector<int>& arr, int l, int r) {
        // check the size of the array
        if(l >= r) return;
        
        // Find the mid of the current array
        int mid = l + (r - l) / 2;
        
        // Recursive calls
        mergeSort(arr, l, mid);
        mergeSort(arr, mid+1, r);
        
        // Compare the elements of the subarrays and merge them in them in the main array
        merge(arr, l, mid, r);
    }
};