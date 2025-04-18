#define _CRT_SECURE_NO_WARNINGS


////判断是不是平衡二叉树
///**
// * struct TreeNode {
// *	int val;
// *	struct TreeNode *left;
// *	struct TreeNode *right;
// *	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// * };
// */
//class Solution {
//public:
//    /**
//     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
//     *
//     *
//     * @param pRoot TreeNode类
//     * @return bool布尔型
//     */
//    bool IsBalanced_Solution(TreeNode* pRoot) {
//        int ret = true;
//        H(pRoot, ret);
//        return ret;
//    }
//
//    int H(TreeNode* root, int& ret) {
//        if (ret == false)
//            return 0;
//        if (root == nullptr)
//            return 0;
//        int left = H(root->left, ret);
//        int right = H(root->right, ret);
//        if (abs(left - right) > 1)
//            ret = false;
//        return max(left, right) + 1;
//    }
//};


//看题解说是前缀和后ac，想出了这样的题解，不过因为复杂度为O(n^4)即便看见n<=100,四次方后也不多，但还是因为是暴力解法认为题解可能更好便没有做
// 所以以后，若没想出来最优解，能暴力还是得暴力，总之得先试一下
//最大子矩阵
//#include <iostream>
//#include<vector>
//#include<climits>
//using namespace std;
//
//int main() {
//    //前缀和，暴力寻找
//    int n = 0;
//    cin >> n;
//    vector<vector<int>> nums(n, vector<int>(n));
//    for (int i = 0; i < n; ++i)
//        for (int j = 0; j < n; ++j)
//            cin >> nums[i][j];
//
//    vector<vector<int>> prifix(n, vector<int>(n));
//    prifix[0][0] = nums[0][0];
//    for (int i = 1; i < n; ++i)
//        prifix[i][0] = prifix[i - 1][0] + nums[i][0];
//    for (int j = 1; j < n; ++j)
//        prifix[0][j] = prifix[0][j - 1] + nums[0][j];
//    for (int i = 1; i < n; ++i) {
//        for (int j = 1; j < n; ++j) {
//            prifix[i][j] = prifix[i - 1][j] + prifix[i][j - 1] - prifix[i - 1][j - 1] + nums[i][j];
//        }
//    }
//
//    int ret = INT_MIN;
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < n; ++j) {
//            for (int x = i; x < n; ++x) {
//                for (int y = j; y < n; ++y) {
//                    //(i, j)到(x, y)的矩阵大小
//                    int a = prifix[x][y];
//                    int b = i - 1 >= 0 ? prifix[i - 1][y] : 0;
//                    int c = j - 1 >= 0 ? prifix[x][j - 1] : 0;
//                    int d = (i - 1 >= 0 && j - 1 >= 0) ? prifix[i - 1][j - 1] : 0;
//                    int cur = a - b - c + d;
//                    ret = max(ret, cur);
//                }
//            }
//        }
//    }
//
//    cout << ret << endl;
//    return 0;
//}
//4
//0 - 2 - 7 0
//9 2 - 6 2
//- 4 1 - 4  1
//- 1 8  0 - 2





//小葱的01串
//#include <iostream>
//#include<string>
//using namespace std;
//
//int main() {
//    //滑动窗口，长度为01各一半的和,当窗口中的01各自数量等于各自总的一半时满足条件
//    //数组变为2n，后面和前面相同
//    int n = 0;
//    cin >> n;
//    string s;
//    cin >> s;
//    int zero = 0, one = 0;//01的数量
//    for (auto& e : s) {
//        if (e == '1')
//            ++one;
//        else
//            ++zero;
//    }
//    s += s;
//    int len = (zero + one) / 2;//窗口长度
//    int front = 0;//窗口前端
//    int cur_0 = 0;//当前0的个数
//    int cur_1 = 0;//当前1的个数
//    int ret = 0;
//    for (int i = 0; i < n + len - 1; ++i) {//保证窗口至少有一个前n个中的字符，不然会重复
//        if (s[i] == '0') ++cur_0;
//        else ++cur_1;
//        if (cur_0 + cur_1 > len) {
//            if (s[front] == '0') --cur_0;
//            else --cur_1;
//            ++front;
//        }
//        if (cur_0 + cur_1 == len) {
//            if (cur_0 == zero / 2 && cur_1 == one / 2)
//                ++ret;
//        }
//    }
//    cout << ret << endl;
//    return 0;
//}