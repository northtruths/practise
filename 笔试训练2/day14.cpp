#define _CRT_SECURE_NO_WARNINGS

//ƹ�����
//#include <iostream>
//#include<string>
//#include<unordered_map>
//using namespace std;
//
//int main() {
//    unordered_map<char, int> hash;
//    string s1, s2;
//    cin >> s1 >> s2;
//    for (auto& e : s1)
//        ++hash[e];
//    unordered_map<char, int> cur;
//    for (auto& e : s2) {
//        ++cur[e];
//    }
//    for (auto& e : cur) {
//        if (e.second > hash[e.first])
//        {
//            cout << "No" << endl;
//            return 0;
//        }
//    }
//    cout << "Yes" << endl;
//    return 0;
//}


//��Ӿ��������˲���������ac��ϸ�ڴ�������ϸ�������ˣ����»����㷨�ô��ˣ���������ô�Ƶ��㷨���ǶԵģ�
//#include <iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//int main() {
//    //̰�Ĳ��ԣ�ÿ��ȡֵȡ��ǰ�����е������С�͵ڶ����Ԫ��
//    int n = 0;
//    cin >> n;
//    vector<long long> v(3 * n);
//    for (int i = 0; i < 3 * n; ++i)
//        cin >> v[i];
//    sort(v.begin(), v.end());
//    long long ret = 0;
//    long long left = 0;//��ǰ��������С���±�
//    for (int i = 3 * n - 2; i >= left++; i -= 2) {
//        ret += v[i];
//    }
//    cout << ret << endl;
//    return 0;
//}



//ɾ���������ֵ�������������δac����������ac�����ж�ʱ�����ȷ˼·�����һ�£�����ʼʱ�����⣬�����־������鿪��̫���У���ûʵʩ��
//#include <iostream>
//#include <unordered_map>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//int main() {
//    int n;
//    cin >> n;
//    unordered_map<int, int> hash;
//    int m = 0;//������
//    for (int i = 0; i < n; ++i)
//    {
//        int in = 0;
//        cin >> in;
//        m = max(m, in);
//        ++hash[in];
//    }
//    vector<int> dp(m + 1);//����0~i�����
//    dp[0] = 0;
//    dp[1] = hash[1];
//    int ret = dp[1];
//    for (int i = 2; i <= m; ++i) {
//        dp[i] = max(dp[i - 1], dp[i - 2] + i * hash[i]);
//        ret = max(ret, dp[i]);
//    }
//    cout << ret << endl;
//    return 0;
//}