#define _CRT_SECURE_NO_WARNINGS



//kotori�ͳ鿨��������ֱ���ҵ�������ϵĴ���ac��֪����ô�����벻����ô������������ˣ��˶���̫���ˣ�ֱ�������Ĵ���������˼����
//#include<iostream>
//#include<vector>
//#include<cmath>
//using namespace std;
//unsigned long long combination(int n, int k) {
//    if (k < 0 || k > n) return 0;
//    if (k == 0 || k == n) return 1;
//    if (k > n - k) k = n - k; // �Ż����㣬���� C(n, k) = C(n, n-k)
//
//    unsigned long long res = 1;
//    for (int i = 1; i <= k; ++i) {
//        res *= (n - k + i);
//        res /= i;
//    }
//    return res;
//}
//int main() {
//    //��ģ���ó����Ȿ��Ϊ����n��������ѡm��0.8��������Ϊ0.2��ѡ������m��0.8��(n-m)��0.2��Ϊ�ܸ���
//    int n, m;
//    cin >> n >> m;
//
//    unsigned long long a = combination(n, m);
//    long double b = pow(0.8, m);
//    long double c = pow(0.2, n - m);
//    printf("%.4Lf\n", a * b * c);
//    return 0;
//}




//ruby������
//#include <iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//int main() {
//    //̰��+˫ָ��
//    //һ��ָ��ָ��ǰ��С���ȣ�һ��ָ��ָ��պô��ڵ���l��λ�ã�һ��ָ��ָ��պ�С�ڵ���r��λ�õ���һ��λ��
//    //��һ��ָ��ÿ��������һ��(��С���ȱ��)���ڶ���ָ��Ѱ��������������һ��λ��(������ԭ��)��������λ��ͬ��
//    //�ڶ���ָ��͵�����ָ��֮���Ԫ�ؾ��Ǳ��εġ�������߲��ʱ�临�Ӷ�Ϊ nlog(n)+3n = nlog(n)
//    int n, l, r;
//    cin >> n >> l >> r;
//    vector<int> nums(n);
//    for (int i = 0; i < n; ++i)
//        cin >> nums[i];
//    sort(nums.begin(), nums.end());
//
//    int left = 0, right = 0;
//    long long ret = 0;
//    for (int i = 0; i < n; ++i) {
//        while (left < n && nums[left] - nums[i] < l)
//            ++left;
//        while (right < n && nums[right] - nums[i] <= r)
//            ++right;
//        if (left >= n)//left�����������Ŀ�ʼ�������������
//            break;
//        ret += right - left;
//    }
//    cout << ret << endl;
//    return 0;
//}




//ѭ����ŵ��
//#include <iostream>
//#include<vector>
//using namespace std;
//
//int main() {
//    //��̬�滮
//    //dp1[i]Ϊi����Ƭ������һ��������Ҫ�����ٲ�����dp2[i]Ϊi����Ƭ����������������Ҫ�����ٲ���
//    //A->B��dp1[i]��:����ȫ��C��dp2[i-1]���������浽B(1)������ȫ��C�ٵ�B��dp2[i-1]��
//    //A->C��dp2[i]��������ȫ��C��dp2[i-1]���������浽B��1����C��A��dp1[i-1]����B��C��1����A��C��dp2[i-1]��
//    int n;
//    cin >> n;
//    vector<long long> dp1(n + 1);
//    vector<long long> dp2(n + 1);
//    dp1[0] = dp2[0] = 0;
//    for (int i = 1; i <= n; ++i) {
//        dp1[i] = (dp2[i - 1] + 1 + dp2[i - 1]) % 1000000007;
//        dp2[i] = (dp2[i - 1] + 1 + dp1[i - 1] + 1 + dp2[i - 1]) % 1000000007;
//    }
//    cout << dp1[n] << " " << dp2[n] << endl;
//    return 0;
//}




