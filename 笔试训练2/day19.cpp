#define _CRT_SECURE_NO_WARNINGS


//С�׵�����֮·
//#include <iostream>
//using namespace std;
//
//int Func(int a, int b) {
//    int c = a % b;
//    while (c) {
//        a = b;
//        b = c;
//        c = a % b;
//    }
//    return b;
//}
//
//int main() {
//    int n = 0;
//    long long x = 0;
//    cin >> n >> x;
//    for (int i = 0; i < n; ++i) {
//        int cur = 0;
//        cin >> cur;
//        if (x >= cur)
//            x += cur;
//        else
//            x += Func(x, cur);
//    }
//    cout << x << endl;
//    return 0;
//}


//���������ֵ
//class Solution {
//public:
//    /**
//     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
//     *
//     *
//     * @param grid int����vector<vector<>>
//     * @return int����
//     */
//    int maxValue(vector<vector<int> >& grid) {
//        //dp[i][j]Ϊ��ijλ�õ�����ֵ
//        int m = grid.size(), n = grid[0].size();
//        vector<vector<int>> dp(m, vector<int>(n));
//        dp[0][0] = grid[0][0];
//        for (int i = 1; i < m; ++i)
//            dp[i][0] = dp[i - 1][0] + grid[i][0];
//        for (int j = 1; j < n; ++j)
//            dp[0][j] = dp[0][j - 1] + grid[0][j];
//        for (int i = 1; i < m; ++i) {
//            for (int j = 1; j < n; ++j) {
//                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
//            }
//        }
//        return dp[m - 1][n - 1];
//    }
//};



//�Գ�֮��
//#include <iostream>
//#include<vector>
//#include<unordered_set>
//#include<string>
//using namespace std;
//
//int main() {
//    int t = 0;
//    cin >> t;
//    int n = 0;
//    while (t--) {
//        cin >> n;
//        getchar();//��Ϊ����Ҫ��getchar����ǰ�����\n�ӵ�
//        int half = (n - 1) / 2;//ǰ�������룬������ֱ���ж���
//        vector<unordered_set<char>> arr(n);
//        if (n % 2 == 1)
//            --half;
//        for (int i = 0; i <= half; ++i)
//        {
//            while (1) {
//                char ch;
//                ch = getchar();
//                if (ch == '\n')
//                    break;
//                arr[i].insert(ch);
//            }
//        }
//        if (n % 2 == 1) {
//            while (1) {
//                char ch;
//                ch = getchar();
//                if (ch == '\n')
//                    break;
//            }
//        }
//        int flag = 0;
//        while (half >= 0) {
//            int flag2 = 0;//�жϵ�ǰ������ַ����Ͷ�Ӧ���ĵ��ַ����Ƿ�����ͬ�ַ�
//            while (1) {
//                char ch;
//                ch = getchar();
//                if (ch == '\n')
//                    break;
//                if (arr[half].count(ch)) {
//                    flag2 = 1;
//                }
//            }
//            if (flag2 == 0) {
//                flag = 1;
//            }
//            --half;
//        }
//        if (flag)
//            cout << "No" << endl;
//        else
//            cout << "Yes" << endl;
//        
//    }
//    return 0;
//}