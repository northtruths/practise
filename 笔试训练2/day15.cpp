#define _CRT_SECURE_NO_WARNINGS

//ƽ����
//#include<iostream>
//#include<cmath>
//using namespace std;
//
//int main() {
//    long long x = 0;
//    cin >> x;
//    double k = sqrt(x);
//    long long a = ceil(k);
//    long long b = floor(k);
//    if (abs(a * a - x) < abs(b * b - x))
//        cout << a * a << endl;
//    else
//        cout << b * b << endl;
//    return 0;
//}



//���飨δac��10%��
//#include <iostream>
//#include<queue>
//#include<unordered_map>
//using namespace std;
//
//int main() {
//    //̰�ģ���ʼ�Ƚ���ͬһ�������˷���ͬһ�飬Ȼ��ÿ�ν���ǰ�����������һ�뵽�յ���
//    //�ܷ���Ĵ������� m - ��ʼ���������
//    unordered_map<int, int> hash;
//    int n, m;
//    cin >> n >> m;
//    for (int i = 0; i < n; ++i) {
//        int in = 0;
//        cin >> in;
//        ++hash[in];
//    }
//    if (hash.size() > m) {
//        cout << -1 << endl;
//        return 0;
//    }
//    int k = m - hash.size();//�ɷ������
//    priority_queue<int> heap;
//    for (auto& e : hash)
//        heap.push(e.second);
//    while (k--) {
//        int temp = (heap.top() + 1) / 2;
//        heap.pop();
//        heap.push(temp);
//    }
//    cout << heap.top() << endl;
//    return 0;
//}


//��ģ�塿��������δac����ûѧͼ�ۣ����ᣩ