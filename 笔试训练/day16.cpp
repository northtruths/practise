#define _CRT_SECURE_NO_WARNINGS

//字符串替换（100）
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
//        // write code here
//        string ret;
//        int _argi = 0;
//        for (int i = 0; i < str.size(); ++i)
//        {
//            if (str[i] == '%')
//            {
//                ret += arg[_argi++];
//                ++i;
//            }
//            else
//            {
//                ret += str[i];
//            }
//        }
//        while (_argi < arg.size())
//        {
//            ret += arg[_argi++];
//        }
//        return ret;
//    }
//};






//神奇数，给出的数其中两位是否能组成质数（100）
//#include <iostream>
//#include <string>
//using namespace std;
//
//bool is_prime(int x)
//{
//    if (x == 2) return true;
//    int flag = 1;
//    int max = x > 9 ? 10 : x;
//    for (int i = 2; i < max; ++i)
//    {
//        if (x / i == (double)x / i)
//        {
//            flag = 0;
//        }
//    }
//    return flag;
//}
//
//int main()
//{
//    int a, b;
//    cin >> a >> b;
//    int ret = 0;
//    for (int i = a; i <= b; ++i)
//    {
//        int flag = 0;
//        string temp(to_string(i));
//        for (int j = 0; j < temp.size(); ++j)
//        {
//            for (int k = j + 1; k < temp.size(); ++k)
//            {
//                if (temp[j] != '0' && is_prime((temp[j] - 48) * 10 + (temp[k] - 48)))
//                {
//                    flag = 1;
//                    ++ret;
//                    //cout << (temp[j] - 48) * 10 + (temp[k] - 48) << endl;
//                    break;
//                }
//                if (temp[k] != '0' && is_prime((temp[j] - 48) + (temp[k] - 48) * 10))
//                {
//                    flag = 1;
//                    ++ret;
//                    //cout << (temp[j] - 48) + (temp[k] - 48) * 10 << endl;
//                    break;
//                }
//            }
//            if (flag) break;
//        }
//    }
//    cout << ret << endl;
//    return 0;
//}






//（40）
//#include<iostream>
//#include<string>
//
//using namespace std;
//
//int main()
//{
//    string s;
//    int len;
//    cin >> s >> len;
//    string ret;
//    ret.resize(len);
//    int max = 0;
//    for (int i = 0; i < s.size(); ++i)
//    {
//        int cur = 0;
//        if (s[i] == 'C' || s[i] == 'G')
//        {
//            for (int j = i; j < i + len - 1; ++j)
//            {
//                if (j >= s.size()) break;
//                if ((s[j] == 'C' && s[j + 1] == 'G')
//                    || (s[j] == 'G' && s[j + 1] == 'C'))
//                {
//                    ++cur;
//                    ++j;
//                }
//            }
//        }
//        if (cur > max)
//        {
//            int reti = 0;
//            max = cur;
//            if (i + len >= s.size())
//            {
//                for (int k = s.size() - len; k < s.size(); ++k)
//                {
//                    ret[reti++] = s[k];
//                }
//            }
//            else
//            {
//                for (int k = i; k < i + len; ++k)
//                {
//
//                    ret[reti++] = s[k];
//                }
//            }
//        }
//    }
//    cout << ret << endl;
//    return 0;
//}