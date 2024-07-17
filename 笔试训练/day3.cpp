#define _CRT_SECURE_NO_WARNINGS

//¼òµ¥µ¥´Ê£¨ËõÐ´Ê××ÖÄ¸²¢´óÐ´£©
//#include<iostream>
//#include<string>
//using namespace std;
//
//int main()
//{
//    string s;
//    string ret;
//    while (cin >> s)
//    {
//        ret += s[0] >= 'a' ? s[0] - 32 : s[0];
//    }
//    cout << ret << endl;
//    return 0;
//}


//dd°®¿ò¿ò
// ´íÁË
//#include<iostream>
//#include<vector>
//using namespace std;
//
//int main()
//{
//    int n = 0, x = 0;
//    cin >> n >> x;
//    vector<int> v(n);
//    for (int i = 0; i < n; ++i)
//    {
//        cin >> v[i];
//    }
//    int l = 0, r = 0;
//    int sum = 0;
//    int min = 0;
//    for (int i = 0; i < n; ++i)
//    {
//        sum += v[i];
//        if (sum >= x)
//        {
//            r = i;
//            min = r - l;
//            break;
//        }
//    }
//    int ret_l = l;
//    int ret_r = r;
//    while (r < n - 1)
//    {
//        ++r;
//        sum += v[r];
//        while (sum - v[l] >= x)
//        {
//            sum -= v[l];
//            ++l;
//        }
//        if (r - l < min)
//        {
//            ret_l = l;
//            ret_r = r;
//            min = r - l;
//        }
//    }
//    cout << ret_l << ' ' << ret_r << endl;
//    return 0;
//}