#include<iostream>


using namespace std;
int main() {
    
    int nums[8] = { 10,9,2,5,3,7,101,184 };
    if (sizeof(nums) / sizeof(nums[0]) == 0) {
        return 0;
    }
    int *dp = new int[sizeof(nums) / sizeof(nums[0])];
    //��ʼ�����Ǳ߽����
    dp[0] = 1;
    int maxans = 1;
    //�Ե����ϱ���
    for (int i = 1; i < sizeof(nums) / sizeof(nums[0]); i++) {
        dp[i] = 1;
        //���±�0��i����
        for (int j = 0; j < i; j++) {
            //�ҵ�ǰ���nums[i]С����nums[j],����dp[i]= dp[j]+1
            if (nums[j] < nums[i]) {
                //��Ϊ���ж��С��nums[i]������Ҳ���ǻ���ڶ������������Ǿ�ȡ���ŵ�dp[i]
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        //���dp[i]��dp����Ǹ�����nums���������������
        maxans = max(maxans, dp[i]);
    }
    cout << maxans;
}
