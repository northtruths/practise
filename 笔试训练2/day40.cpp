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


//�����β��飨������ͷһ��û�кܶ�ϸ�����û���ǵ�����Ϊ״̬ԭ��Ҳ�϶��޷�������ɣ��ڶ���˯���и�����״̬�����������ؾͰ������������Ȼ��ac�ˣ�
//#include<iostream>
//#include<vector>
//#include<unordered_set>
//using namespace std;
//
//class Solution {
//public:
//    /**
//     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
//     *
//     *
//     * @param numProject int����
//     * @param groups int����vector<vector<>>
//     * @return int����vector
//     */
//    vector<int> findOrder(int numProject, vector<vector<int> >& groups) {
//        //ջ��ÿ�����鿴��ջ
//        //ͳ��ջ�׵����ݣ���ǰջԪ�ش���1��������ǰ����ջ����ͬ��ջ��Ԫ�أ���ջ�����ܳ�ջ�������ܹ���ջ
//        int num = 2 * groups.size(); //�ܹ���Ŀ�����������Ϊ0˵���޷����
//        vector<int> hash(numProject, 0);//�����Щ��������ջ�ף�����һ��˵������һ�����ƣ�Ϊ0ʱ˵��������
//        for (auto& e : groups)
//            ++hash[e[0]];//�±�0Ϊջ��
//        vector<int> ret;
//        unordered_set<int> ret_hash;//��¼�Ѿ������Ʊ�ţ������ظ�
//
//        for (int i = 0; i < numProject; ++i) {
//            if (hash[i] == 0) {//һ��ʼ��������
//                if (ret_hash.count(i) == 0) {
//                    ret_hash.insert(i);
//                    ret.push_back(i);
//                }
//            }
//        }
//        int flag = 1;//�ж��Ƿ������ĳ����Ŀ��û�н���ѭ��
//        while (flag) {
//            flag = 0;
//            for (auto& v : groups) {
//                if (v.size() == 2) {
//                    if (hash[v[1]] == 0)//�������Ҫô��һ��ʼ�����ƣ�Ҫô��������⿪�����ƣ����Կ϶��Ѿ���¼���������ټ�¼
//                    {
//                        v.pop_back();
//                        --num;
//                        flag = 1;
//                    }
//                }
//                if (v.size() == 1) {
//                    if (hash[v[0]] == 0)//֮ǰ�������ط���ȫ��������ƣ�ʹhashΪ0����������϶��Ѿ���¼��
//                    {
//                        v.pop_back();
//                        --num;
//                        flag = 1;
//                    }
//                    else {
//                        --hash[v[0]];//���Ƽ�1
//                        if (hash[v[0]] == 0 && ret_hash.count(v[0]) == 0) {
//                            ret_hash.insert(v[0]);
//                            ret.push_back(v[0]);
//                        }
//                        //ֻҪֻ��һ��Ԫ�ؾ�pop����Ϊ�����Ƿ��Ѿ��⿪������������Ӱ�죬�����Ų�popȴ�����ٴ�ѭ�����������Ӱ��
//                        v.pop_back();
//                        --num;
//                        flag = 1;
//                    }
//                }
//            }
//        }
//        if (num != 0)
//            return vector<int>();
//        return ret;
//    }
//};
//
//int main() {
//    Solution sl;
//    vector<vector<int>> groups = { {1,2}, {2,1}, {2, 0} };
//    sl.findOrder(3, groups);
//    return 0;
//}



//�ϳ�����
//#include <iostream>
//#include<vector>
//using namespace std;
//
//int main() {
//    //��̬�滮
//    //����dp��һ��leftһ��right���ֱ�Ϊ��iΪ���ģ���ߵ����ٳ��к��ұߵ����ٳ���
//    //�����ҵ����ұȵ�ǰi���ģ������
//    //left,rightֻ�ֿܷ���������
//    int n = 0;
//    cin >> n;
//    vector<int> hight(n);
//    vector<int> left(n);
//    vector<int> right(n);
//    for (int i = 0; i < n; ++i)//�����ͬʱ���left��ʡʱ��
//    {
//        cin >> hight[i];
//        left[i] = i;//������hight[i]�����ߵĶ��ó���
//        for (int j = i - 1; j >= 0; --j) {
//            if (hight[i] > hight[j])
//                left[i] = min(left[i], left[j] + i - j - 1);//ȡĳ��dpʱ����ǰλ�������м����Ҳ�ó���
//        }
//    }
//
//    for (int i = n - 1; i >= 0; --i) {
//        right[i] = n - i - 1;
//        for (int j = i + 1; j < n; ++j) {
//            if (hight[i] > hight[j])
//                right[i] = min(right[i], right[j] + j - i -1);
//        }
//    }
//
//    int ret = 0x3f3f3f3f;
//    for (int i = 0; i < n; ++i) {
//        ret = min(ret, left[i] + right[i]);
//    }
//    cout << ret << endl;
//    return 0;
//}