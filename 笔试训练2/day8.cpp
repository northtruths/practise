#define _CRT_SECURE_NO_WARNINGS


//����С������
//#include<iostream>
//using namespace std;
//
//int Func1(long long a, long long b)
//{
//    long long c = a % b;
//    while (c)
//    {
//        a = b;
//        b = c;
//        c = a % b;
//    }
//    return b;
//}
//
//int main() {
//    long long a, b;
//    cin >> a >> b;
//    long long min = Func1(a, b);
//    cout << a * b / min << endl;
//    return 0;
//}



//�����������������
//class Solution {
//public:
//    /**
//     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
//     *
//     * max increasing subsequence
//     * @param arr int����vector the array
//     * @return int����
//     */
//    int MLS(vector<int>& arr) {
//        sort(arr.begin(), arr.end());
//        unique(arr.begin(), arr.end());
//        int ret = 0;
//        int cur = 1;
//        for (int i = 1; i < arr.size(); ++i)
//        {
//            if (arr[i] == arr[i - 1] + 1)
//                ++cur;
//            else {
//                ret = max(ret, cur);
//                cur = 1;
//            }
//        }
//        ret = max(ret, cur);
//        return ret;
//    }
//};



//��ĸ�ռ�
//#include<iostream>
//#include<unordered_map>
//using namespace std;
//
//int main()
//{
//    //dp[i][j]Ϊ��i��jλ�õ����÷�
//    int n, m;
//    cin >> m >> n;
//    char arr[m][n];
//    int dp[m][n];
//    unordered_map<char, int> hash;
//    hash.insert({ 'l', 4 });
//    hash.insert({ 'o', 3 });
//    hash.insert({ 'v', 2 });
//    hash.insert({ 'e', 1 });
//    for (int i = 0; i < m; ++i)
//    {
//        for (int j = 0; j < n; ++j)
//        {
//            cin >> arr[i][j];
//            if (i == 0 && j == 0)
//                dp[i][j] = hash[arr[i][j]];
//            else if (i == 0)
//                dp[i][j] = dp[i][j - 1] + hash[arr[i][j]];
//            else if (j == 0)
//                dp[i][j] = dp[i - 1][j] + hash[arr[i][j]];
//        }
//    }
//    for (int i = 1; i < m; ++i)
//    {
//        for (int j = 1; j < n; ++j)
//        {
//            dp[i][j] = hash[arr[i][j]] + max(dp[i - 1][j], dp[i][j - 1]);
//        }
//    }
//    cout << dp[m - 1][n - 1] << endl;
//    return 0;
//}