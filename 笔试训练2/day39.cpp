#define _CRT_SECURE_NO_WARNINGS


//�������ĸ������
//#include <iostream>
//#include<string>
//#include<unordered_map>
//using namespace std;
//
//int main() {
//    string s;
//    unordered_map<char, int> hash;
//    while (cin >> s) {
//        for (auto& ch : s) {
//            ++hash[ch];
//        }
//    }
//    char ret;
//    int count = 0;
//    for (auto& [ch, num] : hash) {
//        if (num > count) {
//            ret = ch;
//            count = num;
//        }
//    }
//    cout << ret << endl;
//    return 0;
//}



//�ַ����루����û��������⣬ûע��������룬�ʼ���е�ӡ���������ˣ�״̬�е�
//#include <iostream>
//#include<string>
//#include <ostream>
//#include<queue>
//#include<unordered_map>
//using namespace std;
//
//int main() {
//    //ͳ��ÿ���ַ�������ΪȨֵ����ͨ������������Ȩ·�������������ַ�������  
//    string s;
//    while (cin >> s) {
//        unordered_map<char, long long> hash;
//        for (auto& ch : s)
//            ++hash[ch];
//        if (hash.size() ==
//            1) { //ֻ��һ���ַ�ֱ�ӷ��أ���Ϊ������ȡ��������СȨֵ�ڵ㣬���Բ��ܼ���
//            cout << 1 << endl;
//            return 0;
//        }
//        priority_queue<long long, vector<long long>, greater<>>
//            heap;//�ѣ�����ȡ����ǰ��С���ڵ�Ȩֵ�������ڵ�
//        for (auto& [x, y] : hash)
//            heap.push(y);
//        long long ret = 0;
//        while (heap.size() > 1) {
//            long long a = heap.top();
//            heap.pop();
//            long long b = heap.top();
//            heap.pop();
//            ret += a + b;
//            heap.push(a + b);
//        }
//        cout << ret << endl;
//    }
//
//    return 0;
//}




//���ٵ���ȫƽ������һ��ʼ�븴���ˣ���Ϊ�Ǳ���dp��˼·��������
//#include <iostream>
//#include<vector>
//#include<cmath>
//using namespace std;
//
//int main() {
//    //��̬�滮��dp[i]Ϊ��i����С������
//    //dp[i] = min[dp[i] + d[0], dp[i - 1] + dp[1], ...]
//    int n = 0;
//    cin >> n;
//    vector<int> dp(n + 1);
//    dp[0] = 0;
//    for (int i = 1; i <= n; ++i) {
//        double temp = sqrt(i);
//        if (temp == (int)temp)//��ǰi��Ϊ��ȫƽ������ֱ�����ٴ���Ϊ1
//        {
//            dp[i] = 1;
//            continue;
//        }
//        for (int j = i - 1; j >= (i + 1) / 2; --j) {
//            if (dp[i])
//                dp[i] = min(dp[i], dp[j] + dp[i - j]);
//            else
//                dp[i] = dp[j] + dp[i - j];
//        }
//    }
//    cout << dp[n] << endl;
//    return 0;
//}