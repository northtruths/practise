#define _CRT_SECURE_NO_WARNINGS

//乒乓球框
//#include <iostream>
//#include<string>
//#include<unordered_map>
//using namespace std;
//
//int main() {
//    unordered_map<char, int> hash;
//    string s1, s2;
//    cin >> s1 >> s2;
//    for (auto& e : s1)
//        ++hash[e];
//    unordered_map<char, int> cur;
//    for (auto& e : s2) {
//        ++cur[e];
//    }
//    for (auto& e : cur) {
//        if (e.second > hash[e.first])
//        {
//            cout << "No" << endl;
//            return 0;
//        }
//    }
//    cout << "Yes" << endl;
//    return 0;
//}


//组队竞赛（看了测试用例后ac，细节处理不够仔细，出错了，导致怀疑算法用错了，但不论怎么推导算法都是对的）
//#include <iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//int main() {
//    //贪心策略：每次取值取当前数组中的最大、最小和第二大的元素
//    int n = 0;
//    cin >> n;
//    vector<long long> v(3 * n);
//    for (int i = 0; i < 3 * n; ++i)
//        cin >> v[i];
//    sort(v.begin(), v.end());
//    long long ret = 0;
//    long long left = 0;//当前数组中最小的下标
//    for (int i = 3 * n - 2; i >= left++; i -= 2) {
//        ret += v[i];
//    }
//    cout << ret << endl;
//    return 0;
//}



//删除相邻数字的最大分数（初次未ac，看了题解后ac，但有段时间把正确思路想出来一下，但开始时看错题，后来又觉得数组开得太大不行，就没实施）
//#include <iostream>
//#include <unordered_map>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//int main() {
//    int n;
//    cin >> n;
//    unordered_map<int, int> hash;
//    int m = 0;//最大的数
//    for (int i = 0; i < n; ++i)
//    {
//        int in = 0;
//        cin >> in;
//        m = max(m, in);
//        ++hash[in];
//    }
//    vector<int> dp(m + 1);//数字0~i的最大
//    dp[0] = 0;
//    dp[1] = hash[1];
//    int ret = dp[1];
//    for (int i = 2; i <= m; ++i) {
//        dp[i] = max(dp[i - 1], dp[i - 2] + i * hash[i]);
//        ret = max(ret, dp[i]);
//    }
//    cout << ret << endl;
//    return 0;
//}