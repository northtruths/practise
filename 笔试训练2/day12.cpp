#define _CRT_SECURE_NO_WARNINGS


//删除公共字符
//#include<iostream>
//#include <unordered_set>
//#include<vector>
//#include<string>
//using namespace std;
//
//int main()
//{
//    string s1, s2;
//    getline(cin, s1);
//    getline(cin, s2);
//    string ret;
//    unordered_set<char> hash;
//    for (auto& e : s2)
//        hash.insert(e);
//    for (auto& e : s1)
//    {
//        if (hash.count(e) == 0)
//            ret += e;
//    }
//    cout << ret << endl;
//    return 0;
//}




//两个链表的第一个公共节点
///*
//struct ListNode {
//	int val;
//	struct ListNode *next;
//	ListNode(int x) :
//			val(x), next(NULL) {
//	}
//};*/
//class Solution {
//public:
//	ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
//		//遍历两个链表，记录元素个数，因为要找到公共节点，
//		//所以将长的那个链表多的节点去掉，从后面对齐两个链表长度，以便找到公共节点
//		int num1 = 0;
//		ListNode* cur1 = pHead1;
//		while (cur1)
//		{
//			++num1;
//			cur1 = cur1->next;
//		}
//		int num2 = 0;
//		ListNode* cur2 = pHead2;
//		while (cur2)
//		{
//			++num2;
//			cur2 = cur2->next;
//		}
//		if (num1 > num2)
//		{
//			for (int i = 0; i < num1 - num2; ++i)
//				pHead1 = pHead1->next;
//		}
//		else if (num2 > num1)
//		{
//			for (int i = 0; i < num2 - num1; ++i)
//				pHead2 = pHead2->next;
//		}
//		while (pHead1)
//		{
//			if (pHead1 == pHead2)
//				return pHead1;
//			else {
//				cout << "p1:" << pHead1->val << "p2:" << pHead2->val << endl;
//				pHead1 = pHead1->next;
//				pHead2 = pHead2->next;
//			}
//		}
//
//		return nullptr;
//	}
//};




//mari和shiny
//#include<iostream>
//#include<string>
//using namespace std;
//
//int main()
//{
//    int n = 0;
//    cin >> n;
//    string s;
//    char ch = 0;
//    for (int i = 0; i < n; ++i) {
//        cin >> ch;
//        if (ch == 's' || ch == 'h' || ch == 'y')
//            s += ch;
//    }
//    n = s.size();
//
//    //暴力超时，dp为0~i有多少个shy
//    //记录当前位置前有多少个sh，如果当前位置i为y，则dp[i] = dp[i - 1] + sh的数量,不为y则等于上个dp
//    //同理，记录当前位置前有多少个s，如果当前位置i为h，则dp2[i] = dp2[i - 1] + s的数量,不为h则等于上个dp
//    long long dp1[n];//shy的数量
//    long long dp2[n];//sh的数量
//    long long dp3[n];//s的数量
//    dp1[0] = dp2[0] = 0;
//    dp3[0] = s[0] == 's' ? 1 : 0;
//    for (int i = 1; i < n; ++i)
//    {
//        if (s[i] == 's')
//        {
//            dp3[i] = dp3[i - 1] + 1;
//            dp1[i] = dp1[i - 1];
//            dp2[i] = dp2[i - 1];
//        }
//        else {
//            if (s[i] == 'h')
//            {
//                dp2[i] = dp2[i - 1] + dp3[i - 1];
//                dp1[i] = dp1[i - 1];
//            }
//            else {
//                dp1[i] = dp1[i - 1] + dp2[i - 1];
//                dp2[i] = dp2[i - 1];
//            }
//            dp3[i] = dp3[i - 1];
//        }
//    }
//    cout << dp1[n - 1] << endl;
//    return 0;
//}