#define _CRT_SECURE_NO_WARNINGS



//��ֵ
//#include <climits>
//#include <iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//int main() {
//    //������������սʿһ�������Ǽ���ӽ��ģ��ҳ�������ӽ��ļ���
//    int n;
//    cin >> n;
//    vector<int> nums(n);
//    for (int i = 0; i < n; ++i)
//        cin >> nums[i];
//    sort(nums.begin(), nums.end());
//    int ret = INT_MAX;
//    for (int i = 1; i < n; ++i)
//        ret = min(ret, nums[i] - nums[i - 1]);
//    cout << ret << endl;
//    return 0;
//}





//kotori�������ӣ�δac��80%��
//#include <iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//bool IsPrime(int n) {
//    if (n <= 1) return false;
//    if (n <= 3) return true;  // 2��3������
//    if (n % 2 == 0 || n % 3 == 0) return false;  // �ų��ܱ�2��3��������
//
//    // ֻ��Ҫ���6n��1��ʽ������
//    for (int i = 5; i * i <= n; i += 6) {
//        if (n % i == 0 || n % (i + 2) == 0) {
//            return false;
//        }
//    }
//    return true;
//}
//
//void FindPrime(int x, vector<int>& nums) {
//    for (int i = 2; i <= x; ++i) {
//        if (x % i == 0 && IsPrime(i))
//            nums.push_back(i);
//    }
//}
//
//int main() {
//    int n;
//    cin >> n;
//    vector<int> nums;
//    for (int i = 0; i < n; ++i) {
//        int x = 0;
//        cin >> x;
//        FindPrime(x, nums);
//    }
//    sort(nums.begin(), nums.end());
//    auto it_end = unique(nums.begin(), nums.end());
//    int ret = 0;
//    auto it_begin = nums.begin();
//    for (auto& e : nums)
//        cout << e << ' ';
//    cout << endl;
//    while (n && it_begin != it_end) {
//        ret += *it_begin;
//        ++it_begin;
//        --n;
//    }
//    if (n)
//        cout << -1 << endl;
//    else
//        cout << ret << endl;
//    return 0;
//}





//dd����ѧ1.0
//#include <iostream>
//#include<vector>
//#include<climits>
//using namespace std;
//
//int main() {
//    //��̬�滮����ά��dp[i][j]Ϊ0~i���ַ������һ������Ϊj����С����
//    //dp[i][j] == dp[i-1][0~j]�е���Сֵ + ��ǰ�ַ���Ϊj�Ĵ���
//    //����dp[i-1][0~25]ʱ��������һ������¼��ǰ����С����Ϊdp[i]��j�ǵ������ߵģ�������ζ�����֮ǰ�ҹ���0~j�������ظ�ȥ��
//    int n;
//    cin >> n;
//    vector<vector<int>> dp(n + 1, vector<int>(26, 0));//��һ�����ڳ�ʼ��
//    for (int i = 1; i <= n; ++i) {
//        char ch = 0;
//        cin >> ch;
//        int cur = INT_MAX;//��ǰ0~j����С
//        for (int j = 0; j < 26; ++j) {
//            cur = min(cur, dp[i - 1][j]);
//            dp[i][j] = cur + (ch == j + 'A' ? 0 : 1);
//        }
//    }
//    int ret = INT_MAX;
//    for (int j = 0; j < 26; ++j)
//        ret = min(ret, dp[n][j]);
//    cout << ret << endl;
//    return 0;
//}