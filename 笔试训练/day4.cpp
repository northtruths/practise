#define _CRT_SECURE_NO_WARNINGS


//Fibonacci ����
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


//��̬��Ա�����ĳ�ʼ���������� + ���� + ���������������м�������ͷ���ӣ�
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



////��������
////���ڵ��ظ����������������������������û�н�������ᣬûѧ��Щ��֪ʶ��
//#include<iostream>
//#include<vector>
//#include<string>
//using namespace std;
//
//
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
//    bool serch(vector<string>& board, string& word, int x, int y, int row, int col, int num, char pre)
//        //numΪ��Ҫ�ҵĵ��ʵĵڼ������±�
//        //row��colΪ�߽���±꣬������ֱ�ӷ���
//        //x��yΪ��ǰ�ַ��±�
//        //preΪ֮ǰ���ַ����ĸ�����
//    {
//        if (x > row || y > col || x < 0 || y < 0)
//            return false;
//        if (word[num] == board[x][y])
//        {
//            ++num;//��word����һ��
//            if (num == word.size())//������
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
//                if (board[i][j] == word[0])//��һ���ַ�ƥ��
//                {
//                    //�������������������
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
////��
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