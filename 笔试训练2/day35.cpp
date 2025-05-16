#define _CRT_SECURE_NO_WARNINGS


//奇数位丢弃
//#include <iostream>
//using namespace std;
//
//int main() {
//    //每次都舍去奇数位，所有剩下的偶数位数位将会减半（例如：0123456，5为第6位，一轮筛选后为135，5就变为第3位了）
//    //所以若某个位数能更多地除以2还能保持偶数（最小非零偶数为2），这就是最后留下的，即0~n中为2的最大指数的位置，即为答案
//    //将0~n看为1~n+1，便于计算，最后减一还原即可
//    int n;
//    while (cin >> n) {
//        ++n;
//        int ret = 1;
//        while (ret * 2 <= n)
//            ret *= 2;
//        --ret;
//        cout << ret << endl;
//    }
//
//    return 0;
//}


//OR64 求和（奇怪的题目，很简单但标签为难，测试用例给的标准输出和答案的输出格式完全不同，误导人）
//#include <iostream>
//#include<vector>
//using namespace std;
//int n, m;
//void Dfs(vector<int>& ret, int ret_size, int cur_i, int sum) {
//    if (sum == m) {
//        for (int i = 0; i < ret_size; ++i) {
//            cout << ret[i] << ' ';
//        }
//        cout << endl;
//        return;
//    }
//    else if (sum > m)
//        return;
//
//    for (int i = cur_i; i <= n; ++i) {
//        sum += i;
//        ret[ret_size] = i;
//        Dfs(ret, ret_size + 1, i + 1, sum);
//        sum -= i;
//    }
//}
//
//int main() {
//    //dfs暴力排列所有情况
//    cin >> n >> m;
//    vector<int> ret(n);
//    Dfs(ret, 0, 1, 0);
//    return 0;
//}



//计算字符串的编辑距离， 看题解后ac，脑袋混乱，知道动态规划，知道状态转移方程，但转移过程情况就是无法清晰地想出来，还是得一步一步读题举例，慢慢考虑所有情况
//#include <iostream>
//#include<vector>
//#include<string>
//
//using namespace std;
//
//int main() {
//    //动态规划，dp[i][j]为s的0~i和t的0~j的最少编辑距离
//    //若s[i] == t[j]，则dp[i][j] = dp[i - 1][j - 1]
//    //若s[i] ！= t[j]，则dp[i][j] = dp[i - 1][j - 1], 考虑增删改的三种情况，dp[i][j] = 三者dp[i-1][j-1], dp[i-1][j], dp[i][j-1]中最小值+1
//    string s, t;
//    cin >> s >> t;
//    int n = s.size(), m = t.size();
//    vector<vector<int>> dp(1 + n, vector<int>(1 + m, 0));
//    for (int i = 1; i <= n; ++i)
//        dp[i][0] = i;
//    for (int j = 1; j <= m; ++j)
//        dp[0][j] = j;
//    for (int i = 1; i <= n; ++i) {
//        for (int j = 1; j <= m; ++j) {
//            if (s[i - 1] == t[j - 1]) {
//                dp[i][j] = dp[i - 1][j - 1];
//            }
//            else {
//                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1;
//            }
//        }
//    }
//    cout << dp[n][m] << endl;
//    return 0;
//}