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


//����������У�һ��