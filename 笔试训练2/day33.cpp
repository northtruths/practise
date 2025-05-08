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



//包含不超过两种字符的最长子串（未ac，70%）
//#include <iostream>
//#include<string>
//using namespace std;
//
//int main(){
//    string s;
//    cin >> s;
//    int ret = 1;
//    int pre = 1;//前面字符串长度
//    int i = 1;
//    while(i < s.size()){
//        if(s[i] != s[i - 1]){
//            break;
//        }
//        ++i;
//    }
//    pre = i;
//    ret = i;
//    while(i < s.size()){
//        int j = i + 1;
//        while(j < s.size()){
//            if(s[j] != s[j - 1])
//                break;
//            ++j;
//        }
//        int cur = j - i;
//        ret = max(ret, pre + cur);
//        pre = cur;
//        i =  j;
//    }
//    
//    cout << ret << endl;
//    return 0;
//}


//字符串的排列（未ac，时间空间复杂度O(n!)）