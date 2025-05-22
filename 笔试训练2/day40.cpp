#define _CRT_SECURE_NO_WARNINGS


//游游的字母串
//#include <iostream>
//#include<vector>
//#include<string>
//using namespace std;
//
//int main() {
//    //遍历26遍，查看变哪个字母的操作最少
//    //变的字符次数分两种情况，当前字符大于所变字符和当前字符小于所变字符
//    //不论那种都是取要么顺着变要么逆着变的较小值
//    string s;
//    cin >> s;
//    int ret = 0x3f3f3f3f;
//    int cur = 0;//变当前字符的操作次数
//    for (char ch = 'a'; ch <= 'z'; ++ch) {//当前要变的字符
//        cur = 0;
//        for (auto& e : s) {
//            if (e <= ch)//若当前字符在所变字符前面
//                cur += min(ch - e, 'z' - ch + e - 'a' + 1);
//            else
//                cur += min(e - ch, 'z' - e + ch - 'a' + 1);
//        }
//        ret = min(ret, cur);
//    }
//    cout << ret << endl;
//    return 0;
//}


//体育课测验（二）（头一天没有很多细节情况没考虑到，因为状态原因也肯定无法想清楚吧，第二天睡醒有个良好状态，条理清晰地就把情况给想明白然后ac了）
//#include<iostream>
//#include<vector>
//#include<unordered_set>
//using namespace std;
//
//class Solution {
//public:
//    /**
//     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
//     *
//     *
//     * @param numProject int整型
//     * @param groups int整型vector<vector<>>
//     * @return int整型vector
//     */
//    vector<int> findOrder(int numProject, vector<vector<int> >& groups) {
//        //栈，每个分组看作栈
//        //统计栈底的数据（当前栈元素大于1），若当前有与栈顶相同的栈底元素，则栈顶不能出栈，否则能够出栈
//        int num = 2 * groups.size(); //总共项目个数，若最后不为0说明无法完成
//        vector<int> hash(numProject, 0);//检查哪些数出现在栈底，出现一次说明就有一个限制，为0时说明无限制
//        for (auto& e : groups)
//            ++hash[e[0]];//下标0为栈底
//        vector<int> ret;
//        unordered_set<int> ret_hash;//记录已经无限制编号，避免重复
//
//        for (int i = 0; i < numProject; ++i) {
//            if (hash[i] == 0) {//一开始就无限制
//                if (ret_hash.count(i) == 0) {
//                    ret_hash.insert(i);
//                    ret.push_back(i);
//                }
//            }
//        }
//        int flag = 1;//判断是否有完成某个项目，没有结束循环
//        while (flag) {
//            flag = 0;
//            for (auto& v : groups) {
//                if (v.size() == 2) {
//                    if (hash[v[1]] == 0)//这种情况要么是一开始无限制，要么是其他组解开的限制，所以肯定已经记录过，不用再记录
//                    {
//                        v.pop_back();
//                        --num;
//                        flag = 1;
//                    }
//                }
//                if (v.size() == 1) {
//                    if (hash[v[0]] == 0)//之前在其他地方完全解除的限制（使hash为0），此情况肯定已经记录过
//                    {
//                        v.pop_back();
//                        --num;
//                        flag = 1;
//                    }
//                    else {
//                        --hash[v[0]];//限制减1
//                        if (hash[v[0]] == 0 && ret_hash.count(v[0]) == 0) {
//                            ret_hash.insert(v[0]);
//                            ret.push_back(v[0]);
//                        }
//                        //只要只有一个元素就pop，因为不论是否已经解开都对其他的无影响，但留着不pop却会因再次循环到这而产生影响
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



//合唱队形
//#include <iostream>
//#include<vector>
//using namespace std;
//
//int main() {
//    //动态规划
//    //两个dp，一个left一个right，分别为以i为中心，左边的最少出列和右边的最少出列
//    //遍历找到左右比当前i矮的，找最大
//    //left,right只能分开单独计算
//    int n = 0;
//    cin >> n;
//    vector<int> hight(n);
//    vector<int> left(n);
//    vector<int> right(n);
//    for (int i = 0; i < n; ++i)//输入的同时填表left，省时间
//    {
//        cin >> hight[i];
//        left[i] = i;//最坏情况是hight[i]最矮，左边的都得出列
//        for (int j = i - 1; j >= 0; --j) {
//            if (hight[i] > hight[j])
//                left[i] = min(left[i], left[j] + i - j - 1);//取某个dp时，当前位置与其中间的人也得出列
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