#define _CRT_SECURE_NO_WARNINGS



//ѹ���ַ���(һ)
//class Solution {
//public:
//    /**
//     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
//     *
//     *
//     * @param param string�ַ���
//     * @return string�ַ���
//     */
//    string compressString(string param) {
//        if (param.size() == 0)
//            return string();
//        string ret;
//        char cur_ch = param[0];//��ǰ�ַ�
//        ret += cur_ch;
//        int cur_num = 1;//��ǰ�ַ�����
//        for (int i = 1; i < param.size(); ++i) {
//            if (param[i] != cur_ch) {
//                if (cur_num != 1)
//                    ret += to_string(cur_num);
//                cur_ch = param[i];
//                ret += cur_ch;
//                cur_num = 1;
//            }
//            else {
//                ++cur_num;
//            }
//        }
//        if (cur_num != 1)
//            ret += to_string(cur_num);
//        return ret;
//    }
//};




//chika���۸�
//#include <iostream>
//#include<vector>
//#include<utility>
//#include<algorithm>
//using namespace std;
//
//int main() {
//    //����Խ����ǰ����ͬ��Խ���ź���
//    int n, k;
//    cin >> n >> k;
//    vector<pair<int, int>> nums(n);//first����second����
//    for (int i = 0; i < n; ++i)
//        cin >> nums[i].second;
//    for (int i = 0; i < n; ++i)
//        cin >> nums[i].first;
//    sort(nums.begin(), nums.end(), [&nums](auto& x, auto& y)->bool
//        {
//            if (x.first > y.first)
//                return true;
//            else if (x.first == y.second) {
//                return x.second < y.second;
//            }
//            else {
//                return false;
//            }
//        });
//    long long sweet = 0, sour = 0;
//    for (int i = 0; i < k; ++i)
//    {
//        sweet += nums[i].first;
//        sour += nums[i].second;
//    }
//    cout << sour << ' ' << sweet << endl;
//    return 0;
//}



////01����
//#include<iostream>
//#include<vector>
//using namespace std;
//
//class Solution {
//public:
//    /**
//     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
//     *
//     * ����01��������Ľ��
//     * @param V int���� ���������
//     * @param n int���� ��Ʒ�ĸ���
//     * @param vw int����vector<vector<>> ��һά��Ϊn,�ڶ�ά��Ϊ2�Ķ�ά����,vw[i][0],vw[i][1]�ֱ�����i+1����Ʒ��vi,wi
//     * @return int����
//     */
//    int knapsack(int V, int n, vector<vector<int> >& vw) {
//        //dp[i][j]Ϊǰi����Ʒ���Ϊj�ı������װ������
//        //dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - vw[i - 1][0]] + vw[i][1]);
//        //i��һά��ʡ��
//        vector<int> dp(V + 1, 0);
//        dp[0] = 0;
//        for (int i = 0; i < n; ++i) {
//            for (int j = V; j >= 0; --j) {
//                if (j - vw[i][0] >= 0)
//                    dp[j] = max(dp[j], dp[j - vw[i][0]] + vw[i][1]);
//            }
//        }
//
//        return dp[V];
//    }
//};
//int main() {
//    Solution s;
//    int n = 2;
//    int V = 10;
//    vector <vector<int>> vw(2, vector<int>(2));
//    vw[0][0] = 1;
//    vw[0][1] = 3;
//    vw[1][0] = 10;
//    vw[1][1] = 4;
//    s.knapsack(V, n, vw);
//    return 0;
//}