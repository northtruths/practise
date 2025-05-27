#define _CRT_SECURE_NO_WARNINGS



//kotori和抽卡（二）（直接找到计算组合的代码ac，知道怎么做但想不出怎么计算排列组合了，运动后太累了，直接用它的代码明天再思考）
//#include<iostream>
//#include<vector>
//#include<cmath>
//using namespace std;
//unsigned long long combination(int n, int k) {
//    if (k < 0 || k > n) return 0;
//    if (k == 0 || k == n) return 1;
//    if (k > n - k) k = n - k; // 优化计算，利用 C(n, k) = C(n, n-k)
//
//    unsigned long long res = 1;
//    for (int i = 1; i <= k; ++i) {
//        res *= (n - k + i);
//        res /= i;
//    }
//    return res;
//}
//int main() {
//    //经模拟后得出问题本质为：从n个概率中选m个0.8，其他均为0.2，选法乘以m个0.8和(n-m)个0.2即为总概率
//    int n, m;
//    cin >> n >> m;
//
//    unsigned long long a = combination(n, m);
//    long double b = pow(0.8, m);
//    long double c = pow(0.2, n - m);
//    printf("%.4Lf\n", a * b * c);
//    return 0;
//}




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




