#define _CRT_SECURE_NO_WARNINGS

//平方数
//#include<iostream>
//#include<cmath>
//using namespace std;
//
//int main() {
//    long long x = 0;
//    cin >> x;
//    double k = sqrt(x);
//    long long a = ceil(k);
//    long long b = floor(k);
//    if (abs(a * a - x) < abs(b * b - x))
//        cout << a * a << endl;
//    else
//        cout << b * b << endl;
//    return 0;
//}



//分组（未ac，10%）
//#include <iostream>
//#include<queue>
//#include<unordered_map>
//using namespace std;
//
//int main() {
//    //贪心：开始先将会同一声部的人分在同一组，然后每次将当前人数最多的组分一半到空的组
//    //能分配的次数等于 m - 初始分配的组数
//    unordered_map<int, int> hash;
//    int n, m;
//    cin >> n >> m;
//    for (int i = 0; i < n; ++i) {
//        int in = 0;
//        cin >> in;
//        ++hash[in];
//    }
//    if (hash.size() > m) {
//        cout << -1 << endl;
//        return 0;
//    }
//    int k = m - hash.size();//可分配次数
//    priority_queue<int> heap;
//    for (auto& e : hash)
//        heap.push(e.second);
//    while (k--) {
//        int temp = (heap.top() + 1) / 2;
//        heap.pop();
//        heap.push(temp);
//    }
//    cout << heap.top() << endl;
//    return 0;
//}


//【模板】拓扑排序（未ac，还没学图论，不会）