#define _CRT_SECURE_NO_WARNINGS


//平方数（50）
//#include <iostream>
//#include<cmath>
//using namespace std;
//
//int main()
//{
//    //int n = 0;
//    //cin >> n;
//    //while (n--)
//    //{
//        long long x = 0;
//        cin >> x;
//        long double a1 = sqrt(x);
//        long long a2 = ceil(a1);
//        long long a3 = floor(a1);
//        if (a2 == a3)
//        {
//            ++a2;
//            --a3;
//        }
//        long long y = abs(x - pow(a2, 2)) < abs(x - pow(a3, 2)) ? pow(a2, 2) : pow(a3, 2);
//        cout << y << endl;
//   //}
//    return 0;
//}







//分组（10）
//#include <climits>
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//
//int main()
//{
//    int n, m;
//    cin >> n >> m;
//    pair<vector<int>, vector<int>> v;//first存声部，second存对应下标声部的个数
//    v.second.resize(n + 1);
//    for (int i = 0; i < n; ++i)
//    {
//        int t = 0;
//        cin >> t;
//        v.first.push_back(t);
//        ++v.second[t];
//    }
//    int count = 0;//记录有几个声部
//    for (int i = 0; i < n; ++i)
//    {
//        if (v.second[i + 1])
//        {
//            ++count;
//        }
//    }
//    if (count > m)
//    {
//        cout << -1 << endl;
//        return 0;
//    }
//    int space = m - count;
//    sort(v.first.begin(), v.first.end());
//    auto end = unique(v.first.begin(), v.first.end());
//    int ret = 0;
//    do
//    {
//        pair<int, std::vector<int>::iterator> max;//记录当前所有声部最多的数量和其位置
//        max.first = INT_MIN;
//        for (auto i = v.first.begin(); i != end; ++i)
//        {
//            if (v.second[*i] > max.first)
//            {
//                max.first = v.second[*i];
//                max.second = i;
//            }
//        }
//        ret = max.first;
//        v.second[*max.second] = (v.second[*max.second] + 1) / 2;
//    } while (space-- > 0);
//    cout << ret << endl;
//    return 0;
//}


//10 9
//1 2 3 4 5 6 7 8 10 10
//
//
//10 9
//1 2 3 4 5 6 7 8 10 11