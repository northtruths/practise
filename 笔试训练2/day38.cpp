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



//小红取数（未ac，暴力超时）
//#include <iostream>
//#include<vector>
//using namespace std;
//
//long long n = 0, k = 0;
//long long ret = 0;
//
//void Dfs(vector<long long>& nums, int i = 0, long long sum = 0) {
//    if (sum % k == 0)
//        ret = max(ret, sum);
//    for (i; i < n; ++i) {
//        Dfs(nums, i + 1, sum + nums[i]);
//    }
//}
//
//int main() {
//    //1.因为数据范围为1e3，大概能支持O(n^2)的复杂度，所以dfs暴力
//    cin >> n >> k;
//    vector<long long> nums(n);
//    for (int i = 0; i < n; ++i)
//        cin >> nums[i];
//    Dfs(nums);
//    if (ret)
//        cout << ret << endl;
//    else
//        cout << -1 << endl;
//    return 0;
//}