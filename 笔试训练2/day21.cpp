#define _CRT_SECURE_NO_WARNINGS\


//����˿����ż
//#include <iostream>
//#include<vector>
//using namespace std;
//
//int main() {
//    int n = 0;
//    cin >> n;
//    vector<int> arr(n);
//    for (int i = 1; i <= n; ++i)
//        arr[i - 1] = i;
//    for (int i = 1; i < n - 1; i += 2) {
//        swap(arr[i], arr[i + 1]);
//    }
//    for (auto& e : arr)
//        cout << e << ' ';
//    cout << endl;
//    return 0;
//}


//����
//#include <iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//int main() {
//    int m, n;
//    cin >> n >> m;
//    vector<int> arr(m + n);
//    for (int i = 0; i < m + n; ++i) {
//        cin >> arr[i];
//    }
//    sort(arr.begin(), arr.end());
//    auto end = unique(arr.begin(), arr.end());
//    for (auto i = arr.begin(); i != end; ++i)
//        cout << *i << ' ';
//    cout << endl;
//    return 0;
//}



//DP22 �����������
//#include <iostream>
//#include<vector>
//#include<string>
//using namespace std;
//
//int main() {
//    //dp[i][j]Ϊ�±�i��j����ִ�
//    //�����s[i] == s[j]��dp[i][j] = dp[i - 1][j - 1] + 2;
//    //����dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
//    string s;
//    cin >> s;
//    int n = s.size();
//    vector<vector<int>> dp(n, vector<int>(n));
//    for (int i = n - 1; i >= 0; --i) {
//        for (int j = 0; j < n; ++j) {
//            if (i > j)
//                dp[i][j] = 0;
//            else if (i == j)
//                dp[i][j] = 1;
//            else {
//                if (s[i] == s[j])
//                    dp[i][j] = dp[i + 1][j - 1] + 2;
//                else
//                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
//            }
//        }
//    }
//    cout << dp[0][n - 1] << endl;;
//    return 0;
//}