// https://www.geeksforgeeks.org/problems/who-will-win-1587115621/1

/*
Sorted Array: focus on binary search.
Time Complexity: O(log n)
Space Complexity: O(1) - no extra space is used.
*/

/*
Note: Make sure you handle the situation when the array narrows down to a single element.
(right >= left) is the condition where the search gets successful.
*/

class Solution {
  public:
    bool searchInSorted(vector<int>& nums, int target) {
        // code here
        int right = nums.size() - 1;
        int left = 0;
        
        if(nums.size() == 0) return false;
        if(nums.size() == 1){
            if(nums[right] == target) return true;
            else return false;
        }

        bool ans = false;
        while(right >= left){
            int mid = (right + left) / 2;
            if (nums[mid] == target){
                ans = true;
                break;
            }
            else if(nums[mid] > target){
                right = mid - 1;
            } else{
                left = mid + 1;
            }
        }

        return ans;
    }
};