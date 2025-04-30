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



//走迷宫
#include<iostream>
#include<vector>
#include<queue>
#include<utility>
using namespace std;

int main() {
    //最短路径，层序遍历
    int n, m;
    cin >> n >> m;
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    --x1, --y1, --x2, --y2;
    vector<string> grid;
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }
    int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
    queue<vector<int>> q;//数组存三个值，x、y和层数
    vector<vector<bool>> hash(n, vector<bool>(m, false));
    q.push({ x1, y1, 0 });
    hash[x1][y1] = true;
    while (!q.empty()) {
        for (auto& e : dir) {
            int x = q.front()[0] + e[0];
            int y = q.front()[1] + e[1];
            if (0 <= x && x < n && 0 <= y && y < m &&
                hash[x][y] == false && grid[x][y] == '.') {
                q.push({ x, y, q.front()[2] + 1 });
                hash[x][y] = true;
            }
            if (x == x2 && y == y2) {
                cout << q.front()[2] + 1 << endl;
                queue<vector<int>> emp;
                swap(q, emp);
                break;
            }
        }
        if (!q.empty())
            q.pop();
    }
    return 0;
}



//主持人调度（二）
//class Solution {
//public:
//    /**
//     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
//     *
//     * 计算成功举办活动需要多少名主持人
//     * @param n int整型 有n个活动
//     * @param startEnd int整型vector<vector<>> startEnd[i][0]用于表示第i个活动的开始时间，startEnd[i][1]表示第i个活动的结束时间
//     * @return int整型
//     */
//    int minmumNumberOfHost(int n, vector<vector<int> >& startEnd) {
//        //先排序，当当前活动的开始时间小于上一个活动的结束时间说明这两个活动不是一个人能完成
//        //创建一个主持人数组，每次遍历这个数组，当没有主持人的结束时间小于当前活动的开始时间，就加一个主持人，
//        //数组的值为主持人主持的上个活动的结束时间
//        sort(startEnd.begin(), startEnd.end(),
//            [&startEnd](vector<int>& x, vector<int>& y) ->bool {return x[0] < y[0]; });
//        vector<int> host;
//        for (int i = 0; i < n; ++i) {
//            int cur_begin = startEnd[i][0], cur_end = startEnd[i][1];
//            int flag = 0;//是否有空闲的主持人
//            for (auto& e : host) {
//                if (e <= cur_begin) {
//                    flag = 1;
//                    e = cur_end;
//                    break;
//                }
//            }
//            if (flag == 0) {
//                host.push_back(cur_end);
//            }
//        }
//
//        return host.size();
//    }
//};