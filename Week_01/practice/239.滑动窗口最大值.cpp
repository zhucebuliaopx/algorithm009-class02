/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
// class Solution {
// public:
// 	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         if ( k <= 0) return {};
//         deque<int> window;
//         vector<int> res;
//         for (int i = 0; i < k; i++) {
//             while (!window.empty() && nums[window.back()] < nums[i])
//             {
//                 window.pop_back();
//             }
//             window.push_back(i);
//         }
//         res.push_back(nums[window.front()]);

//         for (int i = k; i < nums.size(); i++) {
//             if (!window.empty() && window.front() <= i -k){
//                 window.pop_front();
//             }
//             while (!window.empty() && nums[window.back()] < nums[i])
//             {
//                 window.pop_back();
//             }
//             window.push_back(i);
//             res.push_back(nums[window.front()]);
//         }

//         return res;
// 	}
// };

// class Solution {
// public:
// 	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         if ( k <= 0) return {};
//         deque<int> window;
//         vector<int> res;

//         int right = 0;
//         while (right < nums.size())
//         {
//             if (!window.empty() && (right - k) >= window.front())
//             {
//                 window.pop_front();
//             }

//             while (!window.empty() && nums[right]>nums[window.back()]){
//                 window.pop_back();
//             }
//             window.push_back(right);
//             right++;
//             if (right >= k ) res.push_back(nums[window.front()]);
//         }
        
//         return res;
// 	}
// };



// 1. O(NlogK)

// class Solution {
// public:
// 	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         vector<int> result;
//         if (k == 0) return result;
//         multiset<int> w;
//         for (int i = 0, n = (int)nums.size(); i < n; i++) {
//             if (i >= k)
//                 w.erase(w.find(nums[i-k]));
//             w.insert(nums[i]);
//             if (i >= k-1)
//                 result.push_back(*w.rbegin());
//         }
//         return result;
//     }
// };
// 2. O(NlogN)

// class Solution {
// public:
// vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//     vector<int> result;
//     if (k == 0) return result;
//     priority_queue<pair<int, int>> w;
//     for (int i = 0, n = (int)nums.size(); i < n; i++) {
//         while (!w.empty() && w.top().second <= i-k)
//             w.pop();
//         w.push(make_pair(nums[i],i));
//         if (i >= k-1)
//             result.push_back(w.top().first);
//     }
//     return result;
// }
// };
// 3. O(N)

class Solution {
public:
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> result;
    if (k == 0) return result;
    deque<int> w;
    for (int i = 0, n = (int)nums.size(); i < n; i++) {
        while (!w.empty() && w.front() <= i-k)
            w.pop_front();
        while (!w.empty() && nums[w.back()] <= nums[i])
            w.pop_back();
        w.push_back(i);
        if (i >= k-1)
            result.push_back(nums[w.front()]);
    }
    return result;
}
};

// @lc code=end

