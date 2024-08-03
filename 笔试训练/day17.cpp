#define _CRT_SECURE_NO_WARNINGS


//小乐乐改数字（100）
//#include<iostream>
//#include <string>
//
//using namespace std;
//
//int main()
//{
//    int n;
//    cin >> n;
//    string s(to_string(n));
//    for (int i = 0; i < s.size(); ++i)
//    {
//        if (s[i] % 2 == 0)
//            s[i] = 0;
//        else s[i] = 1;
//    }
//    int ret = 0;
//    int ri = 1;
//    for (int i = s.size() - 1; i >= 0; --i)
//    {
//        ret += s[i] * ri;
//        ri *= 10;
//    }
//    cout << ret << endl;
//    return 0;
//}







//十字爆破
//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//int main()
//{
//    int n, m;
//    cin >> n >> m;
//    vector<vector<int>> vv(n);
//    for (int i = 0; i < n; ++i)
//    {
//        for (int j = 0; j < m; ++j)
//        {
//            int t = 0;
//            scanf("%d", &t);
//            vv[i].push_back(t);
//        }
//    }
//    vector<int> row(n);
//    vector<int> col(m);
//    for (int i = 0; i < n; ++i)
//    {
//        for (int& e : vv[i])
//        {
//            row[i] += e;
//        }
//    }
//    for (int i = 0; i < m; ++i)
//    {
//        for (int j = 0; j < n; ++j)
//        {
//            col[i] += vv[j][i];
//        }
//    }
//    for (int i = 0; i < n; ++i)
//    {
//        for (int j = 0; j < m; ++j)
//        {
//            printf("%d ", row[i] + col[j] - vv[i][j]);
//        }
//        printf("\n");
//    }
//    return 0;
//}




//比那名居（天子？）的桃子（100）
//#include <climits>
//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//int main()
//{
//    long long n, k;
//    cin >> n >> k;
//    vector<long long> hp(n);
//    vector<long long> shy(n);
//    for (long long i = 0; i < n; ++i)
//    {
//        cin >> hp[i];
//    }
//    for (long long i = 0; i < n; ++i)
//    {
//        cin >> shy[i];
//    }
//    vector<long long> ret_hp(n - k + 1);
//    vector<long long> ret_shy(n - k + 1);
//
//    for (long long i = 0; i < n - k + 1; ++i)
//    {
//        for (long long j = i; j < i + k; ++j)
//        {
//            ret_hp[i] += hp[j];
//            ret_shy[i] += shy[j];
//        }
//    }
//
//    long long ret = 0;
//    long long max_hp = INT_MIN;
//    long long min_shy = INT_MAX;
//    for (long long i = 0; i < n - k + 1; ++i)
//    {
//        if (ret_hp[i] > max_hp)
//        {
//            ret = i + 1;
//            max_hp = ret_hp[i];
//            min_shy = ret_shy[i];
//        }
//        else if (ret_hp[i] == max_hp)
//        {
//            if (ret_shy[i] < min_shy)
//            {
//                ret = i + 1;
//                min_shy = ret_shy[i];
//            }
//        }
//    }
//    cout << ret << endl;
//    return 0;
//}
