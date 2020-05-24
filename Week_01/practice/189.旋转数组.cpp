/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 旋转数组
 */

// @lc code=start
class Solution {   // 当数组长度到20000的时候会超时，同样的代码java是好的？？？？？？？？？
public:
    void rotate(vector<int>& nums, int k) {
        int tmp, pre;
        for (int i = 0; i < k;i++){
            pre = nums[nums.size() - 1];
            for (int j = 0; j < nums.size(); j++){
                tmp = nums[j];
                nums[j] = pre;
                pre = tmp;
            }
        }
    }
};

/*
public class Solution {
    public void rotate(int[] nums, int k) {
        int temp, previous;
        for (int i = 0; i < k; i++) {
            previous = nums[nums.length - 1];
            for (int j = 0; j < nums.length; j++) {
                temp = nums[j];
                nums[j] = previous;
                previous = temp;
            }
        }
    }
}
*/

// class Solution {
// public:
//     void rotate(vector<int>& nums, int k) {
//         k = k % nums.size();
//         reverse(nums, 0, nums.size()-1);
//         reverse(nums, 0, k - 1);
//         reverse(nums, k, nums.size() -1);
//     }
    
//     void reverse(vector<int>& nums, int start, int end) {
//         while (start < end){
//             int temp = nums[start];
//             nums[start] = nums[end];
//             nums[end] = temp;
//             start++;
//             end--;
//         }
//     }
// };
// @lc code=end

