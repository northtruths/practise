#define _CRT_SECURE_NO_WARNINGS



//��֣�100��
//#include<iostream>
//#include<cmath>
//using namespace std;
//
//int main() {
//    int t = 0;
//    cin >> t;
//
//    while (t--) {
//        int my_atk = 0, e_atk = 0;
//        int my_hp = 0, e_hp = 0;
//        cin >> my_hp >> my_atk >> e_hp >> e_atk;
//        e_hp -= my_atk;
//        if (e_atk == 0 || e_hp <= 0) {
//            cout << -1 << endl;
//            continue;
//        }
//        int time = ceil((double)e_hp / my_atk);
//        int ret = 0;
//        while (my_hp > 0)
//        {
//            my_hp = my_hp - time * e_atk;
//            if (my_hp > 0)   ++ret;
//        }
//        cout << ret << endl;
//    }
//    return 0;
//}







//�ַ����ķ���
//#include<iostream>
//#include<vector>
//#include<string>
//using namespace std;
//
//int main()
//{
//    int n;
//    cin >> n;
//    int ret = 0;
//    vector<vector<int>> vv;
//
//    for (int i = 0; i < n; ++i)
//    {
//        string s;
//        vector<int> v(26);
//        cin >> s;
//        for (char e : s)
//        {
//            ++v[e - 97];
//        }
//        if (vv.empty())
//        {
//            vv.push_back(v);
//            ++ret;
//        }
//        else
//        {
//            int flag = 0;//�ж���û��ͬ�࣬0���ǣ�1��
//            for (int k = 0; k < vv.size(); ++k)//����ÿһ��
//            {
//                int cur = 1;//�жϵ�ǰ�ǲ���ͬһ��, 0���ǣ�1��
//                for (int m = 0; m < 26; ++m)//��ÿһ����ַ������Ƿ���ͬ
//                {
//                    if (vv[k][m] != v[m])
//                    {
//                        cur = 0;
//                        break;
//                    }
//                }
//                if (cur)
//                {
//                    break;
//                }
//                else if (k == vv.size() - 1 && cur == 0)//���һ����������ͬ��
//                {
//                    ++ret;
//                    vv.push_back(v);
//                }
//            }
//        }
//    }
//    cout << ret << endl;
//    return 0;
//}







//��30��
//#include<iostream>
//#include<vector>
//using namespace std;


//class Solution {
//public:
//    /**
//     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
//     *
//     *
//     * @param m int����vector<vector<>>
//     * @return int����
//     */
//    void same(vector<vector<int> >& v, int i, int num)
//    {
//        for (int j = 0; j < v.size(); ++j)
//        {
//            v[i][j] = num;
//            v[j][i] = num;
//        }
//    }
//
//    int citys(vector<vector<int> >& m)
//    {
//        int num = 3;
//        for (int i = 0; i < m.size(); ++i)
//        {
//            if (m[0][i] == 1) m[0][i] = 2;
//            if (m[i][0] == 1) m[i][0] = 2;
//
//        }
//        for (int i = 1; i < m.size() - 1; ++i)//��������
//        {   
//            int flag = 0;
//            for (int j = i - 1; j >= 0; --j)//������������������������ǰ��ĳ����Ƿ���������������
//            {
//                if (m[i][j] >= 1)
//                {
//                    same(m, i, m[i][j] == 1 ? num : m[i][j]);
//                    ++num;
//                    ++flag;
//                    break;
//                }
//            }
//
//            for (int j = i + 1; j < m.size(); ++j)//���������з����������������
//            {
//                if (m[i][j] >= 1)//�о�ɾ�����ϲ������棩
//                {
//                    same(m, i, m[i][j] == 1 ? num : m[i][j]);
//                    ++num;
//                    ++flag;
//                    break;
//                }
//
//            }
//
//            if (flag == 0)
//            {
//                same(m, i, num);
//                ++num;
//            }
//
//        }
//        vector<int> ret;
//        for (int i = 0; i < m.size(); ++i)
//        {
//            int flag = 0;//
//            for (int j = 0; j < ret.size(); ++j)
//            {
//                if (m[i][i] == ret[j])
//                {
//                    flag = 1;
//                    break;
//                }
//            }
//            if (flag == 0)
//            {
//                ret.push_back(m[i][i]);
//            }
//        }
//        return ret.size();
//    }
//};


//int main()
//{
//    vector<vector<int>> vv = { {1, 1, 0, 0}, {1, 1, 1, 0}, {0 ,1 ,1, 0} , {0 ,0 ,0 ,1} };
//    Solution s1;
//    cout << s1.citys(vv) << endl;
//    return 0;
//}
//[[1, 1, 0]
//[1, 1, 0], 
//[0, 0, 1]]

//[[1, 1, 0, 0], [1, 1, 1, 0], [0, 1, 1, 0], [0, 0, 0, 1]]