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



//���������·��