#define _CRT_SECURE_NO_WARNINGS


//������
//#include <iostream>
//#include<cmath>
//using namespace std;
//
//bool JugePrime(long long x) {
//    if (x <= 1)  return false;
//    if (x == 2 || x == 3)  return true;
//    if (x % 2 == 0 || x % 3 == 0)  return false;
//
//    for (int i = 6; i <= sqrt(x); i += 6) {
//        if (x % (i - 1) == 0 || x % (i + 1) == 0)
//            return false;
//    }
//    return true;
//}
//
//int main() {
//    int t;
//    cin >> t;
//    while (t--) {
//        long long a, b;
//        cin >> a >> b;
//        if (JugePrime(a * b))
//            cout << "YES" << endl;
//        else
//            cout << "NO" << endl;
//    }
//    return 0;
//}



//������k�������
//#include <iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//int main() {
//    //���򣬻����������ڣ����������߲�С��k������������������ֵ����ֵҲ�ض�С��k
//    int n, k;
//    cin >> n >> k;
//    vector<int> arr(n);
//    for (int i = 0; i < n; ++i)
//        cin >> arr[i];
//    sort(arr.begin(), arr.end());
//    int ret = 0;
//    int left = 0, right = 0;//���������±�
//    while (right < n) {
//        while (right < n && arr[right] - arr[left] <= k)
//            ++right;
//        ret = max(ret, right - left);
//        ++left;
//    }
//    cout << ret << endl;
//    return 0;
//}


//����������У�һ������ʼδac���ھ���һ��Ķ�ѧϰ�����ľ�����ͨ����ǩ��ʾ��ac��
// ��ʵ�����������Ҿ���򵥣���ѧϰ��������λ������ѧϰЧ���ܲ������׿�ʼ�Ľ������ϻ��Ч����
//#include <iostream>
//#include<string>
//#include<vector>
//using namespace std;
//
//int main() {
//    int n, m;
//    string s1, s2;
//    cin >> n >> m >> s1 >> s2;
//    //dp[i][j]Ϊs1��0~i���Ӵ���s2��0~j���Ӵ��������������
//    //��s1[i] == s2[j]ʱ��dp[i][j] = 1 + dp[i - 1][j - 1]������dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
//    vector<vector<int>> dp(n, vector<int>(m));
//    for (int j = 0; j < m; ++j)//�����һ�б߽�
//        dp[0][j] = s1[0] == s2[j] ? 1 : 0;
//    for (int i = 0; i < n; ++i)//�����һ�б߽�
//        dp[i][0] = s1[i] == s2[0] ? 1 : 0;
//    for (int i = 1; i < n; ++i) {
//        for (int j = 1; j < m; ++j) {
//            dp[i][j] = s1[i] == s2[j] ? 1 + dp[i - 1][j - 1] : max(dp[i - 1][j], dp[i][j - 1]);
//        }
//    }
//    cout << dp[n - 1][m - 1] << endl;
//    return 0;
//}


//����������У�һ�������������Ż��ռ临�Ӷȣ�
//#include <any>
//#include <iostream>
//#include<string>
//#include<vector>
//using namespace std;
//
//int main() {
//    int n, m;
//    string s1, s2;
//    cin >> n >> m >> s1 >> s2;
//    //dp[i][j]Ϊs1��0~i���Ӵ���s2��0~j���Ӵ��������������
//    //��s1[i] == s2[j]ʱ��dp[i][j] = 1 + dp[i - 1][j - 1]������dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
//    //��ͼ���������飬�Ż��ռ�
//    if (n > m) {
//        swap(s1, s2);
//        swap(n, m);
//    }
//    vector<int> dp(n + 1, 0);
//    for (int j = 0; j < m; ++j) {
//        int pre = 0;//��¼dp[i - 1][j - 1]
//        for (int i = 1; i <= n; ++i) {
//            int cur = s1[i - 1] == s2[j] ? 1 + pre : max(dp[i], dp[i - 1]);
//            pre = dp[i];
//            dp[i] = cur;
//        }
//    }
//    cout << dp[n] << endl;
//    return 0;
//}