#define _CRT_SECURE_NO_WARNINGS



//小易的升级之路（100）
//#include<iostream>
//#include<vector>
//using namespace std;
//
//long long 最大公约数(long long a, long long b)
//{
//    long long c = a % b;
//    while (c != 0)
//    {
//        c = a % b;
//        a = b;
//        b = c;
//    }
//    return a;
//}
//
//int main()
//{
//    long long n, x;
//    cin >> n >> x;
//
//    vector<long long> v(n);
//    for (long long i = 0; i < n; ++i)
//    {
//        cin >> v[i];
//    }
//
//    for (long long i = 0; i < n; ++i)
//    {
//        if (x >= v[i])
//        {
//            x += v[i];
//        }
//        else {
//            x += 最大公约数(x, v[i]);
//        }
//    }
//    cout << x << endl;
//    return 0;
//}


//礼物的最大价值（93.75）
//#include <climits>
//class Solution {
//public:
//    /**
//     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
//     *
//     *
//     * @param grid int整型vector<vector<>>
//     * @return int整型
//     */
//    int maxValue(vector<vector<int> >& grid) {
//        int m = grid.size();
//        int n = grid[0].size();
//        vector<vector<int>> ret(m);//动态规划，每格存到这的最大价值
//        for (int i = 0; i < m; ++i)
//        {
//            ret[i].reserve(n);
//        }
//        ret[0][0] = grid[0][0];
//        for (int i = 1; i < n; ++i)
//        {
//            ret[0][i] = grid[0][i] + ret[0][i - 1];
//        }
//        for (int i = 1; i < m; ++i)
//        {
//            ret[i][0] = grid[i][0] + ret[i - 1][0];
//        }
//        int ret_max = INT_MIN;
//        for (int i = 1; i < m; ++i)
//        {
//            for (int j = 1; j < n; ++j)
//            {
//                int a = grid[i][j] + ret[i - 1][j];//加上面的
//                int b = grid[i][j] + ret[i][j - 1];//加左边的
//                ret[i][j] = a > b ? a : b;
//                if (ret[i][j] > ret_max)
//                    ret_max = ret[i][j];
//            }
//        }
//        return ret_max;
//    }
//};




//对称之美(100)
//#include<iostream>
//#include<string>
//#include<vector>
//using namespace std;
//
//int main()
//{
//    int t;
//    cin >> t;
//    while (t--)
//    {
//        int n;
//        cin >> n;
//        string s;
//        for (int i = 0; i < n; ++i)
//        {
//            string temp;
//            cin >> temp;
//            s += temp;
//            s += '|';
//        }
//        s.pop_back();
//        int flag = 0;//1不可能为回文，0可能
//        int left = 0, right = s.size() - 1;//分别从左右遍历的下标
//        for (int i = 0; i < n / 2; ++i)
//        {
//            vector<int> count_left(26);
//            vector<int> count_right(26);
//
//            while (s[left] != '|')
//            {
//                count_left[s[left] - 97] = 1;
//                ++left;
//            }
//            while (s[right] != '|')
//            {
//                count_right[s[right] - 97] = 1;
//                --right;
//            }
//            ++left;
//            --right;//调整到下一个字符串开始
//            for (int k = 0; k < 26; ++k)
//            {
//                count_left[k] += count_right[k];
//            }
//            int juge = 0;//若count_left中没有一个为2的，则说明不能回文
//            for (int e : count_left)
//            {
//                if (e == 2)
//                {
//                    juge = 2;
//                    break;
//                }
//            }
//            if (juge != 2)
//            {
//                flag = 1;
//                break;
//            }
//        }
//        if (flag)
//        {
//            cout << "No" << endl;
//        }
//        else
//        {
//            cout << "Yes" << endl;
//        }
//
//    }
//    return 0;
//}