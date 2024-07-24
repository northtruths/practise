#define _CRT_SECURE_NO_WARNINGS

//给数字添加逗号
//#include<iostream>
//#include<string>
//using namespace std;
//
//int main()
//{
//    int n = 0;
//    cin >> n;
//    string ret(to_string(n));
//    int size = ret.size();
//    for (int i = size - 3; i > 0; i -= 3)
//    {
//        ret.insert(ret.begin() + i, ',');
//    }
//    cout << ret << endl;
//    return 0;
//}




//青蛙跳楼梯
//#include<iostream>
//#include<vector>
//using namespace std;
//
//int main()
//{
//    //动态规划
//    int n = 0;
//    cin >> n;
//    vector<int> ret(n + 1);
//
//    ret[1] = 1;
//    ret[2] = 2;
//    for (int i = 3; i <= n; ++i)
//    {
//        ret[i] = (ret[i - 2]) + (ret[i - 1]);
//    }
//    cout << ret[n] << endl;
//    return 0;
//}



//扑克牌看是不是顺子(给5个数，0可以是任意)
//class Solution {
//public:
//    /**
//     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
//     *
//     *
//     * @param numbers int整型vector
//     * @return bool布尔型
//     */
//    bool IsContinuous(vector<int>& numbers) {
//        sort(numbers.begin(), numbers.end());
//        for (int i = 0; i < 4; ++i)
//        {
//            if (numbers[i] != 0 && numbers[i] == numbers[i + 1])
//                return false;
//        }
//        int min = 0;
//        int max = numbers[numbers.size() - 1];
//        int count = 0;//记录0的数量
//        for (auto e : numbers)
//        {
//            if (e != 0)
//            {
//                min = e;
//                break;
//            }
//            else {
//                ++count;
//            }
//        }
//        if (max - min > 4)
//            return false;
//        if ((max - min - 1) - (5 - count) < count)
//        {
//            return true;
//        }
//        else {
//            return false;
//        }
//    }
//};