#define _CRT_SECURE_NO_WARNINGS



//kanan�͸���
//#include <iostream>
//#include<vector>
//using namespace std;
//
//int main() {
//    //����һ�鼴��
//    int n;
//    cin >> n;
//    vector<int> nums(n);
//    for (int i = 0; i < n; ++i)
//        cin >> nums[i];
//    int ret = 0;
//    int left = 0, right = 1;//˫ָ����������ڼ���
//    while (right < n) {
//        if (nums[right] - nums[right - 1] >= 9) {
//            ret = max(ret, right - left);
//            left = right;
//        }
//        ++right;
//    }
//    ret = max(ret, right - left);
//    cout << ret << endl;
//    return 0;
//}




//�ݷã�δac��50%��
//#include <queue>
//class Solution {
//public:
//    /**
//     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
//     *
//     *
//     * @param CityMap int����vector<vector<>>
//     * @param n int����
//     * @param m int����
//     * @hashurn int����
//     */
//    int countPath(vector<vector<int> >& CityMap, int n, int m) {
//        //�������
//        int bx = 0, by = 0;//��ʼλ��
//        for (int i = 0; i < n; ++i) {
//            for (int j = 0; j < m; ++j) {
//                if (CityMap[i][j] == 1) {
//                    bx = i, by = j;
//                    goto end;
//                }
//            }
//        }
//    end:
//        queue<pair<int, int>> q;
//        q.push({ bx, by });
//        vector<vector<int>> hash(n, vector<int>(m,
//            -1)); //hashΪ��(i,j)λ�õ���С����
//        hash[bx][by] = 0;
//        int ex = 0, ey = 0;//����λ��
//        while (q.size()) {
//            int cur_size = q.size();//��ǰ��
//            while (cur_size--) {
//                auto& [i, j] = q.front();
//                if (CityMap[i][j] == 2)
//                    ex = i, ey = j;
//                for (auto& e : dir) {
//                    int x = i + e[0];
//                    int y = j + e[1];
//                    if (0 <= x && x < n && 0 <= y && y < m && CityMap[x][y] != -1 &&
//                        hash[x][y] == -1) {
//                        hash[x][y] = hash[i][j] + 1;
//                        q.push({ x, y });
//                    }
//                }
//                q.pop();
//            }
//        }
//
//        int ret = 0;
//        int ret_min = 0x3f3f3f3f;
//        for (auto& e : dir) {
//            int x = ex + e[0];
//            int y = ey + e[1];
//            if (0 <= x && x < n && 0 <= y && y < m && hash[x][y] != -1) {
//                if (hash[x][y] < ret_min) {
//                    ret = 1;
//                    ret_min = hash[x][y];
//                }
//                else if (hash[x][y] == ret_min)
//                    ++ret;
//            }
//        }
//        return ret;
//    }
//
//private:
//    int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
//};






//������Ʊ�����ʱ�����ģ�����ȫû״̬�����ᣩ