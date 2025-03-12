#define _CRT_SECURE_NO_WARNINGS


//Fibonacci数列
//#include<iostream>
//#include<vector>
//using namespace std;
//
//int main()
//{
//    //dp找到n的左右两个斐波那契数,然后得出较小那个
//    int a = 1;
//    int b = 1;
//    int n = 0;
//    cin >> n;
//    while (a < n && b < n)//每次ab的斐波那契数都往右移动一位，b > a，当b大于等于n时，a <= n <= b
//    {
//        int c = a + b;
//        a = b;
//        b = c;
//    }
//    cout << min(n - a, b - n) << endl;
//    return 0;
//}




//单词搜索
//using namespace std;
//class Solution {
//public:
//    /**
//     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
//     *
//     *
//     * @param board string字符串vector
//     * @param word string字符串
//     * @return bool布尔型
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
//                if (board[i][j] == head)//首字母相同
//                    dfs(board, word, i, j, 0, hash, flag, dir);
//                if (flag)
//                    return true;
//            }
//        }
//        return false;
//    }
//    //i，j为当前数组的位置，n为当前单词的第n+1个字符,hash为当前位置是否走过,flag为是否找到但单词
//    void dfs(vector<string>& board, string& word, int i, int j, int n,
//        vector<vector<bool>>& hash, bool& flag, int(&dir)[4][2])
//    {
//        if (flag)
//            return;
//        if (n >= word.size())//找到
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


//杨辉三角
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