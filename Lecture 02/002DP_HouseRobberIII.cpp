#include<iostream>
#include<unordered_map>

using namespace std;

class TreeNode {

public :

    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }

};

// recursive implementation

int helper(TreeNode* root) {

    // base case

    if (root == NULL) {

        return 0;

    }

    // recursive case

    // make a decision for the root

    // option 1 : don't rob the root node

    int dontRobRoot = helper(root->left) + helper(root->right);

    // option 2 : rob the root node

    int robRoot = root->val;

    if (root->left != NULL) {

        robRoot += helper(root->left->left) + helper(root->left->right);

    }

    if (root->right != NULL) {

        robRoot += helper(root->right->left) + helper(root->right->right);

    }

    return max(dontRobRoot, robRoot);

}

// recursive implementation

int helperTopDown(TreeNode* root, unordered_map<TreeNode*, int>& dp) {

    // lookup

    if (dp.find(root) != dp.end()) {

        // you already know the maximum money you can rob from the this tree without alerting the police

        return dp[root];

    }

    // base case

    if (root == NULL) {

        return dp[root] = 0;

    }

    // recursive case

    // make a decision for the root

    // option 1 : don't rob the root node

    int dontRobRoot = helperTopDown(root->left, dp) + helperTopDown(root->right, dp);

    // option 2 : rob the root node

    int robRoot = root->val;

    if (root->left != NULL) {

        robRoot += helperTopDown(root->left->left, dp) + helperTopDown(root->left->right, dp);

    }

    if (root->right != NULL) {

        robRoot += helperTopDown(root->right->left, dp) + helperTopDown(root->right->right, dp);

    }

    return dp[root] = max(dontRobRoot, robRoot);

}


int rob(TreeNode* root) {

    // return helper(root);

    unordered_map<TreeNode*, int> dp;

    return helperTopDown(root, dp);

}

int main() {

    // TreeNode* root = new TreeNode(3);

    // root->left = new TreeNode(2);
    // root->left->right = new TreeNode(3);

    // root->right = new TreeNode(3);
    // root->right->right = new TreeNode(1);

    // cout << rob(root) << endl;

    TreeNode* root = new TreeNode(3);

    root->left = new TreeNode(4);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    root->right = new TreeNode(5);
    root->right->right = new TreeNode(1);

    cout << rob(root) << endl;

    return 0;
}