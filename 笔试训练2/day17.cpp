#define _CRT_SECURE_NO_WARNINGS


//小乐乐改数字
//#include<iostream>
//#include<cmath>
//using namespace std;
//
//int main() {
//    int n = 0;
//    cin >> n;
//    int ret = 0;
//    int index = 0;
//    while (n) {
//        int cur = n % 10;
//        n /= 10;
//        if (cur % 2 == 1)
//            ret += pow(10, index);
//        ++index;
//    }
//    cout << ret << endl;
//    return 0;
//}



//十字爆破
//#include <iostream>
//#include<vector>
//using namespace std;
//
//int main() {
//    int n, m;
//    cin >> n >> m;
//    vector<vector<int>> nums(n, vector<int>(m));
//    vector<long long> row(n);//每一行的和
//    vector<long long> col(m);//每一列的和
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < m; ++j) {
//            scanf("%d", &nums[i][j]);
//            row[i] += nums[i][j];
//            col[j] += nums[i][j];
//        }
//    }
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < m; ++j) {
//            cout << row[i] + col[j] - nums[i][j] << ' ';
//        }
//        cout << endl;
//    }
//    return 0;
//}


//比那名居的桃子
//#include <iostream>
//#include<vector>
//using namespace std;
//
//int main() {
//    //滑动窗口，窗口长度为k
//    int n, k;
//    cin >> n >> k;
//    long long happy = 0;//当前窗口快乐值
//    long long happy_max = 0;;//最大快乐值
//    long long shame = 0;//当前窗口羞耻值
//    long long shame_max = 0;//最大快乐值下的羞耻值
//    int front = 0;//窗口头下标
//    int ret = 0;
//    vector<int> h(n), s(n);
//    for (int i = 0; i < n; ++i)
//        cin >> h[i];
//    for (int i = 0; i < n; ++i)
//        cin >> s[i];
//    for (int i = 0; i < n; ++i) {
//        happy += h[i];
//        shame += s[i];
//        if (i - front + 1 > k) {
//            happy -= h[front];
//            shame -= s[front];
//            ++front;
//        }
//        if (happy > happy_max) {
//            happy_max = happy;
//            shame_max = shame;
//            ret = front;
//        }
//        else if (happy == happy_max) {
//            if (shame < shame_max) {
//                shame_max = shame;
//                ret = front;
//            }
//        }
//    }
//    cout << ret + 1 << endl;
//    return 0;
//}

