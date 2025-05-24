#define _CRT_SECURE_NO_WARNINGS


//棋子翻转
//class Solution {
//public:
//    /**
//     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
//     *
//     *
//     * @param A int整型vector<vector<>>
//     * @param f int整型vector<vector<>>
//     * @return int整型vector<vector<>>
//     */
//    vector<vector<int> > flipChess(vector<vector<int> >& A, vector<vector<int> >& f) {
//        //模拟
//        int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
//        for (auto& ab : f) {
//            int a = ab[0] - 1, b = ab[1] - 1;
//            for (auto& e : dir) {
//                int x = a + e[0];
//                int y = b + e[1];
//                if (0 <= x && x < A.size() && 0 <= y && y < A[0].size())
//                    A[x][y] ^= 1;
//            }
//        }
//        return A;
//    }
//};




//宵暗的妖怪
//#include <iostream>
//#include<vector>
//using namespace std;
//
//int main() {
//    //动态规划
//    //dp[i]为0~i的最大饱食度
//    //dp[i] = max(dp[i - 1], dp[i - 3] + a[i - 1])，因为是取连续3个元素的中间，所以选择取i实际上是选择取i-1吞噬i和i-2
//    int n = 0;
//    cin >> n;
//    vector<long long> nums(n);
//    for (int i = 0; i < n; ++i)
//        cin >> nums[i];
//    vector<long long> dp(n);
//    dp[0] = 0;
//    dp[1] = 0;
//    dp[2] = nums[1];
//    for (int i = 3; i < n; ++i) {
//        dp[i] = max(dp[i - 1], dp[i - 3] + nums[i - 1]);
//    }
//    cout << dp[n - 1] << endl;
//    return 0;
//}





//过桥（未ac，75%， 超时）
//#include <iostream>
//#include<vector>
//using namespace std;
//
//long long Dfs(vector<int>& nums, vector<long long>& ret, int i, vector<bool>& hash);
//int n = 0;
//int main() {
//    //记忆化搜索
//    //一个哈希数组记录从这块板子上到终点的最快时间
//    cin >> n;
//    vector<int> nums(n + 1);
//    for (int i = 1; i <= n; ++i)
//        cin >> nums[i];
//    vector<long long> ret(n + 1, 0x3f3f3f3f);
//    vector<bool> hash(n + 1);
//    ret[n] = 0;
//    Dfs(nums, ret, 1, hash);
//    if (hash[n] == 0x3f3f3f3f)
//        cout << -1 << endl;
//    else
//        cout << ret[1] << endl;
//    return 0;
//}
//
////Dfs为从第i块板子上到终点的最快时间
//long long Dfs(vector<int>& nums, vector<long long>& ret, int i, vector<bool>& hash) {
//    //cur为当前时间，i为当前板子标号
//    if (ret[i] != 0x3f3f3f3f) {//ret[n]已初始化0，包含 i == n 的情况
//        return ret[i];
//    }
//    hash[i] = true;
//    if (nums[i] > 0) {
//        for (int j = i + 1; j <= i + nums[i]; ++j) {
//            if (j <= n && hash[j] == false)
//                ret[i] = min(ret[i], Dfs(nums, ret, j, hash) + 1);
//        }
//    }
//    else if (nums[i] < 0) {
//        for (int j = i - 1; j >= i + nums[i]; --j) {
//            if (j > 1 && hash[j] == false)
//                ret[i] = min(ret[i], Dfs(nums, ret, j, hash) + 1);
//            else
//                ret[i] = min(ret[i], ret[1]);
//        }
//    }
//    hash[i] = false;
//    return ret[i];
//}