#define _CRT_SECURE_NO_WARNINGS

//С��Ŀ���
//#include <iostream>
//#include<queue>
//using namespace std;
//
//int main() {
//    //һ��С�ѽ��
//    int n, k;
//    cin >> n >> k;
//    priority_queue<long long, vector<long long>, greater<>> heap;
//    for (int i = 0; i < n; ++i) {
//        long long temp = 0;
//        cin >> temp;
//        heap.push(temp);
//    }
//    long long cur = 0;//�����ʶ��ܺ�
//    int day = 0;
//    while (cur <= k) {
//        cur += heap.top();
//        long long  add = heap.top() * 2;
//        heap.pop();
//        heap.push(add);
//        if (cur <= k)
//            ++day;
//    }
//    cout << day << endl;
//    return 0;
//}


//���Σ�������⡢���ϡ����۵ȵȣ����Աȴ�����������ˣ��ܼ򵥵�һ�⣬���Ǳ߽�����һֱû���ǵ���һֱ���Ժ�һ��ע������ط��ı߽�������
//#include <iostream>
//using namespace std;
//
//int main() {
//    //̰�ģ��ȿ�����ʱ�ĸ����㣬�ٿ���Ӧʣ�µ���������
//    int t = 0;
//    cin >> t;
//    while (t--) {
//        long long n, a, b;
//        cin >> n >> a >> b;
//        long long ret = 0;
//        if (n <= 2)
//            ret += min(a, b);
//        else if (3 * a < 2 * b) {
//            ret += n / 2 * a;
//            if (n % 2 == 1) {
//                ret += min(min(a, b), b - a);
//            }
//        }
//        else {
//            ret += n / 3 * b;
//            if (n % 3 == 1) {
//                ret += min(min(a, b), a + a - b);
//            }
//            else if (n % 3 == 2) {
//                ret += min(min(a, b), a + a + a - b);
//            }
//        }
//        cout << ret << endl;
//    }
//    return 0;
//}


//��λȾɫ
//#include <iostream>
//#include <linux/limits.h>
//#include<vector>
//using namespace std;
//
//int main() {
//    //Ѱ����λ�Ƿ��ܴﵽ�ܺ͵�һ��
//    //��λ�������18λ������С����������
//    long long x = 0;
//    cin >> x;
//    vector<int> nums;
//    double sum = 0;
//    while (x) {
//        int temp = x % 10;
//        sum += temp;
//        nums.push_back(temp);
//        x /= 10;
//    }
//    sum /= 2;
//    if (sum != (int)sum) {
//        cout << "No" << endl;
//        return 0;
//    }
//    //dpΪֻ��ǰiλ�����Ƿ���Ϊj
//    vector<bool> dp(sum + 1);
//    dp[0] = true;
//    for (int i = 0; i < nums.size(); ++i) {
//        for (int j = sum; j >= 0; --j) {
//            if (j - nums[i] >= 0)
//                dp[j] = dp[j] || dp[j - nums[i]] ? true : false;
//        }
//    }
//    if (dp[sum]) {
//        cout << "Yes" << endl;
//    }
//    else {
//        cout << "No" << endl;
//    }
//    return 0;
//}