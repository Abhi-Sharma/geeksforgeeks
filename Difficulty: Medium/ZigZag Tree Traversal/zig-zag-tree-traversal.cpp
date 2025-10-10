/*
class Node {
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
  public:
    vector<int> zigZagTraversal(Node* root) {
        queue<Node*> q;
        q.push(root);
        bool leftToRight = true;
        vector<int> res;
        while(!q.empty()){
            int size = q.size();
            vector<int> ans(size);
            for(int i = 0; i < size; i++){
                Node* node= q.front();
                q.pop();
                int index = leftToRight ? i : size-i-1;
                ans[index] = node->data;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            for(int num : ans){
                res.push_back(num);
            }
            leftToRight = !leftToRight;
        }
        return res;
    }
};