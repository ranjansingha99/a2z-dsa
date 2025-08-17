class Solution {
  public:
    void helper(vector<int>& arr,int currIndex, int n){
        if(currIndex == n){
            return;
        }
        
        int i=currIndex-1;
        int currElem=arr[currIndex];
        for(; i>=0; i--){
            if(currElem < arr[i]) arr[i+1] = arr[i];
            else break;
        }
        arr[i+1] = currElem;
        
        helper(arr, currIndex+1, n);
    }
  
    void insertionSort(vector<int>& arr) {
        // code here
        int size = arr.size();
        
        helper(arr, 0, size);
    }
};