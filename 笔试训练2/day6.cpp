#define _CRT_SECURE_NO_WARNINGS


//�����ӷ�
//#include <iterator>
//class Solution {
//public:
//    /**
//     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
//     *
//     * ����������֮��
//     * @param s string�ַ��� ��ʾ��һ������
//     * @param t string�ַ��� ��ʾ�ڶ�������
//     * @return string�ַ���
//     */
//    string solve(string s, string t) {
//        string ret;
//        reverse(s.rbegin(), s.rend());
//        reverse(t.rbegin(), t.rend());
//        int i_s = 0, i_t = 0;
//        int add = 0;//��λ
//        while (i_s < s.size() && i_t < t.size())
//        {
//            ret += (s[i_s] - '0' + t[i_t] - '0' + add) % 10 + '0';
//            add = (s[i_s] - '0' + t[i_t] - '0' + add) / 10;
//            ++i_s;
//            ++i_t;
//        }
//        while (i_s < s.size())
//        {
//            ret += (s[i_s] - '0' + add) % 10 + '0';
//            add = (s[i_s] - '0' + add) / 10;
//            ++i_s;
//        }
//        while (i_t < t.size())
//        {
//            ret += (t[i_t] - '0' + add) % 10 + '0';
//            add = (t[i_t] - '0' + add) / 10;
//            ++i_t;
//        }
//        if (add)
//            ret += add + '0';
//        reverse(ret.begin(), ret.end());
//        return ret;
//    }
//};



//������ӣ�����
//#include<iostream>
//#include<list>
//using namespace std;
//
//
//struct ListNode {
//    int val;
// 	struct ListNode *next;
//	ListNode(int x) : val(x), next(nullptr) {}
// };
//
//class Solution {
//public:
//    /**
//     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
//     *
//     *
//     * @param head1 ListNode��
//     * @param head2 ListNode��
//     * @return ListNode��
//     */
//    ListNode* addInList(ListNode* head1, ListNode* head2) {
//        list<int> l1, l2;
//        while (head1 != nullptr)
//        {
//            l1.push_back(head1->val);
//            head1 = head1->next;
//        }
//        while (head2 != nullptr)
//        {
//            l2.push_back(head2->val);
//            head2 = head2->next;
//        }
//        reverse(l1.begin(), l1.end());
//        reverse(l2.begin(), l2.end());
//        auto it_l1 = l1.begin();
//        auto it_l2 = l2.begin();
//        int add = 0;//��λ
//        list<int> ret;
//        while (it_l1 != l1.end() && it_l2 != l2.end())
//        {
//            ret.push_back((*it_l1 + *it_l2 + add) % 10);
//            add = (*it_l1 + *it_l2 + add) / 10;
//            ++it_l1; ++it_l2;
//        }
//        while (it_l1 != l1.end())
//        {
//            ret.push_back((*it_l1 + add) % 10);
//            add = (*it_l1 + add) / 10;
//            ++it_l1;
//        }
//        while (it_l2 != l2.end())
//        {
//            ret.push_back((*it_l2 + add) % 10);
//            add = (*it_l2 + add) / 10;
//            ++it_l2;
//        }
//        if (add)
//            ret.push_back(add);
//        reverse(ret.begin(), ret.end());
//        ListNode* r = new ListNode(0);
//        ListNode* cur = r;
//        int i = 0;
//        for (auto& e : ret)
//        {
//            cur->val = e;
//            if (i < ret.size() - 1)
//            {
//                cur->next = new ListNode(0);
//                ++i;
//            }
//            cur = cur->next;
//        }
//        cur = nullptr;
//        return r;
//    }
//};
//int main()
//{
//    ListNode* head1 = new ListNode(0);
//    head1->next = new ListNode(0);
//    head1->next->next = new ListNode(0);
//
//    head1->val = 9;
//    head1->next->val = 3;
//    head1->next->next->val = 7;
//
//    ListNode* head2 = new ListNode(0);
//    head2->next = new ListNode(0);
//
//    head2->val = 6;
//    head2->next->val = 3;
//    Solution s;
//    s.addInList(head1, head2);
//	return 0;
//}