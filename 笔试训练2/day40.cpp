#define _CRT_SECURE_NO_WARNINGS


//游游的字母串
//#include <iostream>
//#include<vector>
//#include<string>
//using namespace std;
//
//int main() {
//    //遍历26遍，查看变哪个字母的操作最少
//    //变的字符次数分两种情况，当前字符大于所变字符和当前字符小于所变字符
//    //不论那种都是取要么顺着变要么逆着变的较小值
//    string s;
//    cin >> s;
//    int ret = 0x3f3f3f3f;
//    int cur = 0;//变当前字符的操作次数
//    for (char ch = 'a'; ch <= 'z'; ++ch) {//当前要变的字符
//        cur = 0;
//        for (auto& e : s) {
//            if (e <= ch)//若当前字符在所变字符前面
//                cur += min(ch - e, 'z' - ch + e - 'a' + 1);
//            else
//                cur += min(e - ch, 'z' - e + ch - 'a' + 1);
//        }
//        ret = min(ret, cur);
//    }
//    cout << ret << endl;
//    return 0;
//}