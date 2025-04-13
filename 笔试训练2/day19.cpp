#define _CRT_SECURE_NO_WARNINGS


//小易的升级之路
//#include <iostream>
//using namespace std;
//
//int Func(int a, int b) {
//    int c = a % b;
//    while (c) {
//        a = b;
//        b = c;
//        c = a % b;
//    }
//    return b;
//}
//
//int main() {
//    int n = 0;
//    long long x = 0;
//    cin >> n >> x;
//    for (int i = 0; i < n; ++i) {
//        int cur = 0;
//        cin >> cur;
//        if (x >= cur)
//            x += cur;
//        else
//            x += Func(x, cur);
//    }
//    cout << x << endl;
//    return 0;
//}


//礼物的最大价值
//class Solution {
//public:
//    /**
//     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
//     *
//     *
//     * @param grid int整型vector<vector<>>
//     * @return int整型
//     */
//    int maxValue(vector<vector<int> >& grid) {
//        //dp[i][j]为到ij位置的最大价值
//        int m = grid.size(), n = grid[0].size();
//        vector<vector<int>> dp(m, vector<int>(n));
//        dp[0][0] = grid[0][0];
//        for (int i = 1; i < m; ++i)
//            dp[i][0] = dp[i - 1][0] + grid[i][0];
//        for (int j = 1; j < n; ++j)
//            dp[0][j] = dp[0][j - 1] + grid[0][j];
//        for (int i = 1; i < m; ++i) {
//            for (int j = 1; j < n; ++j) {
//                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
//            }
//        }
//        return dp[m - 1][n - 1];
//    }
//};



//对称之美
//#include <iostream>
//#include<vector>
//#include<unordered_set>
//#include<string>
//using namespace std;
//
//int main() {
//    int t = 0;
//    cin >> t;
//    int n = 0;
//    while (t--) {
//        cin >> n;
//        getchar();//因为后面要用getchar，提前把这个\n扔掉
//        int half = (n - 1) / 2;//前面半截输入，后面半截直接判断了
//        vector<unordered_set<char>> arr(n);
//        if (n % 2 == 1)
//            --half;
//        for (int i = 0; i <= half; ++i)
//        {
//            while (1) {
//                char ch;
//                ch = getchar();
//                if (ch == '\n')
//                    break;
//                arr[i].insert(ch);
//            }
//        }
//        if (n % 2 == 1) {
//            while (1) {
//                char ch;
//                ch = getchar();
//                if (ch == '\n')
//                    break;
//            }
//        }
//        int flag = 0;
//        while (half >= 0) {
//            int flag2 = 0;//判断当前输入的字符串和对应回文的字符串是否有相同字符
//            while (1) {
//                char ch;
//                ch = getchar();
//                if (ch == '\n')
//                    break;
//                if (arr[half].count(ch)) {
//                    flag2 = 1;
//                }
//            }
//            if (flag2 == 0) {
//                flag = 1;
//            }
//            --half;
//        }
//        if (flag)
//            cout << "No" << endl;
//        else
//            cout << "Yes" << endl;
//        
//    }
//    return 0;
//}