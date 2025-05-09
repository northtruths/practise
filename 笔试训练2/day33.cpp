#define _CRT_SECURE_NO_WARNINGS

//跳台拓展问题
//#include <iostream>
//using namespace std;
//
//int main() {
//    //举例模拟
//    int n;
//    cin >> n;
//    cout << (1 << (n - 1)) << endl;
//    return 0;
//}



//包含不超过两种字符的最长子串（看标签、题解、搞了半天后才ac，还是细节没把控好，这次是把控不好，因为控制细节的方式选错了，类似代码框架没搞好，
// 并且开始做时题意都没完全理解，导致开始思考的方向就有问题）
//#include <iostream>
//#include<string>
//#include<unordered_map>
//using namespace std;
//
//int main() {
//    //滑动窗口
//    //维护窗口，用一个count记录当前字符种数，判断种数是否增减，用一个哈希表，当加减后变化为1、0则说明有加减
//    string s;
//    cin >> s;
//    int left = 0, right = 0;//满足条件的子串左右
//    int hash[26] = { 0 };
//    int count = 0;//字符种数
//    int ret = 0;
//    while (right < s.size()) {
//        if (++hash[s[right] - 'a'] == 1)
//            ++count;
//        if (count > 2)
//            ret = max(ret, right - left);
//        while (right < s.size() && count > 2) {
//            if (--hash[s[left] - 'a'] == 0)
//                --count;
//            ++left;
//        }
//        ++right;
//    }
//    ret = max(ret, right - left);
//    cout << ret << endl;
//    return 0;
//}


//字符串的排列（未ac，时间空间复杂度O(n!)）