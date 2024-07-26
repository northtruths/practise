#define _CRT_SECURE_NO_WARNINGS



//最长回文子串
//#include<iostream>
//#include<string>
//
//using namespace std;
//
//#include <iterator>
//class Solution {
//public:
//    /**
//     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
//     *
//     *
//     * @param A string字符串
//     * @return int整型
//     */
//    bool juge(string& s, int i, int j)
//    {
//        while (i <= j)
//        {
//            if (s[i] != s[j])
//                return false;
//            ++i;
//            --j;
//        }
//        return true;
//    }
//    int getLongestPalindrome(string A) {
//        int ret = 0;
//        for (int i = 0; i < A.size(); ++i)
//        {
//            int count = 0;//0则到目前还不是回文，1为已形成回文但可能更长，2为形成回文后不是回文了该从下一个字符开始判断了
//            for (int j = i + 1; j < A.size(); ++j)
//            {
//                if (juge(A, i, j) && count < 2)
//                {
//                    if (count == 0)
//                        count = 1;
//                    ret = j - i + 1 > ret ? j - i + 1 : ret;
//                }
//                else
//                {
//                    if (count == 1)
//                        break;
//                }
//            }
//        }
//        if (ret == 0) ++ret;
//        return ret;
//    }
//};




////2.
//#include <climits>
//#include<iostream>
//#include<vector>
//using namespace std;
//
//int main()
//{
//    int n;
//    cin >> n;
//    vector<int> v;
//    for (int i = 0; i < n; ++i)
//    {
//        int a;
//        cin >> a;
//        v.push_back(a);
//    }
//    int ret = 0;
//    int min_cur = INT_MAX;
//    for (int i = 0; i < n; ++i)
//    {
//        if (v[i] < min_cur)
//        {
//            min_cur = v[i];
//        }
//        ret = max(v[i] - min_cur, ret);
//    }
//    cout << ret << endl;
//    return 0;
//}