#define _CRT_SECURE_NO_WARNINGS


//天使果冻（脑袋不清晰，有个逻辑问题找了半天才发现在哪，记住先整体梳理逻辑，在细致找每个易出问题的地方）
//#include <iostream>
//#include<vector>
//using namespace std;
//
//int main() {
//    //动态规划，两个dp记录0~i的最大美味度和第二大美味度
//    //若i的位置美味度大于等于前面的最大美味度则更新两个dp，次大->之前最大，之前最大->当前
//    //否则若i的位置美味度大于次大美味度则更新次大美味度，次大->当前
//    int n;
//    cin >> n;
//    vector<int> nums(n);
//    cin >> nums[0];//提前输入，以便等会输入数组时顺便就把dp整出来
//    vector<int> first(n);
//    vector<int> second(n);
//    for (int i = 1; i < n; ++i) {
//        cin >> nums[i];
//        if (i == 1) {
//            first[1] = max(nums[0], nums[1]);
//            second[1] = min(nums[0], nums[1]);
//        }
//        else {
//            if (nums[i] >= first[i - 1]) {
//                second[i] = first[i - 1];
//                first[i] = nums[i];
//            }
//            else if (nums[i] > second[i - 1]) {
//                first[i] = first[i - 1];
//                second[i] = nums[i];
//            }
//            else {
//                first[i] = first[i - 1];
//                second[i] = second[i - 1];
//            }
//        }
//    }
//    int q;
//    cin >> q;
//    while (q--) {
//        int x;
//        cin >> x;
//        cout << second[x - 1] << endl;
//    }
//    return 0;
//}




//dd爱旋转
//#include <iostream>
//#include<vector>
//using namespace std;
//
////关于行镜像
//void row_mirror(vector<vector<int>>& matrix) {
//    int left = 0, right = 0;
//    if (matrix.size() % 2 == 1) {
//        left = matrix.size() / 2 - 1;
//        right = left + 2;
//    }
//    else {
//        right = matrix.size() / 2;
//        left = right - 1;
//    }
//    while (0 <= left) {
//        swap(matrix[left], matrix[right]);
//        --left; ++right;
//    }
//}
//
////关于列镜像
//void col_mirror(vector<vector<int>>& matrix) {
//    int left = 0, right = 0;
//    if (matrix.size() % 2 == 1) {
//        left = matrix.size() / 2 - 1;
//        right = left + 2;
//    }
//    else {
//        right = matrix.size() / 2;
//        left = right - 1;
//    }
//    //列镜像较麻烦，得一个一个交换
//    for (int i = 0; i < matrix.size(); ++i) {
//        int temp_left = left, temp_right = right;
//        while (0 <= temp_left) {
//            swap(matrix[i][temp_left], matrix[i][temp_right]);
//            --temp_left; ++temp_right;
//        }
//    }
//}
//
//int main() {
//    //模拟根据规律可知：顺时针旋转180°就是 行镜像+列镜像
//    //每有两次同方向镜像就等于没变，所以所有情况可简化为最多1次行镜像和列镜像
//    int n = 0;
//    cin >> n;
//    vector<vector<int>> matrix(n, vector<int>(n));
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < n; ++j)
//            cin >> matrix[i][j];
//    }
//    int row = 0, col = 0;//row为行操作, col为列操作
//    int q = 0;
//    cin >> q;
//    while (q--) {
//        int cur = 0;
//        cin >> cur;
//        if (cur == 1) {
//            //将1操作分解为行列
//            ++row;
//            ++col;
//        }
//        else ++row;
//    }
//    row %= 2;
//    col %= 2;
//    if (row) row_mirror(matrix);
//    if (col) col_mirror(matrix);
//    for (auto& i : matrix) {
//        for (auto& j : i)
//            cout << j << ' ';
//        cout << endl;
//    }
//    return 0;
//}



//小红取数（未ac，暴力超时，很久之后把它做出来了，期间被它难得放弃学习了一段时间，题解也不完全能看懂，
// 最后同着之前的题解理解加上模拟，靠着模拟做出来了，还是没有完全理解同余定理，）
//#include <iostream>
//#include<vector>
//using namespace std;
//
//int main() {
//    //01背包+同余定理
//    //dp[i][j]为从前i个挑选，总和%k为j时的最大和
//    //取所有j=0的情况最大值就为结果
//    long long n, k;
//    cin >> n >> k;
//    vector<long long> nums(n);
//    for (long long i = 0; i < n; ++i)
//        cin >> nums[i];
//    vector<vector<long long>> dp(n, vector<long long>(k, -1));
//    dp[0][nums[0] % k] = nums[0];
//    for (long long i = 1; i < n; ++i) {
//        dp[i][nums[i] % k] = max(dp[i][nums[i] % k], nums[i]);
//        for (long long j = k - 1; j >= 0; --j) {
//            dp[i][j] = max(dp[i - 1][j], dp[i][j]);
//            if (dp[i - 1][j] != -1) {//必须要前面的和存在
//                long long a = nums[i] % k;
//                long long b = (a + j) % k;
//                dp[i][b] = max(dp[i - 1][b], dp[i - 1][j] + nums[i]);
//            }
//
//        }
//    }
//    long long ret = -1;
//    for (auto& e : dp) {
//        ret = max(ret, e[0]);
//    }
//    if (ret == 0)
//        ret = -1;
//    cout << ret << endl;
//    return 0;
//}