#define _CRT_SECURE_NO_WARNINGS


//����ַ�
//#include <iostream>
//#include<string>
//#include<climits>
//using namespace std;
//
//int main() {
//    string a, b;
//    cin >> a >> b;
//    int n = b.size() - a.size();
//    int ret = INT_MAX;
//    for (int i = 0; i <= n; ++i) {
//        int cur = 0;
//        int k = 0;
//        for (int j = i; j < i + a.size(); ++j) {
//            if (a[k++] != b[j])
//                ++cur;
//        }
//        ret = min(ret, cur);
//    }
//    cout << ret << endl;
//    return 0;
//}



//����任���������Ƶ��ac��̰�ľ����Ѷ���д�����ҹ��ɣ�
//#include <iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//int main() {
//    //̰�ģ�
//    int n;
//    cin >> n;
//    vector<int> arr(n);
//    int m = 0;
//    for (int i = 0; i < n; ++i) {
//        cin >> arr[i];
//        m = max(arr[i], m);
//    }
//    int flag = 1;
//    for (int i = 0; i < n; ++i) {
//        if (!(m % arr[i] == 0 && (m / arr[i] % 2 == 0 || m / arr[i] == 1))) {
//            flag = 0;
//            break;
//        }
//    }
//    if (flag)
//        cout << "YES" << endl;
//    else
//        cout << "NO" << endl;
//    return 0;
//}


//װ������
//#include <iostream>
//#include<vector>
//using namespace std;
//
//int main() {
//    //dp[i][j]Ϊֻ��ǰi����Ʒ����Ʒ�����С�ڵ���j��������
//    //dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - arr[i]] + arr[i])
//    //i��һάʡ��
//    int V = 0, n = 0;
//    cin >> V >> n;
//    vector<int> arr(n);
//    for (int i = 0; i < n; ++i)
//        cin >> arr[i];
//    vector<int> dp(V + 1);
//    dp[0] = 0;
//    for (int i = 0; i < n; ++i) {
//        for (int j = V; j >= 0; --j) {
//            if (j - arr[i] >= 0)
//                dp[j] = max(dp[j], dp[j - arr[i]] + arr[i]);
//        }
//    }
//    cout << V - dp[V] << endl;
//    return 0;
//}