/*
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
    int maxSum(Node* root, int& maxi){
        if(root == NULL) return 0;
        int leftSum = max(0,maxSum(root->left,maxi));
        int rightSum = max(0,maxSum(root->right,maxi));
        maxi = max(maxi,leftSum+rightSum+root->data);
        return (root->data) + max(leftSum,rightSum);
    }
  public:
    int findMaxSum(Node *root) {
        int maxi = INT_MIN;
        maxSum(root,maxi);
        return maxi;
    }
};