#define _CRT_SECURE_NO_WARNINGS


//添加字符
//#include <iostream>
//#include<string>
//#include<climits>
//using namespace std;
//
//int main() {
//    string a, b;
//    cin >> a >> b;
//    int n = b.size() - a.size();
//    int ret = INT_MAX;
//    for (int i = 0; i <= n; ++i) {
//        int cur = 0;
//        int k = 0;
//        for (int j = i; j < i + a.size(); ++j) {
//            if (a[k++] != b[j])
//                ++cur;
//        }
//        ret = min(ret, cur);
//    }
//    cout << ret << endl;
//    return 0;
//}



//数组变换（看题解视频后ac，贪心尽量把东西写下来找规律）
//#include <iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//int main() {
//    //贪心，
//    int n;
//    cin >> n;
//    vector<int> arr(n);
//    int m = 0;
//    for (int i = 0; i < n; ++i) {
//        cin >> arr[i];
//        m = max(arr[i], m);
//    }
//    int flag = 1;
//    for (int i = 0; i < n; ++i) {
//        if (!(m % arr[i] == 0 && (m / arr[i] % 2 == 0 || m / arr[i] == 1))) {
//            flag = 0;
//            break;
//        }
//    }
//    if (flag)
//        cout << "YES" << endl;
//    else
//        cout << "NO" << endl;
//    return 0;
//}


//装箱问题
//#include <iostream>
//#include<vector>
//using namespace std;
//
//int main() {
//    //dp[i][j]为只看前i个物品，物品总体积小于等于j的最大体积
//    //dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - arr[i]] + arr[i])
//    //i这一维省略
//    int V = 0, n = 0;
//    cin >> V >> n;
//    vector<int> arr(n);
//    for (int i = 0; i < n; ++i)
//        cin >> arr[i];
//    vector<int> dp(V + 1);
//    dp[0] = 0;
//    for (int i = 0; i < n; ++i) {
//        for (int j = V; j >= 0; --j) {
//            if (j - arr[i] >= 0)
//                dp[j] = max(dp[j], dp[j - arr[i]] + arr[i]);
//        }
//    }
//    cout << V - dp[V] << endl;
//    return 0;
//}