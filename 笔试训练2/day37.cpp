#define _CRT_SECURE_NO_WARNINGS





#include <iostream>
#include<vector>
using namespace std;

int n, m;
int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

int Dfs(vector<vector<int>>& grid, vector<vector<int>>& dp, int i, int j) {
    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    for (auto& e : dir) {
        int x = i + e[0];
        int y = j + e[1];
        if (0 <= x && x < n && 0 <= y && y < m && grid[x][y] < grid[i][j]) {
            dp[i][j] = max(dp[i][j], 1 + Dfs(grid, dp, x, y));
        }
    }
    dp[i][j] = max(1, dp[i][j]);
    return dp[i][j];
}

int main() {
    //dfs+剪枝（记忆化搜索）
    //dp[i][j]表示从位置(i, j)位置开始的最长线路
    //dp[i][j]查看四周是否有小于当前并且能直接接上的，能就直接接上
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }
    vector<vector<int>> dp(n, vector<int>(m, -1));//-1表示未来过    
    int ret = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            ret = max(ret, Dfs(grid, dp, i, j));
        }
    }
    cout << ret << endl;
    return 0;
}

