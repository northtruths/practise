#define _CRT_SECURE_NO_WARNINGS


//����һ��С�������޵�
//#include<iostream>
//using namespace std;
//
//int main() {
//    long long a, b, h, k;
//    cin >> a >> h >> b >> k;
//    long long damage = 0;
//    int nums = min(h / b + (h % b == 0 ? 0 : 1), k / a + (k % a == 0 ? 0 : 1));
//    damage += nums * (a + b);
//    h -= nums * b;
//    k -= nums * a;
//    if (h > 0)
//        damage += a * 10;
//    if (k > 0)
//        damage += b * 10;
//    cout << damage << endl;
//    return 0;
//}



//���������������
//class Solution {
//public:
//    /**
//     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
//     *
//     *
//     * @param array int����vector
//     * @return int����
//     */
//    int FindGreatestSumOfSubArray(vector<int>& array) {
//        //dp[i]Ϊ���±�iλ��Ϊ��β������
//
//        int n = array.size();
//        int dp_pre;
//        int ret = dp_pre = array[0];
//        for (int i = 1; i < n; ++i) {
//            int dp_cur = max(array[i], dp_pre + array[i]);
//            ret = max(ret, dp_cur);
//            dp_pre = dp_cur;
//        }
//        return ret;
//    }
//};



//�ǶԳ�֮��
//#include<iostream>
//#include<string>
//using namespace std;
//
//bool juge(string& s, int left, int right)
//{
//    while (left <= right) {
//        if (s[left++] != s[right--])
//            return false;
//    }
//    return true;
//}
//int main() {
//    string s;
//    cin >> s;
//    int flag = 0;
//    for (int i = 1; i < s.size(); ++i) {
//        if (s[i] != s[i - 1]) {
//            flag = 1;
//            break;
//        }
//    }
//    if (flag == 0) {
//        cout << 0 << endl;
//        return 0;
//    }
//    int n = s.size();
//    int ret = n;
//    int left = 0, right = n - 1;
//    while (juge(s, left, right) && left <= right) {
//        --ret;
//        ++left;
//    }
//    cout << ret << endl;
//    return 0;
//}