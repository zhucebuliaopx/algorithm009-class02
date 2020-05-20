/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         vector<int> t;
//         for (int i=0; i < nums.size()-1; i++){
//             for (int j=i+1; j < nums.size(); j++){
//                 if ((nums[i]+nums[j]) == target){
//                     t.push_back(i);
//                     t.push_back(j);
//                     return t;
//                 }
//             }
//         }
//         return t;
//     }
// };
// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         map<int, int> mymap;
//         vector<int> v(2, 0);
//         for (int i=0;i<nums.size();i++){
//             mymap[nums[i]] = i;
//         }

//         for (int i=0;i<nums.size();i++){
//             int t = target - nums[i];
//             if (mymap.count(t) > 0 && mymap[t] != i){
//                 return {i, mymap[t]};
//             }
//         }
//         return v;
//     }
// };

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mymap;
        vector<int> v(2, 0);
        for (int i=0;i<nums.size();i++){
            int t = target - nums[i];
            if (mymap.count(t) > 0){
                return {mymap[t], i};
            }
            mymap[nums[i]] = i;
        }
        return v;
    }
};
// @lc code=end

