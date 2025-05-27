#define _CRT_SECURE_NO_WARNINGS



//差值
//#include <climits>
//#include <iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//int main() {
//    //排序，相邻两个战士一定是它们间最接近的，找出所有最接近的即可
//    int n;
//    cin >> n;
//    vector<int> nums(n);
//    for (int i = 0; i < n; ++i)
//        cin >> nums[i];
//    sort(nums.begin(), nums.end());
//    int ret = INT_MAX;
//    for (int i = 1; i < n; ++i)
//        ret = min(ret, nums[i] - nums[i - 1]);
//    cout << ret << endl;
//    return 0;
//}





//kotori和素因子（未ac，80%）
//#include <iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//bool IsPrime(int n) {
//    if (n <= 1) return false;
//    if (n <= 3) return true;  // 2和3是质数
//    if (n % 2 == 0 || n % 3 == 0) return false;  // 排除能被2或3整除的数
//
//    // 只需要检查6n±1形式的因数
//    for (int i = 5; i * i <= n; i += 6) {
//        if (n % i == 0 || n % (i + 2) == 0) {
//            return false;
//        }
//    }
//    return true;
//}
//
//void FindPrime(int x, vector<int>& nums) {
//    for (int i = 2; i <= x; ++i) {
//        if (x % i == 0 && IsPrime(i))
//            nums.push_back(i);
//    }
//}
//
//int main() {
//    int n;
//    cin >> n;
//    vector<int> nums;
//    for (int i = 0; i < n; ++i) {
//        int x = 0;
//        cin >> x;
//        FindPrime(x, nums);
//    }
//    sort(nums.begin(), nums.end());
//    auto it_end = unique(nums.begin(), nums.end());
//    int ret = 0;
//    auto it_begin = nums.begin();
//    for (auto& e : nums)
//        cout << e << ' ';
//    cout << endl;
//    while (n && it_begin != it_end) {
//        ret += *it_begin;
//        ++it_begin;
//        --n;
//    }
//    if (n)
//        cout << -1 << endl;
//    else
//        cout << ret << endl;
//    return 0;
//}





//dd爱科学1.0
//#include <iostream>
//#include<vector>
//#include<climits>
//using namespace std;
//
//int main() {
//    //动态规划，二维，dp[i][j]为0~i的字符串最后一个基因为j的最小代价
//    //dp[i][j] == dp[i-1][0~j]中的最小值 + 当前字符变为j的代价
//    //遍历dp[i-1][0~25]时，可以用一个数记录当前的最小，因为dp[i]的j是递增在走的，无论如何都大于之前找过的0~j，避免重复去找
//    int n;
//    cin >> n;
//    vector<vector<int>> dp(n + 1, vector<int>(26, 0));//多一行用于初始化
//    for (int i = 1; i <= n; ++i) {
//        char ch = 0;
//        cin >> ch;
//        int cur = INT_MAX;//当前0~j的最小
//        for (int j = 0; j < 26; ++j) {
//            cur = min(cur, dp[i - 1][j]);
//            dp[i][j] = cur + (ch == j + 'A' ? 0 : 1);
//        }
//    }
//    int ret = INT_MAX;
//    for (int j = 0; j < 26; ++j)
//        ret = min(ret, dp[n][j]);
//    cout << ret << endl;
//    return 0;
//}