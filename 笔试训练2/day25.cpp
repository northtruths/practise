#define _CRT_SECURE_NO_WARNINGS



//��С��
//#include<iostream>
//#include<string>
//#include<cmath>
//using namespace std;
//
//bool Juge(int x) {
//    if (x < 2)
//        return false;
//    for (int i = 2; i <= sqrt(x); ++i) {
//        if (x % i == 0)
//            return false;
//    }
//    return true;
//}
//
//int main() {
//    string s;
//    cin >> s;
//    int arr[26] = { 0 };
//    for (auto& e : s)
//        ++arr[e - 'a'];
//    int maxn = 0, minn = 0x3f3f;
//    for (int i = 0; i < 26; ++i) {
//        maxn = max(maxn, arr[i]);
//        if (arr[i] != 0)
//            minn = min(minn, arr[i]);
//    }
//    int ret = maxn - minn;
//    if (Juge(ret)) {
//        cout << "Lucky Word" << endl;
//        cout << ret << endl;
//    }
//    else {
//        cout << "No Answer" << endl;
//        cout << 0 << endl;
//    }
//    return 0;
//}



//�����˵��ȣ�һ��
//class Solution {
//public:
//    /**
//     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
//     *
//     *
//     * @param schedule int����vector<vector<>>
//     * @return bool������
//     */
//    bool hostschedule(vector<vector<int> >& schedule) {
//        sort(schedule.begin(), schedule.end(),
//            [&schedule](vector<int>& v1, vector<int>& v2) ->bool {return v1[0] < v2[0]; });
//        for (int i = 1; i < schedule.size(); ++i) {
//            if (schedule[i][0] < schedule[i - 1][1])
//                return false;
//        }
//        return true;
//    }
//};



//�ָ�Ⱥ��Ӽ�
//#include<iostream>
//#include<vector>
//using namespace std;
//
//int main() {
//    int n;
//    cin >> n;
//    vector<int> nums(n);
//    int sum = 0;
//    for (int i = 0; i < n; ++i) {
//        cin >> nums[i];
//        sum += nums[i];
//    }
//    if (sum % 2 == 1)//Ϊ�����򲻿���
//    {
//        cout << "false" << endl;
//        return 0;
//    }
//    sum /= 2;
//    //����dp
//    //dp[i][j]Ϊֻ��ǰi��������Ϊj�Ƿ��ܳ���
//    vector<bool> dp(sum + 1, false);
//    dp[0] = true;
//    int flag = 0;//ֻҪ;�г��ֹ���Ϊsum�������
//    for (int i = 0; i < n; ++i) {
//        for (int j = sum; j >= 0; --j) {
//            if (j - nums[i] >= 0)
//                dp[j] = dp[j - nums[i]] == true ? true : false;
//        }
//    }
//    if (dp[sum])
//        cout << "true" << endl;
//    else
//        cout << "false" << endl;
//    return 0;
//}

