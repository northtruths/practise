#define _CRT_SECURE_NO_WARNINGS


//#include<iostream>
//using namespace std;
//
//int main()
//{
//    int n, m, a, b;
//    cin >> n >> m >> a >> b;
//    if ((n == 0 || m == 0) || (m <= 1 && n <= 1))
//    {
//        cout << 0 << endl;
//        return 0;
//    }
//    if (a == 2 * b || b == 2 * a)
//    {
//        int ret = 0;
//        if (a == 2 * b)//全组a
//        {
//            int num1 = n >= 2 * m ? m : n / 2;
//            if (num1 == m)
//            {
//                ret =  num1 * a ;
//            }
//            else
//            {
//                int num2 = (n % 2 == 1 && m - n / 2 >= 2) ? 1 : 0;
//                ret =  num1 * a + num2 * b;
//            }
//        }
//        if (b == 2 * a)//全组b
//        {
//            int num2 = m >= 2 * n ? n : m / 2;
//            if (num2 == n)
//            {
//                cout << num2 * b << endl;
//                return 0;
//            }
//            else
//            {
//                int num1 = (m % 2 == 1 && n - m / 2 >= 2) ? 1 : 0;
//                cout << num1 * a + num2 * b << endl;
//                return 0;
//            }
//        }
//        int nums_less = min(m, n);
//        int num12 = nums_less / 3;
//        m -= num12;
//        n -= num12;
//        int num1 = 0, num2 = 0;
//        if (n < m)
//        {
//            if (n == 2 && m >= 4)
//            {
//                num2 += 2;
//            }
//            if (n == 1 && m >= 2)
//            {
//                num2 += 1;
//            }
//        }
//        if (m < n)
//        {
//            if (m == 2 && n >= 4)
//            {
//                num1 += 2;
//            }
//            if (m == 1 && n >= 2)
//            {
//                num1 += 1;
//            }
//        }
//        ret = max(num1 * a + num2 * b + num12 * (a + b), ret);
//        cout << ret << endl;
//        return 0;
//    }
//    if (a > 2 * b || b > 2 * a)
//    {
//        if (a > 2 * b)//全组a
//        {
//            int num1 = n >= 2 * m ? m : n / 2;
//            if (num1 == m)
//            {
//                cout << num1 * a << endl;
//                return 0;
//            }
//            else
//            {
//                int num2 = (n % 2 == 1 && m - n / 2 >= 2) ? 1 : 0;
//                cout << num1 * a + num2 * b << endl;
//                return 0;
//            }
//        }
//        if (b > 2 * a)//全组b
//        {
//            int num2 = m >= 2 * n ? n : m / 2;
//            if (num2 == n)
//            {
//                cout << num2 * b << endl;
//                return 0;
//            }
//            else
//            {
//                int num1 = (m % 2 == 1 && n - m / 2 >= 2) ? 1 : 0;
//                cout << num1 * a + num2 * b << endl;
//                return 0;
//            }
//        }
//    }
//    else
//    {
//        int nums_less = min(m, n);
//        int num12 = nums_less / 3;
//        m -= num12;
//        n -= num12;
//        int num1 = 0, num2 = 0;
//        if (n < m)
//        {
//            if (n == 2 && m >= 4)
//            {
//                num2 += 2;
//            }
//            if (n == 1 && m >= 2)
//            {
//                num2 += 1;
//            }
//        }
//        if (m < n)
//        {
//            if (m == 2 && n >= 4)
//            {
//                num1 += 2;
//            }
//            if (m == 1 && n >= 2)
//            {
//                num1 += 1;
//            }
//        }
//        cout << num1 * a + num2 * b + num12 * (a + b) << endl;
//        return 0;
//    }
//    return 0;
//}




//买股票的最好时机 二
//#include <iostream>
//#include<vector>
//using namespace std;
//
//int main()
//{
//    //买卖股票，股跌最低时买，最高时卖
//    int n = 0;
//    cin >> n;
//    vector<int> v(n);
//    for (int i = 0; i < n; ++i)
//    {
//        int IN = 0;
//        cin >> IN;
//        v[i] = IN;
//    }
//
//    int ret = 0;
//    int min = 0;
//    int max = 0;
//    int flag = 0;//0为已卖(未持有股票), 1为已买股票, 2为准备卖票
//    for (int i = 0; i < n; ++i)
//    {
//        if (flag == 0)
//        {
//
//            while (i < n && v[i + 1] < v[i])
//            {
//                ++i;
//            }
//            if (i == n) break;
//            min = v[i];//此时跌底
//            flag = 1;
//        }
//        else
//        {
//            while (i < n && v[i + 1] > v[i])
//            {
//                ++i;
//            }
//            if (i == n)
//            {
//                max = v[i - 1];
//            }
//            else
//            {
//                max = v[i];
//            }
//            flag = 2;
//        }
//        if (flag == 2)
//        {
//            ret += max - min;
//            flag = 0;
//        }
//    }
//    cout << ret << endl;
//    return 0;
//}


//逆转字符
//#include<iostream>
//#include <iterator>
//#include<string>
//
//using namespace std;
//
//int main()
//{
//    string put_in;
//    string ch;
//    string ret;
//    getline(cin, put_in);
//    auto rb = put_in.rbegin();
//    auto re = put_in.rend();
//    for (auto& e : put_in)
//    {
//        if (e == ' ' || e == '.')
//            ch += ' ';
//    }
//    int ch_i = 0;
//    auto copy_end = put_in.size() - 1;
//    int i = 0;
//    for (i = put_in.size() - 1; i >= 0; --i)
//    {
//        if (put_in[i] == ' ')
//        {
//            if (i < copy_end)
//            {
//                for (int j = i + 1; j <= copy_end; ++j)
//                {
//                    ret += put_in[j];
//                }
//            }
//            copy_end = i - 1;
//            ret += ch[ch_i++];
//        }
//    }
//    for (int j = 0; j <= copy_end; ++j)
//    {
//        ret += put_in[j];
//    }
//    cout << ret << endl;
//    return 0;
//}