#define _CRT_SECURE_NO_WARNINGS


//��ȡ���ظ�������
//#include <iostream>
//#include<cmath>
//using namespace std;
//
//int main() {
//    int n;
//    cin >> n;
//    int hash[10] = { 0 };//���ֵĹ�ϣ��
//    while (n) {
//        int cur = n % 10;
//        if (hash[cur] == 0) {
//            ++hash[cur];
//            cout << cur;
//        }
//        n /= 10;
//    }
//    return 0;
//}


//AB32 ����������
//#include <iostream>
//#include<queue>
//using namespace std;
//
//int main() {
//    int n;
//    cin >> n;
//    priority_queue<long long, vector<long long>, greater<>> heap;
//    for (int i = 0; i < n; ++i)
//    {
//        int temp = 0;
//        cin >> temp;
//        heap.push(temp);
//    }
//    long long ret = 0;
//    while (heap.size() > 1) {
//        long long a = heap.top();
//        heap.pop();
//        long long b = heap.top();
//        heap.pop();
//        ret += (a + b);
//        heap.push(a + b);
//    }
//    cout << ret << endl;
//    return 0;
//}



//DP36 abb��������ac�������������һ�ţ�ϸ����û��������Ѿ�����ȷ�𰸲�һ˿˿����֪��Ϊʲô������������ȱ������˼���������������ǵ���̫ƣ��û�����о��񣿣�
//#include <iostream>
//#include<string>
//#include<vector>
//using namespace std;
//
//int main() {
//    //��̬�滮��һ������hash��¼i֮ǰ��ĳ���ַ�Ϊ��β��ab�ͣ�һ������count��¼i֮ǰ��ÿ����ĸ���ֵĸ���
//    //�Ե�ǰ�ַ�Ϊ��β��abb�͵���hash����¼�Ķ�Ӧ������
//    //Ȼ����count����hash->�Ե�ǰ��ĸ��β��ab�͵���i-count��¼����ĸ���� + ֮ǰ�Լ�¼�ģ�Ȼ�����count����ǰ��ĸ++��
//    int n;
//    cin >> n;
//    string s;
//    cin >> s;
//    vector<long long> hash(26, 0);
//    vector<long long> count(26, 0);
//    long long ret = 0;
//    for (int i = 0; i < n; ++i) {
//        ret += hash[s[i] - 'a'];
//        hash[s[i] - 'a'] += i - count[s[i] - 'a'];
//        ++count[s[i] - 'a'];
//    }
//    cout << ret << endl;
//    return 0;
//}