#define _CRT_SECURE_NO_WARNINGS


//排序子序列
//#include <iostream>
//#include<vector>
//using namespace std;
//
//int main() {
//    int n;
//    cin >> n;
//    vector<int> arr(n);
//    for (int i = 0; i < n; ++i)
//        cin >> arr[i];
//    int mod = 0;//1表示当前为升序，2降,0不确定
//    int ret = 0;
//    for (int i = 1; i < n; ++i) {
//        while (i < n && arr[i] == arr[i - 1])
//            ++i;
//        if (i >= n)
//            break;
//        if (mod == 0) {
//            if (arr[i] > arr[i - 1])
//                mod = 1;
//            else
//                mod = 2;
//            ++ret;
//        }
//        else if (mod == 1 && arr[i] < arr[i - 1])
//            mod = 0;
//        else if (mod == 2 && arr[i] > arr[i - 1])
//            mod = 0;
//    }
//    if (mod == 0)
//        ++ret;
//    cout << ret << endl;
//    return 0;
//}



//消减整数
//#include<iostream>
//#include<cmath>
//using namespace std;
//
//int MinTimes(int h) {
//    int n = 0;
//    int sub = 0;
//    while (sub + pow(2, n) <= h) {
//        sub += pow(2, n);
//        ++n;
//    }
//    --n;
//    int ret = n + 1;
//    h -= sub;
//    for (n; n >= 0 && h > 0; --n) {
//        sub = pow(2, n);
//        if (h >= sub) {
//            h -= sub;
//            ++ret;
//        }
//    }
//    return ret;
//}
//
//int main() {
//    //贪心：每次先找2^0、2^1、...、2^n的和，使其刚好小于h并且加上2^(n+1)就会大于h
//    //因为能使用更大的就用更大的，两个较小的始终能被一个较大的替换
//    //之后从2^n到2^0，h还大于就减去
//    int t = 0;
//    cin >> t;
//    while (t--) {
//        int h = 0;
//        cin >> h;
//        cout << MinTimes(h) << endl;
//    }
//    return 0;
//}



//最长上升子序列（二）（看题解后ac，已经做过的题，因为是进行优化，便做不来了，做题不仅画图分析，还要结合用例用实例逐步模拟分析）
//class Solution {
//public:
//    /**
//     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
//     *
//     * 该数组最长严格上升子序列的长度
//     * @param a int整型vector 给定的数组
//     * @return int整型
//     */
//    int LIS(vector<int>& a) {
//        //贪心+二分
//        //画图分析，对于前面相同的序列，现在有多个能接上的元素，当然是接最小的最好
//        //一个数组记录长度为i的情况下，末尾的最大值
//        //若当前元素大于数组所有元素，数组新增，否则找到第一个大于等于当前元素的位置，进行替换
//        int n = a.size();
//        if (n == 0)  return 0;
//        vector<int> dp;
//        dp.push_back(a[0]);
//        for (int i = 0; i < n; ++i) {
//            if (a[i] > dp[dp.size() - 1]) {
//                dp.push_back(a[i]);
//                continue;
//            }
//            int left = 0, right = dp.size() - 1;
//            while (left <= right) {
//                int mid = (left + right) >> 1;
//                if (dp[mid] == a[i])//有这个值就直接替换（不操作）
//                    break;
//                else if (dp[mid] > a[i]) right = mid - 1;
//                else left = mid + 1;
//            }
//            if (left > right) {//此时数组中没有以a[i]为结尾的序列，可以进行替换，替换位置为left
//                dp[left] = a[i];
//            }
//        }
//        return dp.size();
//    }
//};