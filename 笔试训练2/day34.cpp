#define _CRT_SECURE_NO_WARNINGS


//ISBN����
//#include <iostream>
//#include<string>
//using namespace std;
//
//int main() {
//    //ģ��
//    string s;
//    cin >> s;
//    int x = 0;//ʶ����
//    int n = 1;
//    for (auto& ch : s) {
//        if (n > 9)
//            break;
//        if (ch == '-')
//            continue;
//        else {
//            x += n * (ch - 48);
//            ++n;
//        }
//    }
//    x %= 11;
//    if (x == 10)
//        x = 'X';
//    else
//        x += 48;
//    if (x == s[s.size() - 1])
//        cout << "Right" << endl;
//    else {
//        s[s.size() - 1] = x;
//        cout << s << endl;
//    }
//    return 0;
//}



//kotori���Թ�
//#include <iostream>
//#include<vector>
//#include<array>
//#include<queue>
//#include<utility>
//using namespace std;
//
//int main() {
//    //�������
//    int n, m;
//    cin >> n >> m;
//    vector<vector<char>> grid(n, vector<char>(m));
//    int x, y;//��¼k��λ��
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < m; ++j) {
//            cin >> grid[i][j];
//            if (grid[i][j] == 'k') {
//                x = i, y = j;
//            }
//        }
//    }
//    int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
//    vector<vector<bool>> hash(n, vector<bool>(m));//�ж�·���Ƿ�����
//    vector<vector<int>> dist(n, vector<int>(m, 0));//��ʼ�㵽�˴��ľ���
//    queue<pair<int, int>> qp;
//    qp.push({ x, y });
//    int ret_min = 0;
//    int flag = 0;//�ж��Ƿ��ҵ��������
//    int ret_count = 0;
//    while (!qp.empty()) {
//        auto& [a, b] = qp.front();
//        hash[a][b] = true;
//        if (grid[a][b] == 'e') {
//            ++ret_count;
//            if (flag == 0) {
//                ret_min = dist[a][b];
//                flag = 1;
//            }
//        }
//        else {
//            for (auto& e : dir) {
//                x = a + e[0];
//                y = b + e[1];
//                if (0 <= x && x < n && 0 <= y && y < m && hash[x][y] == false && grid[x][y] != '*') {
//                    qp.push({ x, y });
//                    dist[x][y] = dist[a][b] + 1;
//                }
//            }
//        }
//        qp.pop();
//    }
//    if (ret_count) {
//        cout << ret_count << ' ' << ret_min << endl;
//    }
//    else {
//        cout << -1 << endl;
//    }
//
//    return 0;
//}



//���������·�������˼���������ɹ�ac��������С�����ǩ����˵�����о��������������ǻ��ǰ��˴�æ��
// tips�������ܾ�֮ǰ������������û��������������������������⣬������ѭ����+�Ż�һ��һ���������ɣ�
//class Solution {
//public:
//    /**
//     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
//     *
//     * ����·������󳤶�
//     * @param matrix int����vector<vector<>> ���������ÿ����
//     * @return int����
//     */
//    int solve(vector<vector<int> >& matrix) {
//        //�ݹ飬����һ�������¼��i��j��ʼ���·������֦��
//        //��ǰλ�ý��������ܽ��ϲ��Ҽ�¼����λ�ü��ɣ���Ϊ·������ԭ�򣬲�������ظ����
//        int n = matrix.size(), m = matrix[0].size();
//        vector<vector<int> > ret(n, vector<int>(m, -1));
//        int ret_max = 0;
//        for (int i = 0; i < n; ++i) {
//            for (int j = 0; j < m; ++j) {
//                ret_max = max(ret_max, Dfs(matrix, ret, i, j));
//            }
//        }
//        return ret_max;
//    }
//
//private:
//    int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
//
//    //dfs������i��jΪ�����·��
//    int Dfs(vector<vector<int> >& grid, vector<vector<int> >& ret, int i, int j) {
//        if (ret[i][j] != -1)//����Ϊ-1˵���Դ�Ϊ��ʼ��·����Ѿ���¼
//            return ret[i][j];
//        for (auto& e : dir) {
//            int x = i + e[0];
//            int y = j + e[1];
//            //���x��y��λ�ñȵ�ǰ�󣬲��Ҳ�Ϊ-1��˵����ֱ�ӽ��ϣ�Ϊ-1�͵ݹ���ȥ����x��y��λ��
//            if (0 <= x && x < grid.size() && 0 <= y && y < grid[0].size() && grid[i][j] < grid[x][y]) {
//                ret[i][j] = max(ret[i][j], 1 + Dfs(grid, ret, x, y));
//            }
//        }
//        ret[i][j] = max(1, ret[i][j]);//���ܳ������ܶ����ܽ��ϣ��˿�i��jλ�û���Ϊ-1�������Ϊ1��־�Ѿ�������˴�
//        return ret[i][j];
//    }
//};