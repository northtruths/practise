#define _CRT_SECURE_NO_WARNINGS


//���
//#include <iostream>
//#include<cmath>
//using namespace std;
//
//int main() {
//    int t = 0;
//    cin >> t;
//    while (t--) {
//        int h, a, H, A;
//        cin >> h >> a >> H >> A;
//        if (A <= 0 || a >= H) {
//            cout << -1 << endl;
//        }
//        else {
//            int x = ceil((double)H / a);//����һ��������Ҫ�Ļغ���
//            int y = A * (x - 1);//����һ��������Ҫ���ĵ�Ѫ��
//            int ret = floor((double)h / y);
//            if (h - ret * y <= 0)
//                --ret;
//            cout << ret << endl;
//        }
//    }
//    return 0;
//}


//�ַ����ķ���
//#include <iostream>
//#include<string>
//#include<unordered_set>
//#include<algorithm>
//using namespace std;
//
//int main() {
//    int n = 0;
//    cin >> n;
//    unordered_set<string> ret;
//    while (n--) {
//        string s;
//        cin >> s;
//        sort(s.begin(), s.end());
//        ret.insert(s);
//    }
//    cout << ret.size() << endl;
//    return 0;
//}


//NC345 ����Ⱥ������δac�������˵��ͼ�ۣ����Ǵ������ͼ�ۻ���ѧ�����Լ��ȳ��ԣ�