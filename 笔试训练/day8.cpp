#define _CRT_SECURE_NO_WARNINGS

//最小公倍数
//#include<iostream>
//using namespace std;
//
//long long 最大公约数(long long m, long long s)
//{
//    //辗转相除法
//    long long c = 0;
//    while (m % s != 0)
//    {
//        c = m % s;
//        m = s;
//        s = c;
//    }
//    if (c == 0)//m是s的倍数，s就为最小公约数
//        c = s;
//    return c;
//}
//
//int main()
//{
//    long long a = 0, b = 0;
//    cin >> a >> b;
//    if (b > a)
//    {
//        swap(a, b);
//    }
//    cout << (a * b) / 最大公约数(a, b) << endl;
//    return 0;
//}



//数组中最长子序列（要值连续，位置可以不连续）
//class Solution {
//public:
//    /**
//     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
//     *
//     * max increasing subsequence
//     * @param arr int整型vector the array
//     * @return int整型
//     */
//    int MLS(vector<int>& arr) {
//        sort(arr.begin(), arr.end());
//        // for(const auto& e : arr)
//        // {
//        //     cout << e << ' ';
//        // }
//        // cout << endl;
//        unique(arr.begin(), arr.end());
//        int max = 0;//最长长度,不加上首元素
//        int cur = 0;//当前长度
//        for (int i = 1; i < arr.size(); ++i)
//        {
//            if (arr[i] == arr[i - 1] + 1)
//            {
//                ++cur;
//            }
//            else
//            {
//                if (cur > max)
//                {
//                    max = cur;
//                }
//                cur = 0;
//            }
//        }
//        return max + 1;
//    }
//};




//字母收集(love)，得分最大，动态规划
//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//int score(vector<string>& put_in, int i, int j)
//{
//    char ch = put_in[i][j];
//    if (ch == 'l') return 4;
//    if (ch == 'o') return 3;
//    if (ch == 'v') return 2;
//    if (ch == 'e') return 1;
//    return 0;
//}
//
//int main()
//{
//    int n = 0, m = 0;
//    cin >> n >> m;
//    //动态规划，n*m的数组，值为到此位置的最多分数
//    vector<string> put_in(n);
//    string in;
//    for (int i = 0; i < n; ++i)
//    {
//        cin >> in;
//        put_in[i] = in;
//    }
//    vector<vector<int>> vv(n);
//    for (int i = 0; i < n; ++i)
//    {
//        vv[i].reserve(m);
//    }
//
//    if (put_in[0][0] == 'l') vv[0][0] = 4;
//    if (put_in[0][0] == 'o') vv[0][0] = 3;
//    if (put_in[0][0] == 'v') vv[0][0] = 2;
//    if (put_in[0][0] == 'e') vv[0][0] = 1;
//
//    for (int i = 0; i < n; ++i)
//    {
//        for (int j = 0; j < m; ++j)
//        {
//            if (i == 0 && j == 0) continue;
//            if (i == 0)
//            {
//                vv[i][j] = vv[i][j - 1] + score(put_in, i, j);
//            }
//            else if (j == 0)
//            {
//                vv[i][j] = vv[i - 1][j] + score(put_in, i, j);
//            }
//            else
//            {
//                int a = vv[i][j - 1] + score(put_in, i, j);
//                int b = vv[i - 1][j] + score(put_in, i, j);
//                vv[i][j] = a > b ? a : b;
//            }
//        }
//    }
//
//    int ret = 0;
//    int i = 0, j = 0;
//    for (int i = n - 1; j <= m - 1; ++j)
//    {
//        ret = max(vv[i][j], ret);
//    }
//    i = 0;
//    for (int j = m - 1; i <= n - 1; ++i)
//    {
//        ret = max(vv[i][j], ret);
//    }
//    cout << ret << endl;
//    return 0;
//}