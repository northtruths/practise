#define _CRT_SECURE_NO_WARNINGS


//在字符串找出最长连续数字串
//#include<iostream>
//#include<string>
//using namespace std;
//
//int main()
//{
//    string s;
//    cin >> s;
//    int ret_begin = 0;//记录最大的数字串的开头下标
//    int ret_end = 0;//记录最大的数字串的末尾下标
//    int cur1 = 0, cur2 = 0;//当前这次的首尾下标
//    for (int i = 0; i < s.size(); ++i)
//    {
//        if (s[i] >= '0' && s[i] <= '9')
//        {
//            cur1 = i;
//            while (s[i] >= '0' && s[i] <= '9')
//            {
//                ++i;
//            }
//            cur2 = --i;
//            if (cur2 - cur1 > ret_end - ret_begin)
//            {
//                ret_begin = cur1;
//                ret_end = cur2;
//            }
//        }
//    }
//    for (int i = ret_begin; i <= ret_end; ++i)
//    {
//        cout << s[i];
//    }
//    cout << endl;
//    return 0;
//}





////岛屿数量
//#include<iostream>
//#include<vector>
//using namespace std;
//
//void one(vector<vector<char> >& grid, int i, int j, int row, int col)
//{
//    if (grid[i][j] == '0')
//        return;
//    if (grid[i][j] == '1')
//    {
//        grid[i][j] = '2';
//        if (i - 1 >= 0)
//        {
//            if (grid[i - 1][j] == '1')
//            {
//                one(grid, i - 1, j, row, col);
//            }
//        }
//        if (i + 1 <= row - 1)
//        {
//            if (grid[i + 1][j] == '1')
//            {
//                one(grid, i + 1, j, row, col);
//            }
//        }
//        if (j - 1 >= 0)
//        {
//            if (grid[i][j - 1] == '1')
//            {
//                one(grid, i, j - 1, row, col);
//            }
//        }
//        if (j + 1 <= col - 1)
//        {
//            if (grid[i][j + 1] == '1')
//            {
//                one(grid, i, j + 1, row, col);
//            }
//        }
//    }
//}
//
//int solve(vector<vector<char> >& grid) 
//{
//    int row = grid.size();
//    int col = grid[0].size();
//    int ret = 0;
//    for (int i = 0; i < row; ++i)
//    {
//        for (int j = 0; j < col; ++j)
//        {
//            if (grid[i][j] == '1')
//            {
//                one(grid, i, j, row, col);
//                ++ret;
//            }
//        }
//    }
//    return ret;
//}
//
//
//int main()
//{
//    vector<vector<char>> grid(5);
//    for (int i = 0; i < 5; ++i)
//    {
//        for (int j = 0; j < 5; ++j)
//        {
//            char in = 0;
//            cin >> in;
//            grid[i].push_back(in);
//        }
//    }
//    cout << solve(grid) << endl;
//    return 0;
//}
//[[1, 1, 0, 0, 0], 
// [0, 1, 0, 1, 1], 
// [0, 0, 0, 1, 1],
// [0, 0, 0, 0, 0], 
// [0, 0, 1, 1, 1]]


//拼三角（6个木棍是否能拼两个三角形）
//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<stdbool.h>
//using namespace std;
//
//bool is_triangle(int a, int b, int c)
//{
//    if (a >= b && a >= c)
//    {
//        if (b + c > a)
//        {
//            return true;
//        }
//        else return false;
//    }
//    if (b >= a && b >= c)
//    {
//        if (a + c > b)
//        {
//            return true;
//        }
//        else return false;
//    }
//    if (c >= b && c >= a)
//    {
//        if (b + a > c)
//        {
//            return true;
//        }
//        else return false;
//    }
//}
//
//int main()
//{
//    int t = 0;
//    cin >> t;
//    vector<int> v(6);
//    while (t--)
//    {
//        for (int i = 0; i < 6; ++i)
//        {
//            cin >> v[i];
//        }
//        int flag = 0;
//        sort(v.begin(), v.end());
//        do
//        {
//            if (is_triangle(v[0], v[1], v[2]) && is_triangle(v[3], v[4], v[5]))
//            {
//                flag = 1;
//                break;
//            }
//        } while (next_permutation(v.begin(), v.end()));
//        if (flag)
//        {
//            cout << "Yes" << endl;
//        }
//        else {
//            {
//                cout << "No" << endl;
//            }
//        }
//
//    }
//    return 0;
//}