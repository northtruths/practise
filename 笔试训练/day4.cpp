#define _CRT_SECURE_NO_WARNINGS


//Fibonacci 数列
//#include<iostream>
//#include<vector>
//using namespace std;
//
//int main()
//{
//    int n = 0;
//    cin >> n;
//    vector<int> v;
//    v.push_back(0);
//    v.push_back(1);
//    int a = 0, b = 1;
//    do {
//        v.push_back(a + b);
//        a = v[v.size() - 2];
//        b = v[v.size() - 1];
//    } while (a + b < n);
//    int ret = n - b < (a + b) - n ? n - b : (a + b) - n;
//    cout << ret << endl;
//    return 0;
//}


//静态成员变量的初始化，类型名 + 域名 + 变量名，域名在中间而不是最开头（坑）
//#include<iostream>
//using namespace std;
//class one
//{
//public:
//	static int num;
//	int a = 0;
//
//};
//int one::num = 0;
//
//int main()
//{
//	cout << one::num << endl;
//	one::num += 1;
//	cout << one::num << endl;
//
//}



////单词搜素
////相邻的重复搜索解决，但隔几个长的连起来没有解决（不会，没学那些的知识）
//#include<iostream>
//#include<vector>
//#include<string>
//using namespace std;
//
//
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
//    bool serch(vector<string>& board, string& word, int x, int y, int row, int col, int num, char pre)
//        //num为所要找的单词的第几个的下标
//        //row，col为边界的下标，超过就直接返回
//        //x，y为当前字符下标
//        //pre为之前的字符在哪个方向
//    {
//        if (x > row || y > col || x < 0 || y < 0)
//            return false;
//        if (word[num] == board[x][y])
//        {
//            ++num;//找word的下一个
//            if (num == word.size())//找完了
//            {
//                return true;
//            }
//
//        }
//        else
//        {
//            return false;
//        }
//        bool one = 0, tow = 0, tree = 0, four = 0;
//        if(pre != 'n')
//        one = serch(board, word, x - 1, y, row, col, num, 's');
//        if(pre != 's')
//        tow = serch(board, word, x + 1, y, row, col, num, 'n');
//        if(pre != 'w')
//        tree = serch(board, word, x, y - 1, row, col, num, 'e');
//        if(pre != 'e')
//        four = serch(board, word, x, y + 1, row, col, num, 'w');
//        return one || tow || tree || four;
//    }
//    bool exist(vector<string>& board, string word) {
//        for (int i = 0; i < board.size(); ++i)
//        {
//            for (int j = 0; j < board[i].size(); ++j)
//            {
//                if (board[i][j] == word[0])//第一个字符匹配
//                {
//                    //上左下右深度优先搜索
//                    if (serch(board, word, i, j, board.size() - 1, board[i].size() - 1, 0, NULL))
//                    {
//                        return true;
//                    }
//                }
//            }
//        }
//        return false;
//    }
//
//};
//
//
//bool main()
//{
//    Solution s1;
//    vector<string> board(3);
//    for (int i = 0; i < 3; ++i)
//    {
//        cin >> board[i];
//    }
//    string word;
//    cin >> word;
//
//    return s1.exist(board, word);
//}
////例
////XYZE
////SFZE
////XDAA
////EEE



#include <iostream>
#include<vector>
#include<cmath>
using namespace std;

long long index(long long m, long long n)
{
    if (n == 0 || m == n)
        return 1;

    long long a = 1, b = 1;
    for (long long i = 1; i <= n; ++i)
    {
        b *= i;
    }
    while(n--)
    {
        a *= m--;
    }

    return a / b;
}
int main()
{
    long long n = 0;
    cin >> n;
    vector<vector<long long>> vv(n);
    vv[0].push_back(1);
    for (long long i = 1; i < n; ++i)
    {
        for (long long j = 0; j <= i; ++j)
        {
            
            vv[i].push_back(index(i, j));
        }
    }
    for (long long i = 0; i < n; ++i)
    {
        for (long long j = 0; j <= i; ++j)
        {
            printf("%5lld", vv[i][j]);
        }
        cout << '\n';
    }

}