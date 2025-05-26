#define _CRT_SECURE_NO_WARNINGS













//ruby和薯条
//#include <iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//int main() {
//    //贪心+双指针
//    //一个指针指向当前最小长度，一个指针指向刚好大于等于l的位置，一个指针指向刚好小于等于r的位置的下一个位置
//    //第一个指针每次向右走一个(最小长度变大)，第二个指针寻找满足条件的下一个位置(可以是原地)，第三个位置同理
//    //第二个指针和第三个指针之间的元素就是本次的“最萌身高差”，时间复杂度为 nlog(n)+3n = nlog(n)
//    int n, l, r;
//    cin >> n >> l >> r;
//    vector<int> nums(n);
//    for (int i = 0; i < n; ++i)
//        cin >> nums[i];
//    sort(nums.begin(), nums.end());
//
//    int left = 0, right = 0;
//    long long ret = 0;
//    for (int i = 0; i < n; ++i) {
//        while (left < n && nums[left] - nums[i] < l)
//            ++left;
//        while (right < n && nums[right] - nums[i] <= r)
//            ++right;
//        if (left >= n)//left是条件成立的开始，它走完就完了
//            break;
//        ret += right - left;
//    }
//    cout << ret << endl;
//    return 0;
//}




//循环汉诺塔
//#include <iostream>
//#include<vector>
//using namespace std;
//
//int main() {
//    //动态规划
//    //dp1[i]为i个金片移向下一个柱子需要的最少操作，dp2[i]为i个金片移向下两个柱子需要的最少操作
//    //A->B（dp1[i]）:上面全到C（dp2[i-1]），最下面到B(1)，上面全到C再到B（dp2[i-1]）
//    //A->C（dp2[i]）：上面全到C（dp2[i-1]），最下面到B（1），C到A（dp1[i-1]），B到C（1），A到C（dp2[i-1]）
//    int n;
//    cin >> n;
//    vector<long long> dp1(n + 1);
//    vector<long long> dp2(n + 1);
//    dp1[0] = dp2[0] = 0;
//    for (int i = 1; i <= n; ++i) {
//        dp1[i] = (dp2[i - 1] + 1 + dp2[i - 1]) % 1000000007;
//        dp2[i] = (dp2[i - 1] + 1 + dp1[i - 1] + 1 + dp2[i - 1]) % 1000000007;
//    }
//    cout << dp1[n] << " " << dp2[n] << endl;
//    return 0;
//}