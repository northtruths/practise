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