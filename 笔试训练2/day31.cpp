#define _CRT_SECURE_NO_WARNINGS

//小红的口罩
//#include <iostream>
//#include<queue>
//using namespace std;
//
//int main() {
//    //一个小堆解决
//    int n, k;
//    cin >> n >> k;
//    priority_queue<long long, vector<long long>, greater<>> heap;
//    for (int i = 0; i < n; ++i) {
//        long long temp = 0;
//        cin >> temp;
//        heap.push(temp);
//    }
//    long long cur = 0;//不舒适度总和
//    int day = 0;
//    while (cur <= k) {
//        cur += heap.top();
//        long long  add = heap.top() * 2;
//        heap.pop();
//        heap.push(add);
//        if (cur <= k)
//            ++day;
//    }
//    cout << day << endl;
//    return 0;
//}


//春游（看了题解、资料、讨论等等，最后对比代码给做出来了，很简单的一题，但是边界条件一直没考虑到，一直错，以后一定注意各个地方的边界条件）
//#include <iostream>
//using namespace std;
//
//int main() {
//    //贪心，先看坐满时哪个划算，再看对应剩下的人数安排
//    int t = 0;
//    cin >> t;
//    while (t--) {
//        long long n, a, b;
//        cin >> n >> a >> b;
//        long long ret = 0;
//        if (n <= 2)
//            ret += min(a, b);
//        else if (3 * a < 2 * b) {
//            ret += n / 2 * a;
//            if (n % 2 == 1) {
//                ret += min(min(a, b), b - a);
//            }
//        }
//        else {
//            ret += n / 3 * b;
//            if (n % 3 == 1) {
//                ret += min(min(a, b), a + a - b);
//            }
//            else if (n % 3 == 2) {
//                ret += min(min(a, b), a + a + a - b);
//            }
//        }
//        cout << ret << endl;
//    }
//    return 0;
//}


//数位染色
//#include <iostream>
//#include <linux/limits.h>
//#include<vector>
//using namespace std;
//
//int main() {
//    //寻找数位是否能达到总和的一半
//    //数位很少最多18位，数据小，背包问题
//    long long x = 0;
//    cin >> x;
//    vector<int> nums;
//    double sum = 0;
//    while (x) {
//        int temp = x % 10;
//        sum += temp;
//        nums.push_back(temp);
//        x /= 10;
//    }
//    sum /= 2;
//    if (sum != (int)sum) {
//        cout << "No" << endl;
//        return 0;
//    }
//    //dp为只看前i位，和是否能为j
//    vector<bool> dp(sum + 1);
//    dp[0] = true;
//    for (int i = 0; i < nums.size(); ++i) {
//        for (int j = sum; j >= 0; --j) {
//            if (j - nums[i] >= 0)
//                dp[j] = dp[j] || dp[j - nums[i]] ? true : false;
//        }
//    }
//    if (dp[sum]) {
//        cout << "Yes" << endl;
//    }
//    else {
//        cout << "No" << endl;
//    }
//    return 0;
//}