#define _CRT_SECURE_NO_WARNINGS


//kotori��������ѧ�⣩
//#include <iostream>
//using namespace std;
//
//int main() {
//    int n = 0, m = 0;
//    cin >> n >> m;
//    long long ret = n;
//    for (int i = 1; i < m; ++i) {
//        ret = ret * (n - 1) % 109;
//    }
//    cout << ret << endl;
//    return 0;
//}



//���Թ�
#include<iostream>
#include<vector>
#include<queue>
#include<utility>
using namespace std;

int main() {
    //���·�����������
    int n, m;
    cin >> n >> m;
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    --x1, --y1, --x2, --y2;
    vector<string> grid;
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }
    int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
    queue<vector<int>> q;//���������ֵ��x��y�Ͳ���
    vector<vector<bool>> hash(n, vector<bool>(m, false));
    q.push({ x1, y1, 0 });
    hash[x1][y1] = true;
    while (!q.empty()) {
        for (auto& e : dir) {
            int x = q.front()[0] + e[0];
            int y = q.front()[1] + e[1];
            if (0 <= x && x < n && 0 <= y && y < m &&
                hash[x][y] == false && grid[x][y] == '.') {
                q.push({ x, y, q.front()[2] + 1 });
                hash[x][y] = true;
            }
            if (x == x2 && y == y2) {
                cout << q.front()[2] + 1 << endl;
                queue<vector<int>> emp;
                swap(q, emp);
                break;
            }
        }
        if (!q.empty())
            q.pop();
    }
    return 0;
}



//�����˵��ȣ�����
//class Solution {
//public:
//    /**
//     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
//     *
//     * ����ɹ��ٰ���Ҫ������������
//     * @param n int���� ��n���
//     * @param startEnd int����vector<vector<>> startEnd[i][0]���ڱ�ʾ��i����Ŀ�ʼʱ�䣬startEnd[i][1]��ʾ��i����Ľ���ʱ��
//     * @return int����
//     */
//    int minmumNumberOfHost(int n, vector<vector<int> >& startEnd) {
//        //�����򣬵���ǰ��Ŀ�ʼʱ��С����һ����Ľ���ʱ��˵�������������һ���������
//        //����һ�����������飬ÿ�α���������飬��û�������˵Ľ���ʱ��С�ڵ�ǰ��Ŀ�ʼʱ�䣬�ͼ�һ�������ˣ�
//        //�����ֵΪ���������ֵ��ϸ���Ľ���ʱ��
//        sort(startEnd.begin(), startEnd.end(),
//            [&startEnd](vector<int>& x, vector<int>& y) ->bool {return x[0] < y[0]; });
//        vector<int> host;
//        for (int i = 0; i < n; ++i) {
//            int cur_begin = startEnd[i][0], cur_end = startEnd[i][1];
//            int flag = 0;//�Ƿ��п��е�������
//            for (auto& e : host) {
//                if (e <= cur_begin) {
//                    flag = 1;
//                    e = cur_end;
//                    break;
//                }
//            }
//            if (flag == 0) {
//                host.push_back(cur_end);
//            }
//        }
//
//        return host.size();
//    }
//};