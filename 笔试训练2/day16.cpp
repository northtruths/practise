#define _CRT_SECURE_NO_WARNINGS




//字符串替换
//class Solution {
//public:
//    /**
//     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
//     *
//     *
//     * @param str string字符串 原串
//     * @param arg char字符型vector 需替换数组
//     * @return string字符串
//     */
//    string formatString(string str, vector<char>& arg) {
//        string ret;
//        int cur = 0;//arg当前的位置
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



//神奇数
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
//    //因为只找两位数的质数，所以记录10~99的质数的两位数字，比如17记录pair(1,7)
//    //拆解当前数字，寻找是否满足一个之前的记录
//    //哈希记录
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



//DNA序列
//#include <iostream>
//#include<vector>
//#include<string>
//using namespace std;
//
//int main()
//{
//    //滑动窗口
//    int ret = 0;//返回的头下标
//    int ret_n = 0;//记录最多cg
//    int cur = 0;//当前cg数量
//    string s;
//    cin >> s;
//    int n = 0;
//    cin >> n;
//    int front = 0;//窗口的头下标
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