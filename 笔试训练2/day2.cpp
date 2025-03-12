#define _CRT_SECURE_NO_WARNINGS


//牛牛的快递
//#include<iostream>
//using namespace std;
//int main()
//{
//    float a;
//    char b;
//    cin >> a >> b;
//    if (a <= 1)
//        cout << 20 + (b == 'y' ? 5 : 0) << endl;
//    else
//    {
//        a -= 1;
//        if ((int)a == a)
//            cout << 20 + a + (b == 'y' ? 5 : 0) << endl;
//        else
//            cout << 20 + (int)a + 1 + (b == 'y' ? 5 : 0) << endl;
//    }
//
//    return 0;
//}


//最小花费爬楼梯
//#include <iostream>
//#include<vector>
//using namespace std;
//
//int main() {
//    //dp[i]为爬到第i阶梯的最小费用
//    //dp[i]为到它前面两个阶梯并加上自身费用的较小值
//    int n;
//    cin >> n;
//    vector<int> v(n);
//    for (int i = 0; i < n; ++i)
//        cin >> v[i];
//    vector<int> dp(n);
//    dp[0] = dp[1] = 0;
//    for (int i = 2; i < n; ++i)
//    {
//        dp[i] = min(dp[i - 1] + v[i - 1], dp[i - 2] + v[i - 2]);
//    }
//    cout << min(dp[n - 1] + v[n - 1], dp[n - 2] + v[n - 2]) << endl;
//    return 0;
//}
 


//数组中两个字符串的最小距离
//#include <climits>
//#include <iostream>
//#include<string>
//#include<vector>
//using namespace std;
//
//int main()
//{
//    int ret = INT_MAX;
//    int n;
//    cin >> n;
//    string s1, s2;
//    vector<string> vs(n);
//    cin >> s1 >> s2;
//    for (int i = 0; i < n; ++i)
//        cin >> vs[i];
//    int index1 = -1, index2 = -1;
//    for (int i = 0; i < n; ++i)
//    {
//        if (vs[i] == s1)
//        {
//            index1 = i;
//            if (index2 != -1)
//                ret = min(ret, index1 - index2);
//        }
//        if (vs[i] == s2)
//        {
//            index2 = i;
//            if (index1 != -1)
//                ret = min(ret, index2 - index1);
//        }
//        if (ret == 0)    break;
//    }
//    if (index1 == -1 || index2 == -1)
//        ret = -1;
//    cout << ret << endl;
//    return 0;
//}



//dd爱框框
//#include<iostream>
//#include<vector>
//#include<climits>
//using namespace std;
//
//int main()
//{
//    //滑动窗口、双指针
//    //先从left=0开始找到满足x的right,然后如果left能往右走就右走，
//    //不能则先right右走一个位置，再判断left，如此循环
//    pair<int, int> ret;//答案
//    int left = 0, right = 0;
//    int cur = 0;//当前l~r的和
//    int n, x;
//    cin >> n >> x;
//    vector<int> arr(n);
//    for (int i = 0; i < n; ++i)
//        cin >> arr[i];
//    while (cur < x) {
//        cur += arr[right++];
//    }
//    --right;
//    ret.first = left;
//    ret.second = right == -1 ? 0 : right;//如果right为-1说明一开始就满足条件，right真实为0
//    if (ret.first == ret.second)
//    {
//        cout << ret.first << ' ' << ret.second << endl;
//        return 0;
//    }
//    cur -= arr[right];
//    do
//    {
//        cur += arr[right];
//        int flag = 0;//判断left是否右移，因为代码原因left会多移动一位
//        while (cur >= x)
//        {
//            flag = 1;
//            cur -= arr[left];
//            ++left;
//        }
//        if (flag) {
//            --left;
//            cur += arr[left];
//        }
//        if (right - left < ret.second - ret.first)
//        {
//            ret.first = left;
//            ret.second = right;
//        }
//        ++right;
//    } while (right < n);
//    cout << ret.first + 1 << ' ' << ret.second + 1 << endl;
//    return 0;
//}




//除2！(未ac)
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//void bubble(vector<int>& v, int i = 0)
//{
//    while (i < v.size() - 1 && v[i] < v[i + 1])
//    {
//        int temp = v[i];
//        v[i] = v[i + 1];
//        v[i + 1] = temp;
//        ++i;
//    }
//}
//int main()
//{
//    int n, k;
//    cin >> n >> k;
//    vector<int> v;
//    long long ret = 0;
//    for (int i = 0; i < n; ++i)
//    {
//        int a = 0;
//        cin >> a;
//        ret += a;
//        if (a % 2 == 0)
//            v.push_back(a);
//    }
//    sort(v.rbegin(), v.rend());
//    while (v.size() != 0 && k--)
//    {
//        v[0] /= 2;
//        ret -= v[0];
//        bubble(v);
//    }
//    cout << ret << endl;
//    return 0;
//}