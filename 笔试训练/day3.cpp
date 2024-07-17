#define _CRT_SECURE_NO_WARNINGS

//简单单词（缩写首字母并大写）
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


//dd爱框框
// 错了
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


//除2！
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void mysort(vector<int>& v, int* pk)
{
    int max = v[pk[0]];
    int mid = v[pk[1]];
    int min = v[pk[2]];
    int maxi = pk[0];
    int midi = pk[1];
    int mini = pk[2];
    int temp1 = maxi, temp2 = midi, temp3 = mini;
    if (max >= mid && max >= min)
    {
        if (mid >= min)
        {
            return;
        }
        else {
            pk[0] = temp1;
            pk[1] = temp3;
            pk[2] = temp2;
        }
    }
    else if (mid >= max && mid >= min)
    {
        if (max >= min)
        {
            pk[0] = temp2;
            pk[1] = temp1;
            pk[2] = temp3;
        }
        else {
            pk[0] = temp2;
            pk[1] = temp3;
            pk[2] = temp1;
        }
    }
    else if (min >= max && min >= mid)
    {
        if (max >= mid)
        {
            pk[0] = temp3;
            pk[1] = temp1;
            pk[2] = temp2;
        }
        else {
            pk[0] = temp3;
            pk[1] = temp2;
            pk[2] = temp1;
        }
    }
}

int main()
{
    int n = 0, k = 0;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    // for(int i = 0; i < n; ++i)
    // {
    //     cout << v[i] << ' ';
    // }
    int pk[3] = { -1 , -1, -1 };//记录最后三个最大的比较
    for (int i = n - 1; i >= 0; --i)//从后面找偶数，并且记录除后的最后三个
    {
        if (v[i] % 2 == 0)
        {
            if (pk[2] == -1)//初始pk数组
            {
                if (pk[0] == -1) pk[0] = i;
                else if (pk[1] == -1) pk[1] = i;
                else pk[2] = i;
                continue;
            }
            int flag = 0;//标志最大除后是否是奇数
            while (v[i] <= v[pk[2]] && k)//当前位置大于pk中最小的，则结束循环时当前位置为所有中最大的了
            {
                if (k)
                {
                    --k;
                    v[pk[0]] /= 2;
                    if (v[pk[0]] % 2 != 0)
                    {
                        pk[0] = i;
                        flag = 1;
                        mysort(v, pk);
                        break;
                    }
                    mysort(v, pk);
                }
            }
            if (flag != 1)
            {
                pk[2] = pk[1];
                pk[1] = pk[0];
                pk[0] = i;
            }
        }
        if (k == 0) break;
    }
    while(k)
    {
        --k;
        v[pk[0]] /= 2;
        if (v[pk[0]] % 2 != 0)
        {
            int temp = pk[0];
            pk[0] = pk[1];
            pk[1] = pk[2];
            pk[0] = temp;
        }
        
    }
    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
        sum += v[i];
    }
    cout << sum << endl;
    return 0;
}