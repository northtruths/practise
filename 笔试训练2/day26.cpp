#define _CRT_SECURE_NO_WARNINGS


//С���ABC
//#include<iostream>
//#include<string>
//#include<climits>
//using namespace std;
//
//int main() {
//    string s;
//    cin >> s;
//    int ret = -1;
//    for (int i = 0; i < s.size(); ++i) {
//        if (i - 1 >= 0 && i + 1 < s.size() && s[i - 1] == s[i + 1]) {
//            ret = ret == -1 ? 3 : min(ret, 3);
//        }
//        if (i + 1 < s.size() && s[i] == s[i + 1]) {
//            ret = 2;
//            break;
//        }
//    }
//    cout << ret << endl;
//    return 0;
//}


//������ȡ��
//#include<iostream>
//#include<vector>
//using namespace std;
//
//int main() {
//    //dp[i]Ϊ����0~i��ȡ�������ֵ
//    int n = 0;
//    cin >> n;
//    vector<int> nums(n);
//    for (int i = 0; i < n; ++i) {
//        cin >> nums[i];
//    }
//    if (n == 1) {
//        cout << nums[0] << endl;
//        return 0;
//    }
//    vector<int> dp(n);
//    dp[0] = nums[0];
//    dp[1] = max(nums[1], nums[0]);
//    for (int i = 2; i < n; ++i) {
//        dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
//    }
//    cout << dp[n - 1] << endl;
//    return 0;
//}



//�յ�ң�أ�δac����ʱ�临�Ӷȹ��ߣ������˸�����hash���ʱ�䣬���Ӷȳ���ʱ�����������ٿ���
//#include <iostream>
//#include<vector>
//#include<unordered_map>
//using namespace std;
//
//int main() {
//    //ÿ����Ա����һ���ܽ���״̬�����䣬������ж�Ա���������غ������Ǵ�
//    int n, p;
//    cin >> n >> p;
//    int ret = 0;
//    unordered_map<int, int> hash;
//    for (int i = 0; i < n; ++i) {
//        int temp = 0;
//        cin >> temp;
//        for (int k = temp - p; k <= p + temp; ++k) {
//            ret = max(ret, ++hash[k]);
//        }
//    }
//    cout << ret << endl;
//    return 0;
//}


//�յ�ң�أ�������ac������+���֣�
//#include <iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//int FindMin(vector<int>& nums, int min);//Ѱ�ҵ�ǰ����ͷ�±�
//int FindMax(vector<int>& nums, int max);//Ѱ�ҵ�ǰ����β�±�
//
//int main() {
//    //����ÿһ�¶ȣ�Ѱ���ж��ٶ�Ա�ܽ���״̬
//    //����Ѱ�Ҷ�Ա���������������ö����ҵ��ܽ����¶ȵĶ�Ա�������С������֮�Ϊ��
//    int n, p;
//    cin >> n >> p;
//    vector<int> nums(n);
//    for (int i = 0; i < n; ++i)
//        cin >> nums[i];
//    sort(nums.begin(), nums.end());
//    int ret = 0;
//    for (int i = nums[0]; i <= nums[nums.size() - 1]; ++i) {
//        int min_cur = i - p, max_cur = i + p;
//        int min_i = 0, max_i = 0;
//        min_i = FindMin(nums, min_cur);
//        max_i = FindMax(nums, max_cur);
//        ret = max(ret, max_i - min_i + 1);
//    }
//    cout << ret << endl;
//    return 0;
//}
//
//int FindMin(vector<int>& nums, int min) {
//    int min_i = 0;
//    int left = 0, right = nums.size() - 1;
//    while (left < right) {
//        int mid = (left + right) >> 1;
//        if (nums[mid] == min) {//�ҵ���ֱ�ӷ���
//            while (mid - 1 >= 0 && nums[mid - 1] == min)
//                mid = mid - 1;
//            min_i = mid;
//            return min_i;
//        }
//        if (nums[mid] > min)
//            right = mid - 1;
//        else
//            left = mid + 1;
//    }
//    min_i = left;//С�ڵĲ������ȥ�����ڵĵ����ȥ
//    return min_i;
//}
//
//int FindMax(vector<int>& nums, int max) {
//    int max_i = 0;
//    int left = 0, right = nums.size() - 1;
//    while (left < right) {
//        int mid = (left + right) >> 1;
//        if (nums[mid] == max) {//�ҵ���ֱ�ӷ���
//            while (mid + 1 < nums.size() && nums[mid + 1] == max)
//                mid = mid + 1;
//            max_i = mid;
//            return max_i;
//        }
//        if (nums[mid] > max)
//            right = mid - 1;
//        else
//            left = mid + 1;
//    }
//
//    if (left == right && nums[left] == max) {
//        while (left + 1 < nums.size() && nums[left + 1] == max)
//            left = left + 1;
//        max_i = left;
//    }
//    max_i = right;//���ڵĲ������ȥ��С�ڵĵ����ȥ
//    return max_i;
//}


//�յ�ң�أ��ⷨ���� �������ڡ����������ѧ�߼���
//#include <iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//int main() {
//    //ͨ����Ŀʽ�ӿɵã�k - p <= a[i] <= k + p����k��p�̶�ʱ��a[i]���Ϊk+p����СΪk-p
//    //���Ե�a[i]�ķ�Χ��k+p - k-p��2p��֮�ڣ�����һ��k�����ⷶΧ�ڵĶ�Ա
//    //�������ڣ�����Ϊa[i]ͷβ�Ĳ�ֵС�ڵ���2p
//    int n, p;
//    cin >> n >> p;
//    vector<int> nums(n);
//    for (int i = 0; i < n; ++i)
//        cin >> nums[i];
//    sort(nums.begin(), nums.end());
//    int ret = 0;
//    int left = 0, right = 0;//��������
//    while (right < nums.size()) {
//        while (right < nums.size() && nums[right] - nums[left] <= 2 * p)
//            ++right;
//        ret = max(ret, right - left);
//        ++left;
//    }
//    cout << ret << endl;
//    return 0;
//}