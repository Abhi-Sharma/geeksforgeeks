/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
    bool isleaf(Node* node){
        return !node->left && !node->right;
    }
    void addleft(Node* root, vector<int>& ans){
        Node* curr = root->left;
        while(curr){
            if(!isleaf(curr)) ans.push_back(curr->data);
            if(curr->left) curr = curr->left;
            else curr = curr->right;
        }
    }
    void addLeaves(Node* root, vector<int>& ans){
        if(isleaf(root)){
            ans.push_back(root->data);
        }
        if(root->left) addLeaves(root->left,ans);
        if(root->right) addLeaves(root->right, ans);
     }
     
     void addRight(Node* root, vector<int>& ans){
         Node* curr = root->right;
         vector<int> temp;
         while(curr){
             if(!isleaf(curr)) temp.push_back(curr->data);
             if(curr->right) curr = curr->right;
             else curr = curr->left;
         }
         
         for(int i = temp.size() - 1; i >= 0; i--){
             ans.push_back(temp[i]);
         }
     }
  public:
    vector<int> boundaryTraversal(Node *root) {
        vector<int> ans;
        if(!root) return ans;
        if(!isleaf(root)) ans.push_back(root->data);
        addleft(root,ans);
        addLeaves(root,ans);
        addRight(root,ans);
        return ans;
    }
};