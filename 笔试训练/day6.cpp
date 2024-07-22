#define _CRT_SECURE_NO_WARNINGS

#include<algorithm>
//#include<iostream>
//#include<string>
//#include<cmath>
//using namespace std;
//
//
//string solve(string s, string t) {
//    string& long_s = s.size() > t.size() ? s : t;
//    string& short_s = s.size() > t.size() ? t : s;
//
//    string ret;
//    int add = 0;
//    reverse(s.begin(), s.end());
//    reverse(t.begin(), t.end());
//
//    for (int i = 0; i < short_s.size(); ++i)
//    {
//        int a = s[i] - 48;
//        int b = t[i] - 48;
//        ret += (a + b + add) % 10;
//        add = (a + b + add) / 10;
//    }
//    for (int i = short_s.size(); i < long_s.size(); ++i)
//    {
//        int a = long_s[i] - 48;
//        ret += (a + add) % 10;
//        add = (a + add) / 10;
//    }
//    if (add != 0)
//    {
//        ret += add;
//    }
//    reverse(ret.begin(), ret.end());
//    for (auto& e : ret)
//    {
//        e += 48;
//    }
//    return ret;
//}
//int main()
//{
//	string s1;
//    string s2;
//    cin >> s1 >> s2;
//    cout << solve(s1, s2) << endl;
//
//	return 0;
//}




//#include<iostream>
//#include<list>
//using namespace std;
//
//
// struct ListNode {
// int val;
// struct ListNode *next;
// ListNode(int x) : val(x), next(nullptr) {}
// };
////class Solution {
////public:
//    /**
//     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
//     *
//     *
//     * @param head1 ListNode类
//     * @param head2 ListNode类
//     * @return ListNode类
//     */
//    ListNode* addInList(ListNode* head1, ListNode* head2) {
//        list<int, allocator<int>> ret;
//        list<int, allocator<int>> l1;
//        list<int, allocator<int>> l2;
//        while (head1)
//        {
//            l1.push_back(head1->val);
//            head1 = head1->next;
//        }
//        while (head2)
//        {
//            l2.push_back(head2->val);
//            head2 = head2->next;
//        }
//        reverse(l1.begin(), l1.end());
//        reverse(l2.begin(), l2.end());
//        list<int, allocator<int>>& long_list = l1.size() > l2.size() ? l1 : l2;
//        list<int, allocator<int>>& short_list = l1.size() > l2.size() ? l2 : l1;
//        int add = 0;
//        while(!short_list.empty())
//        {
//            int a = long_list.front();
//            int b = short_list.front();
//            ret.push_back((a + b + add) % 10);
//            add = (a + b + add) / 10;
//            long_list.pop_front();
//            short_list.pop_front();
//        }
//        while (!long_list.empty())
//        {
//            int a = long_list.front();
//            ret.push_back((a + add) % 10);
//            add = (a + add) / 10;
//            long_list.pop_front();
//        }
//        if (add != 0)
//        {
//            ret.push_back(add);
//        }
//        reverse(ret.begin(), ret.end());
//        ListNode* ret2 = (ListNode*)malloc(sizeof(ListNode));
//        ListNode* cur = ret2;
//        ListNode* prev = nullptr;
//        for (auto& e : ret)
//        {
//            prev = cur;
//            cur->val = e;
//            cur->next = (ListNode*)malloc(sizeof(ListNode));
//            cur = cur->next;
//        }
//        prev->next = nullptr;
//        return ret2;
//    }
////};
//int main()
//{
//    ListNode* head1 = (ListNode*)malloc(sizeof(ListNode));
//    head1->val = 9;
//    head1->next = (ListNode*)malloc(sizeof(ListNode));
//    head1->next->val = 3;
//    head1->next->next = (ListNode*)malloc(sizeof(ListNode));
//    head1->next->next->val = 7;
//    head1->next->next->next = nullptr;
//    ListNode* head2 = (ListNode*)malloc(sizeof(ListNode));
//    head2->val = 6;
//    head2->next = (ListNode*)malloc(sizeof(ListNode));
//    head2->next->val = 3;
//    head2->next->next = nullptr;
//    addInList(head1, head2);
//	return 0;
//}
//[9,3,7],[6,3]




//#include<iostream>
//#include<string>
//using namespace std;
//
//    /**
//     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
//     *
//     *
//     * @param s string字符串 第一个整数
//     * @param t string字符串 第二个整数
//     * @return string字符串
//     */
//    string Add(string s, string t) {
//        if (s.empty() || t.empty())
//        {
//            if (s.empty() && t.empty())
//            {
//                return "";
//            }
//            else if (s.empty())
//            {
//                return t;
//            }
//            else
//            {
//                return s;
//            }
//
//        }
//        reverse(s.begin(), s.end());
//        reverse(t.begin(), t.end());
//        string& long_s = s.size() > t.size() ? s : t;
//        string& short_s = s.size() > t.size() ? t : s;
//
//        string ret;
//        int add = 0;
//        for (int i = 0; i < short_s.size(); ++i)
//        {
//            int a = s[i] - 48;
//            int b = t[i] - 48;
//            ret += (a + b + add) % 10;
//            add = (a + b + add) / 10;
//        }
//        for (int i = short_s.size(); i < long_s.size(); ++i)
//        {
//            int a = long_s[i] - 48;
//            ret += (a + add) % 10;
//            add = (a + add) / 10;
//        }
//        if (add != 0)
//        {
//            ret += add;
//        }
//        reverse(ret.begin(), ret.end());
//        for (auto& e : ret)
//        {
//            e += 48;
//        }
//        return ret;
//    }
//    string solve(string s, string t) {
//        if (s == "0" || t == "0")
//            return "0";
//        reverse(s.begin(), s.end());
//        reverse(t.begin(), t.end());
//        string& long_s = s.size() > t.size() ? s : t;
//        string& short_s = s.size() > t.size() ? t : s;
//
//        string ret;
//        string ADD;
//        int add = 0;
//        for (int i = 0; i < short_s.size(); ++i)
//        {
//            int a = short_s[i] - 48;
//            for (int j = 0; j < long_s.size(); ++j)
//            {
//                int b = long_s[j] - 48;
//                ADD += (a * b + add) % 10;
//                add = (a * b + add) / 10;
//            }
//            reverse(ADD.begin(), ADD.end());
//            for (auto& e : ADD)
//            {
//                e += 48;
//            }
//            ret = Add(ret, ADD);
//            ADD.clear();
//            reverse(long_s.begin(), long_s.end());
//            long_s += '0';//乘10
//            reverse(long_s.begin(), long_s.end());
//        }
//        return ret;
//    }
//
//    int main()
//    {
//        string s1("15");
//        string s2("111");
//        cout << solve(s1, s2) << endl;
//        return 0;
//    }