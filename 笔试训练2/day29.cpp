#define _CRT_SECURE_NO_WARNINGS


//����������
//#include <iostream>
//#include<vector>
//using namespace std;
//
//int main() {
//    int n;
//    cin >> n;
//    vector<int> arr(n);
//    for (int i = 0; i < n; ++i)
//        cin >> arr[i];
//    int mod = 0;//1��ʾ��ǰΪ����2��,0��ȷ��
//    int ret = 0;
//    for (int i = 1; i < n; ++i) {
//        while (i < n && arr[i] == arr[i - 1])
//            ++i;
//        if (i >= n)
//            break;
//        if (mod == 0) {
//            if (arr[i] > arr[i - 1])
//                mod = 1;
//            else
//                mod = 2;
//            ++ret;
//        }
//        else if (mod == 1 && arr[i] < arr[i - 1])
//            mod = 0;
//        else if (mod == 2 && arr[i] > arr[i - 1])
//            mod = 0;
//    }
//    if (mod == 0)
//        ++ret;
//    cout << ret << endl;
//    return 0;
//}



//��������
//#include<iostream>
//#include<cmath>
//using namespace std;
//
//int MinTimes(int h) {
//    int n = 0;
//    int sub = 0;
//    while (sub + pow(2, n) <= h) {
//        sub += pow(2, n);
//        ++n;
//    }
//    --n;
//    int ret = n + 1;
//    h -= sub;
//    for (n; n >= 0 && h > 0; --n) {
//        sub = pow(2, n);
//        if (h >= sub) {
//            h -= sub;
//            ++ret;
//        }
//    }
//    return ret;
//}
//
//int main() {
//    //̰�ģ�ÿ������2^0��2^1��...��2^n�ĺͣ�ʹ��պ�С��h���Ҽ���2^(n+1)�ͻ����h
//    //��Ϊ��ʹ�ø���ľ��ø���ģ�������С��ʼ���ܱ�һ���ϴ���滻
//    //֮���2^n��2^0��h�����ھͼ�ȥ
//    int t = 0;
//    cin >> t;
//    while (t--) {
//        int h = 0;
//        cin >> h;
//        cout << MinTimes(h) << endl;
//    }
//    return 0;
//}



//����������У�������������ac���Ѿ��������⣬��Ϊ�ǽ����Ż������������ˣ����ⲻ����ͼ��������Ҫ���������ʵ����ģ�������
//class Solution {
//public:
//    /**
//     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
//     *
//     * ��������ϸ����������еĳ���
//     * @param a int����vector ����������
//     * @return int����
//     */
//    int LIS(vector<int>& a) {
//        //̰��+����
//        //��ͼ����������ǰ����ͬ�����У������ж���ܽ��ϵ�Ԫ�أ���Ȼ�ǽ���С�����
//        //һ�������¼����Ϊi������£�ĩβ�����ֵ
//        //����ǰԪ�ش�����������Ԫ�أ����������������ҵ���һ�����ڵ��ڵ�ǰԪ�ص�λ�ã������滻
//        int n = a.size();
//        if (n == 0)  return 0;
//        vector<int> dp;
//        dp.push_back(a[0]);
//        for (int i = 0; i < n; ++i) {
//            if (a[i] > dp[dp.size() - 1]) {
//                dp.push_back(a[i]);
//                continue;
//            }
//            int left = 0, right = dp.size() - 1;
//            while (left <= right) {
//                int mid = (left + right) >> 1;
//                if (dp[mid] == a[i])//�����ֵ��ֱ���滻����������
//                    break;
//                else if (dp[mid] > a[i]) right = mid - 1;
//                else left = mid + 1;
//            }
//            if (left > right) {//��ʱ������û����a[i]Ϊ��β�����У����Խ����滻���滻λ��Ϊleft
//                dp[left] = a[i];
//            }
//        }
//        return dp.size();
//    }
//};