#define _CRT_SECURE_NO_WARNINGS


//���ε���ĸ��
//#include <iostream>
//#include<vector>
//#include<string>
//using namespace std;
//
//int main() {
//    //����26�飬�鿴���ĸ���ĸ�Ĳ�������
//    //����ַ������������������ǰ�ַ����������ַ��͵�ǰ�ַ�С�������ַ�
//    //�������ֶ���ȡҪô˳�ű�Ҫô���ű�Ľ�Сֵ
//    string s;
//    cin >> s;
//    int ret = 0x3f3f3f3f;
//    int cur = 0;//�䵱ǰ�ַ��Ĳ�������
//    for (char ch = 'a'; ch <= 'z'; ++ch) {//��ǰҪ����ַ�
//        cur = 0;
//        for (auto& e : s) {
//            if (e <= ch)//����ǰ�ַ��������ַ�ǰ��
//                cur += min(ch - e, 'z' - ch + e - 'a' + 1);
//            else
//                cur += min(e - ch, 'z' - e + ch - 'a' + 1);
//        }
//        ret = min(ret, cur);
//    }
//    cout << ret << endl;
//    return 0;
//}