#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int findMaxLength(vector<int>& A) {
    int N = A.size();
    vector<int> dp(N, 1);
    unordered_map<int, int> lastIndex;

    sort(A.begin(), A.end());

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (A[i] % A[j] == 0 && lastIndex.count(A[j]) && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
            }
        }
        lastIndex[A[i]] = i;
    }

    int maxLength = *max_element(dp.begin(), dp.end());
    return maxLength;
}

int main() {
    vector<int> A = { 1, 2,2,16,2};
    int maxLength = findMaxLength(A);
    cout << maxLength << endl;  // Êä³ö£º4

    return 0;
}
