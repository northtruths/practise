#define _CRT_SECURE_NO_WARNINGS

//��С������
//#include<iostream>
//using namespace std;
//
//long long ���Լ��(long long m, long long s)
//{
//    //շת�����
//    long long c = 0;
//    while (m % s != 0)
//    {
//        c = m % s;
//        m = s;
//        s = c;
//    }
//    if (c == 0)//m��s�ı�����s��Ϊ��С��Լ��
//        c = s;
//    return c;
//}
//
//int main()
//{
//    long long a = 0, b = 0;
//    cin >> a >> b;
//    if (b > a)
//    {
//        swap(a, b);
//    }
//    cout << (a * b) / ���Լ��(a, b) << endl;
//    return 0;
//}



//������������У�Ҫֵ������λ�ÿ��Բ�������
//class Solution {
//public:
//    /**
//     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
//     *
//     * max increasing subsequence
//     * @param arr int����vector the array
//     * @return int����
//     */
//    int MLS(vector<int>& arr) {
//        sort(arr.begin(), arr.end());
//        // for(const auto& e : arr)
//        // {
//        //     cout << e << ' ';
//        // }
//        // cout << endl;
//        unique(arr.begin(), arr.end());
//        int max = 0;//�����,��������Ԫ��
//        int cur = 0;//��ǰ����
//        for (int i = 1; i < arr.size(); ++i)
//        {
//            if (arr[i] == arr[i - 1] + 1)
//            {
//                ++cur;
//            }
//            else
//            {
//                if (cur > max)
//                {
//                    max = cur;
//                }
//                cur = 0;
//            }
//        }
//        return max + 1;
//    }
//};




//��ĸ�ռ�(love)���÷���󣬶�̬�滮
//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//int score(vector<string>& put_in, int i, int j)
//{
//    char ch = put_in[i][j];
//    if (ch == 'l') return 4;
//    if (ch == 'o') return 3;
//    if (ch == 'v') return 2;
//    if (ch == 'e') return 1;
//    return 0;
//}
//
//int main()
//{
//    int n = 0, m = 0;
//    cin >> n >> m;
//    //��̬�滮��n*m�����飬ֵΪ����λ�õ�������
//    vector<string> put_in(n);
//    string in;
//    for (int i = 0; i < n; ++i)
//    {
//        cin >> in;
//        put_in[i] = in;
//    }
//    vector<vector<int>> vv(n);
//    for (int i = 0; i < n; ++i)
//    {
//        vv[i].reserve(m);
//    }
//
//    if (put_in[0][0] == 'l') vv[0][0] = 4;
//    if (put_in[0][0] == 'o') vv[0][0] = 3;
//    if (put_in[0][0] == 'v') vv[0][0] = 2;
//    if (put_in[0][0] == 'e') vv[0][0] = 1;
//
//    for (int i = 0; i < n; ++i)
//    {
//        for (int j = 0; j < m; ++j)
//        {
//            if (i == 0 && j == 0) continue;
//            if (i == 0)
//            {
//                vv[i][j] = vv[i][j - 1] + score(put_in, i, j);
//            }
//            else if (j == 0)
//            {
//                vv[i][j] = vv[i - 1][j] + score(put_in, i, j);
//            }
//            else
//            {
//                int a = vv[i][j - 1] + score(put_in, i, j);
//                int b = vv[i - 1][j] + score(put_in, i, j);
//                vv[i][j] = a > b ? a : b;
//            }
//        }
//    }
//
//    int ret = 0;
//    int i = 0, j = 0;
//    for (int i = n - 1; j <= m - 1; ++j)
//    {
//        ret = max(vv[i][j], ret);
//    }
//    i = 0;
//    for (int j = m - 1; i <= n - 1; ++i)
//    {
//        ret = max(vv[i][j], ret);
//    }
//    cout << ret << endl;
//    return 0;
//}