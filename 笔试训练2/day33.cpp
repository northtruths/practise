#define _CRT_SECURE_NO_WARNINGS

//��̨��չ����
//#include <iostream>
//using namespace std;
//
//int main() {
//    //����ģ��
//    int n;
//    cin >> n;
//    cout << (1 << (n - 1)) << endl;
//    return 0;
//}



//���������������ַ�����Ӵ�������ǩ����⡢���˰�����ac������ϸ��û�ѿغã�����ǰѿز��ã���Ϊ����ϸ�ڵķ�ʽѡ���ˣ����ƴ�����û��ã�
// ���ҿ�ʼ��ʱ���ⶼû��ȫ��⣬���¿�ʼ˼���ķ���������⣩
//#include <iostream>
//#include<string>
//#include<unordered_map>
//using namespace std;
//
//int main() {
//    //��������
//    //ά�����ڣ���һ��count��¼��ǰ�ַ��������ж������Ƿ���������һ����ϣ�����Ӽ���仯Ϊ1��0��˵���мӼ�
//    string s;
//    cin >> s;
//    int left = 0, right = 0;//�����������Ӵ�����
//    int hash[26] = { 0 };
//    int count = 0;//�ַ�����
//    int ret = 0;
//    while (right < s.size()) {
//        if (++hash[s[right] - 'a'] == 1)
//            ++count;
//        if (count > 2)
//            ret = max(ret, right - left);
//        while (right < s.size() && count > 2) {
//            if (--hash[s[left] - 'a'] == 0)
//                --count;
//            ++left;
//        }
//        ++right;
//    }
//    ret = max(ret, right - left);
//    cout << ret << endl;
//    return 0;
//}


//�ַ��������У�δac��ʱ��ռ临�Ӷ�O(n!)��