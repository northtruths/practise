#define _CRT_SECURE_NO_WARNINGS


//�������ʣ�80%��
//#include <algorithm>
//#include<iostream>
//#include<string>
//#include<math.h>
//using namespace std;
//
//bool judge(long long a)
//{
//    for (long long i = 2; i < (int)sqrt(a); ++i)
//    {
//        long double r = a / (long double)i;
//        if (r == (long long)r)
//            return false;
//    }
//    return true;
//}
//
//int main()
//{
//    int t = 0;
//    cin >> t;
//    string s = to_string(t);
//    string add(s.begin(), s.end() - 1);
//    reverse(add.begin(), add.end());
//    s += add;
//
//    long long a = atoi(s.c_str());
//    if (judge(a))
//    {
//        cout << "prime" << endl;
//    }
//    else {
//        cout << "noprime" << endl;
//    }
//    return 0;
//}



//����
//#include <iostream>
//#include<utility>
//#include<vector>
//using namespace std;
//
//int main() {
//    int n;
//    cin >> n;
//    vector<pair<int, int>> v;
//    for (int i = 0; i < n; ++i)
//    {
//        int a, b;
//        cin >> a >> b;
//        int flag = 0;//1�Ǳ��滻�ˣ��Ͳ��ò�����
//        for (int j = 0; j < v.size(); ++j)
//        {
//            if (v[j].first == a)
//            {
//                if (b < v[j].second)
//                {
//                    v[j] = { a, b };
//                }
//                flag = 1;
//                break;
//            }
//            if (v[j].first < a && b <= v[j].second)
//            {
//                v[j] = { a, b };
//                flag = 1;
//                break;
//            }
//        }
//        if (flag == 0)
//        {
//            v.push_back({ a, b });
//        }
//    }
//    //����
//    return 0;
//}