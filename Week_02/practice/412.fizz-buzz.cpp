/*
 * @lc app=leetcode.cn id=412 lang=cpp
 *
 * [412] Fizz Buzz
 */

// @lc code=start
// class Solution {
// public:
//     vector<string> fizzBuzz(int n) {
//         vector<string> s;
//         for (int i=1;i <= n; i++){
//             if ( i % 15 == 0){
//                 s.push_back("FizzBuzz");
//             }else if (i % 3 == 0){
//                 s.push_back("Fizz");
//             }else if( i % 5 == 0){
//                 s.push_back("Buzz");
//             }else{
//                 s.push_back(to_string(i));
//             }
//         }
//         return s;
//     }
// };


class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> s;
        map<int, string> fizzBuzz;

        fizzBuzz[3] = "Fizz";
        fizzBuzz[5] = "Buzz";
        for (int i = 1; i <= n; i++) {
            string tmp = "";
            for (auto j : fizzBuzz) if (i % j.first == 0) tmp += j.second;
            if (tmp.empty()) tmp = to_string(i);
            s.emplace_back(tmp);
        }
        return s;
    }
};
// @lc code=end

