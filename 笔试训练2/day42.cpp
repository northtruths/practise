#define _CRT_SECURE_NO_WARNINGS


//����ֵ
//#include <climits>
//class Solution {
//public:
//    /**
//     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
//     *
//     *
//     * @param A int����vector
//     * @param n int����
//     * @return int����
//     */
//    int getDis(vector<int>& A, int n) {
//        //��̬�滮
//        //�ü�¼��ǰ��֮ǰ����Сֵ��dp[i] = max(dp[i - 1], ��ǰֵ����Сֵ)
//        //���������Ż�
//		  //����ʵ��̰��˼��
//        long long ret = 0;
//        long long pre_min = A[0];//ǰ�����Сֵ
//        for (int i = 1; i < n; ++i) {
//            ret = max(ret, A[i] - pre_min);
//            pre_min = min(pre_min, (long long)A[i]);
//        }
//        return ret;
//    }
//};




//�һ���Ǯ
//#include <iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//int main() {
//    //��ȫ����
//    //dp[i][j]Ϊֻ��ǰi����ֵ����Ϊj����С��ֵ
//    //dp[i][j] = min(dp[i][j], dp[i - 1][j - money[i]] + 1)
//    //i��һάʡ��
//    int n, aim;
//    cin >> n >> aim;
//    vector<int> money(n);
//    for (int i = 0; i < n; ++i)
//        cin >> money[i];
//    sort(money.begin(), money.end());//����֤����Ļ��ұ�ǰ����ֵ�󣬼���������ǰ��Ĵ�
//    vector<int> dp(aim + 1, 0x3f3f3f3f);
//    dp[0] = 0;
//    for (int i = 0; i < n; ++i) {
//        for (int j = 1; j <= aim; ++j) {
//            if (j - money[i] >= 0) {
//                dp[j] = min(dp[j], dp[j - money[i]] + 1);
//            }
//        }
//    }
//    if (dp[aim] == 0x3f3f3f3f)
//        cout << -1 << endl;
//    else
//        cout << dp[aim] << endl;
//    return 0;
//}




С����Ӵ���δac�����ᣩ