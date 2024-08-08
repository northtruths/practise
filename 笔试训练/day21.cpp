#define _CRT_SECURE_NO_WARNINGS

//爱丽丝的人偶（100）
//#include<iostream>
//#include<vector>
//using namespace std;
//
//int main()
//{
//    int n;
//    cin >> n;
//    vector<int> v(n);
//    for (int i = 0; i < n; ++i)
//    {
//        v[i] = i + 1;
//    }
//    for (int i = 0; i < n; i += 2)
//    {
//        if (i + 1 < n)
//        {
//            swap(v[i], v[i + 1]);
//        }
//    }
//    for (int e : v)
//    {
//        cout << e << " ";
//    }
//    cout << endl;
//    return 0;
//}








//集合（100）
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//int main()
//{
//    int n, m;
//    cin >> n >> m;
//    vector<int> ret(m + n);
//    for (int i = 0; i < m + n; ++i)
//    {
//        cin >> ret[i];
//    }
//    sort(ret.begin(), ret.end());
//    vector<int>::iterator ret_end = unique(ret.begin(), ret.end());
//    for (auto i = ret.begin(); i != ret_end; ++i)
//    {
//        cout << *i << ' ';
//    }
//    return 0;
//}







//最长回文子序列（50， 算法超时）
//#include<iostream>
//#include<vector>
//#include<string>
//using namespace std;
//int count_max(const string& s);
//
//int juge_max(const string& s, int left, int right)
//{
//    int len = 0;
//    int flag = 1;
//    while (left < right)
//    {
//        while (left < right && s[left] == s[right])
//        {
//            len += 2;
//            ++left;
//            --right;
//        }
//        if (left < right && s[left] != s[right])
//        {
//            len += count_max(s.substr(left, right - left + 1));
//            flag = 0;
//            break;
//        }
//    }
//    if (flag && left == right)
//        ++len;
//    return  len;
//}
//
//int count_max(const string& s)
//{
//    vector<int> ch(26, 0);
//    int ret = 0;
//    for (int i = 0; i < s.size(); ++i)
//    {
//        int endi = s.size() - 1;
//        if (ch[s[i] - 97] == 0)
//        {
//            ch[s[i] - 97] = 1;
//            while (s[endi] != s[i])
//            {
//                --endi;
//            }
//            if (endi - i + 1 > ret)
//            {
//                int cur = juge_max(s, i, endi);
//                ret = cur > ret ? cur : ret;
//            }
//        }
//    }
//    return ret;
//}
//
//int main()
//{
//    //思路：从a~z中找出每一个以这个字母为首尾的回文串,递归
//    string s;
//    cin >> s;
//    cout << count_max(s) << endl;
//    return 0;
//}