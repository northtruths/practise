#define _CRT_SECURE_NO_WARNINGS




//�ַ����滻
//class Solution {
//public:
//    /**
//     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
//     *
//     *
//     * @param str string�ַ��� ԭ��
//     * @param arg char�ַ���vector ���滻����
//     * @return string�ַ���
//     */
//    string formatString(string str, vector<char>& arg) {
//        string ret;
//        int cur = 0;//arg��ǰ��λ��
//        for (int i = 0; i < str.size(); ++i) {
//            if (str[i] == '%') {
//                ret += arg[cur++];
//                ++i;
//            }
//            else {
//                ret += str[i];
//            }
//        }
//        for (cur; cur < arg.size(); ++cur) {
//            ret += arg[cur];
//        }
//        return ret;
//    }
//};



//������
//#include <iostream>
//#include<cmath>
//#include<unordered_set>
//#include<utility>
//#include<vector>
//using namespace std;
//
//bool Func(int x) {
//    for (int i = 2; i <= sqrt(x); ++i)
//        if (x % i == 0)
//            return false;
//    return true;
//}
//
//bool is_s(int m, unordered_set<int>& hash)
//{
//    vector<int> v;
//    while (m) {
//        v.push_back(m % 10);
//        m /= 10;
//    }
//    for (int i = 0; i < v.size() - 1; ++i)
//    {
//        for (int j = i + 1; j < v.size(); ++j)
//        {
//            int x = v[i];
//            int y = v[j];
//            int a = 10 * x + y;
//            int b = 10 * y + x;
//            if (hash.count(a) || hash.count(b))
//                return true;
//        }
//    }
//    return false;
//}
//
//int main()
//{
//    //��Ϊֻ����λ�������������Լ�¼10~99����������λ���֣�����17��¼pair(1,7)
//    //��⵱ǰ���֣�Ѱ���Ƿ�����һ��֮ǰ�ļ�¼
//    //��ϣ��¼
//    int a, b;
//    cin >> a >> b;
//    unordered_set<int> hash;
//    for (int i = 11; i <= 99; ++i) {
//        if (Func(i)) {
//            hash.insert(i);
//        }
//    }
//    int ret = 0;
//    for (int i = a; i <= b; ++i) {
//        if (is_s(i, hash))
//            ++ret;
//    }
//
//    cout << ret << endl;
//    return 0;
//}



//DNA����
//#include <iostream>
//#include<vector>
//#include<string>
//using namespace std;
//
//int main()
//{
//    //��������
//    int ret = 0;//���ص�ͷ�±�
//    int ret_n = 0;//��¼���cg
//    int cur = 0;//��ǰcg����
//    string s;
//    cin >> s;
//    int n = 0;
//    cin >> n;
//    int front = 0;//���ڵ�ͷ�±�
//    for (int i = 0; i < s.size(); ++i) {
//        if (s[i] == 'C' || s[i] == 'G')
//            ++cur;
//        if (i - front + 1 > n)
//        {
//            if (s[front] == 'C' || s[front] == 'G')
//                --cur;
//            ++front;
//        }
//        if (cur > ret_n)
//        {
//            ret_n = cur;
//            ret = front;
//        }
//    }
//
//    cout << s.substr(ret, n) << endl;
//    return 0;
//}