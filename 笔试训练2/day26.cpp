#define _CRT_SECURE_NO_WARNINGS


//С���ABC
//#include<iostream>
//#include<string>
//#include<climits>
//using namespace std;
//
//int main() {
//    string s;
//    cin >> s;
//    int ret = -1;
//    for (int i = 0; i < s.size(); ++i) {
//        if (i - 1 >= 0 && i + 1 < s.size() && s[i - 1] == s[i + 1]) {
//            ret = ret == -1 ? 3 : min(ret, 3);
//        }
//        if (i + 1 < s.size() && s[i] == s[i + 1]) {
//            ret = 2;
//            break;
//        }
//    }
//    cout << ret << endl;
//    return 0;
//}


//������ȡ��
//#include<iostream>
//#include<vector>
//using namespace std;
//
//int main() {
//    //dp[i]Ϊ����0~i��ȡ�������ֵ
//    int n = 0;
//    cin >> n;
//    vector<int> nums(n);
//    for (int i = 0; i < n; ++i) {
//        cin >> nums[i];
//    }
//    if (n == 1) {
//        cout << nums[0] << endl;
//        return 0;
//    }
//    vector<int> dp(n);
//    dp[0] = nums[0];
//    dp[1] = max(nums[1], nums[0]);
//    for (int i = 2; i < n; ++i) {
//        dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
//    }
//    cout << dp[n - 1] << endl;
//    return 0;
//}



//�յ�ң�أ�δac����ʱ�临�Ӷȹ��ߣ������˸�����hash���ʱ�䣬���Ӷȳ���ʱ�����������ٿ���
//#include <iostream>
//#include<vector>
//#include<unordered_map>
//using namespace std;
//
//int main() {
//    //ÿ����Ա����һ���ܽ���״̬�����䣬������ж�Ա���������غ������Ǵ�
//    int n, p;
//    cin >> n >> p;
//    int ret = 0;
//    unordered_map<int, int> hash;
//    for (int i = 0; i < n; ++i) {
//        int temp = 0;
//        cin >> temp;
//        for (int k = temp - p; k <= p + temp; ++k) {
//            ret = max(ret, ++hash[k]);
//        }
//    }
//    cout << ret << endl;
//    return 0;
//}