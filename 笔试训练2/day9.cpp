#define _CRT_SECURE_NO_WARNINGS


#define _CRT_SECURE_NO_WARNINGS

//��Ӷ���
//#include <iostream>
//#include<string>
//#include<algorithm>
//using namespace std;
//
//int main() {
//    int n = 0;
//    cin >> n;
//    string s = to_string(n);
//    string ret;
//    int t = 0;
//    for (int i = s.size() - 1; i >= 0; --i)
//    {
//        ret += s[i];
//        ++t;
//        if (t == 3)
//        {
//            ret += ',';
//            t = 0;
//        }
//    }
//    if (ret[ret.size() - 1] == ',')
//        ret.erase(ret.size() - 1, 1);
//    reverse(ret.begin(), ret.end());
//    cout << ret << endl;
//}



//��̨��
//#include<iostream>
//using namespace std;
//
//int main() {
//    //dp[i]Ϊ���ϵ�į�׵��������
//    //��į�׿��Դ�i-1��i-2��̨��������
//    //dp[i] = dp[i - 1] + dp[i - 2];
//    int n;
//    cin >> n;
//    int dp[n + 1];
//    dp[0] = 0;
//    dp[1] = 1;
//    dp[2] = 2;
//    for (int i = 3; i <= n; ++i) {
//        dp[i] = dp[i - 1] + dp[i - 2];
//    }
//    cout << dp[n] << endl;
//    return 0;
//}



//�˿���˳��
//class Solution {
//public:
//    /**
//     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
//     *
//     *
//     * @param numbers int����vector
//     * @return bool������
//     */
//    bool IsContinuous(vector<int>& numbers) {
//        //�����ظ��ķ��㣬��false
//        //������С��ֵ������4����
//        sort(numbers.begin(), numbers.end());
//        int count = 0;
//        for (int i = 0; i < 5; ++i)
//        {
//            if (i < 4 && numbers[i] && numbers[i] == numbers[i + 1])
//                return false;
//            if (numbers[i] == 0)
//                ++count;
//        }
//        int dif = numbers[4] - numbers[count];
//        if (dif <= 4)
//            return true;
//        else
//            return false;
//    }
//};