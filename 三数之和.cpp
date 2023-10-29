#include <vector>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <string>
#include <set>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> res;
    set<vector<int>> set;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] > 0) break;
        if (i - 1 >= 0 && nums[i - 1] == nums[i]) continue;
        int l = i + 1, r = nums.size() - 1;
        while (l < r) {
            int sum = nums[i] + nums[l] + nums[r];
            if (sum == 0) {
                vector<int> tmp = { nums[i], nums[l], nums[r] };
                if (set.count(tmp) == 0) {
                    res.push_back(tmp);
                    set.insert(tmp);
                }
                l++;
                r--;
            }
            else if (sum < 0) {
                l++;
            }
            else {
                r--;
            }
        }
    }
    return res;
}


//1.按照字符串类型读取整行的输入
int main() {
    string str;
    getline(cin, str);
    stringstream ss(str);

    vector<vector<int>> x;
    vector<int> nums;

    char del = ',';// 分割符号为，
    string tmp;
    while (getline(ss, tmp, del)) {
        nums.push_back(stoi(tmp));
    }

    x = threeSum(nums);

    for (auto v : x) {
        cout << "[";
        for (auto i : v) {
            cout << i <<" ";
        }
        cout << "] ";
            
    }
    
 
    return 0;

    
    
}

