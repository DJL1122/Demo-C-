#include<iostream>


using namespace std;
int main() {
    
    int nums[8] = { 10,9,2,5,3,7,101,184 };
    if (sizeof(nums) / sizeof(nums[0]) == 0) {
        return 0;
    }
    int *dp = new int[sizeof(nums) / sizeof(nums[0])];
    //初始化就是边界情况
    dp[0] = 1;
    int maxans = 1;
    //自底向上遍历
    for (int i = 1; i < sizeof(nums) / sizeof(nums[0]); i++) {
        dp[i] = 1;
        //从下标0到i遍历
        for (int j = 0; j < i; j++) {
            //找到前面比nums[i]小的数nums[j],即有dp[i]= dp[j]+1
            if (nums[j] < nums[i]) {
                //因为会有多个小于nums[i]的数，也就是会存在多种组合了嘛，我们就取最大放到dp[i]
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        //求出dp[i]后，dp最大那个就是nums的最长递增子序列啦
        maxans = max(maxans, dp[i]);
    }
    cout << maxans;
}
