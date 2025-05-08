#define _CRT_SECURE_NO_WARNINGS


//素数回文
//#include<iostream>
//#include<vector>
//#include<cmath>
//#include<algorithm>
//using namespace std;
//
//bool is_prime(long long x) {
//    if (x == 2 || x == 3)    return true;
//    if (x % 2 == 0 || x % 3 == 0)    return false;
//    for (int i = 6; i + 1 <= sqrt(x); i += 6) {
//        if (x % (i - 1) == 0 || x % (i + 1) == 0)
//            return false;
//    }
//    return true;
//}
//int main() {
//    //模拟
//    long long t;
//    cin >> t;
//    vector<long long > temp;
//    while (t) {
//        temp.push_back(t % 10);
//        t /= 10;
//    }
//    reverse(temp.begin(), temp.end());
//    for (int i = temp.size() - 2; i >= 0; --i) {
//        temp.push_back(temp[i]);
//    }
//    long long x = 0;
//    for (int i = 0; i < temp.size(); ++i) {
//        x += pow(10, temp.size() - 1 - i) * temp[i];
//    }
//    if (is_prime(x))
//        cout << "prime" << endl;
//    else
//        cout << "noprime" << endl;
//    return 0;
//}


//活动安排
//#include <iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//int main() {
//    //贪心+排序+二分
//    //记录选择n个活动的最佳末尾时间，每次寻找之前的记录，若开始时间大于记录(结束时间)，并且结束时间小于它下一个记录，
//    //则将更大的记录更新未当前小的这个
//    //原理：因为排序后开始时间是升序的，当前活动的开始时间必定大于等于之前的，
//    //只要当前活动能接上之前的，那么结束时间越小越好，然后能接到最后就接，不能再考虑是否能更新，最后记录的个数即为答案
//    int n;
//    cin >> n;
//    vector<vector<int>> record(n, vector<int>(2));
//    for (int i = 0; i < n; ++i) {
//        int a, b;
//        cin >> a >> b;
//        record[i][0] = a;
//        record[i][1] = b;
//    }
//    sort(record.begin(), record.end(), [&record](vector<int>& x, vector<int>& y)->bool {return x[0] < y[0]; });
//    vector<int> ret;
//    ret.push_back(record[0][1]);
//    for (int i = 1; i < n; ++i) {
//        if (record[i][0] >= ret[ret.size() - 1]) {
//            ret.push_back(record[i][1]);
//        }
//        else {
//            int left = 0, right = ret.size() - 1;
//            while (left <= right) {
//                int mid = (left + right) >> 1;
//                if (ret[mid] == record[i][0]) {
//                    right = mid;
//                    left = mid + 1;
//                }
//                else if (ret[mid] < record[i][0])
//                    left = mid + 1;
//                else
//                    right = mid - 1;
//            }
//            ret[left] = min(ret[left], record[i][1]);
//        }
//    }
//    cout << ret.size() << endl;
//    return 0;
//}



////合唱团（看题解后ac，大部分思路都到位了，又是差临门一脚，知道若两个最大、最小dp，它们在同一i位置选取的学员k数量不一定相同，得想办法控制，
//// 但因为还是缺乏独立思考，明明将这个需要控制的变量加入dp中，二维dp就解决了）
//#include <iostream>
//#include<vector>
//using namespace std;
//
//int main() {
//    //动态规划，dp1[i][j]为选取第i个、此时选了j个学生的最大乘积，dp2[i]为最小
//    //dp1[i]计算：向前寻找最大d个dp，若学生还不够k个，直接乘，若够了，除去i位置的ai再乘，记录最大
//    //因为负数的存在，dp2存储最小，当前能力者为负数时，若这个最小值为负数，乘起来说不定就是最大了
//    int n;
//    cin >> n;
//    vector<int> nums(n);
//    for (int i = 0; i < n; ++i)
//        cin >> nums[i];
//    int k, d;
//    cin >> k >> d;
//    vector<vector<long long>> dp1(n, vector<long long>(k + 1, 1));
//    vector<vector<long long>> dp2(n, vector<long long>(k + 1, 1));
//    long long ret = nums[0];
//    for (int i = 0; i < n; ++i) {
//        dp1[i][1] = dp2[i][1] = nums[i];
//        for (int z = i - 1; z >= max(0, i - d); --z) {
//            for (int j = 1; j <= k; ++j) {
//                if (nums[i] < 0) {
//                    dp1[i][j] = max(dp1[i][j], dp2[z][j - 1] * nums[i]);
//                    dp2[i][j] = min(dp2[i][j], dp1[z][j - 1] * nums[i]);
//                }
//                else {
//                    dp1[i][j] = max(dp1[i][j], dp1[z][j - 1] * nums[i]);
//                    dp2[i][j] = min(dp2[i][j], dp2[z][j - 1] * nums[i]);
//                }
//                ret = max(dp1[i][k], ret);
//            }
//        }
//    }
//    cout << ret << endl;
//    return 0;
//}