#define _CRT_SECURE_NO_WARNINGS


//最长回文字串
//class Solution {
//public:
//    /**
//     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
//     *
//     *
//     * @param A string字符串
//     * @return int整型
//     */
//    int getLongestPalindrome(string A) {
//        // write code here
//        int ret = 1;
//        for (int i = 0; i < A.size(); ++i)
//        {
//            ret = max(ret, len(A, i));
//        }
//        return ret;
//    }
//
//    int len(string& s, int k)
//    {
//        int a = 1;
//        int left = k - 1;
//        int right = k + 1;
//        while (left >= 0 && right < s.size())
//        {
//            if (s[left] == s[right])
//                a += 2;
//            else
//                break;
//            --left; ++right;
//        }
//        if (k + 1 < s.size() && s[k] == s[k + 1])
//        {
//            int b = 2;
//            left = k - 1;
//            right = k + 2;
//            while (left >= 0 && right < s.size())
//            {
//                if (s[left] == s[right])
//                    b += 2;
//                else
//                    break;
//                --left; ++right;
//            }
//            return max(a, b);
//        }
//        return a;
//    }
//};



//买卖股票的最好时机(一)
//#include<iostream>
//#include<vector>
//using namespace std;
//
//int main()
//{
//    int n = 0;
//    cin >> n;
//    vector<int> p(n);
//    for (int i = 0; i < n; ++i)
//        cin >> p[i];
//    vector<int> dp_min(n);//第i下标的位置及之前的最低票价
//    dp_min[0] = p[0];
//    int ret = 0;
//    for (int i = 1; i < n; ++i)
//    {
//        dp_min[i] = min(dp_min[i - 1], p[i]);
//        ret = max(p[i] - dp_min[i], ret);
//    }
//    cout << ret << endl;
//    return 0;
//}


//NC369 [NOIP2002 普及组] 过河卒（未ac，但去题库里，是核心代码模式，ac过了，所以可能是输出格式之类的问题）
//#include<iostream>
//#include<vector>
//#include<unordered_map>
//using namespace std;
//
//int main()
//{
//    int m, n, x, y;
//    cin >> n >> m >> x >> y;
//    vector<int> dir[8] = { {1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1} };
//    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));//dp为下标为i、j的路径条数，dp[i][j] = dp[i-1][j] + dp[i][j-1]
//    if(0 <= x  && x <= n && 0 <= y && y <= m)
//        dp[x][y] = -1;
//    for (auto& e : dir)
//    {
//        if (0 <= x + e[0] && x + e[0] <= n
//            && 0 <= y + e[1] && y + e[1] <= m)
//            dp[x + e[0]][y + e[1]] = -1;
//    }
//
//    if (dp[0][0] == -1)
//    {
//        cout << 0 << endl;
//        return 0;
//    }
//    dp[0][0] = 1;
//    for (int i = 1; i <= n; ++i)
//    {
//        if(dp[i][0] != -1)
//            dp[i][0] = dp[i - 1][0];
//    }
//    for (int j = 1; j <= m; ++j)
//    {
//        if(dp[0][j] != -1)
//            dp[0][j] = dp[0][j - 1];
//    }
//
//    for (int i = 1; i <= n; ++i)
//    {
//        for (int j = 1; j <= m; ++j)
//        {
//            if (dp[i][j] == -1)//此处有马，不能走
//                continue;
//            else
//                dp[i][j] = (dp[i - 1][j] == -1 ? 0 : dp[i - 1][j]) + (dp[i][j - 1] == -1 ? 0 : dp[i][j - 1]);
//        }
//    }
//    cout << dp[n][m] << endl;
//    return 0;
//}