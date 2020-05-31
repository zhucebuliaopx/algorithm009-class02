/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

// @lc code=start
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // hash保存，<num, 频率>
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size();i++) {
            m[nums[i]]++;
        }
        int n = m.size();
        //使用容量为k的小根堆保存数据，将键值对插入，根部数据的频率最低，当后边的数据d于根部，替换即可，最终的heap保存的就是top k 个元素
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (auto it=m.begin(); it!=m.end(); it++){
            if (k == pq.size()){
                if (it->second > pq.top().first){
                    pq.pop();
                    pq.push_back(it->second, it->first);
                }
            }else{
                pq.push_back(make_pair(it->second, it->first));  // c++中，两个pair类型比较，默认先比较第一个，第一个相同再比较第二个,保证小根堆按照频率排好序
            }
        }
        // 顺序输入目标数组
        vector<int> v;
        while(!pq.is_empty()){
            v.push_back(pq.top().second);
            pq.pop();
        }
        return v;
    }
};
// @lc code=end

