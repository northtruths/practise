#define _CRT_SECURE_NO_WARNINGS



//ѹ���ַ���1��100��
//#include <string>
//class Solution {
//public:
//    /**
//     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
//     *
//     *
//     * @param param string�ַ���
//     * @return string�ַ���
//     */
//    string compressString(string param) {
//        string& s = param;
//        int pre = 0;
//        int cur = 0;
//        string ret;
//        while (pre < s.size())
//        {
//            int count = 0;
//            while (cur < s.size() && s[pre] == s[cur])
//            {
//                ++count;
//                ++cur;
//            }
//            ret += s[pre];
//            if (count > 1)
//            {
//                string add = to_string(count);
//                ret += add;
//            }
//            pre = cur;
//        }
//        return ret;
//    }
//};






//chika���۸̣�40����ʱ��
//#include <climits>
//#include<iostream>
//#include<utility>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//
//bool com(pair<int, int> p1, pair<int, int> p2)
//{
//    return p1.first < p2.first;
//}
//
//int main()
//{
//    int n, k;
//    cin >> n >> k;
//    vector<int> acid(n);
//    vector<int> sweet(n);
//
//    for (int i = 0; i < n; ++i)
//    {
//        cin >> acid[i];
//    }
//    for (int i = 0; i < n; ++i)
//    {
//        cin >> sweet[i];
//    }
//
//    vector<pair<int, int>> ret;//ǰ�����
//    for (int i = 0; i < n; ++i)
//    {
//        if (ret.size() == k)
//        {
//            if (sweet[i] >= ret[0].first)
//            {
//                int s = ret[0].first;
//                int max = INT_MIN;//�ҳ���ǰ�����͵��������
//                int maxi = 0;//��Ӧ�±�
//                int tempi = 0;
//                if (s == ret[1].first)
//                {
//
//                    while (tempi < ret.size() && s == ret[tempi].first)
//                    {
//                        if (ret[tempi].second > max)
//                        {
//                            max = ret[tempi].second;
//                            maxi = tempi;
//                        }
//                        ++tempi;
//                    }
//                }
//                if (sweet[i] == s)
//                {
//                    ret[maxi].second = acid[i] <= ret[maxi].second ? acid[i] : ret[maxi].second;
//                }
//                else
//                {
//                    ret[maxi].first = sweet[i];
//                    ret[maxi].second = acid[i];
//                    sort(ret.begin(), ret.end(), com);
//                }
//            }
//        }
//        else
//        {
//            pair<int, int> p_temp(sweet[i], acid[i]);
//            ret.push_back(p_temp);
//            sort(ret.begin(), ret.end(), com);
//        }
//    }
//    int ret_a = 0;
//    int ret_s = 0;
//    for (int i = 0; i < k; ++i)
//    {
//        ret_s += ret[i].first;
//        ret_a += ret[i].second;
//    }
//    cout << ret_a << " " << ret_s << endl;
//    return 0;
//}