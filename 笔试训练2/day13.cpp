#define _CRT_SECURE_NO_WARNINGS


//ţţ������
//#include<iostream>
//using namespace std;
//int main() {
//    int t = 0;
//    cin >> t;
//    while (t--) {
//        int n, k;
//        cin >> n >> k;
//        int flag = 0;//��ǰ��ʤ����
//        int ret = 0;
//        while (n--) {
//            char ch = 0;
//            cin >> ch;
//            if (ch == 'W') {
//                ++flag;
//                if (flag >= 3)
//                    ret += k;
//                else
//                    ret += 1;
//            }
//            else {
//                flag = 0;
//                ret -= 1;
//            }
//        }
//        cout << ret << endl;
//    }
//    return 0;
//}


//����ظ�������
//class Solution {
//public:
//    /**
//     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
//     *
//     *
//     * @param arr int����vector the array
//     * @return int����
//     */
//    int maxLength(vector<int>& arr) {
//        //��������
//        //��ϣ��¼״̬������ǰ����Ѿ����ˣ��Ӵ��ڿ�ͷһֱɾ��ֱ��ɾ����ͬ
//        int ret = 0;
//        int front = 0;//����ͷ�±�
//        unordered_map<int, int> hash;
//        for (int i = 0; i < arr.size(); ++i) {
//            //��ǰ���Ⱦ�Ϊ i - front + 1
//            while (hash[arr[i]]) {//ǰ������
//                --hash[arr[front]];
//                ++front;
//            }
//            ++hash[arr[i]];
//            ret = max(ret, i - front + 1);
//        }
//        return ret;
//    }
//};



//�����ַ�����δac�����ᣩ
//#include <iostream>
//using namespace std;
//
//int main() {
//
//}