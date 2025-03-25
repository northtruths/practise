#define _CRT_SECURE_NO_WARNINGS


#define _CRT_SECURE_NO_WARNINGS

//添加逗号
//#include <iostream>
//#include<string>
//#include<algorithm>
//using namespace std;
//
//int main() {
//    int n = 0;
//    cin >> n;
//    string s = to_string(n);
//    string ret;
//    int t = 0;
//    for (int i = s.size() - 1; i >= 0; --i)
//    {
//        ret += s[i];
//        ++t;
//        if (t == 3)
//        {
//            ret += ',';
//            t = 0;
//        }
//    }
//    if (ret[ret.size() - 1] == ',')
//        ret.erase(ret.size() - 1, 1);
//    reverse(ret.begin(), ret.end());
//    cout << ret << endl;
//}



//跳台阶
//#include<iostream>
//using namespace std;
//
//int main() {
//    //dp[i]为跳上第i台阶的最多跳法
//    //第i台阶可以从i-1和i-2的台阶上跳上
//    //dp[i] = dp[i - 1] + dp[i - 2];
//    int n;
//    cin >> n;
//    int dp[n + 1];
//    dp[0] = 0;
//    dp[1] = 1;
//    dp[2] = 2;
//    for (int i = 3; i <= n; ++i) {
//        dp[i] = dp[i - 1] + dp[i - 2];
//    }
//    cout << dp[n] << endl;
//    return 0;
//}



//扑克牌顺子
//class Solution {
//public:
//    /**
//     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
//     *
//     *
//     * @param numbers int整型vector
//     * @return bool布尔型
//     */
//    bool IsContinuous(vector<int>& numbers) {
//        //若有重复的非零，则false
//        //最大减最小差值不大于4即可
//        sort(numbers.begin(), numbers.end());
//        int count = 0;
//        for (int i = 0; i < 5; ++i)
//        {
//            if (i < 4 && numbers[i] && numbers[i] == numbers[i + 1])
//                return false;
//            if (numbers[i] == 0)
//                ++count;
//        }
//        int dif = numbers[4] - numbers[count];
//        if (dif <= 4)
//            return true;
//        else
//            return false;
//    }
//};