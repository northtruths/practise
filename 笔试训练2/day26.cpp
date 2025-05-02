#define _CRT_SECURE_NO_WARNINGS


//小红的ABC
//#include<iostream>
//#include<string>
//#include<climits>
//using namespace std;
//
//int main() {
//    string s;
//    cin >> s;
//    int ret = -1;
//    for (int i = 0; i < s.size(); ++i) {
//        if (i - 1 >= 0 && i + 1 < s.size() && s[i - 1] == s[i + 1]) {
//            ret = ret == -1 ? 3 : min(ret, 3);
//        }
//        if (i + 1 < s.size() && s[i] == s[i + 1]) {
//            ret = 2;
//            break;
//        }
//    }
//    cout << ret << endl;
//    return 0;
//}


//不相邻取数
//#include<iostream>
//#include<vector>
//using namespace std;
//
//int main() {
//    //dp[i]为数组0~i能取到的最大值
//    int n = 0;
//    cin >> n;
//    vector<int> nums(n);
//    for (int i = 0; i < n; ++i) {
//        cin >> nums[i];
//    }
//    if (n == 1) {
//        cout << nums[0] << endl;
//        return 0;
//    }
//    vector<int> dp(n);
//    dp[0] = nums[0];
//    dp[1] = max(nums[1], nums[0]);
//    for (int i = 2; i < n; ++i) {
//        dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
//    }
//    cout << dp[n - 1] << endl;
//    return 0;
//}



//空调遥控（未ac，但时间复杂度过高，忽略了给更新hash表的时间，复杂度超大，时间晚了明天再看）
//#include <iostream>
//#include<vector>
//#include<unordered_map>
//using namespace std;
//
//int main() {
//    //每个队员都有一个能进入状态的区间，求出所有队员区间的最大重合数就是答案
//    int n, p;
//    cin >> n >> p;
//    int ret = 0;
//    unordered_map<int, int> hash;
//    for (int i = 0; i < n; ++i) {
//        int temp = 0;
//        cin >> temp;
//        for (int k = temp - p; k <= p + temp; ++k) {
//            ret = max(ret, ++hash[k]);
//        }
//    }
//    cout << ret << endl;
//    return 0;
//}


//空调遥控（看题解后ac，排序+二分）
//#include <iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//int FindMin(vector<int>& nums, int min);//寻找当前区间头下标
//int FindMax(vector<int>& nums, int max);//寻找当前区间尾下标
//
//int main() {
//    //对于每一温度，寻找有多少队员能进入状态
//    //对于寻找队员，可以先排序，再用二分找到能接受温度的队员的最大最小，两边之差即为答案
//    int n, p;
//    cin >> n >> p;
//    vector<int> nums(n);
//    for (int i = 0; i < n; ++i)
//        cin >> nums[i];
//    sort(nums.begin(), nums.end());
//    int ret = 0;
//    for (int i = nums[0]; i <= nums[nums.size() - 1]; ++i) {
//        int min_cur = i - p, max_cur = i + p;
//        int min_i = 0, max_i = 0;
//        min_i = FindMin(nums, min_cur);
//        max_i = FindMax(nums, max_cur);
//        ret = max(ret, max_i - min_i + 1);
//    }
//    cout << ret << endl;
//    return 0;
//}
//
//int FindMin(vector<int>& nums, int min) {
//    int min_i = 0;
//    int left = 0, right = nums.size() - 1;
//    while (left < right) {
//        int mid = (left + right) >> 1;
//        if (nums[mid] == min) {//找到了直接返回
//            while (mid - 1 >= 0 && nums[mid - 1] == min)
//                mid = mid - 1;
//            min_i = mid;
//            return min_i;
//        }
//        if (nums[mid] > min)
//            right = mid - 1;
//        else
//            left = mid + 1;
//    }
//    min_i = left;//小于的不能算进去，大于的得算进去
//    return min_i;
//}
//
//int FindMax(vector<int>& nums, int max) {
//    int max_i = 0;
//    int left = 0, right = nums.size() - 1;
//    while (left < right) {
//        int mid = (left + right) >> 1;
//        if (nums[mid] == max) {//找到了直接返回
//            while (mid + 1 < nums.size() && nums[mid + 1] == max)
//                mid = mid + 1;
//            max_i = mid;
//            return max_i;
//        }
//        if (nums[mid] > max)
//            right = mid - 1;
//        else
//            left = mid + 1;
//    }
//
//    if (left == right && nums[left] == max) {
//        while (left + 1 < nums.size() && nums[left + 1] == max)
//            left = left + 1;
//        max_i = left;
//    }
//    max_i = right;//大于的不能算进去，小于的得算进去
//    return max_i;
//}


//空调遥控（解法二， 滑动窗口。多多利用数学逻辑）
//#include <iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//int main() {
//    //通过题目式子可得：k - p <= a[i] <= k + p，当k和p固定时，a[i]最大为k+p，最小为k-p
//    //所以当a[i]的范围在k+p - k-p（2p）之内，必有一个k满足这范围内的队员
//    //滑动窗口，条件为a[i]头尾的差值小于等于2p
//    int n, p;
//    cin >> n >> p;
//    vector<int> nums(n);
//    for (int i = 0; i < n; ++i)
//        cin >> nums[i];
//    sort(nums.begin(), nums.end());
//    int ret = 0;
//    int left = 0, right = 0;//窗口两边
//    while (right < nums.size()) {
//        while (right < nums.size() && nums[right] - nums[left] <= 2 * p)
//            ++right;
//        ret = max(ret, right - left);
//        ++left;
//    }
//    cout << ret << endl;
//    return 0;
//}