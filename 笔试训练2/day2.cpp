#define _CRT_SECURE_NO_WARNINGS


//ţţ�Ŀ��
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


//��С������¥��
//#include <iostream>
//#include<vector>
//using namespace std;
//
//int main() {
//    //dp[i]Ϊ������i���ݵ���С����
//    //dp[i]Ϊ����ǰ���������ݲ�����������õĽ�Сֵ
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
 


//�����������ַ�������С����
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



//dd�����
//#include<iostream>
//#include<vector>
//#include<climits>
//using namespace std;
//
//int main()
//{
//    //�������ڡ�˫ָ��
//    //�ȴ�left=0��ʼ�ҵ�����x��right,Ȼ�����left�������߾����ߣ�
//    //��������right����һ��λ�ã����ж�left�����ѭ��
//    pair<int, int> ret;//��
//    int left = 0, right = 0;
//    int cur = 0;//��ǰl~r�ĺ�
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
//    ret.second = right == -1 ? 0 : right;//���rightΪ-1˵��һ��ʼ������������right��ʵΪ0
//    if (ret.first == ret.second)
//    {
//        cout << ret.first << ' ' << ret.second << endl;
//        return 0;
//    }
//    cur -= arr[right];
//    do
//    {
//        cur += arr[right];
//        int flag = 0;//�ж�left�Ƿ����ƣ���Ϊ����ԭ��left����ƶ�һλ
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




//��2��(δac)
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