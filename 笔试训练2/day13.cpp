#define _CRT_SECURE_NO_WARNINGS


//牛牛冲钻五
//#include<iostream>
//using namespace std;
//int main() {
//    int t = 0;
//    cin >> t;
//    while (t--) {
//        int n, k;
//        cin >> n >> k;
//        int flag = 0;//当前连胜场数
//        int ret = 0;
//        while (n--) {
//            char ch = 0;
//            cin >> ch;
//            if (ch == 'W') {
//                ++flag;
//                if (flag >= 3)
//                    ret += k;
//                else
//                    ret += 1;
//            }
//            else {
//                flag = 0;
//                ret -= 1;
//            }
//        }
//        cout << ret << endl;
//    }
//    return 0;
//}


//最长无重复子数组
//class Solution {
//public:
//    /**
//     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
//     *
//     *
//     * @param arr int整型vector the array
//     * @return int整型
//     */
//    int maxLength(vector<int>& arr) {
//        //滑动窗口
//        //哈希记录状态，若当前这个已经有了，从窗口开头一直删除直到删除相同
//        int ret = 0;
//        int front = 0;//窗口头下标
//        unordered_map<int, int> hash;
//        for (int i = 0; i < arr.size(); ++i) {
//            //当前长度就为 i - front + 1
//            while (hash[arr[i]]) {//前面已有
//                --hash[arr[front]];
//                ++front;
//            }
//            ++hash[arr[i]];
//            ret = max(ret, i - front + 1);
//        }
//        return ret;
//    }
//};



//重排字符串（未ac，不会）
//#include <iostream>
//using namespace std;
//
//int main() {
//
//}