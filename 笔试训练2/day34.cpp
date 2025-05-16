#define _CRT_SECURE_NO_WARNINGS


//ISBN号码
//#include <iostream>
//#include<string>
//using namespace std;
//
//int main() {
//    //模拟
//    string s;
//    cin >> s;
//    int x = 0;//识别码
//    int n = 1;
//    for (auto& ch : s) {
//        if (n > 9)
//            break;
//        if (ch == '-')
//            continue;
//        else {
//            x += n * (ch - 48);
//            ++n;
//        }
//    }
//    x %= 11;
//    if (x == 10)
//        x = 'X';
//    else
//        x += 48;
//    if (x == s[s.size() - 1])
//        cout << "Right" << endl;
//    else {
//        s[s.size() - 1] = x;
//        cout << s << endl;
//    }
//    return 0;
//}



//kotori和迷宫
//#include <iostream>
//#include<vector>
//#include<array>
//#include<queue>
//#include<utility>
//using namespace std;
//
//int main() {
//    //层序遍历
//    int n, m;
//    cin >> n >> m;
//    vector<vector<char>> grid(n, vector<char>(m));
//    int x, y;//记录k的位置
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < m; ++j) {
//            cin >> grid[i][j];
//            if (grid[i][j] == 'k') {
//                x = i, y = j;
//            }
//        }
//    }
//    int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
//    vector<vector<bool>> hash(n, vector<bool>(m));//判断路径是否来过
//    vector<vector<int>> dist(n, vector<int>(m, 0));//起始点到此处的距离
//    queue<pair<int, int>> qp;
//    qp.push({ x, y });
//    int ret_min = 0;
//    int flag = 0;//判断是否找到最近出口
//    int ret_count = 0;
//    while (!qp.empty()) {
//        auto& [a, b] = qp.front();
//        hash[a][b] = true;
//        if (grid[a][b] == 'e') {
//            ++ret_count;
//            if (flag == 0) {
//                ret_min = dist[a][b];
//                flag = 1;
//            }
//        }
//        else {
//            for (auto& e : dir) {
//                x = a + e[0];
//                y = b + e[1];
//                if (0 <= x && x < n && 0 <= y && y < m && hash[x][y] == false && grid[x][y] != '*') {
//                    qp.push({ x, y });
//                    dist[x][y] = dist[a][b] + 1;
//                }
//            }
//        }
//        qp.pop();
//    }
//    if (ret_count) {
//        cout << ret_count << ' ' << ret_min << endl;
//    }
//    else {
//        cout << -1 << endl;
//    }
//
//    return 0;
//}



//矩阵最长递增路径（隔了几天后做，成功ac，不过不小心瞟到标签，虽说不看感觉能做出来，但是还是帮了大忙，
// tips，这道题很久之前就做过，不过没马上想出来，若不能立即想出题解，还是遵循暴力+优化一步一步做出来吧）
//class Solution {
//public:
//    /**
//     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
//     *
//     * 递增路径的最大长度
//     * @param matrix int整型vector<vector<>> 描述矩阵的每个数
//     * @return int整型
//     */
//    int solve(vector<vector<int> >& matrix) {
//        //递归，并用一个数组记录从i、j开始的最长路径（剪枝）
//        //当前位置接上四周能接上并且记录过的位置即可，因为路径递增原因，不会出现重复情况
//        int n = matrix.size(), m = matrix[0].size();
//        vector<vector<int> > ret(n, vector<int>(m, -1));
//        int ret_max = 0;
//        for (int i = 0; i < n; ++i) {
//            for (int j = 0; j < m; ++j) {
//                ret_max = max(ret_max, Dfs(matrix, ret, i, j));
//            }
//        }
//        return ret_max;
//    }
//
//private:
//    int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
//
//    //dfs返回以i、j为起点的最长路径
//    int Dfs(vector<vector<int> >& grid, vector<vector<int> >& ret, int i, int j) {
//        if (ret[i][j] != -1)//若不为-1说明以此为开始的路径最长已经记录
//            return ret[i][j];
//        for (auto& e : dir) {
//            int x = i + e[0];
//            int y = j + e[1];
//            //如果x，y的位置比当前大，并且不为-1，说明能直接接上，为-1就递归下去计算x，y的位置
//            if (0 <= x && x < grid.size() && 0 <= y && y < grid[0].size() && grid[i][j] < grid[x][y]) {
//                ret[i][j] = max(ret[i][j], 1 + Dfs(grid, ret, x, y));
//            }
//        }
//        ret[i][j] = max(1, ret[i][j]);//可能出现四周都不能接上，此刻i，j位置还是为-1，将其改为1标志已经计算过此处
//        return ret[i][j];
//    }
//};