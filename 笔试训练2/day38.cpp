#define _CRT_SECURE_NO_WARNINGS


//��ʹ�������Դ����������и��߼��������˰���ŷ������ģ���ס�����������߼�����ϸ����ÿ���׳�����ĵط���
//#include <iostream>
//#include<vector>
//using namespace std;
//
//int main() {
//    //��̬�滮������dp��¼0~i�������ζ�Ⱥ͵ڶ�����ζ��
//    //��i��λ����ζ�ȴ��ڵ���ǰ��������ζ�����������dp���δ�->֮ǰ���֮ǰ���->��ǰ
//    //������i��λ����ζ�ȴ��ڴδ���ζ������´δ���ζ�ȣ��δ�->��ǰ
//    int n;
//    cin >> n;
//    vector<int> nums(n);
//    cin >> nums[0];//��ǰ���룬�Ա�Ȼ���������ʱ˳��Ͱ�dp������
//    vector<int> first(n);
//    vector<int> second(n);
//    for (int i = 1; i < n; ++i) {
//        cin >> nums[i];
//        if (i == 1) {
//            first[1] = max(nums[0], nums[1]);
//            second[1] = min(nums[0], nums[1]);
//        }
//        else {
//            if (nums[i] >= first[i - 1]) {
//                second[i] = first[i - 1];
//                first[i] = nums[i];
//            }
//            else if (nums[i] > second[i - 1]) {
//                first[i] = first[i - 1];
//                second[i] = nums[i];
//            }
//            else {
//                first[i] = first[i - 1];
//                second[i] = second[i - 1];
//            }
//        }
//    }
//    int q;
//    cin >> q;
//    while (q--) {
//        int x;
//        cin >> x;
//        cout << second[x - 1] << endl;
//    }
//    return 0;
//}




//dd����ת
//#include <iostream>
//#include<vector>
//using namespace std;
//
////�����о���
//void row_mirror(vector<vector<int>>& matrix) {
//    int left = 0, right = 0;
//    if (matrix.size() % 2 == 1) {
//        left = matrix.size() / 2 - 1;
//        right = left + 2;
//    }
//    else {
//        right = matrix.size() / 2;
//        left = right - 1;
//    }
//    while (0 <= left) {
//        swap(matrix[left], matrix[right]);
//        --left; ++right;
//    }
//}
//
////�����о���
//void col_mirror(vector<vector<int>>& matrix) {
//    int left = 0, right = 0;
//    if (matrix.size() % 2 == 1) {
//        left = matrix.size() / 2 - 1;
//        right = left + 2;
//    }
//    else {
//        right = matrix.size() / 2;
//        left = right - 1;
//    }
//    //�о�����鷳����һ��һ������
//    for (int i = 0; i < matrix.size(); ++i) {
//        int temp_left = left, temp_right = right;
//        while (0 <= temp_left) {
//            swap(matrix[i][temp_left], matrix[i][temp_right]);
//            --temp_left; ++temp_right;
//        }
//    }
//}
//
//int main() {
//    //ģ����ݹ��ɿ�֪��˳ʱ����ת180����� �о���+�о���
//    //ÿ������ͬ������͵���û�䣬������������ɼ�Ϊ���1���о�����о���
//    int n = 0;
//    cin >> n;
//    vector<vector<int>> matrix(n, vector<int>(n));
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < n; ++j)
//            cin >> matrix[i][j];
//    }
//    int row = 0, col = 0;//rowΪ�в���, colΪ�в���
//    int q = 0;
//    cin >> q;
//    while (q--) {
//        int cur = 0;
//        cin >> cur;
//        if (cur == 1) {
//            //��1�����ֽ�Ϊ����
//            ++row;
//            ++col;
//        }
//        else ++row;
//    }
//    row %= 2;
//    col %= 2;
//    if (row) row_mirror(matrix);
//    if (col) col_mirror(matrix);
//    for (auto& i : matrix) {
//        for (auto& j : i)
//            cout << j << ' ';
//        cout << endl;
//    }
//    return 0;
//}



//С��ȡ����δac��������ʱ���ܾ�֮������������ˣ��ڼ䱻���ѵ÷���ѧϰ��һ��ʱ�䣬���Ҳ����ȫ�ܿ�����
// ���ͬ��֮ǰ�����������ģ�⣬����ģ���������ˣ�����û����ȫ���ͬ�ඨ����
//#include <iostream>
//#include<vector>
//using namespace std;
//
//int main() {
//    //01����+ͬ�ඨ��
//    //dp[i][j]Ϊ��ǰi����ѡ���ܺ�%kΪjʱ������
//    //ȡ����j=0��������ֵ��Ϊ���
//    long long n, k;
//    cin >> n >> k;
//    vector<long long> nums(n);
//    for (long long i = 0; i < n; ++i)
//        cin >> nums[i];
//    vector<vector<long long>> dp(n, vector<long long>(k, -1));
//    dp[0][nums[0] % k] = nums[0];
//    for (long long i = 1; i < n; ++i) {
//        dp[i][nums[i] % k] = max(dp[i][nums[i] % k], nums[i]);
//        for (long long j = k - 1; j >= 0; --j) {
//            dp[i][j] = max(dp[i - 1][j], dp[i][j]);
//            if (dp[i - 1][j] != -1) {//����Ҫǰ��ĺʹ���
//                long long a = nums[i] % k;
//                long long b = (a + j) % k;
//                dp[i][b] = max(dp[i - 1][b], dp[i - 1][j] + nums[i]);
//            }
//
//        }
//    }
//    long long ret = -1;
//    for (auto& e : dp) {
//        ret = max(ret, e[0]);
//    }
//    if (ret == 0)
//        ret = -1;
//    cout << ret << endl;
//    return 0;
//}