#define _CRT_SECURE_NO_WARNINGS


//打怪
//#include <iostream>
//#include<cmath>
//using namespace std;
//
//int main() {
//    int t = 0;
//    cin >> t;
//    while (t--) {
//        int h, a, H, A;
//        cin >> h >> a >> H >> A;
//        if (A <= 0 || a >= H) {
//            cout << -1 << endl;
//        }
//        else {
//            int x = ceil((double)H / a);//击败一个怪物需要的回合数
//            int y = A * (x - 1);//击败一个怪物需要消耗的血量
//            int ret = floor((double)h / y);
//            if (h - ret * y <= 0)
//                --ret;
//            cout << ret << endl;
//        }
//    }
//    return 0;
//}


//字符串的分类
//#include <iostream>
//#include<string>
//#include<unordered_set>
//#include<algorithm>
//using namespace std;
//
//int main() {
//    int n = 0;
//    cin >> n;
//    unordered_set<string> ret;
//    while (n--) {
//        string s;
//        cin >> s;
//        sort(s.begin(), s.end());
//        ret.insert(s);
//    }
//    cout << ret.size() << endl;
//    return 0;
//}


//NC345 城市群数量（未ac，看题解说是图论，于是打算快点把图论基础学了再自己先尝试）
//赶紧学了图论基础后，成功ac（笑）
//class Solution {
//public:
//    /**
//     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
//     *
//     *
//     * @param m int整型vector<vector<>>
//     * @return int整型
//     */
//    int citys(vector<vector<int> >& m) {
//        //创建一个图，然后遍历，hash记录是否走过
//        //每一个节点的遍历，都会让其连通子树被遍历
//        int n = m.size();
//        vector<vector<int>> hash(n, vector<int>(n, false));
//        int ret = 0;
//        for (int i = 0; i < n; ++i) {
//            if (dfs(m, hash, i))
//                ++ret;
//        }
//        return ret;
//    }
//
//    bool dfs(vector<vector<int> >& m, vector<vector<int> >& hash, int cur) {
//        //cur就为第几个节点(减一)
//        int flag = 0;//判断是否有还没有计算的城市群
//        for (int i = 0; i < m.size(); ++i) {
//            if (hash[cur][i] == false && m[cur][i] == 1) {
//                flag = 1;
//                hash[cur][i] = hash[i][cur] = true;
//                dfs(m, hash, i);
//            }
//        }
//        return flag;
//    }
//};