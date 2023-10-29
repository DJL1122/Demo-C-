#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void creatBracket(int n, string tar, vector<string>& res, int left_num = 0, int right_num = 0) {
    if (left_num == n && right_num == n) {
        res.emplace_back(tar);
        return;
    }
    if (left_num < n) {
        creatBracket(n, tar + "(", res, left_num + 1, right_num);
    }
    if (right_num < left_num) {
        creatBracket(n, tar + ")", res, left_num, right_num + 1);
    }
}

int main() {
    vector<string> res;
    int n;
    string temp = "";
    cin >> n;
    creatBracket(n, temp, res);
    for (vector<string>::iterator it = res.begin(); it != res.end();it++) {
        cout << "\""<< * it << "\"" << ",";
    }
}

//class Solution {
//public:
//    vector<string> generateParenthesis(int n) {
//        std::vector<std::string> res{};
//        std::string tmp{};
//        AddParenthesis(res, tmp, n, n);
//        return res;
//    }
//    void AddParenthesis(std::vector<std::string>& res, std::string& tmp, int l, int r) {
//        if (l > r || l < 0) return; //¾øÃî
//        if (l == 0 && r == 0) {
//            res.push_back(tmp);
//            return;
//        }
//        tmp += '(';
//        AddParenthesis(res, tmp, l - 1, r);
//        tmp.pop_back();
//        tmp += ')';
//        AddParenthesis(res, tmp, l, r - 1);
//        tmp.pop_back();
//    }
//};