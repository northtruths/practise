#define _CRT_SECURE_NO_WARNINGS


//kotori和气球（数学题）
//#include <iostream>
//using namespace std;
//
//int main() {
//    int n = 0, m = 0;
//    cin >> n >> m;
//    long long ret = n;
//    for (int i = 1; i < m; ++i) {
//        ret = ret * (n - 1) % 109;
//    }
//    cout << ret << endl;
//    return 0;
//}




#include <iostream>
#include<vector>
#include<string>
using namespace std;
int n, m;
int begin_x, begin_y, end_x, end_y;

void dfs(vector<string>& grid, vector<vector<int>>& hash, int(&dir)[4][2], int x, int y, int& ret, int cur) {
    if (x < 0 || x >= n || y < 0 || y >= m || hash[x][y])
        return;
    if (grid[x][y] == '*')
        return;
    if (x == end_x && y == end_y) {
        ret = min(ret, cur);
        return;
    }
    hash[x][y] = true;
    for (auto& e : dir) {
        dfs(grid, hash, dir, x + e[0], y + e[1], ret, cur + 1);
    }
    hash[x][y] = false;
}

int main() {
    //dfs遍历即可
    cin >> n >> m;
    cin >> begin_x >> begin_y >> end_x >> end_y;
    vector<string> grid(n);
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }
    int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
    int ret = 0x3f3f3f3f;
    vector<vector<int>> hash(n, vector<int>(m));
    dfs(grid, hash, dir, begin_x, begin_y, ret, 0);

    cout << (ret == 0x3f3f ? -1 : ret) << endl;
    return 0;
}