#define _CRT_SECURE_NO_WARNINGS


//神奇的字母（二）
//#include <iostream>
//#include<string>
//#include<unordered_map>
//using namespace std;
//
//int main() {
//    string s;
//    unordered_map<char, int> hash;
//    while (cin >> s) {
//        for (auto& ch : s) {
//            ++hash[ch];
//        }
//    }
//    char ret;
//    int count = 0;
//    for (auto& [ch, num] : hash) {
//        if (num > count) {
//            ret = ch;
//            count = num;
//        }
//    }
//    cout << ret << endl;
//    return 0;
//}



//字符编码（又是没有审清楚题，没注意多组输入，最开始还有点印象后面就忘了，状态有点差）
//#include <iostream>
//#include<string>
//#include <ostream>
//#include<queue>
//#include<unordered_map>
//using namespace std;
//
//int main() {
//    //统计每个字符个数作为权值，再通过哈夫曼树加权路径长度算出最短字符串长度  
//    string s;
//    while (cin >> s) {
//        unordered_map<char, long long> hash;
//        for (auto& ch : s)
//            ++hash[ch];
//        if (hash.size() ==
//            1) { //只有一个字符直接返回，因为堆至少取出两个最小权值节点，所以不能兼容
//            cout << 1 << endl;
//            return 0;
//        }
//        priority_queue<long long, vector<long long>, greater<>>
//            heap;//堆，用于取出当前最小根节点权值的两个节点
//        for (auto& [x, y] : hash)
//            heap.push(y);
//        long long ret = 0;
//        while (heap.size() > 1) {
//            long long a = heap.top();
//            heap.pop();
//            long long b = heap.top();
//            heap.pop();
//            ret += a + b;
//            heap.push(a + b);
//        }
//        cout << ret << endl;
//    }
//
//    return 0;
//}




//最少的完全平方数（一开始想复杂了，以为是背包dp，思路不清晰）
//#include <iostream>
//#include<vector>
//#include<cmath>
//using namespace std;
//
//int main() {
//    //动态规划，dp[i]为和i的最小个数和
//    //dp[i] = min[dp[i] + d[0], dp[i - 1] + dp[1], ...]
//    int n = 0;
//    cin >> n;
//    vector<int> dp(n + 1);
//    dp[0] = 0;
//    for (int i = 1; i <= n; ++i) {
//        double temp = sqrt(i);
//        if (temp == (int)temp)//当前i就为完全平方数，直接最少次数为1
//        {
//            dp[i] = 1;
//            continue;
//        }
//        for (int j = i - 1; j >= (i + 1) / 2; --j) {
//            if (dp[i])
//                dp[i] = min(dp[i], dp[j] + dp[i - j]);
//            else
//                dp[i] = dp[j] + dp[i - j];
//        }
//    }
//    cout << dp[n] << endl;
//    return 0;
//}