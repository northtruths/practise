#define _CRT_SECURE_NO_WARNINGS


//提取不重复的整数
//#include <iostream>
//#include<cmath>
//using namespace std;
//
//int main() {
//    int n;
//    cin >> n;
//    int hash[10] = { 0 };//数字的哈希表
//    while (n) {
//        int cur = n % 10;
//        if (hash[cur] == 0) {
//            ++hash[cur];
//            cout << cur;
//        }
//        n /= 10;
//    }
//    return 0;
//}


//AB32 哈夫曼编码
//#include <iostream>
//#include<queue>
//using namespace std;
//
//int main() {
//    int n;
//    cin >> n;
//    priority_queue<long long, vector<long long>, greater<>> heap;
//    for (int i = 0; i < n; ++i)
//    {
//        int temp = 0;
//        cin >> temp;
//        heap.push(temp);
//    }
//    long long ret = 0;
//    while (heap.size() > 1) {
//        long long a = heap.top();
//        heap.pop();
//        long long b = heap.top();
//        heap.pop();
//        ret += (a + b);
//        heap.push(a + b);
//    }
//    cout << ret << endl;
//    return 0;
//}



//DP36 abb（看题解后ac，真的又是临门一脚，细节又没想清楚，已经和正确答案差一丝丝，不知道为什么老是这样，是缺乏自我思考纠错能力，还是单纯太疲倦没法集中精神？）
//#include <iostream>
//#include<string>
//#include<vector>
//using namespace std;
//
//int main() {
//    //动态规划，一个数组hash记录i之前以某个字符为结尾的ab型，一个数组count记录i之前的每个字母出现的个数
//    //以当前字符为结尾的abb型等于hash所记录的对应数量，
//    //然后以count更新hash->以当前字母结尾的ab型等于i-count记录的字母个数 + 之前以记录的，然后更新count（当前字母++）
//    int n;
//    cin >> n;
//    string s;
//    cin >> s;
//    vector<long long> hash(26, 0);
//    vector<long long> count(26, 0);
//    long long ret = 0;
//    for (int i = 0; i < n; ++i) {
//        ret += hash[s[i] - 'a'];
//        hash[s[i] - 'a'] += i - count[s[i] - 'a'];
//        ++count[s[i] - 'a'];
//    }
//    cout << ret << endl;
//    return 0;
//}