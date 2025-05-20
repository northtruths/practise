#define _CRT_SECURE_NO_WARNINGS



//旋转字符串（因为审题以为是寻找A的旋转子串，实则是一个整个字符串，耗了点时间，做完其他题回来才发现）
//所以要认真审题
//class Solution {
//public:
//    /**
//     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
//     *
//     * 旋转字符串
//     * @param A string字符串
//     * @param B string字符串
//     * @return bool布尔型
//     */
//    bool solve(string A, string B) {
//        int n = A.size(), m = B.size();
//        A += A;
//        if (m != n) return false;
//        for (int i = 0; i < n; ++i) {
//            int flag = 0;
//            for (int j = 0; j < m; ++j) {
//                if (A[i + j] != B[j]) {
//                    flag = 1;
//                    break;
//                }
//            }
//            if (flag == 0)
//                return true;
//        }
//        return false;
//    }
//};


//合并k个已排序的链表
///**
// * struct ListNode {
// *	int val;
// *	struct ListNode *next;
// *	ListNode(int x) : val(x), next(nullptr) {}
// * };
// */
//class Solution {
//public:
//    /**
//     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
//     *
//     *
//     * @param lists ListNode类vector
//     * @return ListNode类
//     */
//    ListNode* mergeKLists(vector<ListNode*>& lists) {
//        //排序
//        vector<int> nums;
//        for (int i = 0; i < lists.size(); ++i) {
//            ListNode* cur = lists[i];
//            while (cur) {
//                nums.push_back(cur->val);
//                cur = cur->next;
//            }
//        }
//        sort(nums.begin(), nums.end());
//        ListNode* prev = new ListNode(0);
//        ListNode* ret = prev;
//        for (auto& e : nums) {
//            prev->next = new  ListNode(e);
//            prev = prev->next;
//        }
//        ret = ret->next;
//        return ret;
//    }
//};





////滑雪（因为审题原因将题目复杂了很多，以为要将路径给打印出来，费力半天后才发现不需要，所以要认真审题！同一天出两次同样的错误）
//#include <iostream>
//#include<vector>
//using namespace std;
//
//int n, m;
//int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
//
//int Dfs(vector<vector<int>>& grid, vector<vector<int>>& dp, int i, int j) {
//    if (dp[i][j] != -1) {
//        return dp[i][j];
//    }
//    for (auto& e : dir) {
//        int x = i + e[0];
//        int y = j + e[1];
//        if (0 <= x && x < n && 0 <= y && y < m && grid[x][y] < grid[i][j]) {
//            dp[i][j] = max(dp[i][j], 1 + Dfs(grid, dp, x, y));
//        }
//    }
//    dp[i][j] = max(1, dp[i][j]);
//    return dp[i][j];
//}
//
//int main() {
//    //dfs+剪枝（记忆化搜索）
//    //dp[i][j]表示从位置(i, j)位置开始的最长线路
//    //dp[i][j]查看四周是否有小于当前并且能直接接上的，能就直接接上
//    cin >> n >> m;
//    vector<vector<int>> grid(n, vector<int>(m));
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < m; ++j) {
//            cin >> grid[i][j];
//        }
//    }
//    vector<vector<int>> dp(n, vector<int>(m, -1));//-1表示未来过    
//    int ret = 0;
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < m; ++j) {
//            ret = max(ret, Dfs(grid, dp, i, j));
//        }
//    }
//    cout << ret << endl;
//    return 0;
//}

