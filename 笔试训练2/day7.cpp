#define _CRT_SECURE_NO_WARNINGS



//在字符串中找出最长连续数字串
//#include <iostream>
//#include<string>
//using namespace std;
//
//int main() {
//    string s;
//    cin >> s;
//    string ret;
//    for (int i = 0; i < s.size(); ++i)
//    {
//        if ('0' <= s[i] && s[i] <= '9')
//        {
//            int j = i;
//            while (j < s.size())
//            {
//                if ('0' <= s[j] && s[j] <= '9') {
//                    ++j;
//                }
//                else
//                    break;
//            }
//            if (j - i > ret.size())
//            {
//                ret = s.substr(i, j - i);
//            }
//        }
//    }
//    cout << ret << endl;
//}



//岛屿数量
//class Solution {
//public:
//    /**
//     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
//     *
//     * 判断岛屿数量
//     * @param grid char字符型vector<vector<>>
//     * @return int整型
//     */
//    int solve(vector<vector<char>>& grid) {
//        int ret = 0;
//        int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
//        vector<vector<bool>> hash(grid.size(), vector<bool>(grid[0].size(), false));
//        for (int i = 0; i < grid.size(); ++i) {
//            for (int j = 0; j < grid[0].size(); ++j) {
//                if (grid[i][j] == '1' && hash[i][j] == false)
//                {
//                    ++ret;
//                    dfs(grid, hash, i, j, dir);
//                }
//            }
//        }
//        return ret;
//    }
//
//    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& hash, int i, int j, int(&dir)[4][2])
//    {
//        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()
//            || hash[i][j] || grid[i][j] == '0')
//            return;
//        hash[i][j] = true;
//        for (auto& e : dir) {
//            dfs(grid, hash, i + e[0], j + e[1], dir);
//        }
//    }
//};



//拼三角
//#include<iostream>
//#include<cmath>
//using namespace std;
//
//bool is_san(int a, int b, int c)
//{
//    if (b > a)
//    {
//        int temp = b;
//        b = a;
//        a = temp;
//    }
//    if (c > a)
//    {
//        int temp = c;
//        c = a;
//        a = temp;
//    }
//    if (b + c > a && abs(b - c) < a)
//    {
//        return true;
//    }
//    else
//        return false;
//}
//
//int main()
//{
//    //就是看这六根棍子是否能拼两个三角形
//    int t = 0;
//    cin >> t;
//    while (t--)
//    {
//        int arr[6];
//        for (int i = 0; i < 6; ++i)
//            cin >> arr[i];
//        int flag = 0;//判断此次是否能组成
//        for (int i = 0; i < 4; ++i) {
//            if (flag) break;
//            for (int j = i + 1; j < 5; ++j) {
//                if (flag) break;
//                for (int k = j + 1; k < 6; ++k) {
//                    if (flag) break;
//                    int abc[3];
//                    int abci = 0;
//                    for (int temp = 0; temp < 6; ++temp)
//                        if (temp != i && temp != j && temp != k)
//                            abc[abci++] = temp;
//                    if (is_san(arr[i], arr[j], arr[k]) && is_san(arr[abc[0]], arr[abc[1]], arr[abc[2]]))
//                    {
//                        cout << "Yes" << endl;
//                        flag = 1;
//                    }
//                }
//            }
//        }
//        if (flag == 0)
//            cout << "No" << endl;
//    }
//    return 0;
//}