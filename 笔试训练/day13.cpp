#define _CRT_SECURE_NO_WARNINGS



//#include <cstdio>
//#include<iostream>
//using namespace std;
//
//int main()
//{
//    int T = 0;
//    cin >> T;
//    while (T--)
//    {
//        int n = 0, k = 0;
//        cin >> n >> k;
//        getchar();
//        int count = 0;//��ʤ����
//        int num = 0;
//        while (n--)
//        {
//            char ch = getchar();
//            cout << ch << endl;
//            if (ch == 'W')
//            {
//                ++count;
//                if (count >= 3)
//                {
//                    num += k;
//                }
//                else {
//                    ++num;
//                    count = 0;
//                }
//            }
//            else {
//                --num;
//            }
//
//        }
//        //cout << num << endl;
//        getchar();
//    }
//    return 0;
//}





#include <climits>
#include <vector>
#include<iostream>
using namespace std;

class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     *
     * @param arr int����vector the array
     * @return int����
     */
    int maxLength(vector<int>& arr) {
        int ret = 0;
        int min = INT_MAX;
        int max = INT_MIN;
        pair<vector<int>, vector<int>> v;
        for (int i = 0; i < arr.size(); ++i)
        {

            if (min <= arr[i] && arr[i] <= max)
            {
                for (int j = 0; j < v.first.size(); ++j)
                {
                    if (v.first[j] == arr[i])
                    {
                        ret = v.first.size() > ret ? v.first.size() : ret;
                        i = v.second[j] + 1;
                        v.first.clear();
                        v.second.clear();
                        min = INT_MAX;
                        max = INT_MIN;
                        if (arr[i] > max) max = arr[i];
                        if (arr[i] < min) min = arr[i];
                        break;
                    }
                }
            }
            else
            {
                if (arr[i] > max) max = arr[i];
                if (arr[i] < min) min = arr[i];
            }
            v.first.push_back(arr[i]);
            v.second.push_back(i);
        }
        if (!v.first.empty())
        {
            ret = v.first.size() > ret ? v.first.size() : ret;
        }
        return ret;
    }
};


int main()
{
    vector<int> arr = { 7, 9, 10, 12, 7, 11, 5, 4 };
    Solution s;
    cout << s.maxLength(arr) << endl;
    return 0;
}