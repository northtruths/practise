#define _CRT_SECURE_NO_WARNINGS


//���ε�you
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
//        t1 = a < c ? a : c;//���� o ����� you �ĸ���
//        if (b >= t1)
//        {
//            t2 = b - t1;//o ʣ�µĸ���
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


//���õ�ƻ����������
//#include<iostream>
//#include<vector>
//using namespace std;
//
//class Solution {
//public:
//    /**
//     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
//     *
//     *
//     * @param grid int����vector<vector<>>
//     * @return int����
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
//        int flag = 0;//��¼�Ƿ񴫲�
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
//        int time = 1;//�����ĵڼ���
//        int flag = 0;//��һ���Ƿ񴫲�
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