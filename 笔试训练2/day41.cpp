#define _CRT_SECURE_NO_WARNINGS


//���ӷ�ת
//class Solution {
//public:
//    /**
//     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
//     *
//     *
//     * @param A int����vector<vector<>>
//     * @param f int����vector<vector<>>
//     * @return int����vector<vector<>>
//     */
//    vector<vector<int> > flipChess(vector<vector<int> >& A, vector<vector<int> >& f) {
//        //ģ��
//        int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
//        for (auto& ab : f) {
//            int a = ab[0] - 1, b = ab[1] - 1;
//            for (auto& e : dir) {
//                int x = a + e[0];
//                int y = b + e[1];
//                if (0 <= x && x < A.size() && 0 <= y && y < A[0].size())
//                    A[x][y] ^= 1;
//            }
//        }
//        return A;
//    }
//};




//����������
//#include <iostream>
//#include<vector>
//using namespace std;
//
//int main() {
//    //��̬�滮
//    //dp[i]Ϊ0~i�����ʳ��
//    //dp[i] = max(dp[i - 1], dp[i - 3] + a[i - 1])����Ϊ��ȡ����3��Ԫ�ص��м䣬����ѡ��ȡiʵ������ѡ��ȡi-1����i��i-2
//    int n = 0;
//    cin >> n;
//    vector<long long> nums(n);
//    for (int i = 0; i < n; ++i)
//        cin >> nums[i];
//    vector<long long> dp(n);
//    dp[0] = 0;
//    dp[1] = 0;
//    dp[2] = nums[1];
//    for (int i = 3; i < n; ++i) {
//        dp[i] = max(dp[i - 1], dp[i - 3] + nums[i - 1]);
//    }
//    cout << dp[n - 1] << endl;
//    return 0;
//}





//���ţ�δac��75%�� ��ʱ��
//#include <iostream>
//#include<vector>
//using namespace std;
//
//long long Dfs(vector<int>& nums, vector<long long>& ret, int i, vector<bool>& hash);
//int n = 0;
//int main() {
//    //���仯����
//    //һ����ϣ�����¼���������ϵ��յ�����ʱ��
//    cin >> n;
//    vector<int> nums(n + 1);
//    for (int i = 1; i <= n; ++i)
//        cin >> nums[i];
//    vector<long long> ret(n + 1, 0x3f3f3f3f);
//    vector<bool> hash(n + 1);
//    ret[n] = 0;
//    Dfs(nums, ret, 1, hash);
//    if (hash[n] == 0x3f3f3f3f)
//        cout << -1 << endl;
//    else
//        cout << ret[1] << endl;
//    return 0;
//}
//
////DfsΪ�ӵ�i������ϵ��յ�����ʱ��
//long long Dfs(vector<int>& nums, vector<long long>& ret, int i, vector<bool>& hash) {
//    //curΪ��ǰʱ�䣬iΪ��ǰ���ӱ��
//    if (ret[i] != 0x3f3f3f3f) {//ret[n]�ѳ�ʼ��0������ i == n �����
//        return ret[i];
//    }
//    hash[i] = true;
//    if (nums[i] > 0) {
//        for (int j = i + 1; j <= i + nums[i]; ++j) {
//            if (j <= n && hash[j] == false)
//                ret[i] = min(ret[i], Dfs(nums, ret, j, hash) + 1);
//        }
//    }
//    else if (nums[i] < 0) {
//        for (int j = i - 1; j >= i + nums[i]; --j) {
//            if (j > 1 && hash[j] == false)
//                ret[i] = min(ret[i], Dfs(nums, ret, j, hash) + 1);
//            else
//                ret[i] = min(ret[i], ret[1]);
//        }
//    }
//    hash[i] = false;
//    return ret[i];
//}