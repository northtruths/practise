#define _CRT_SECURE_NO_WARNINGS



//���ε�����ż����ģ�⣩
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




//��ٶ��Σ�������ac��һ���ܼ򵥵ı����⣬��Ϊ״̬���ðɣ�֪���ñ������Դ����ҵ��벻��һ��ϸ�ڣ��Ժ��ǵö໭ͼ������˼·����Ҫ��
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
//            if (hash[a[i]] == true)//�����������Ѿ��Ž�ȥ�ˣ�˵������������������
//                continue;
//            hash[i] = true;
//            dfs(a, hash, count + 1);
//            hash[i] = false;
//        }
//    }
//}
//
//int main() {
//    //�����������������������ע���ϸ��
//    cin >> n;
//    vector<int> a(n + 1);
//    vector<bool> hash(n + 1);
//    for (int i = 1; i <= n; ++i)
//        cin >> a[i];
//    dfs(a, hash, 0);
//    cout << ret << endl;
//    return 0;
//}





//�������е����·���ͣ���������ac����ʵҲ��򵥣���������dp���⼸��û������Ȼ���Դ�Ҳ�е������֮�����侲��ͼ����Ϊ���ϲߣ�
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
//     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
//     *
//     *
//     * @param root TreeNode��
//     * @return int����
//     */
//    int ret = INT_MIN;
//    int maxPathSum(TreeNode* root) {
//        //����dp����ͨ�����������ڵ������ͨ�����������ڵ�����·���ͣ����������·���;�Ϊ����ң���С��0ʱ��ȥ
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