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




#include <iostream>
#include<vector>
using namespace std;

int main() {
    //��̬�滮��dp1[i]Ϊѡȡ��i����ѧ�������˻���dp2[i]Ϊѡȡ��i������С
    //dp1[i]���㣺��ǰѰ�����d��dp����ѧ��������k����ֱ�ӳˣ������ˣ���ȥiλ�õ�ai�ٳˣ���¼���
    //��Ϊ�����Ĵ��ڣ�dp2�洢��С����ǰ������Ϊ����ʱ���������СֵΪ������������˵�������������
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i)
        cin >> nums[i];
    int k, d;
    cin >> k >> d;
    vector<int> dp1(n, -0x3f3f3f3f);
    vector<int> dp2(n, 0x3f3f3f3f);
    dp1[0] = dp2[0] = nums[0];
    int stu = 0;//��ǰѡȡѧ������
    int ret = 0;
    for (int i = 1; i < n; ++i) {
        int flag = 0;
        for (int j = i - 1; j >= max(0, i - d); --j) {
            if (stu >= k) {
                if (nums[j] == 0)
                    continue;
                dp1[i] = max(dp1[i], max(dp2[j] * nums[i] / nums[j], dp1[j] * nums[i] / nums[j]));
                dp2[i] = min(dp2[i], min(dp2[j] * nums[i] / nums[j], dp1[j] * nums[i] / nums[j]));
                ret = max(ret, dp1[i]);
            }
            else {
                dp1[i] = max(dp1[i], max(dp2[j] * nums[i], dp1[j] * nums[i]));
                dp2[i] = min(dp2[i], min(dp2[j] * nums[i], dp1[j] * nums[i]));
                ret = max(ret, dp1[i]);
                flag = 1;
                ++stu;
            }
        } 
    }
    cout << ret << endl;
    return 0;
}