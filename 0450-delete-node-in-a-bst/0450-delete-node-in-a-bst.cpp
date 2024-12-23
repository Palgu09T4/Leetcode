/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
   TreeNode* findRightmost(TreeNode* root) {
    while (root->right != NULL) {
        root = root->right;
    }
    return root;
}

// Recursive function to delete a node from the BST
TreeNode* deleteNode(TreeNode* root, int key) {
    // Base case: if the tree is empty
    if (root == NULL) {
        return NULL;
    }

    // If the key is smaller than the current node's value, go to the left subtree
    if (key < root->val) {
        root->left = deleteNode(root->left, key);
    }
    // If the key is greater than the current node's value, go to the right subtree
    else if (key > root->val) {
        root->right = deleteNode(root->right, key);
    }
    // If the current node is the one to be deleted
    else {
        // Case 1: Node with only one child or no child
        if (root->left == NULL) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        } 
        else if (root->right == NULL) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }

        // Case 2: Node with two children
        // Find the rightmost node in the left subtree (or the inorder predecessor)
        TreeNode* temp = findRightmost(root->left);

        // Copy the value of the inorder predecessor to this node
        root->val = temp->val;

        // Delete the inorder predecessor
        root->left = deleteNode(root->left, temp->val);
    }

    return root;
}
};