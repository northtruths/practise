#define _CRT_SECURE_NO_WARNINGS


//游游的you
//#include<iostream>
//using namespace std;
//
//int main()
//{
//    int q = 0;
//    cin >> q;
//    while (q--)
//    {
//        int a = 0, b = 0, c = 0;
//        cin >> a >> b >> c;
//        int ret = 0;
//        int num_you = min(a, min(b, c));
//        ret += 2 * num_you;
//        b -= num_you;
//        if (b >= 2)
//            ret += b - 1;
//        cout << ret << endl;
//    }
//    return 0;
//}



//腐烂的苹果（虽然ac了，但还得看看题解）
//#include <vector>
//#include<iostream>
//using namespace std;
//class Solution {
//public:
//    int rotApple(vector<vector<int>>& grid) {
//        int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
//        int minute = 0;
//        vector<vector<bool>> hash(grid.size(), vector<bool>(grid[0].size(), false));//记录此处是否做过传播源了
//        while (1) {
//            vector<pair<int, int>> index;
//            bool temp_flag = false;//这个flag判断当前时间是否进行了传播
//            for (int i = 0; i < grid.size(); ++i) {
//                for (int j = 0; j < grid[0].size(); ++j) {
//                    if (grid[i][j] == 2 && hash[i][j] == false) {
//                        hash[i][j] = true;
//                        for (auto& e : dir) {
//                            int x = i + e[0];
//                            int y = j + e[1];
//                            if (!(x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size())) {
//                                if (grid[x][y] == 1) {
//                                    temp_flag = true;
//                                    index.push_back({ x, y });
//                                }
//                            }
//                        }
//                    }
//                }
//            }
//
//        if (temp_flag == false)
//            break;
//        for (auto& e : index)
//            grid[e.first][e.second] = 2;
//        ++minute;
//        }
//    
//        for (auto& e : grid)
//            for (auto& ee : e)
//                if (ee == 1)
//                    return -1;
//        return minute;
//
//    }
//};
//
//int main()
//{
//    vector<vector<int>> grid = { {2,1,1}, {1, 0, 1}, {1,1,1} };
//    Solution s;
//    cout << s.rotApple(grid);
//    return 0;
//}



//孩子们的游戏(圆圈中最后剩下的数)（虽然ac，但好像不满足题目条件的空间复杂度O(1)，并且再复习复习list的使用吧，用得有点少）
//#include<list>
//#include<iostream>
//using namespace std;
//
//class Solution {
//public:
//    /**
//     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
//     *
//     *
//     * @param n int整型
//     * @param m int整型
//     * @return int整型
//     */
//    int LastRemaining_Solution(int n, int m) {
//        list<int> l(n);
//        auto it_cur = l.begin();
//        auto it_end = l.end();
//        for (int i = 0; i < n; ++i)
//        {
//            *it_cur = i;
//            ++it_cur;
//        }
//        it_cur = l.begin();
//        while (l.size() > 1)
//        {
//            int time = m - 1;
//            while (time--)
//            {
//                ++it_cur;
//                if (it_cur == it_end)
//                    it_cur = l.begin();
//            }
//            auto it_temp = it_cur;//删除的点
//            ++it_cur;
//            if (it_cur == it_end)
//                it_cur = l.begin();
//            l.erase(it_temp);
//            it_end = l.end();
//        }
//        return *l.begin();
//    }
//};