#define _CRT_SECURE_NO_WARNINGS


////�ж��ǲ���ƽ�������
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
//     * @param pRoot TreeNode��
//     * @return bool������
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


//�����˵��ǰ׺�ͺ�ac���������������⣬������Ϊ���Ӷ�ΪO(n^4)���㿴��n<=100,�Ĵη���Ҳ���࣬��������Ϊ�Ǳ����ⷨ��Ϊ�����ܸ��ñ�û����
// �����Ժ���û��������Ž⣬�ܱ������ǵñ�������֮������һ��
//����Ӿ���
//#include <iostream>
//#include<vector>
//#include<climits>
//using namespace std;
//
//int main() {
//    //ǰ׺�ͣ�����Ѱ��
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
//                    //(i, j)��(x, y)�ľ����С
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





//С�е�01��
//#include <iostream>
//#include<string>
//using namespace std;
//
//int main() {
//    //�������ڣ�����Ϊ01��һ��ĺ�,�������е�01�����������ڸ����ܵ�һ��ʱ��������
//    //�����Ϊ2n�������ǰ����ͬ
//    int n = 0;
//    cin >> n;
//    string s;
//    cin >> s;
//    int zero = 0, one = 0;//01������
//    for (auto& e : s) {
//        if (e == '1')
//            ++one;
//        else
//            ++zero;
//    }
//    s += s;
//    int len = (zero + one) / 2;//���ڳ���
//    int front = 0;//����ǰ��
//    int cur_0 = 0;//��ǰ0�ĸ���
//    int cur_1 = 0;//��ǰ1�ĸ���
//    int ret = 0;
//    for (int i = 0; i < n + len - 1; ++i) {//��֤����������һ��ǰn���е��ַ�����Ȼ���ظ�
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