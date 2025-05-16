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



#include <iostream>
#include<queue>
using namespace std;

int main() {
    int n;
    cin >> n;
    //建个小堆，每次取两个，pair的second表示当前的树的高度
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
    for (int i = 0; i < n; ++i)
    {
        int temp = 0;
        cin >> temp;
        heap.push({ temp, 1 });
    }
    while (heap.size() > 1) {
        auto& a = heap.top();
        heap.pop();
        auto& b = heap.top();
        heap.pop();
        heap.push({ a.first * a.second + b.first * b.second, a.second + 1 });
    }
    cout << heap.top().first << endl;
    return 0;
}