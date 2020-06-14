/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */

// @lc code=start
// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         return nums[nums.size()/2];
//     }
// };
/*
该用法的前提是多数一定存在，因为个数满足n/2，所以排序后的中数一定是多数本数
*/

// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         unordered_map<int, int> m;
//         int limit = nums.size()/2;
//         for (int num: nums) {
//             if (++m[num] > limit) return num;
//         }
//         return -1;
//     }
// };


// class Solution {  // 投票法 ，只要票数过半，最后肯定会返回
// public:
//     int majorityElement(vector<int>& nums) {
//         int count = 0;
//         int candidate;
//         for (int num: nums){
//             if (count == 0) candidate = num;
//             if (num == candidate) count++;
//             else count--;
            
//         }
//         return candidate;
//     }
// };


// class Solution {  // 牛逼啊兄弟, 概率统计秀一脸，总感觉运气不好会找不到
// public:
//     int majorityElement(vector<int>& nums) {    //每一轮随机选择一个数字，统计出现次数，因为目标出现频率大于二分之一，所以效率较高
//         while(true)
//         {
//             int candidate=nums[rand() % nums.size()],count=0;   
//             for(int n:nums)
//             {
//             if(n==candidate)     
//                 count++;
//             }
//             if(count > nums.size()/2)           return candidate;
//         }
//         return -1;
//     }
// };



// @lc code=end

