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
/*
时间复杂度:148mm
空间复杂度: 31m
*/

// 3. O(N)

// class Solution {
// public:
// vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//     vector<int> result;
//     if (k == 0) return result;
//     deque<int> w;
//     for (int i = 0, n = (int)nums.size(); i < n; i++) {
//         while (!w.empty() && w.front() <= i-k)
//             w.pop_front();
//         while (!w.empty() && nums[w.back()] <= nums[i])
//             w.pop_back();
//         w.push_back(i);
//         if (i >= k-1)
//             result.push_back(nums[w.front()]);
//     }
//     return result;
// }
// };

/*
时间复杂度O(n):92 mm
空间复杂度: 28m
*/


// class Solution {  
// public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         vector<int> result;
//         int max = nums[0];
//         int max_index = 0;
//         int j = 0;
//         for (int i = 0; i < nums.size()-k+1; i++) {
//             if (i > 0 && max_index >= i){
//                 j = i + k -1;
//             }else{
//                 max = nums[i];
//                 j = i + 1;
//             }
//             for (; j < k+i ; j++){
//                 if (max < nums[j]) {
//                     max = nums[j];
//                     max_index = j;
//                 }
//             }
//             result.push_back(max);
//         }    
//         return result;
//     }
// };
/*
时间复杂度O(n): 88m 
空间复杂度O(1): 28mm 使用了常数项变量
*/

//dp

class Solution{
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        int n = nums.size();
        vector<int> left(n, 0), right(n+1, 0);
        int j=0;
        for (int i = 0; i < n;i++) {
            if (i%k == 0){
                left[i] = nums[i];
            }else{
                left[i] = max(left[i-1], nums[i]);
            }

            j = n - i - 1;
            if ((j+1)%k == 0){
                right[j] = nums[j];
            }else
            {
                right[j] = max(right[j+1], nums[j]);
            }
        }

        for (int i = 0; i < n-k+1;i++) {
            result.push_back(max(left[i+k-1], right[i]));
        }
        return result;
    }
};

// @lc code=end

