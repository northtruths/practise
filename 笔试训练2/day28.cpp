#define _CRT_SECURE_NO_WARNINGS



//游游的重组偶数（模拟）
//#include<iostream>
//#include <ostream>
//#include<vector>
//using namespace std;
//
//int main() {
//    int q = 0;
//    cin >> q;
//    while (q--) {
//        int cur = 0;
//        cin >> cur;
//        if ((cur & 1) == 0) {
//            cout << cur << endl;
//            continue;
//        }
//        vector<int> temp;
//        while (cur) {
//            int a = cur % 10;
//            temp.push_back(a);
//            cur /= 10;
//        }
//        int i = 1;
//        for (i; i < temp.size(); ++i) {
//            if ((temp[i] & 1) == 0)
//                break;
//        }
//        if (i >= temp.size())
//            cout << -1 << endl;
//        else {
//            temp[0] = temp[0] ^ temp[i];
//            temp[i] = temp[0] ^ temp[i];
//            temp[0] = temp[0] ^ temp[i];
//            for (i = temp.size() - 1; i >= 0; --i)
//                cout << temp[i];
//            cout << endl;
//        }
//    }
//    return 0;
//}




//体操队形（看题解后ac，一道很简单的暴力题，因为状态不好吧，知道得暴力但脑袋混乱得想不出一点细节，以后还是得多画图，理清思路很重要）
//#include<iostream>
//#include <vector>
//using namespace std;
//
//int n;
//int ret;
//void dfs(vector<int>& a, vector<bool>& hash, int count) {
//    if (count == a.size() - 1) {
//        ++ret;
//        return;
//    }
//    for (int i = 1; i <= n; ++i) {
//        if (hash[i] == false) {
//            if (hash[a[i]] == true)//如果诉求的人已经排进去了，说明不符合条件，跳过
//                continue;
//            hash[i] = true;
//            dfs(a, hash, count + 1);
//            hash[i] = false;
//        }
//    }
//}
//
//int main() {
//    //画决策树，分析情况和所需注意的细节
//    cin >> n;
//    vector<int> a(n + 1);
//    vector<bool> hash(n + 1);
//    for (int i = 1; i <= n; ++i)
//        cin >> a[i];
//    dfs(a, hash, 0);
//    cout << ret << endl;
//    return 0;
//}





//二叉树中的最大路径和（看完题解后ac，其实也算简单，不过树形dp的题几乎没做过，然后脑袋也有点糊，总之还是冷静画图分析为上上策）
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
//     * @param root TreeNode类
//     * @return int整型
//     */
//    int ret = INT_MIN;
//    int maxPathSum(TreeNode* root) {
//        //树形dp？找通过左子树根节点的最大和通过右子树根节点的最大路径和，根树的最大路径和就为左加右，但小于0时舍去
//        FindMax(root);
//        return ret;
//    }
//
//    int FindMax(TreeNode* root) {
//        if (root == nullptr)
//            return 0;
//        int left = FindMax(root->left);
//        int right = FindMax(root->right);
//        int cur = root->val + max(0, left) + max(0, right);
//        ret = max(ret, cur);
//        return max(0, max(left, right)) + root->val;
//    }
//};