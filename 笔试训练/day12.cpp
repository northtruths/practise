#define _CRT_SECURE_NO_WARNINGS


//删除公共字符
//#include <algorithm>
//#include<iostream>
//#include<string>
//using namespace std;
//
//int main()
//{
//    string ret;
//    string del;
//    getline(cin, ret);
//    getline(cin, del);
//    string::iterator del_end = unique(del.begin(), del.end());
//    int deli = 0;
//    int flag = 0;
//    for (auto j = del.begin(); j != del_end; ++j)
//    {
//        for (auto i = ret.begin(); i != ret.end(); ++i)
//        {
//            while (i != ret.end() && *j == *i)
//            {
//                i = ret.erase(i);
//            }
//            if (i == ret.end())
//            {
//                flag = 1;
//                break;
//            }
//        }
//        if (flag)
//            break;
//    }
//    cout << ret << endl;
//    return 0;
//}










//两个链表的第一个公共结点
//#include<iostream>
//using namespace std;
//struct ListNode {
//	int val;
//	struct ListNode* next;
//
//};
//class Solution {
//public:
//	ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
//		int num1 = 0, num2 = 0;
//		ListNode* temp1 = pHead1;
//		while (temp1 != NULL)
//		{
//			++num1;
//			temp1 = temp1->next;
//		}
//		ListNode* temp2 = pHead2;
//		while (temp2 != NULL)
//		{
//			++num2;
//			temp2 = temp2->next;
//		}
//		temp1 = pHead1;
//		temp2 = pHead2;
//		if (num1 > num2)
//		{
//			while (num1 > num2)
//			{
//				--num1;
//				temp1 = temp1->next;
//			}
//		}
//		else if (num2 > num1)
//		{
//			while (num2 > num1)
//			{
//				--num2;
//				temp2 = temp2->next;
//			}
//		}
//		while (num1--)
//		{
//			if (temp1 == temp2)
//			{
//				return temp1;//temp1和temp2都一样
//			}
//			temp1 = temp1->next;
//			temp2 = temp2->next;
//		}
//		return nullptr;
//	}
//};
//
//int main()
//{
//	ListNode h1;
//	h1.val = 1;
//	ListNode h2;
//	h2.val = 2;
//	ListNode h3;
//	h3.val = 3;
//	ListNode h4;
//	h4.val = 4;
//	ListNode h5;
//	h5.val = 5;
//	ListNode h6;
//	h6.val = 6;
//	ListNode h7;
//	h7.val = 7;
//
//	h1.next = &h2;
//	h2.next = &h3;
//	h3.next = &h6;
//	h6.next = &h7;
//	h4.next = &h5;
//	h5.next = &h6;
//	h7.next = NULL;
//	Solution s;
//	cout << s.FindFirstCommonNode(&h1, &h4)->val << endl;
//	return 0;
//}






//#include<iostream>
//#include<string>
//using namespace std;
//
//int main()
//{
//    int n;
//    cin >> n;
//    string s;
//    getchar();
//    getline(cin, s);
//    string ch;
//    for(auto& e : s)
//    { 
//        if (e == 's' || e == 'h' || e == 'y')
//            ch += e;
//    }
//    int i = 0, j = 0, k = 0;
//    int ret = 0;
//    for (i = 0; i < ch.size() - 2; ++i)
//    {
//        if (ch[i] == 's')
//        {
//            for (j = i + 1; j < ch.size() - 1; ++j)
//            {
//                if (ch[j] == 'h')
//                {
//                    for (k = j + 1; k < ch.size(); ++k)
//                    {
//                        if (ch[k] == 'y')
//                            ++ret;
//                    }
//                }
//            }
//        }
//    }
//    cout << ret << endl;
//    return 0;
//}




#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string in;
    getchar();
    getline(cin, in);
    string ch;
    vector<int> s; vector<int> h; vector<int> y;

    for (int i = 0; i < in.size(); ++i)
    {
        if (in[i] == 's')
        {
            ch += 's';
            s.push_back(i);
        }
        if (in[i] == 'h')
        {
            ch += 'h';
            h.push_back(i);
        }
        if (in[i] == 'y')
        {
            ch += 'y';
            y.push_back(i);
        }
    }
    int i = 0, j = 0, k = 0;
    int si = 0, hi = 0, yi = 0;
    int ret = 0;
    for (i = s[si]; si < s.size(); ++si)
    {
        i = s[si];
        hi = 0;
        for (j = h[hi]; hi < h.size(); ++hi)
        {
            j = h[hi];
            if (j > i)
            {
                yi = 0;
                for (k = y[yi]; yi < y.size(); ++yi)
                {
                    k = y[yi];
                    if (k > j)
                        ++ret;
                }

            }

        }
    }
    cout << ret << endl;
    return 0;
}