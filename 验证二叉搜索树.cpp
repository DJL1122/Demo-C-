#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};



bool isValidBST(TreeNode* root) {
    if (root == NULL || (root->left == NULL && root->right == NULL)) return true;
    if (root->left == NULL) {
        if (root->val >= root->right->val) return false;
        return isValidBST(root->right);
    }
    else if (root->right == NULL) {
        if (root->val <= root->left->val) return false;
        return isValidBST(root->left);
    }
    else {
        if (root->val >= root->right->val || root->val <= root->left->val) return false;
        return isValidBST(root->left) && isValidBST(root->right);
    }
}

int main() {
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
   /* root->left->left = new TreeNode(NULL);
    root->left->right = new TreeNode(NULL);
    root->right->left = new TreeNode(3);
    root->right->right = new TreeNode(6);*/

    cout << isValidBST(root);
}