#define _CRT_SECURE_NO_WARNINGS


//���ε�ˮ���������δac��
//#include<iostream>
//#include<cmath>
//using namespace std;
//
//long long a_value(int n, int m, int a, int b)
//{
//    int value = 0;
//    long long ga = min(n / 2, m);//�����a����
//    n -= ga * 2;
//    m -= ga;
//    value += ga * a;
//    long long gb = min(n, m / 2);
//    value += gb * b;
//    return value;
//}
//
//long long b_value(int n, int m, int a, int b)
//{
//    long long value = 0;
//    long long gb = min(n, m / 2);//�����b����
//    n -= gb * 2;
//    m -= gb;
//    value += gb * b;
//    long long ga = min(n / 2, m);
//    value += ga * a;
//    return value;
//}
//
//long long ab_value(int n, int m, int a, int b)
//{
//    long long value = 0;
//    long long g = min(n / 3, m / 3);//�����һaһb������
//    n -= g * 3;
//    m -= g * 3;
//    value += g * (a + b);
//    if (m == 2 && n == 2)
//        value += max(a, b);
//    else if (n == 1 && m == 2)
//        value += b;
//    else if (n == 2 && m == 1)
//        value += a;
//    return value;
//}
//int main() {
//    //�Ƚ�����a��b��һaһb����˭��
//    long long n, m, a, b;
//    cin >> n >> m >> a >> b;
//    cout << max(a_value(n, m, a, b), max(b_value(n, m, a, b), ab_value(n, m, a, b))) << endl;
//    return 0;
//}




//������Ʊ�����ʱ��������
//#include<iostream>
//#include<vector>
//using namespace std;
//
//int main()
//{
//    //��������¼�뵱ǰλ������Ĳ���Ͳ��ȣ�cur����pre����top����֮����floor
//    //��cur����pre����floor����pre��˵��pre�ǲ���,��ʱ��Ʊ
//    //��curС��pre����top����pre��˵��pre�ǲ��壬��ʱ������Ʊ������floor��top����Ϊcur
//
//    int n = 0;
//    cin >> n;
//    int ret = 0;
//    int floor = 0;
//    int top = 0;
//    int pre = 0;
//    cin >> pre;
//    floor = top = pre;
//    int cur = 0;
//    for (int i = 1; i < n; ++i)
//    {
//        cin >> cur;
//        //cout << "pre:" << pre << "cur:" << cur << "top:" << top << "floor:" << floor << endl; 
//        if (cur == pre)
//            continue;
//        else if (cur > pre)
//        {
//            top = cur;
//            pre = cur;
//        }
//        else if (cur < pre) {
//            if (pre == top)
//            {
//                ret += top - floor;
//                top = floor = cur;
//            }
//            pre = cur;
//        }
//        else {
//            floor = cur;
//            pre = cur;
//        }
//
//    }
//    ret += max(0, cur - floor);
//    cout << ret << endl;
//    return 0;
//}



//�����ַ���
//#include <cstdio>
//#include<iostream>
//#include<string>
//#include<algorithm>
//using namespace std;
//
//int main()
//{
//    string s;
//    string temp;
//    getline(cin, s);
//    string ch;//���
//    string ret;
//    for (int i = s.size() - 1; i >= 0; --i) {
//        if (s[i] == ' ' || s[i] == '.') {
//            reverse(temp.begin(), temp.end());
//            ret += temp;
//            ret += ch;
//            if (ch == ".")
//                ret += ' ';
//            ch = s[i];
//            temp.clear();
//        }
//        else {
//            temp += s[i];
//        }
//
//    }
//    reverse(temp.begin(), temp.end());
//    ret += temp;
//    cout << ret << endl;
//    return 0;
//}