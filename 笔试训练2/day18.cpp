#define _CRT_SECURE_NO_WARNINGS



//压缩字符串(一)
//class Solution {
//public:
//    /**
//     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
//     *
//     *
//     * @param param string字符串
//     * @return string字符串
//     */
//    string compressString(string param) {
//        if (param.size() == 0)
//            return string();
//        string ret;
//        char cur_ch = param[0];//当前字符
//        ret += cur_ch;
//        int cur_num = 1;//当前字符个数
//        for (int i = 1; i < param.size(); ++i) {
//            if (param[i] != cur_ch) {
//                if (cur_num != 1)
//                    ret += to_string(cur_num);
//                cur_ch = param[i];
//                ret += cur_ch;
//                cur_num = 1;
//            }
//            else {
//                ++cur_num;
//            }
//        }
//        if (cur_num != 1)
//            ret += to_string(cur_num);
//        return ret;
//    }
//};




//chika和蜜柑
//#include <iostream>
//#include<vector>
//#include<utility>
//#include<algorithm>
//using namespace std;
//
//int main() {
//    //排序，越甜排前，相同甜越酸排后面
//    int n, k;
//    cin >> n >> k;
//    vector<pair<int, int>> nums(n);//first是甜，second是酸
//    for (int i = 0; i < n; ++i)
//        cin >> nums[i].second;
//    for (int i = 0; i < n; ++i)
//        cin >> nums[i].first;
//    sort(nums.begin(), nums.end(), [&nums](auto& x, auto& y)->bool
//        {
//            if (x.first > y.first)
//                return true;
//            else if (x.first == y.second) {
//                return x.second < y.second;
//            }
//            else {
//                return false;
//            }
//        });
//    long long sweet = 0, sour = 0;
//    for (int i = 0; i < k; ++i)
//    {
//        sweet += nums[i].first;
//        sour += nums[i].second;
//    }
//    cout << sour << ' ' << sweet << endl;
//    return 0;
//}



////01背包
//#include<iostream>
//#include<vector>
//using namespace std;
//
//class Solution {
//public:
//    /**
//     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
//     *
//     * 计算01背包问题的结果
//     * @param V int整型 背包的体积
//     * @param n int整型 物品的个数
//     * @param vw int整型vector<vector<>> 第一维度为n,第二维度为2的二维数组,vw[i][0],vw[i][1]分别描述i+1个物品的vi,wi
//     * @return int整型
//     */
//    int knapsack(int V, int n, vector<vector<int> >& vw) {
//        //dp[i][j]为前i个物品体积为j的背包最多装的重量
//        //dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - vw[i - 1][0]] + vw[i][1]);
//        //i这一维可省略
//        vector<int> dp(V + 1, 0);
//        dp[0] = 0;
//        for (int i = 0; i < n; ++i) {
//            for (int j = V; j >= 0; --j) {
//                if (j - vw[i][0] >= 0)
//                    dp[j] = max(dp[j], dp[j - vw[i][0]] + vw[i][1]);
//            }
//        }
//
//        return dp[V];
//    }
//};
//int main() {
//    Solution s;
//    int n = 2;
//    int V = 10;
//    vector <vector<int>> vw(2, vector<int>(2));
//    vw[0][0] = 1;
//    vw[0][1] = 3;
//    vw[1][0] = 10;
//    vw[1][1] = 4;
//    s.knapsack(V, n, vw);
//    return 0;
//}