#define _CRT_SECURE_NO_WARNINGS


//����λ����
//#include <iostream>
//using namespace std;
//
//int main() {
//    //ÿ�ζ���ȥ����λ������ʣ�µ�ż��λ��λ������루���磺0123456��5Ϊ��6λ��һ��ɸѡ��Ϊ135��5�ͱ�Ϊ��3λ�ˣ�
//    //������ĳ��λ���ܸ���س���2���ܱ���ż������С����ż��Ϊ2���������������µģ���0~n��Ϊ2�����ָ����λ�ã���Ϊ��
//    //��0~n��Ϊ1~n+1�����ڼ��㣬����һ��ԭ����
//    int n;
//    while (cin >> n) {
//        ++n;
//        int ret = 1;
//        while (ret * 2 <= n)
//            ret *= 2;
//        --ret;
//        cout << ret << endl;
//    }
//
//    return 0;
//}


//OR64 ��ͣ���ֵ���Ŀ���ܼ򵥵���ǩΪ�ѣ������������ı�׼����ʹ𰸵������ʽ��ȫ��ͬ�����ˣ�
//#include <iostream>
//#include<vector>
//using namespace std;
//int n, m;
//void Dfs(vector<int>& ret, int ret_size, int cur_i, int sum) {
//    if (sum == m) {
//        for (int i = 0; i < ret_size; ++i) {
//            cout << ret[i] << ' ';
//        }
//        cout << endl;
//        return;
//    }
//    else if (sum > m)
//        return;
//
//    for (int i = cur_i; i <= n; ++i) {
//        sum += i;
//        ret[ret_size] = i;
//        Dfs(ret, ret_size + 1, i + 1, sum);
//        sum -= i;
//    }
//}
//
//int main() {
//    //dfs���������������
//    cin >> n >> m;
//    vector<int> ret(n);
//    Dfs(ret, 0, 1, 0);
//    return 0;
//}



//�����ַ����ı༭���룬 ������ac���Դ����ң�֪����̬�滮��֪��״̬ת�Ʒ��̣���ת�ƹ�����������޷�����������������ǵ�һ��һ��������������������������
//#include <iostream>
//#include<vector>
//#include<string>
//
//using namespace std;
//
//int main() {
//    //��̬�滮��dp[i][j]Ϊs��0~i��t��0~j�����ٱ༭����
//    //��s[i] == t[j]����dp[i][j] = dp[i - 1][j - 1]
//    //��s[i] ��= t[j]����dp[i][j] = dp[i - 1][j - 1], ������ɾ�ĵ����������dp[i][j] = ����dp[i-1][j-1], dp[i-1][j], dp[i][j-1]����Сֵ+1
//    string s, t;
//    cin >> s >> t;
//    int n = s.size(), m = t.size();
//    vector<vector<int>> dp(1 + n, vector<int>(1 + m, 0));
//    for (int i = 1; i <= n; ++i)
//        dp[i][0] = i;
//    for (int j = 1; j <= m; ++j)
//        dp[0][j] = j;
//    for (int i = 1; i <= n; ++i) {
//        for (int j = 1; j <= m; ++j) {
//            if (s[i - 1] == t[j - 1]) {
//                dp[i][j] = dp[i - 1][j - 1];
//            }
//            else {
//                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1;
//            }
//        }
//    }
//    cout << dp[n][m] << endl;
//    return 0;
//}