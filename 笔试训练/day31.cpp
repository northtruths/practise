#define _CRT_SECURE_NO_WARNINGS

//小红的口罩（36%，运行超时）

//#include<iostream>
//#include<algorithm>
//#include<vector>
//using namespace std;
//
//void my_buble(vector<int>& v)
//{
//    for (int i = 0; i < v.size() - 1; ++i)
//    {
//        if (v[i] > v[i + 1])
//        {
//            int temp = v[i];
//            v[i] = v[i + 1];
//            v[i + 1] = temp;
//        }
//        else {
//            break;//因为我们排的是有序数组，并且只有首元素是不确定，所以排好首元素即可
//        }
//    }
//}
//
//int main()
//{
//    int n, k;
//    cin >> n >> k;
//    vector<int> v;
//    v.resize(n);
//    for (int i = 0; i < n; ++i)
//    {
//        int in = 0;
//        cin >> in;
//        v[i] = in;
//    }
//
//    sort(v.begin(), v.end());
//    int count = 0;//计量不舒适度
//    int day = 0;
//    while (count < k)
//    {
//        count += v[0];
//        v[0] *= 2;
//        ++day;
//        my_buble(v);
//    }
//    if (count > k)
//    {
//        --day;
//    }
//    cout << day << endl;
//    return 0;
//}





//春游（0）（不知道哪错了，测试能过，运行却一个不行）
//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//int main()
//{
//    int T;
//    cin >> T;
//    while (T--)
//    {
//        int n, a, b;
//        cin >> n >> a >> b;
//        int cost = 0;
//        if ((double)b / 3 > (double)a / 2)
//        {
//            cost = n / 2 * a;
//            int c = n % 2;//多的人，0 和 1
//            if (c == 1)
//            {
//                if (b < 2 * a)
//                {
//                    cost = cost - a + b;
//                }
//                else {
//                    cost += a;
//                }
//            }
//            cout << cost << endl;
//        }
//        else if ((double)b / 3 < (double)a / 2)
//        {
//            cost = n / 3 * b;
//            int c = n % 3;//0,1,2
//            if (c == 1)
//            {
//                if (b < a)
//                {
//                    cost += b;
//                }
//                else {
//                    cost = cost - b + 2 * a;
//                }
//            }
//            else if (c == 2)
//            {
//                if (b <= a)
//                {
//                    cost += b;
//                }
//                else {
//                    cost += a;
//                }
//            }
//            cout << cost << endl;
//        }
//        else
//        {
//            int ca = n % 2;//0,1
//            int cb = n % 3;//0,1,2
//            if (ca == 0)
//            {
//                cost = n / 2 * a;
//            }
//            else if (cb == 0)
//            {
//                cost = n / 3 * b;
//            }
//            else if (cb == 2)
//            {
//                cost = n / 3 * b + a;
//            }
//            else {
//                cost = n / 2 * a + a;
//            }
//            cout << cost << endl;
//        }
//    }
//    return 0;
//}



//涂数字（不会）