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



//���������������ַ�����Ӵ���δac��70%��
//#include <iostream>
//#include<string>
//using namespace std;
//
//int main(){
//    string s;
//    cin >> s;
//    int ret = 1;
//    int pre = 1;//ǰ���ַ�������
//    int i = 1;
//    while(i < s.size()){
//        if(s[i] != s[i - 1]){
//            break;
//        }
//        ++i;
//    }
//    pre = i;
//    ret = i;
//    while(i < s.size()){
//        int j = i + 1;
//        while(j < s.size()){
//            if(s[j] != s[j - 1])
//                break;
//            ++j;
//        }
//        int cur = j - i;
//        ret = max(ret, pre + cur);
//        pre = cur;
//        i =  j;
//    }
//    
//    cout << ret << endl;
//    return 0;
//}


//�ַ��������У�δac��ʱ��ռ临�Ӷ�O(n!)��