#define _CRT_SECURE_NO_WARNINGS


//Fibonacci����
//#include<iostream>
//#include<vector>
//using namespace std;
//
//int main()
//{
//    //dp�ҵ�n����������쳲�������,Ȼ��ó���С�Ǹ�
//    int a = 1;
//    int b = 1;
//    int n = 0;
//    cin >> n;
//    while (a < n && b < n)//ÿ��ab��쳲��������������ƶ�һλ��b > a����b���ڵ���nʱ��a <= n <= b
//    {
//        int c = a + b;
//        a = b;
//        b = c;
//    }
//    cout << min(n - a, b - n) << endl;
//    return 0;
//}




//��������
//using namespace std;
//class Solution {
//public:
//    /**
//     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
//     *
//     *
//     * @param board string�ַ���vector
//     * @param word string�ַ���
//     * @return bool������
//     */
//    bool exist(vector<string>& board, string word) {
//        char head = word[0];
//        int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
//        vector<vector<bool>> hash(board.size(), vector<bool>(board[0].size()));
//        bool flag = 0;
//        for (int i = 0; i < board.size(); ++i)
//        {
//            for (int j = 0; j < board[0].size(); ++j)
//            {
//                if (board[i][j] == head)//����ĸ��ͬ
//                    dfs(board, word, i, j, 0, hash, flag, dir);
//                if (flag)
//                    return true;
//            }
//        }
//        return false;
//    }
//    //i��jΪ��ǰ�����λ�ã�nΪ��ǰ���ʵĵ�n+1���ַ�,hashΪ��ǰλ���Ƿ��߹�,flagΪ�Ƿ��ҵ�������
//    void dfs(vector<string>& board, string& word, int i, int j, int n,
//        vector<vector<bool>>& hash, bool& flag, int(&dir)[4][2])
//    {
//        if (flag)
//            return;
//        if (n >= word.size())//�ҵ�
//        {
//            flag = true;
//            return;
//        }
//        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size()
//            || board[i][j] != word[n] || hash[i][j])
//            return;
//        hash[i][j] = true;
//        for (auto& e : dir)
//        {
//            dfs(board, word, i + e[0], j + e[1], n + 1, hash, flag, dir);
//        }
//        hash[i][j] = false;
//
//    }
//};


//�������
//#include<iostream>
//#include<vector>
//using namespace std;
//
//int main()
//{
//    int n = 0;
//    cin >> n;
//    if (n == 1) { printf("%5d\n", 1); return 0; }
//    vector<vector<int>> v(n, vector<int>(n));
//    v[0][0] = 1;
//    printf("%5d\n", 1);
//    for (int i = 1; i < n; ++i)
//    {
//        for (int j = 0; j <= i; ++j)
//        {
//            if (j == 0 || j == i)
//            {
//                v[i][j] = 1;
//                printf("%5d", v[i][j]);
//                continue;
//            }
//            v[i][j] = v[i - 1][j - 1] + v[i - 1][j];
//            printf("%5d", v[i][j]);
//        }
//        printf("\n");
//    }
//
//    return 0;
//}