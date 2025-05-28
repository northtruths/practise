#define _CRT_SECURE_NO_WARNINGS



//kanan和高音
//#include <iostream>
//#include<vector>
//using namespace std;
//
//int main() {
//    //遍历一遍即可
//    int n;
//    cin >> n;
//    vector<int> nums(n);
//    for (int i = 0; i < n; ++i)
//        cin >> nums[i];
//    int ret = 0;
//    int left = 0, right = 1;//双指针遍历，便于计算
//    while (right < n) {
//        if (nums[right] - nums[right - 1] >= 9) {
//            ret = max(ret, right - left);
//            left = right;
//        }
//        ++right;
//    }
//    ret = max(ret, right - left);
//    cout << ret << endl;
//    return 0;
//}




//拜访（未ac，50%）
//#include <queue>
//class Solution {
//public:
//    /**
//     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
//     *
//     *
//     * @param CityMap int整型vector<vector<>>
//     * @param n int整型
//     * @param m int整型
//     * @hashurn int整型
//     */
//    int countPath(vector<vector<int> >& CityMap, int n, int m) {
//        //层序遍历
//        int bx = 0, by = 0;//开始位置
//        for (int i = 0; i < n; ++i) {
//            for (int j = 0; j < m; ++j) {
//                if (CityMap[i][j] == 1) {
//                    bx = i, by = j;
//                    goto end;
//                }
//            }
//        }
//    end:
//        queue<pair<int, int>> q;
//        q.push({ bx, by });
//        vector<vector<int>> hash(n, vector<int>(m,
//            -1)); //hash为到(i,j)位置的最小步数
//        hash[bx][by] = 0;
//        int ex = 0, ey = 0;//结束位置
//        while (q.size()) {
//            int cur_size = q.size();//当前层
//            while (cur_size--) {
//                auto& [i, j] = q.front();
//                if (CityMap[i][j] == 2)
//                    ex = i, ey = j;
//                for (auto& e : dir) {
//                    int x = i + e[0];
//                    int y = j + e[1];
//                    if (0 <= x && x < n && 0 <= y && y < m && CityMap[x][y] != -1 &&
//                        hash[x][y] == -1) {
//                        hash[x][y] = hash[i][j] + 1;
//                        q.push({ x, y });
//                    }
//                }
//                q.pop();
//            }
//        }
//
//        int ret = 0;
//        int ret_min = 0x3f3f3f3f;
//        for (auto& e : dir) {
//            int x = ex + e[0];
//            int y = ey + e[1];
//            if (0 <= x && x < n && 0 <= y && y < m && hash[x][y] != -1) {
//                if (hash[x][y] < ret_min) {
//                    ret = 1;
//                    ret_min = hash[x][y];
//                }
//                else if (hash[x][y] == ret_min)
//                    ++ret;
//            }
//        }
//        return ret;
//    }
//
//private:
//    int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
//};






//买卖股票的最好时机（四）（完全没状态，不会）