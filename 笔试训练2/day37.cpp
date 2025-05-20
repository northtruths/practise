#define _CRT_SECURE_NO_WARNINGS



//��ת�ַ�������Ϊ������Ϊ��Ѱ��A����ת�Ӵ���ʵ����һ�������ַ��������˵�ʱ�䣬��������������ŷ��֣�
//����Ҫ��������
//class Solution {
//public:
//    /**
//     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
//     *
//     * ��ת�ַ���
//     * @param A string�ַ���
//     * @param B string�ַ���
//     * @return bool������
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


//�ϲ�k�������������
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
//     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
//     *
//     *
//     * @param lists ListNode��vector
//     * @return ListNode��
//     */
//    ListNode* mergeKLists(vector<ListNode*>& lists) {
//        //����
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





////��ѩ����Ϊ����ԭ����Ŀ�����˺ܶ࣬��ΪҪ��·������ӡ���������������ŷ��ֲ���Ҫ������Ҫ�������⣡ͬһ�������ͬ���Ĵ���
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
//    //dfs+��֦�����仯������
//    //dp[i][j]��ʾ��λ��(i, j)λ�ÿ�ʼ�����·
//    //dp[i][j]�鿴�����Ƿ���С�ڵ�ǰ������ֱ�ӽ��ϵģ��ܾ�ֱ�ӽ���
//    cin >> n >> m;
//    vector<vector<int>> grid(n, vector<int>(m));
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < m; ++j) {
//            cin >> grid[i][j];
//        }
//    }
//    vector<vector<int>> dp(n, vector<int>(m, -1));//-1��ʾδ����    
//    int ret = 0;
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < m; ++j) {
//            ret = max(ret, Dfs(grid, dp, i, j));
//        }
//    }
//    cout << ret << endl;
//    return 0;
//}

