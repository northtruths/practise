#define _CRT_SECURE_NO_WARNINGS

//1.����ͳ��
//#include<iostream>
//using namespace std;
//int main()
//{
//    int ret = 0;
//    int L = 0, R = 0;
//    cin >> L >> R;
//    for (int i = L; i <= R; ++i)
//    {
//        int cur = i;
//        while (cur)
//        {
//            if (cur % 10 == 2)
//                ++ret;
//            cur /= 10;
//        }
//    }
//    cout << ret << endl;
//    return 0;
//}



//��������Ľ���
//class Solution {
//public:
//    /**
//     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
//     *
//     *
//     * @param nums1 int����vector
//     * @param nums2 int����vector
//     * @return int����vector
//     */
//    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
//        vector<int> ret;
//        unordered_map<int, int> map1;
//        unordered_map<int, int> map2;
//
//        for (auto& e : nums1)
//            ++map1[e];
//        for (auto& e : nums2)
//            ++map2[e];
//        for (auto& e : map1)
//        {
//            if (map2.count(e.first))
//                ret.push_back(e.first);
//        }
//        return ret;
//    }
//};



//�������
//#include <iostream>
//#include<string>
//#include<vector>
//using namespace std;
//
//int main() {
//    string s;
//    cin >> s;
//    vector<int> map(s.size(), 0);//�ж�λ��i�Ƿ�ɾ��
//    for (int i = 0; i < s.size(); ++i)
//    {
//        if (i + 1 < s.size() && map[i] == 0 && map[i + 1] == 0 && s[i] == s[i + 1])
//        {
//            map[i] = map[i + 1] = 1;
//            int left = i - 1; int right = i + 2;
//            while (left >= 0 && map[left])
//                --left;
//            while (right < s.size() && map[right])
//                ++right;
//            while (left >= 0 && right < s.size())
//            {
//                if (s[left] == s[right])
//                {
//                    map[left] = map[right] = 1;
//                    ++i;
//                    while (map[left])
//                        --left;
//                    while (map[right])
//                        ++right;
//                }
//                else {
//                    break;
//                }
//            }
//            ++i;
//        }
//    }
//    string ret;
//    for (int i = 0; i < s.size(); ++i)
//    {
//        if (map[i] == 0)
//            ret += s[i];
//    }
//    if (ret.size())
//        cout << ret << endl;
//    else
//        cout << 0 << endl;
//}