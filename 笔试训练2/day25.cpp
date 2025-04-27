#define _CRT_SECURE_NO_WARNINGS



//笨小猴
//#include<iostream>
//#include<string>
//#include<cmath>
//using namespace std;
//
//bool Juge(int x) {
//    if (x < 2)
//        return false;
//    for (int i = 2; i <= sqrt(x); ++i) {
//        if (x % i == 0)
//            return false;
//    }
//    return true;
//}
//
//int main() {
//    string s;
//    cin >> s;
//    int arr[26] = { 0 };
//    for (auto& e : s)
//        ++arr[e - 'a'];
//    int maxn = 0, minn = 0x3f3f;
//    for (int i = 0; i < 26; ++i) {
//        maxn = max(maxn, arr[i]);
//        if (arr[i] != 0)
//            minn = min(minn, arr[i]);
//    }
//    int ret = maxn - minn;
//    if (Juge(ret)) {
//        cout << "Lucky Word" << endl;
//        cout << ret << endl;
//    }
//    else {
//        cout << "No Answer" << endl;
//        cout << 0 << endl;
//    }
//    return 0;
//}



//主持人调度（一）
//class Solution {
//public:
//    /**
//     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
//     *
//     *
//     * @param schedule int整型vector<vector<>>
//     * @return bool布尔型
//     */
//    bool hostschedule(vector<vector<int> >& schedule) {
//        sort(schedule.begin(), schedule.end(),
//            [&schedule](vector<int>& v1, vector<int>& v2) ->bool {return v1[0] < v2[0]; });
//        for (int i = 1; i < schedule.size(); ++i) {
//            if (schedule[i][0] < schedule[i - 1][1])
//                return false;
//        }
//        return true;
//    }
//};



//分割等和子集
//#include<iostream>
//#include<vector>
//using namespace std;
//
//int main() {
//    int n;
//    cin >> n;
//    vector<int> nums(n);
//    int sum = 0;
//    for (int i = 0; i < n; ++i) {
//        cin >> nums[i];
//        sum += nums[i];
//    }
//    if (sum % 2 == 1)//为奇数则不可能
//    {
//        cout << "false" << endl;
//        return 0;
//    }
//    sum /= 2;
//    //背包dp
//    //dp[i][j]为只看前i个数，和为j是否能成立
//    vector<bool> dp(sum + 1, false);
//    dp[0] = true;
//    int flag = 0;//只要途中出现过和为sum，则成立
//    for (int i = 0; i < n; ++i) {
//        for (int j = sum; j >= 0; --j) {
//            if (j - nums[i] >= 0)
//                dp[j] = dp[j - nums[i]] == true ? true : false;
//        }
//    }
//    if (dp[sum])
//        cout << "true" << endl;
//    else
//        cout << "false" << endl;
//    return 0;
//}

