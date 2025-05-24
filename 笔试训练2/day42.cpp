#define _CRT_SECURE_NO_WARNINGS


//最大差值
//#include <climits>
//class Solution {
//public:
//    /**
//     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
//     *
//     *
//     * @param A int整型vector
//     * @param n int整型
//     * @return int整型
//     */
//    int getDis(vector<int>& A, int n) {
//        //动态规划
//        //拿记录当前及之前的最小值，dp[i] = max(dp[i - 1], 当前值减最小值)
//        //滚动数组优化
//		  //这其实是贪心思想
//        long long ret = 0;
//        long long pre_min = A[0];//前面的最小值
//        for (int i = 1; i < n; ++i) {
//            ret = max(ret, A[i] - pre_min);
//            pre_min = min(pre_min, (long long)A[i]);
//        }
//        return ret;
//    }
//};




//兑换零钱
//#include <iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//int main() {
//    //完全背包
//    //dp[i][j]为只看前i种面值，和为j的最小面值
//    //dp[i][j] = min(dp[i][j], dp[i - 1][j - money[i]] + 1)
//    //i这一维省略
//    int n, aim;
//    cin >> n >> aim;
//    vector<int> money(n);
//    for (int i = 0; i < n; ++i)
//        cin >> money[i];
//    sort(money.begin(), money.end());//排序保证后面的货币比前面面值大，即可能能用前面的凑
//    vector<int> dp(aim + 1, 0x3f3f3f3f);
//    dp[0] = 0;
//    for (int i = 0; i < n; ++i) {
//        for (int j = 1; j <= aim; ++j) {
//            if (j - money[i] >= 0) {
//                dp[j] = min(dp[j], dp[j - money[i]] + 1);
//            }
//        }
//    }
//    if (dp[aim] == 0x3f3f3f3f)
//        cout << -1 << endl;
//    else
//        cout << dp[aim] << endl;
//    return 0;
//}




小红的子串（未ac，不会）