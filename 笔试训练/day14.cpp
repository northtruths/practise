#define _CRT_SECURE_NO_WARNINGS


//乒乓球框（100）
//#include<iostream>
//#include<string>
//#include<algorithm>
//
//using namespace std;
//
//int main()
//{
//    string s1;
//    string s2;
//    cin >> s1 >> s2;
//    sort(s1.begin(), s1.end());
//    sort(s2.begin(), s2.end());
//    int i2 = 0;
//    for (int i1 = 0; i1 < s1.size(); ++i1)
//    {
//        if (s1[i1] == s2[i2])
//        {
//            ++i2;
//        }
//        if (i2 == s2.size())
//            break;
//    }
//    if (i2 == s2.size()) cout << "Yes" << endl;
//    else cout << "No" << endl;
//    return 0;
//}




//组队竞赛（10）
//#include<iostream>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//
//int main()
//{
//    //贪心
//    int n;
//    cin >> n;
//    vector<int> v(3 * n);
//    for (int i = 0; i < 3 * n; ++i)
//    {
//        int temp = 0;
//        cin >> temp;
//        v[i] = temp;
//    }
//    sort(v.begin(), v.end());
//    int ret = 0;
//    for (int i = v.size() - 2; i >= 2; i -= 2)
//    {
//        ret += v[i];
//    }
//    cout << ret << endl;
//    return 0;
//}





//删除相邻数字的最大分数（0）
//#include <climits>
//#include <iostream>
//#include<vector>
//using namespace std;
//
//int main()
//{
//    int n;
//    cin >> n;
//    vector<int> v(n);
//    int max = INT_MIN;
//    int min = INT_MAX;
//    for (int i = 0; i < n; ++i)
//    {
//        int a = 0;
//        cin >> a;
//        v[i] = a;
//        if (a > max) max = a;
//        if (a < min) min = a;
//    }
//    vector<int> count(max - min + 2);//记录数字几有几个
//    for (int i = 0; i < n; ++i)
//    {
//        ++count[v[i]];
//    }
//    int ret = 0;
//    if (count[count.size() - 1] * count.size() - 1 >= count[count.size() - 2] * count.size() - 2)
//    {
//        ret += count[count.size() - 1] * count.size() - 1;
//        count[count.size() - 1] = 0;
//        count[count.size() - 2] = 0;
//    }
//    int falg = 1;
//    while (falg)
//    {
//        falg = 0;
//        for (int i = 1; i < count.size() - 1; ++i)
//        {
//            if (count[i] == 0) continue;
//            if (count[i] * i >= count[i - 1] * (i - 1) + count[i + 1] * (i + 1))
//            {
//                ret += i * count[i];
//                count[i - 1] = 0;
//                count[i] = 0;
//                count[i + 1] = 0;
//                ++i;
//                falg = 1;
//            }
//            if (i < count.size() - 3 && count[i] * i + count[i + 2] * (i + 2) >= count[i - 1] * (i - 1) + count[i + 1] * (i + 1) + count[i + 3] * (i + 3))
//            {
//                ret += count[i] * i + count[i + 2] * (i + 2);
//                count[i - 1] = 0;
//                count[i] = 0;
//                count[i + 1] = 0;
//                count[i + 2] = 0;
//                count[i + 3] = 0;
//                i += 3;
//                falg = 1;
//            }
//
//        }
//    }
//    cout << ret << endl;
//    return 0;
//}

//17
//1 1 2 2 2 2 2 3 3 3 4 4 5 6 7 7 8
