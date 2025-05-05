#define _CRT_SECURE_NO_WARNINGS


//爱吃素
//#include <iostream>
//#include<cmath>
//using namespace std;
//
//bool JugePrime(long long x) {
//    if (x <= 1)  return false;
//    if (x == 2 || x == 3)  return true;
//    if (x % 2 == 0 || x % 3 == 0)  return false;
//
//    for (int i = 6; i <= sqrt(x); i += 6) {
//        if (x % (i - 1) == 0 || x % (i + 1) == 0)
//            return false;
//    }
//    return true;
//}
//
//int main() {
//    int t;
//    cin >> t;
//    while (t--) {
//        long long a, b;
//        cin >> a >> b;
//        if (JugePrime(a * b))
//            cout << "YES" << endl;
//        else
//            cout << "NO" << endl;
//    }
//    return 0;
//}



//相差不超过k的最多数
//#include <iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//int main() {
//    //排序，滑动滑动窗口，若窗口两边差小于k，则里面任意两数差值绝对值也必定小于k
//    int n, k;
//    cin >> n >> k;
//    vector<int> arr(n);
//    for (int i = 0; i < n; ++i)
//        cin >> arr[i];
//    sort(arr.begin(), arr.end());
//    int ret = 0;
//    int left = 0, right = 0;//窗口两边下标
//    while (right < n) {
//        while (right < n && arr[right] - arr[left] <= k)
//            ++right;
//        ret = max(ret, right - left);
//        ++left;
//    }
//    cout << ret << endl;
//    return 0;
//}


//最长公共子序列（一）（开始未ac，在经过一天的对学习方法的精进后，通过标签提示下ac，
// 其实这题做过并且经典简单，但学习方法不到位，导致学习效果很差，如今明白开始改进并马上获得效果）
//#include <iostream>
//#include<string>
//#include<vector>
//using namespace std;
//
//int main() {
//    int n, m;
//    string s1, s2;
//    cin >> n >> m >> s1 >> s2;
//    //dp[i][j]为s1的0~i的子串和s2的0~j的子串的最长公共子序列
//    //当s1[i] == s2[j]时，dp[i][j] = 1 + dp[i - 1][j - 1]，否则dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
//    vector<vector<int>> dp(n, vector<int>(m));
//    for (int j = 0; j < m; ++j)//处理第一行边界
//        dp[0][j] = s1[0] == s2[j] ? 1 : 0;
//    for (int i = 0; i < n; ++i)//处理第一列边界
//        dp[i][0] = s1[i] == s2[0] ? 1 : 0;
//    for (int i = 1; i < n; ++i) {
//        for (int j = 1; j < m; ++j) {
//            dp[i][j] = s1[i] == s2[j] ? 1 + dp[i - 1][j - 1] : max(dp[i - 1][j], dp[i][j - 1]);
//        }
//    }
//    cout << dp[n - 1][m - 1] << endl;
//    return 0;
//}


//最长公共子序列（一）（滚动数组优化空间复杂度）
//#include <any>
//#include <iostream>
//#include<string>
//#include<vector>
//using namespace std;
//
//int main() {
//    int n, m;
//    string s1, s2;
//    cin >> n >> m >> s1 >> s2;
//    //dp[i][j]为s1的0~i的子串和s2的0~j的子串的最长公共子序列
//    //当s1[i] == s2[j]时，dp[i][j] = 1 + dp[i - 1][j - 1]，否则dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
//    //画图理解滚动数组，优化空间
//    if (n > m) {
//        swap(s1, s2);
//        swap(n, m);
//    }
//    vector<int> dp(n + 1, 0);
//    for (int j = 0; j < m; ++j) {
//        int pre = 0;//记录dp[i - 1][j - 1]
//        for (int i = 1; i <= n; ++i) {
//            int cur = s1[i - 1] == s2[j] ? 1 + pre : max(dp[i], dp[i - 1]);
//            pre = dp[i];
//            dp[i] = cur;
//        }
//    }
//    cout << dp[n] << endl;
//    return 0;
//}