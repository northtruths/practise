#define _CRT_SECURE_NO_WARNINGS



//������Ӵ�
//#include<iostream>
//#include<string>
//
//using namespace std;
//
//#include <iterator>
//class Solution {
//public:
//    /**
//     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
//     *
//     *
//     * @param A string�ַ���
//     * @return int����
//     */
//    bool juge(string& s, int i, int j)
//    {
//        while (i <= j)
//        {
//            if (s[i] != s[j])
//                return false;
//            ++i;
//            --j;
//        }
//        return true;
//    }
//    int getLongestPalindrome(string A) {
//        int ret = 0;
//        for (int i = 0; i < A.size(); ++i)
//        {
//            int count = 0;//0��Ŀǰ�����ǻ��ģ�1Ϊ���γɻ��ĵ����ܸ�����2Ϊ�γɻ��ĺ��ǻ����˸ô���һ���ַ���ʼ�ж���
//            for (int j = i + 1; j < A.size(); ++j)
//            {
//                if (juge(A, i, j) && count < 2)
//                {
//                    if (count == 0)
//                        count = 1;
//                    ret = j - i + 1 > ret ? j - i + 1 : ret;
//                }
//                else
//                {
//                    if (count == 1)
//                        break;
//                }
//            }
//        }
//        if (ret == 0) ++ret;
//        return ret;
//    }
//};




////2.
//#include <climits>
//#include<iostream>
//#include<vector>
//using namespace std;
//
//int main()
//{
//    int n;
//    cin >> n;
//    vector<int> v;
//    for (int i = 0; i < n; ++i)
//    {
//        int a;
//        cin >> a;
//        v.push_back(a);
//    }
//    int ret = 0;
//    int min_cur = INT_MAX;
//    for (int i = 0; i < n; ++i)
//    {
//        if (v[i] < min_cur)
//        {
//            min_cur = v[i];
//        }
//        ret = max(v[i] - min_cur, ret);
//    }
//    cout << ret << endl;
//    return 0;
//}