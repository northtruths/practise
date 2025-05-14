#define _CRT_SECURE_NO_WARNINGS

//跳台拓展问题
//#include <iostream>
//using namespace std;
//
//int main() {
//    //举例模拟
//    int n;
//    cin >> n;
//    cout << (1 << (n - 1)) << endl;
//    return 0;
//}



//包含不超过两种字符的最长子串（看标签、题解、搞了半天后才ac，还是细节没把控好，这次是把控不好，因为控制细节的方式选错了，类似代码框架没搞好，
// 并且开始做时题意都没完全理解，导致开始思考的方向就有问题）
//#include <iostream>
//#include<string>
//#include<unordered_map>
//using namespace std;
//
//int main() {
//    //滑动窗口
//    //维护窗口，用一个count记录当前字符种数，判断种数是否增减，用一个哈希表，当加减后变化为1、0则说明有加减
//    string s;
//    cin >> s;
//    int left = 0, right = 0;//满足条件的子串左右
//    int hash[26] = { 0 };
//    int count = 0;//字符种数
//    int ret = 0;
//    while (right < s.size()) {
//        if (++hash[s[right] - 'a'] == 1)
//            ++count;
//        if (count > 2)
//            ret = max(ret, right - left);
//        while (right < s.size() && count > 2) {
//            if (--hash[s[left] - 'a'] == 0)
//                --count;
//            ++left;
//        }
//        ++right;
//    }
//    ret = max(ret, right - left);
//    cout << ret << endl;
//    return 0;
//}


//字符串的排列（未ac，时间空间复杂度O(n!)）
// (后来做就过了，其实就是正常递归，只不过头脑混乱题都读得懵懂，完全无法分析思路的时间复杂度，加上看了如何剪枝优化，还是得头脑清晰地时候刷题)
//class Solution {
//public:
//    /**
//     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
//     *
//     *
//     * @param str string字符串
//     * @return string字符串vector
//     */
//    vector<string> Permutation(string str) {
//        //每次选择没有选的，递归，时间复杂度刚好为n!
//        //排序+剪枝优化
//        sort(str.begin(), str.end());
//        vector<bool> hash(str.size(), false);
//        string temp;
//        DFS(str, hash, temp);
//        return ret;
//    }
//
//private:
//
//    void DFS(string& str, vector<bool>& hash, string& cur) {
//        if (cur.size() == str.size()) {
//            ret.push_back(cur);
//        }
//        else {
//            for (int i = 0; i < str.size(); ++i) {
//                if (hash[i] == false) {
//                    if (i - 1 >= 0 && hash[i - 1] == false && str[i] == str[i - 1])
//                        continue;//剪枝
//                    cur += str[i];
//                    hash[i] = true;
//                    DFS(str, hash, cur);
//                    hash[i] = false;
//                    cur.pop_back();
//                }
//            }
//        }
//    }
//    vector<string> ret;
//};