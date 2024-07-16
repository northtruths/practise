#define _CRT_SECURE_NO_WARNINGS


//牛牛的快递
//#include<iostream>
//using namespace std;
//
//int main()
//{
//    float a = 0;
//    char b = 0;
//    int money = 0;
//    cin >> a >> b;
//    if (a <= 1)
//    {
//        money += 20;
//        if (b == 'y') money += 5;
//        cout << money << endl;
//    }
//    else {
//        float c = --a;
//        money = 20 + ((int)(a + 0.5) >= c ? (int)(a + 0.5) : (int)(a + 0.5) + 1);
//        if (b == 'y') money += 5;
//        cout << money << endl;
//    }
//    return 0;
//}


//最小花费爬楼梯
//#include<iostream>
//using namespace std;
//
//int main()
//{
//    int n = 0;
//    cin >> n;
//    int cost[n];
//    for (int i = 0; i < n; ++i)
//    {
//        cin >> cost[i];
//    }
//    int min[n];//到第i层的最小花费
//    min[0] = 0;
//    min[1] = 0;
//    for (int i = 2; i < n; ++i)//从第三层开始，最小花费等于，它前两层的花费加上到前两层花费中小的那个
//    {
//        int c1 = cost[i - 1] + min[i - 1];
//        int c2 = cost[i - 2] + min[i - 2];
//        min[i] = c1 < c2 ? c1 : c2;
//    }
//    if (n == 1)
//    {
//        cout << 0 << endl;
//    }
//    else if (n == 2)
//    {
//        int ret = cost[0] < cost[1] ? cost[0] : cost[1];
//        cout << ret << endl;
//    }
//    else
//    {
//        int ret = min[n - 2] + cost[n - 2] < min[n - 1] + cost[n - 1] ? min[n - 2] + cost[n - 2] : min[n - 1] + cost[n - 1];
//        cout << ret << endl;
//    }
//    return 0;
//}



////数组中两字符串最小距离
//
////过95%
//#include<iostream>
//#include<string>
//#include<vector>
//#include<cmath>
//using namespace std;
//
//int main()
//{
//    int n = 0;
//    cin >> n;
//    string s1;
//    string s2;
//    vector<string> ss(n);
//    cin >> s1 >> s2;
//    for (int i = 0; i < n; ++i)
//    {
//        cin >> ss[i];
//    }
//    //双指针，一个找到对应位置，另一个再找下一个，记录最小位置
//    int index1 = -1;//s1下标
//    int index2 = -1;
//    //先找 s1 和 s2 的第一个位置
//    for (int i = 0; i < n; ++i)
//    {
//        if (ss[i] == s1)
//        {
//            index1 = i;
//            break;
//        }
//    }
//    if (index1 == -1)
//    {
//        cout << -1 << endl;
//        return 0;
//    }
//    for (int i = 0; i < n; ++i)
//    {
//        if (ss[i] == s2)
//        {
//            index2 = i;
//            break;
//        }
//    }
//    if (index2 == -1)
//    {
//        cout << -1 << endl;
//        return 0;
//    }
//    int ret = abs(index1 - index2);
//    for (int i = index1 + 1; i < n; ++i)
//    {
//        if (ss[i] == s1)
//        {
//            index1 = i;
//            ret = min(ret, abs(index1 - index2));
//            for (int j = index2 + 1; j < n; ++j)
//            {
//                if (ss[j] == s2) index2 = j;
//                ret = min(ret, abs(index1 - index2));
//                break;
//            }
//        }
//    }
//    cout << ret << endl;
//    return 0;
//}
//
//
////改进：但还是只过95%
//#include<iostream>
//#include<string>
//#include<vector>
//#include<cmath>
//using namespace std;
//
//int main()
//{
//    int n = 0;
//    cin >> n;
//    string s1;
//    string s2;
//    vector<string> ss(n);
//    cin >> s1 >> s2;
//    for (int i = 0; i < n; ++i)
//    {
//        cin >> ss[i];
//    }
//    //双指针，一个找到对应位置，另一个再找下一个，记录最小位置
//    int index1 = -1;//s1下标
//    int index2 = -1;
//    //先找 s1 和 s2 的第一个位置
//    for (int i = 0; i < n; ++i)
//    {
//        if (ss[i] == s1)
//        {
//            index1 = i;
//            break;
//        }
//    }
//    if (index1 == -1)
//    {
//        cout << -1 << endl;
//        return 0;
//    }
//    for (int i = 0; i < n; ++i)
//    {
//        if (ss[i] == s2)
//        {
//            index2 = i;
//            break;
//        }
//    }
//    if (index2 == -1)
//    {
//        cout << -1 << endl;
//        return 0;
//    }
//    int ret = abs(index1 - index2);
//    int flag1 = 0;//记录其中一个移动时，所遇到的另外一个的个数，若大于一，另一个移动时得多移动以达到最近的一个
//    int flag2 = 0;
//    for (int i = index1 + 1; i < n; ++i)
//    {
//        if (ss[i] == s2) ++flag2;
//        if (ss[i] == s1)
//        {
//            if (flag1 > 1)
//            {
//                if (index1 < index2)
//                {
//                    --flag1;
//                    continue;
//                }
//                else {
//                    flag1 = 0;
//                }
//            }
//            index1 = i;
//            ret = min(ret, abs(index1 - index2));
//            for (int j = index2 + 1; j < n; ++j)
//            {
//                if (ss[j] == s1) ++flag1;
//                if (ss[j] == s2)
//                {
//                    if (flag2 > 1)
//                    {
//                        if (index2 < index1)
//                        {
//                            --flag2;
//                            continue;
//                        }
//                        else
//                        {
//                            flag2 = 0;
//                        }
//                    }
//                    index2 = j;
//                }
//                ret = min(ret, abs(index1 - index2));
//                break;
//            }
//        }
//    }
//    cout << ret << endl;
//    return 0;
//}