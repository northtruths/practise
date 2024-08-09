#define _CRT_SECURE_NO_WARNINGS



//添加字符
//#include<iostream>
//#include<string>
//#include<limits.h>
//using namespace std;
//
//int main()
//{
//    string A;
//    string B;
//    cin >> A >> B;
//    int ret = INT_MAX;
//    for (int i = 0; i <= B.size() - A.size(); ++i)
//    {
//        int cur = 0;
//        int curi = 0;
//        for (int j = i; j < i + A.size(); ++j)
//        {
//
//            if (A[curi] != B[j])
//            {
//                ++cur;
//            }
//            ++curi;
//        }
//        ret = cur < ret ? cur : ret;
//    }
//    cout << ret << endl;
//    return 0;
//}




//数组变换(一个数组，通过乘二变换，看能不能让所有数相等)（完全不会）




//装箱问题（背包问题？不会）
//#include <climits>
//#include <functional>
//#include<iostream>
//#include<algorithm>
//#include<vector>
//using namespace std;
//
//int main()
//{
//    int m, n;
//    cin >> m >> n;
//    vector<int> v(n);
//    for (int i = 0; i < n; ++i)
//    {
//        cin >> v[i];
//    }
//    int ret = INT_MAX;
//    sort(v.begin(), v.end(), greater<int>());
//    for (int i = 0; i < n; ++i)
//    {
//        int cur = 0;
//        for (int j = i; j < n; ++j)
//        {
//            cur = v[i];
//            for(int k = j + 1; k < n; ++k)
//            {
//                if (cur + v[k] <= m)
//                {
//                    cur += v[k];
//                    if (cur == m)
//                    {
//                        cout << 0 << endl;
//                        return 0;
//                    }
//                }
//                else
//                {
//                    continue;
//                }
//            }
//            ret = cur < ret ? cur : ret;
//        }
//
//    }
//    cout << ret << endl;
//    return 0;
//}