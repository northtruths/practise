#define _CRT_SECURE_NO_WARNINGS


//��������
//#include<iostream>
//#include<vector>
//#include<cmath>
//#include<algorithm>
//using namespace std;
//
//bool is_prime(long long x) {
//    if (x == 2 || x == 3)    return true;
//    if (x % 2 == 0 || x % 3 == 0)    return false;
//    for (int i = 6; i + 1 <= sqrt(x); i += 6) {
//        if (x % (i - 1) == 0 || x % (i + 1) == 0)
//            return false;
//    }
//    return true;
//}
//int main() {
//    //ģ��
//    long long t;
//    cin >> t;
//    vector<long long > temp;
//    while (t) {
//        temp.push_back(t % 10);
//        t /= 10;
//    }
//    reverse(temp.begin(), temp.end());
//    for (int i = temp.size() - 2; i >= 0; --i) {
//        temp.push_back(temp[i]);
//    }
//    long long x = 0;
//    for (int i = 0; i < temp.size(); ++i) {
//        x += pow(10, temp.size() - 1 - i) * temp[i];
//    }
//    if (is_prime(x))
//        cout << "prime" << endl;
//    else
//        cout << "noprime" << endl;
//    return 0;
//}


//�����
//#include <iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//int main() {
//    //̰��+����+����
//    //��¼ѡ��n��������ĩβʱ�䣬ÿ��Ѱ��֮ǰ�ļ�¼������ʼʱ����ڼ�¼(����ʱ��)�����ҽ���ʱ��С������һ����¼��
//    //�򽫸���ļ�¼����δ��ǰС�����
//    //ԭ����Ϊ�����ʼʱ��������ģ���ǰ��Ŀ�ʼʱ��ض����ڵ���֮ǰ�ģ�
//    //ֻҪ��ǰ��ܽ���֮ǰ�ģ���ô����ʱ��ԽСԽ�ã�Ȼ���ܽӵ����ͽӣ������ٿ����Ƿ��ܸ��£�����¼�ĸ�����Ϊ��
//    int n;
//    cin >> n;
//    vector<vector<int>> record(n, vector<int>(2));
//    for (int i = 0; i < n; ++i) {
//        int a, b;
//        cin >> a >> b;
//        record[i][0] = a;
//        record[i][1] = b;
//    }
//    sort(record.begin(), record.end(), [&record](vector<int>& x, vector<int>& y)->bool {return x[0] < y[0]; });
//    vector<int> ret;
//    ret.push_back(record[0][1]);
//    for (int i = 1; i < n; ++i) {
//        if (record[i][0] >= ret[ret.size() - 1]) {
//            ret.push_back(record[i][1]);
//        }
//        else {
//            int left = 0, right = ret.size() - 1;
//            while (left <= right) {
//                int mid = (left + right) >> 1;
//                if (ret[mid] == record[i][0]) {
//                    right = mid;
//                    left = mid + 1;
//                }
//                else if (ret[mid] < record[i][0])
//                    left = mid + 1;
//                else
//                    right = mid - 1;
//            }
//            ret[left] = min(ret[left], record[i][1]);
//        }
//    }
//    cout << ret.size() << endl;
//    return 0;
//}



////�ϳ��ţ�������ac���󲿷�˼·����λ�ˣ����ǲ�����һ�ţ�֪�������������Сdp��������ͬһiλ��ѡȡ��ѧԱk������һ����ͬ������취���ƣ�
//// ����Ϊ����ȱ������˼���������������Ҫ���Ƶı�������dp�У���άdp�ͽ���ˣ�
//#include <iostream>
//#include<vector>
//using namespace std;
//
//int main() {
//    //��̬�滮��dp1[i][j]Ϊѡȡ��i������ʱѡ��j��ѧ�������˻���dp2[i]Ϊ��С
//    //dp1[i]���㣺��ǰѰ�����d��dp����ѧ��������k����ֱ�ӳˣ������ˣ���ȥiλ�õ�ai�ٳˣ���¼���
//    //��Ϊ�����Ĵ��ڣ�dp2�洢��С����ǰ������Ϊ����ʱ���������СֵΪ������������˵�������������
//    int n;
//    cin >> n;
//    vector<int> nums(n);
//    for (int i = 0; i < n; ++i)
//        cin >> nums[i];
//    int k, d;
//    cin >> k >> d;
//    vector<vector<long long>> dp1(n, vector<long long>(k + 1, 1));
//    vector<vector<long long>> dp2(n, vector<long long>(k + 1, 1));
//    long long ret = nums[0];
//    for (int i = 0; i < n; ++i) {
//        dp1[i][1] = dp2[i][1] = nums[i];
//        for (int z = i - 1; z >= max(0, i - d); --z) {
//            for (int j = 1; j <= k; ++j) {
//                if (nums[i] < 0) {
//                    dp1[i][j] = max(dp1[i][j], dp2[z][j - 1] * nums[i]);
//                    dp2[i][j] = min(dp2[i][j], dp1[z][j - 1] * nums[i]);
//                }
//                else {
//                    dp1[i][j] = max(dp1[i][j], dp1[z][j - 1] * nums[i]);
//                    dp2[i][j] = min(dp2[i][j], dp2[z][j - 1] * nums[i]);
//                }
//                ret = max(dp1[i][k], ret);
//            }
//        }
//    }
//    cout << ret << endl;
//    return 0;
//}