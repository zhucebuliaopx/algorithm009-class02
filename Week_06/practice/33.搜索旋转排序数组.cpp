/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
       int n = nums.size();
       if (n == 0) return -1;
       if (n == 1) return nums[0] == target ? 0 : -1;
       int first = 0;
       int end = n - 1;
       while (first <= end) {
           int mid = first + (end - first)/2;
           if (target == nums[mid]) return mid;
           if (nums[0] <= nums[mid]){
               if (target >= nums[first] && target <= nums[mid]){
                   end = mid -1;
               }else{
                   first = mid + 1;
               }
           }else{
               if ( target >= nums[mid] && target <= nums[n-1]){
                   first = mid + 1;
               }else{
                   end = mid - 1;
               }
           }
       }
       return -1;
    }
};
// @lc code=end

