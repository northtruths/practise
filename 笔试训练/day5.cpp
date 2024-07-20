#define _CRT_SECURE_NO_WARNINGS


//游游的you
//#include <iostream>
//using namespace std;
//
//int main()
//{
//    int q = 0;
//    cin >> q;
//    int a, b, c;
//
//    while (q--)
//    {
//        cin >> a >> b >> c;
//        int ret = 0;
//        int t1 = 0, t2 = 0;
//        t1 = a < c ? a : c;//不看 o 能组合 you 的个数
//        if (b >= t1)
//        {
//            t2 = b - t1;//o 剩下的个数
//        }
//        else
//        {
//            t1 = b;
//            t2 = 0;
//        }
//        ret = 2 * t1 + (t2 >= 2 ? t2 - 1 : 0);
//        cout << ret << endl;
//    }
//    return 0;
//}


//腐烂的苹果（传播）
//#include<iostream>
//#include<vector>
//using namespace std;
//
//class Solution {
//public:
//    /**
//     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
//     *
//     *
//     * @param grid int整型vector<vector<>>
//     * @return int整型
//     */
//    bool juge(vector<vector<int> >& grid, int i, int j, int row, int col)
//    {
//        if (i == 0 || j == 0 || i == row - 1 || j == col - 1)
//        {
//            if ((i == 0 && j == 0) || (i == row - 1 && j == col - 1))
//            {
//                if (i == 0 && j == 0)
//                    return !grid[i + 1][j] && !grid[i][j + 1];
//                else
//                    return !grid[i - 1][j] && !grid[i][j - 1];
//            }
//            else if ((i == 0 && j == col - 1) || (i == row - 1 && j == 0))
//            {
//                if (i == 0 && j == col - 1)
//                    return !grid[i + 1][j] && !grid[i][j - 1];
//                else
//                    return !grid[i - 1][j] && !grid[i][j + 1];
//            }
//            else if (i == 0)
//            {
//                return !grid[i + 1][j] && !grid[i][j - 1] && !grid[i][j + 1];
//            }
//            else if (i == row - 1)
//            {
//                return !grid[i - 1][j] && !grid[i][j - 1] && !grid[i][j + 1];
//            }
//            else if (j == 0)
//            {
//                return !grid[i - 1][j] && !grid[i + 1][j] && !grid[i][j + 1];
//            }
//            else {
//                return !grid[i - 1][j] && !grid[i + 1][j] && !grid[i][j - 1];
//            }
//        }
//        else
//        {
//            return !grid[i - 1][j] && !grid[i + 1][j] && !grid[i][j - 1] && !grid[i][j + 1];
//        }
//    }
//
//    bool spread(vector<vector<int> >& grid, int i, int j, int row, int col, int& time)
//    {
//        int flag = 0;//记录是否传播
//        if ((i == 0 && j == 0) || (i == row - 1 && j == col - 1))
//        {
//            if (i == 0 && j == 0)
//            {
//                if (grid[i + 1][j] == 1)
//                {
//                    grid[i + 1][j] = time + 2;
//                    flag = 1;
//                }
//                if (grid[i][j + 1] == 1)
//                {
//                    grid[i][j + 1] = time + 2;
//                    flag = 1;
//                }
//            }
//            else
//            {
//                if (grid[i - 1][j] == 1)
//                {
//                    grid[i - 1][j] = time + 2;
//                    flag = 1;
//                }
//                if (grid[i][j - 1] == 1)
//                {
//                    grid[i][j - 1] = time + 2;
//                    flag = 1;
//                }
//            }
//        }
//        else if ((i == 0 && j == col - 1) || (i == row - 1 && j == 0))
//        {
//            if (i == 0 && j == col - 1)
//            {
//                if (grid[i + 1][j] == 1)
//                {
//                    grid[i + 1][j] = time + 2;
//                    flag = 1;
//                }
//                if (grid[i][j - 1] == 1)
//                {
//                    grid[i][j - 1] = time + 2;
//                    flag = 1;
//                }
//            }
//            else
//            {
//                if (grid[i - 1][j] == 1)
//                {
//                    grid[i - 1][j] = time + 2;
//                    flag = 1;
//                }
//                if (grid[i][j + 1] == 1)
//                {
//                    grid[i][j + 1] = time + 2;
//                    flag = 1;
//                }
//            }
//        }
//        else if (i == 0)
//        {
//            if (grid[i + 1][j] == 1)
//            {
//                grid[i + 1][j] = time + 2;
//                flag = 1;
//            }
//            if (grid[i][j + 1] == 1)
//            {
//                grid[i][j + 1] = time + 2;
//                flag = 1;
//            }
//            if (grid[i][j - 1] == 1)
//            {
//                grid[i][j - 1] = time + 2;
//                flag = 1;
//            }
//        }
//        else if (i == row - 1)
//        {
//            if (grid[i - 1][j] == 1)
//            {
//                grid[i - 1][j] = time + 2;
//                flag = 1;
//            }
//            if (grid[i][j + 1] == 1)
//            {
//                grid[i][j + 1] = time + 2;
//                flag = 1;
//            }
//            if (grid[i][j - 1] == 1)
//            {
//                grid[i][j - 1] = time + 2;
//                flag = 1;
//            }
//        }
//        else if (j == 0)
//        {
//            if (grid[i - 1][j] == 1)
//            {
//                grid[i - 1][j] = time + 2;
//                flag = 1;
//            }
//            if (grid[i + 1][j] == 1)
//            {
//                grid[i + 1][j] = time + 2;
//                flag = 1;
//            }
//            if (grid[i][j + 1] == 1)
//            {
//                grid[i][j + 1] = time + 2;
//                flag = 1;
//            }
//        }
//        else
//        {
//            if (grid[i - 1][j] == 1)
//            {
//                grid[i - 1][j] = time + 2;
//                flag = 1;
//            }
//            if (grid[i + 1][j] == 1)
//            {
//                grid[i + 1][j] = time + 2;
//                flag = 1;
//            }
//            if (grid[i][j - 1] == 1)
//            {
//                grid[i][j - 1] = time + 2;
//                flag = 1;
//            }
//        }
//        return flag;
//    }
//
//    int rotApple(vector<vector<int> >& grid) {
//        int row = grid.size();
//        int col = grid[0].size();
//        int time = 1;//传播的第几次
//        int flag = 0;//这一遍是否传播
//        while(1)
//        {
//            flag = 0;
//            for (int i = 0; i < row; ++i)
//            {
//                for (int j = 0; j < col; ++j)
//                {
//                    if (grid[i][j] == 1)
//                    {
//                        if (juge(grid, i, j, row, col))
//                            return -1;
//                    }
//                    if (grid[i][j] == time + 1)
//                    {
//                        if (spread(grid, i, j, row, col, time))
//                        {
//                            flag = 1;
//                        }
//                    }
//                }
//            }
//            if (flag == 0)
//            {
//                return time - 1;
//            }
//            ++time;
//        }
//        return time - 1;
//    }
//
//
//};
//
//
//int main()
//{
//    Solution s1;
//    int n = 0;
//    vector<vector<int>> grid(3);
//    for (int i = 0; i < 3; ++i)
//    {
//        for (int j = 0; j < 3; ++j)
//        {
//            int a = 0;
//            cin >> a;
//            grid[i].push_back(a);
//        }
//    }
//    cout << s1.rotApple(grid) << endl;
//    return 0;
//}
//
////2 1 1 
////1 0 1 
////1 1 1